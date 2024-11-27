"""
Se le da un número entero n y una matriz entera 2D queries.

Hay n ciudades numeradas de 0 a n - 1. Inicialmente, hay un unidireccional camino desde la ciudad i a la ciudad i + 1 para todos 0 <= i < n - 1.

queries[i] = [ui, vi] representa la adición de un nuevo unidireccional camino desde la ciudad a la ciudad . Después de cada consulta, debe encontrar el longitud de la camino más corto de la ciudad a la ciudad .uivi0n - 1

Devolver una matriz answer dónde para cada uno i en el rango [0, queries.length - 1], answer[i] es el longitud del camino más corto de la ciudad 0 a la ciudad n - 1 después de procesar el primero i + 1 consultas.

Ejemplo 1:
Entrada: n = 5, consultas = [[2,4],[0,2],[0,4]]
Salida: [3,2,1]
Explicación:
Después de la adición de la carretera de 2 a 4, la longitud del camino más corto de 0 a 4 es 3.
Después de la adición de la carretera de 0 a 2, la longitud del camino más corto de 0 a 4 es 2.
Después de la adición de la carretera de 0 a 4, la longitud del camino más corto de 0 a 4 es 1.

Ejemplo 2:
Entrada: n = 4, consultas = [[0,3],[0,2]]
Salida: [1,1]
Explicación:
Después de la adición de la carretera de 0 a 3, la longitud del camino más corto de 0 a 3 es 1.
Después de la adición de la carretera de 0 a 2, la longitud del camino más corto sigue siendo 1.
"""
class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        # Grafo inicial con caminos unidireccionales entre ciudades consecutivas
        graph = [[] for _ in range(n)]
        for i in range(n - 1):
            graph[i].append(i + 1)

        # lista para almacenar respuestas
        answer = []

        # procesamos cada consulta
        for u, v in queries:
            #agregar camino al Grafo
            graph[u].append(v)

            # encontrar el camino mas corto usando Dijkstra
            shortest_path = self.dijkstra(graph, 0, n - 1)
            answer.append(shortest_path)

        return answer

    def dijkstra(self, graph: List[List[int]], start: int, end: int) -> int:
        # Inicializar distancias
        distances = [float('inf')] * len(graph)
        distances[start] = 0
        
        # Cola de prioridad para Dijkstra
        pq = [(0, start)]
        
        while pq:
            current_distance, current_node = heapq.heappop(pq)
            
            # Si hemos llegado al nodo final, retornamos la distancia
            if current_node == end:
                return current_distance
            
            # Si ya encontramos un camino más corto, ignoramos
            if current_distance > distances[current_node]:
                continue
            
            # Explorar vecinos
            for neighbor in graph[current_node]:
                distance = current_distance + 1
                
                # Actualizar distancia si encontramos un camino más corto
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))
        
        # Si no hay camino, retorna infinito
        return float('inf')

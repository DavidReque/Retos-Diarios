"""
Hay n equipos numerados de 0 a n - 1 en un torneo; cada equipo es también un nodo en un DAG.

Se te da el entero n y a 0-indexado Arreglo entero 2D edges de longitud m representando el DAG, donde indica que hay una ventaja dirigida por el equipo al equipo en el gráfico.edges[i] = [ui, vi]uivi

Un borde dirigido desde a a b en el gráfico significa ese equipo a es más fuerte que equipo b y equipo b es más débil que equipo a.

Equipo a será el campeón del torneo si no hay equipo b eso es más fuerte que equipo a.

Devolución el equipo que será el campeón del torneo si hay un único campeón, de lo contrario, regresa -1.

Notas

A ciclo es una serie de nodos tal que el nodo es el mismo nodo que el nodo , los nodos son distintos, y hay un borde dirigido desde el nodo al nodo para cada en el rango .a1, a2, ..., an, an+1a1an+1a1, a2, ..., anaiai+1i[1, n]
A DAG es un gráfico dirigido que no tiene ninguno ciclo.

Ejemplo 1:
Entrada: n = 3, edges = [[0,1],[1,2]]
Salida: 0
Explicación: El equipo 1 es más débil que el equipo 0. El equipo 2 es más débil que el equipo 1. Entonces el campeón es el equipo 0.

Ejemplo 2:
Entrada: n = 4, edges = [[0,2],[1,3],[1,2]]
Salida: -1
Explicación: El equipo 2 es más débil que el equipo 0 y el equipo 1. El equipo 3 es más débil que el equipo 1. Pero el equipo 1 y el equipo 0 no son más débiles que cualquier otro equipo. Entonces la respuesta es -1.
"""

class Solution:
    def findChampion(self, n: int, edges: list[list[int]]) -> int:
        # contamos cuantos equipos son mas fuertes que cada equipo 
        stronger_counts = [0] * n

        # marcamos los equipos a los que se les ha ganado
        for u, v in edges:
            stronger_counts[v] += 1 

        # encontramos los equipos que no han sido vencidos
        champions = [i for i in range(n) if stronger_counts[i] == 0]

        return champions[0] if len(champions) == 1 else -1

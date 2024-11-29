/*
 Te dan un m x n matriz grid consistiendo en no negativo enteros donde grid[row][col] representa el mínimo tiempo necesario para poder visitar la celda (row, col), lo que significa que puedes visitar la celda (row, col) sólo cuando el tiempo que visita es mayor o igual a grid[row][col].

Estás parado en el superior izquierda celda de la matriz en el segundo, y debes mudarte a cualquiera celda adyacente en las cuatro direcciones: arriba, abajo, izquierda y derecha. Cada movimiento que haces toma 1 segundo.0th

Devolución el mínimo tiempo requerido en el que puede visitar la celda inferior derecha de la matriz. Si no puede visitar la celda inferior derecha, regrese -1.

Ejemplo 1:
Entrada: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Salida: 7
Explicación: Uno de los caminos que podemos tomar es el siguiente:
- en t = 0, estamos en la celda (0,0).
- en t = 1, nos movemos a la celda (0,1). Es posible porque grid[0][1] <= 1.
- en t = 2, nos movemos a la celda (1,1). Es posible porque grid[1][1] <= 2.
- en t = 3, nos movemos a la celda (1,2). Es posible porque grid[1][2] <= 3.
- en t = 4, nos movemos a la celda (1,1). Es posible porque grid[1][1] <= 4.
- en t = 5, nos movemos a la celda (1,2). Es posible porque grid[1][2] <= 5.
- en t = 6, nos movemos a la celda (1,3). Es posible porque grid[1][3] <= 6.
- en t = 7, nos movemos a la celda (2,3). Es posible porque grid[2][3] <= 7.
La última vez es 7. Se puede demostrar que es el tiempo mínimo posible.
 
Ejemplo 2:
Entrada: grid = [[0,2,4],[3,2,1],[1,0,4]]
Salida: -1
Explicación: No hay camino desde la parte superior izquierda a la celda inferior derecha.
 */

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Verificación inicial de movimiento imposible
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        // Caso especial para matriz 1x1
        if (m == 1 && n == 1) {
            return 0;
        }

        // Estructuras para BFS
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // Direcciones de movimiento
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        // Comenzamos desde (0,0)
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [tiempo, pos] = pq.top();
            pq.pop();

            int row = pos.first, col = pos.second;

            // Ya encontramos un camino más corto
            if (tiempo > dist[row][col]) continue;

            // Llegamos al destino
            if (row == m-1 && col == n-1) {
                return tiempo;
            }

            for (auto [dr, dc] : dirs) {
                int nr = row + dr, nc = col + dc;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Tiempo mínimo para moverse
                    int next_time = max(tiempo + 1, grid[nr][nc]);

                    // Ajuste de paridad
                    if ((next_time - grid[nr][nc]) % 2 == 0) {
                        next_time++;
                    }

                    if (next_time < dist[nr][nc]) {
                        dist[nr][nc] = next_time;
                        pq.push({next_time, {nr, nc}});
                    }
                }
            }
        }

        return -1; // No se encontró camino
    }
};

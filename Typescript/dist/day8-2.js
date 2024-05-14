/**
 En una mina de oro grid de tamaño m x n, cada célula de esta mina tiene un número entero que representa la cantidad de oro en esa célula, 0 si está vacío.

Devuelva la cantidad máxima de oro que puede recolectar en las condiciones:

Cada vez que se encuentre en una celda, recogerá todo el oro en esa celda.
Desde su posición, puede caminar un paso hacia la izquierda, derecha, arriba o abajo.
No puedes visitar la misma celda más de una vez.
Nunca visite una celda con 0 oro.
Puedes empezar y dejar de recoger oro de cualquiera posición en la cuadrícula que tiene algo de oro.
 
Ejemplo 1:

Entrada: grid = [[0,6,0],[5,8,7],[0,9,0]]
Salida: 24
Explicación:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Camino para obtener el máximo de oro, 9 -> 8 -> 7.
Ejemplo 2:

Entrada: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Salida: 28
Explicación:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Camino para obtener el máximo de oro, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 
 */
function getMaximumGold(grid) {
    let maxGold = 0; //Inicializamos la cantidad máxima de oro recolectado
    // Función de búsqueda en profundidad (DFS) para explorar todas las posibles rutas
    function dfs(row, col, currentGold) {
        // Verificamos si estamos dentro de los límites de la cuadrícula y si la celda actual tiene oro
        if (row < 0 || row >= grid.length || col < 0 || col >= grid[0].length || grid[row][col] === 0) {
            return;
        }
        // Recolectamos el oro de la celda actual
        currentGold += grid[row][col];
        console.log("current gold " + currentGold);
        //Guardamos el máximo oro recolectado hasta el momento
        maxGold = Math.max(maxGold, currentGold);
        console.log("oro máximo ", maxGold);
        // Marcamos la celda actual como visitada para evitar visitarla nuevamente
        const temp = grid[row][col];
        grid[row][col] = 0;
        // Exploramos las cuatro direcciones posibles: arriba, abajo, izquierda, derecha
        dfs(row + 1, col, currentGold);
        dfs(row - 1, col, currentGold);
        dfs(row, col + 1, currentGold);
        dfs(row, col - 1, currentGold);
        // Restauramos el valor de la celda actual después de la exploración
        grid[row][col] = temp;
    }
    // Recorremos toda la cuadrícula y llamamos a la función dfs desde cada celda que tiene oro
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (grid[i][j] !== 0) {
                dfs(i, j, 0);
            }
        }
    }
    return maxGold;
}
;
const grid = [[0, 6, 0], [5, 8, 7], [0, 9, 0]];
for (let i = 0; i < grid.length; i++) {
    console.log(grid[i]);
}
console.log(getMaximumGold(grid));
export {};
//# sourceMappingURL=day8-2.js.map
//2812. Find the Safest Path in a Grid
function maximumSafenessFactor(grid: number[][]): number {
    const n = grid.length // Tamaño de la cuadrícula (n x n)

    const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]; // Direcciones para moverse: derecha, abajo, izquierda, arriba

    // Inicializamos la matriz de distancias con Infinito
    const distance = Array.from({ length: n }, () => Array(n).fill(Infinity)); 

    // BFS para calcular la distancia mínima a cualquier ladrón
    const queue: [number, number][] = []; // Cola para BFS

    //Recorremos toda la cuadrícula para encontrar las posiciones de los ladrones
    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (grid[r][c] === 1) { // Si encontramos un ladrón
                queue.push([r, c]); // Añadimos su posición a la cola
                distance[r][c] = 0; // La distancia desde el ladrón a sí mismo es 0
            }
        }
    }


};
/**
 * Dado un array entero nums de único elementos, retorno todo posible 
subconjuntos: A subconjunto de una matriz es una selección de elementos (posiblemente ninguno) de la matriz.(el conjunto de potencia).

El conjunto de soluciones no debe contiene subconjuntos duplicados. Devuelva la solución cualquier orden.

Ejemplo 1:

Entrada: nums = [1,2,3]
Salida: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Ejemplo 2:

Entrada: nums = [0]
Salida: [[],[0]]
 * @param nums 

#los subconjuntos son: [], [a], [b], [a, b].
#para nums[] = [1, 3], los subconjuntos son:
 */

function subsets(nums: number[]): number[][] {
    //Inicializamos result para almacenar todos los subconjuntos.
    const result: number[][] = []

    // Función recursiva para generar subconjuntos
    //index es el índice actual en nums
    //currentSubset es el subconjunto actual que estamos construyendo.
    const findSubset = (index: number, currentSubset: number[]) => {
        // Añadimos una copia del subconjunto actual al resultado
        result.push([...currentSubset])

        // Iteramos sobre los elementos a partir del índice actual
        for (let i = index; i < nums.length; i++) {
            // Incluimos el elemento nums[i] en el subconjunto actual
            currentSubset.push(nums[i])
            // Continuamos recursivamente para los siguientes elementos
            findSubset(i + 1, currentSubset)
            // Excluimos el último elemento (backtracking)
            currentSubset.pop()
        }
    }
    //Iniciamos la recursión con el índice 0 y un subconjunto vacío
    findSubset(0, [])

    return result
}; 

console.log(subsets([1, 2, 3])); // Salida: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
console.log(subsets([0]));       // Salida: [[],[0]]

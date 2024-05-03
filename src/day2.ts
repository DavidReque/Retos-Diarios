/*Dada una matriz de enteros nums y un número entero target, regreso índices de los dos números de tal manera que se suman target.

Puede suponer que cada entrada tendría exactamente una solución, y no puede usar el igual elemento dos veces.

Puede devolver la respuesta en cualquier orden.

Ejemplo 1:

Entrada: nums = [2,7,11,15], target = 9
Salida: [0,1]
Explicación: Porque nums[0] + nums[1] == 9, volvemos [0, 1].
Ejemplo 2:

Entrada: nums = [3,2,4], target = 6
Salida: [1,2]
Ejemplo 3:

Entrada: nums = [3,3], target = 6
Salida: [0,1]
*/

export function twoSum(nums: number[], target: number): number[] {
    // tabla de hash
    // la clave es el número en la matriz y el valor es el índice de ese número en la matriz
    // [2, 7, 11, 15] = { 2: 0, 7: 1, 11: 2, 15: 3 }
    const numIndexMap: { [key: number]: number } = {};

    for(let i = 0; i < nums.length; i++) {
        const num = nums[i]
        
        //calcular la diferencia entre target y el numero actual en la matriz 
        //ejemplo: si target es 9  y num es 7, entonces la diferencia sería 9 - 7 = 2. Estamos buscando un número en la matriz que sea igual a esta diferencia
        const diff = target - num

        // si existe la clave diff en la tabla hash, significa que encontramos los numeros que sumen el objetivo
        if (numIndexMap[diff] !== undefined) {
            return [numIndexMap[diff], i]
        }

        numIndexMap[num] = i
    }

    throw new Error('No se encontraron dos numeros que sumen el objetivo')
};
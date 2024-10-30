/*Puede recordar que una matriz arr es a montaña si y solo si:

arr.length >= 3
Existe algún índice i (0-indexado) con 0 < i < arr.length - 1 tal que:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Dado un array entero nums, regreso el mínimo número de elementos a eliminar para hacer a montaña.nums​​​

Ejemplo 1:
Entrada: nums = [1,3,1]
Salida: 0
Explicación: La matriz en sí es una matriz de montaña, por lo que no necesitamos eliminar ningún elemento.

Ejemplo 2:
Entrada: nums = [2,1,1,5,6,2,3,1]
Salida: 3
Explicación: Una solución es eliminar los elementos en los índices 0, 1 y 5, haciendo que la matriz nums = [1,5,6,3,1].
 */

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1); // vector de subsecuencia crecienre que termina en i
        vector<int> right(n, 1); // empieza en i
        
        // construir la subsecuencia creciente desde la izquierda
        for(int i = 1; i < n; ++i) {
          for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
              left[i] = max(left[i], left[j] + 1);
            }
          }
        }

        // construir la subsecuencia desde la derecha
        for (int i = n - 2; i >= 0; --i) {
          for (int j = n - 1; j > i; --j) {
            if (nums[i] > nums[j]) {
                right[i] = max(right[i], right[j] + 1);
            }
          }
        }

        // Encontrar la longitud máxima de la subsecuencia de montaña 
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; ++i) {
          if (left[i] > 1 && right[i] > 1) {
            maxMountainLength = max(maxMountainLength, left[i] + right[i] - 1);
          }
        }

        return n - maxMountainLength;
    }
}

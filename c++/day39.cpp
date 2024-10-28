/**Se le da una matriz entera nums. Una subsecuencia de nums se llama a raya cuadrada si:

La longitud de la subsecuencia es al menos 2, y
después ordenando la subsecuencia, cada elemento (excepto el primer elemento) es el cuadrado del número anterior.
Devolución la longitud de la raya cuadrada más larga en nums, o volver -1 si no hay raya cuadrada.

A subsecuencia es una matriz que se puede derivar de otra matriz eliminando algunos o ningún elemento sin cambiar 
el orden de los elementos restantes.

Ejemplo 1:

Entrada: nums = [4,3,6,16,8,2]
Salida: 3
Explicación: Elija la subsecuencia [4,16,2]. Después de clasificarlo, se convierte en [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Por lo tanto, [4,16,2] es una raya cuadrada.
Se puede demostrar que cada subsecuencia de longitud 4 no es una raya cuadrada.
Ejemplo 2:

Entrada: nums = [2,3,5,6,7]
Salida: -1
Explicación: No hay una racha cuadrada en números, así que regrese - 1.
**//

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // ordenar el arreglo
        sort(nums.begin(), nums.end());
        
        // crear un mapa para almacenar la subsecuencia mas larga
        unordered_map<int, int> dp;
        int maxStreak = -1; // variable para almacenar la longuitud maxima
        
        for (int num: nums) {
          // encontramos la raiz cuadrada entera del numero actual
            int root = sqrt(num);

          // Verificamos si el cuadrado de la raíz es igual al número (para evitar valores no enteros)
          if (root * root == num && dp.find(root) != dp.end()) {
            // Si el número es un cuadrado perfecto y su raíz está en dp, extendemos la subsecuencia
            dp[num] = dp[root] + 1;
          } else {
            // si no empezamos una subsecuencia con 1
            dp[num] = 1;
          }

          // actualizamos la longuitud maxima
          maxStreak = max(maxStreak, dp[num]);
        }

    return (maxStreak >= 2) ? maxStreak : -1;
    }
}

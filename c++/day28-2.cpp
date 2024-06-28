/*Dado un número de matriz entera, devuelva todos los trillizos [nums[i], nums[j], nums[k]] tal que i != j, i != k, y j != k, y nums[i] + nums[j] + nums[k] == 0.

Observe que el conjunto de soluciones no debe contener trillizos duplicados.

Ejemplo 1:
Entrada: números = [-1,0,1,2,-1,-4]
Salida: [[-1,-1,2],[-1,0,1]]
Explicación: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
Los trillizos distintos son [-1,0,1] y [-1,-1,2].
Observe que el orden de la salida y el orden de los trillizos no importa.

Ejemplo 2:
Entrada: nums = [0,1,1]
Salida: []
Explicación: El único triplete posible no suma hasta 0.

Ejemplo 3:
Entrada: nums = [0,0,0]
Salida: [[0,0,0]]
Explicación: El único triplete posible suma hasta 0.

Dado un array de enteros, encontrar todos los tripletes únicos que suman cero.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        // Ordenar el array
        sort(nums.begin(), nums.end());

        // Iterar a través del array para el primer número
        for (int i = 0; i < n - 2; i++) {
            // Optimización: si el primer número es positivo, no puede haber suma cero
            if (nums[i] > 0) break;

            // Evitar duplicados para el primer número
            // Si el número actual es igual al anterior, lo saltamos.
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // Usar dos punteros para los otros dos números
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    // encontramos triplete
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Evitar duplicados para el segundo y tercer numero
                    // Para left avanzamos mientras el siguiente número sea igual al actual
                    while (left < right && nums[left] == nums[left+1]) left++;
                    // Para left avanzamos mientras el siguiente número sea igual al actual
                    while (left < right && nums[right] == nums[right-1]) right--;

                    left++;
                    right--;
                } else if (sum < 0)
                {
                    // La suma es muy pequena
                    left++;
                }
                else {
                    // La suma es muy grande
                    right--;
                }
            }
        }

        return result;
    }
};

/*
1. Ordenamos el array para facilitar la búsqueda y el manejo de duplicados.
2. Iteramos a través del array para el primer número del triplete.
3. Usamos dos punteros (left y right) para encontrar los otros dos números.
4. Para cada combinación, calculamos la suma y la comparamos con cero.
5. Si encontramos una suma cero, añadimos el triplete al resultado y movemos los punteros para evitar duplicados.
6. Si la suma es menor que cero, incrementamos left para aumentar la suma.
7. Si la suma es mayor que cero, decrementamos right para disminuir la suma.
8. Utilizamos comprobaciones de duplicados para asegurar tripletes únicos.*/
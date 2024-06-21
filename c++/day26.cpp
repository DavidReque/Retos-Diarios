/*Dado un array entero nums de longitud n y un número entero target, encuentra tres enteros en nums de tal manera que la suma esté más cerca de target.

Devolución la suma de los tres enteros.

Puede suponer que cada entrada tendría exactamente una solución.

Ejemplo 1:

Entrada: nums = [-1,2,1,-4], target = 1
Salida: 2
Explicación: La suma más cercana al objetivo es 2. (-1 + 2 + 1 = 2).
Ejemplo 2:

Entrada: nums = [0,0,0], target = 1
Salida: 0
Explicación: La suma más cercana al objetivo es 0. (0 + 0 + 0 = 0).*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Ordenar el array
        sort(nums.begin(), nums.end());
        // Inicializar closest_sum con un valor arbitrario grande
        int closest_sum = nums[0] + nums[1] + nums[2];

        // iterar sobre cada elemento excepto sobre los dos ultimos
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;

            // Usar dos punteros para encontrar la suma más cercana al target
            while (left < right)
            {
                int current_sum = nums[i] + nums[left] + nums[right];

                cout << "Probando combinación: " << nums[i] << ", " << nums[left] << ", " << nums[right] 
                     << " con suma = " << current_sum << endl;

                // Actualizar closest_sum si current_sum está más cerca del target
                //Durante la iteración, actualizamos closest_sum si encontramos una 
                //suma que esté más cerca del target que la anterior.
                if (abs(current_sum - target) < abs(closest_sum - target))
                {
                    closest_sum = current_sum;
                }

                // Mover los punteros dependiendo de la comparación con el target
                //Dependiendo de si la suma actual es mayor o menor que el target, 
                //movemos los punteros para intentar acercarnos más al target.
                if (current_sum < target)
                {
                    ++left;
                } else
                {
                    --right;
                }
            }
        }

        return closest_sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Resultado: " << solution.threeSumClosest(nums1, target1) << endl;
    
    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Resultado: " << solution.threeSumClosest(nums2, target2) << endl;
    
    return 0;
}

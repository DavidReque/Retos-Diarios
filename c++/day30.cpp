/*Dado un array nums de n enteros, devuelve *un array de todos los cuadrupletes únicos [nums[a], nums[b], nums[c], nums[d]] tales que:

0 <= a, b, c, d < n
a, b, c, y d son distintos.
nums[a] + nums[b] + nums[c] + nums[d] == objetivo
Puedes devolver la respuesta en cualquier orden.

Ejemplo 1
Entrada: nums = [1,0,-1,0,-2,2], objetivo = 0
Salida: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Ejemplo 2
Entrada: nums = [2,2,2,2,2], objetivo = 8
Salida: [[2,2,2,2]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        if (n < 4) return result; // No hay suficientes elementos

        for (int a = 0; a < n; a++) {
            // Evitamos duplicados del primer numero
            // Si el número actual es igual al anterior, lo saltamos.
            if (a > 0 && nums[a] == nums[a - 1]) continue;

            for (int b = a + 1; b < n - 2; b++) {

                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                
                int c = b + 1;
                int d = n - 1;

                while (c < d) {
                    // Usamos Long long para evitar desbordamiento
                    long long sum = (long long)nums[a] + nums[b] + nums[c] + nums[d];

                    if (sum == target) {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        
                        // Evitar duplicados para el segundo y tercer numero
                        // Para c avanzamos mientras el siguiente número sea igual al actual
                        while (c < d && nums[c] == nums[c + 1]) c++;
                        
                        // Para c avanzamos mientras el anterior número sea igual al actual
                        while (c < d && nums[d] == nums[d - 1]) d--;

                        c++;
                        d--;
                    } else if (sum < target)
                    {
                        c++;
                    } else {
                        d--;
                    }
                }
            }
        }
        return result;
    }
};
/*
 Dado un array entero nums y un número entero val, eliminar todas las ocurrencias de val en nums en el lugar. El orden de los elementos puede ser cambiado. Entonces regresa el número de elementos en nums que no son iguales a val.

Considere el número de elementos en nums que no son iguales a val ser k, para ser aceptado, debe hacer las siguientes cosas:

Cambiar la matriz nums tal que el primero k elementos de nums contiene los elementos que no son iguales a val. Los elementos restantes de nums no son importantes, así como el tamaño de nums.
Devolución k.
Juez Personalizado:

El juez probará su solución con el siguiente código:

int[] nums = [...]; // Arreglo de entrada
int val = ...; // Valor a eliminar
int[] watedNums = [...]; // La respuesta esperada con la longitud correcta.
                            // Se ordena sin valores iguales a val.

int k = removeElement(nums, val); //Llame a tu implementación

assert k == watedNums.length;
sort(nums, 0, k); // Ordenar los primeros k elementos de números
para (int i = 0; i < realLength; i++) {
    asertar números[i] == watedNums[i];
}
Si todas las afirmaciones pasan, entonces su solución será aceptado.

Ejemplo 1:
Entrada: nums = [3,2,2,3], val = 3
Salida: 2, números = [2,2,_,_]
Explicación: Su función debe devolver k = 2, con los dos primeros elementos de números siendo 2.
No importa lo que deje más allá de la k devuelta (de ahí que sean guiones bajos).

Ejemplo 2:
Entrada: nums = [0,1,2,2,3,0,4,2], val = 2
Salida: 5, números = [0,1,4,0,3,_,_,_]
Explicación: Su función debe devolver k = 5, con los primeros cinco elementos de números que contienen 0, 0, 1, 3 y 4.
Tenga en cuenta que los cinco elementos se pueden devolver en cualquier orden.
No importa lo que deje más allá de la k devuelta (de ahí que sean guiones bajos).
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

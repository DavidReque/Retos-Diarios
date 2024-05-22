/*
Dado un array entero nums ordenado en orden no decreciente, eliminar los duplicados en el lugar de tal manera que cada elemento único aparece solo una vez. El orden relativo de los elementos se debe mantener el igual. Entonces regresa el número de elementos únicos en nums.

Considere el número de elementos únicos de nums ser k, para ser aceptado, debe hacer las siguientes cosas:

Cambiar la matriz nums tal que el primero k elementos de nums contiene los elementos únicos en el orden en que estuvieron presentes nums inicialmente. Los elementos restantes de nums no son importantes, así como el tamaño de nums.
Devolución k.
Juez Personalizado:

El juez probará su solución con el siguiente código:

int[] nums = [...]; // Arreglo de entrada
int[] watedNums = [...]; // La respuesta esperada con la longitud correcta

int k = removeDuplicates(nums); //Llame a tu implementación

assert k == watedNums.length;
para (int i = 0; i < k; i++) {
    asertar números[i] == watedNums[i];
}
Si todas las afirmaciones pasan, entonces su solución será aceptado. 

Ejemplo 1:

Entrada: nums = [1,1,2]
Salida: 2, números = [1,2,_]
Explicación: Su función debe devolver k = 2, con los dos primeros elementos de números siendo 1 y 2 respectivamente.
No importa lo que deje más allá de la k devuelta (de ahí que sean guiones bajos).
Ejemplo 2:

Entrada: nums = [0,0,1,1,1,2,2,3,3,4]
Salida: 5, números = [0,1,2,3,4,_,_,_,_,_,_]
Explicación: Su función debe devolver k = 5, con los primeros cinco elementos de números siendo 0, 1, 2, 3 y 4 respectivamente.
No importa lo que deje más allá de la k devuelta (de ahí que sean guiones bajos).
*/

// Función para eliminar duplicados en el lugar y devolver el número de elementos únicos
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    // Si el tamaño del arreglo es 0, no hay elementos únicos
    if (numsSize == 0) return 0;

    // k es el índice para colocar el próximo elemento único encontrado
    int k = 1;

    // iteramos sobre el arreglo empezando desde el segundo elemento
    for (int i = 1; i < numsSize; i++)
    {
        // Si el elemento actual es diferente al elemento anterior, es único
        if (nums[i] != nums[i - 1])
        {
            //colocamos el elemento unico de la posicion k y aumentamos k
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main () {
    int nums1[] = {1, 1, 2};
    int nums2[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k1 = removeDuplicates(nums1, 3);
    int k2 = removeDuplicates(nums2, 10);

    printf("Array 1: [");
    for (int i = 0; i < k1; i++) {
        printf("%d", nums1[i]);
        if (i < k1 - 1) printf(", ");
    }
    printf("]\n");

    printf("Array 2: [");
    for (int i = 0; i < k2; i++) {
        printf("%d", nums2[i]);
        if (i < k2 - 1) printf(", ");
    }
    printf("]\n");

    return 0
}
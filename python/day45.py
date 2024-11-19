"""
Se le da una matriz entera nums y un número entero k. Encuentre la suma máxima de subarreglos de todos los subarrays de nums que cumplan las siguientes condiciones:

La longitud del subarreglo es k, y
Todos los elementos del subarray son distinto.
Devolución la suma máxima de submatrices de todas las submatrices que cumplen las condiciones. Si ningún subarreglo cumple con las condiciones, regrese 0.

A subarreglo es una secuencia contigua no vacía de elementos dentro de una matriz.

Ejemplo 1:
Entrada: nums = [1,5,4,2,9,9,9], k = 3
Salida: 15
Explicación: Los subarrays de nums con longitud 3 son:
- [1,5,4] que cumple con los requisitos y tiene una suma de 10.
- [5,4,2] que cumple con los requisitos y tiene una suma de 11.
- [4,2,9] que cumple con los requisitos y tiene una suma de 15.
- [2,9,9] que no cumple los requisitos porque se repite el elemento 9.
- [9,9,9] que no cumple los requisitos porque se repite el elemento 9.
Devolvemos 15 porque es la suma máxima de subarrays de todos los subarrays que cumplen las condiciones

Ejemplo 2:
Entrada: nums = [4,4,4], k = 3
Salida: 0
Explicación: Los subarrays de nums con longitud 3 son:
- [4,4,4] que no cumple los requisitos porque se repite el elemento 4.
Devolvemos 0 porque ninguna submatriz cumple las condiciones.
"""

class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)

        # si el array es mas pequeno que k retornamos 0
        if n < k:
            return 0

        current_sum = 0
        max_sum = 0
        count = {}

        # primera ventana de tamano k
        for i in range(k):
            # sumamos cada numero
            current_sum += nums[i]
            # incrementamos el contador en el diccionario
            count[nums[i]] = count.get(nums[i], 0) + 1

        # si todos los elementos son diferentes en la primera ventana
        if len(count) == k:
            max_sum = current_sum

        for i in range(k, n):
            # Removemos el número que sale (el primero de la ventana anterior)
            current_sum -= nums[i - k]
            # Decrementamos su contador en el diccionario
            count[nums[i - k]] -= 1
            # si el contador llega a 0, eliminamos la Entrada
            if count[nums[i - k]] == 0:
                del count[nums[i - k]]

            # agregamos el nuevo numero que entro en la ventana
            current_sum += nums[i]
            count[nums[i]] = count.get(nums[i], 0) + 1

            # si todos los elementos son diferentes actualizamos max_sum
            if len(count) == k:
                max_sum = max(max_sum, current_sum)
        
    return max_sum

"""
ventana deslizante
[1,5,4],2,9,9,9  → current_sum = 10, max_sum = 10
1,[5,4,2],9,9,9  → current_sum = 11, max_sum = 11
1,5,[4,2,9],9,9  → current_sum = 15, max_sum = 15
1,5,4,[2,9,9],9  → no válido (9 repetido)
1,5,4,2,[9,9,9]  → no válido (9 repetido)
"""

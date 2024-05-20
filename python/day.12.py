#El XOR total de una matriz se define como el bit a bit XOR de todos sus elementos, o 0 si la matriz es vacío.

#Por ejemplo, el XOR total de la matriz [2,5,6] es 2 XOR 5 XOR 6 = 1.
#Dada una matriz nums, regreso el suma de todos Total XOR para cada subconjunto de nums. 

#Nota: Subconjuntos con el igual los elementos deben ser contados múltiple tiempos.

#Una matriz a es a subconjunto de una matriz b si a se puede obtener de b eliminando algunos elementos (posiblemente cero) de b.

#Ejemplo 1:

#Entrada: nums = [1,3]
#Salida: 6
#Explicación: Los 4 subconjuntos de [1,3] son:
#- El subconjunto vacío tiene un total de XOR de 0.
#- [1] tiene un total de XOR de 1.
#- [3] tiene un total de XOR de 3.
#- [1,3] tiene un total de XOR de 1 XOR 3 = 2.
#0 + 1 + 3 + 2 = 6
#Ejemplo 2:

#Entrada: nums = [5,1,6]
#Salida: 28
#Explicación: Los 8 subconjuntos de [5,1,6] son:
#- El subconjunto vacío tiene un total de XOR de 0.
#- [5] tiene un total de XOR de 5.
#- [1] tiene un total de XOR de 1.
#- [6] tiene un total de XOR de 6.
#- [5,1] tiene un total de XOR de 5 XOR 1 = 4.
#- [5,6] tiene un total de XOR de 5 XOR 6 = 3.
#- [1,6] tiene un total de XOR de 1 XOR 6 = 7.
#- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
#0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
#Example 3:

#Input: nums = [3,4,5,6,7,8]
#Output: 480
#Explanation: The sum of all XOR totals for every subset is 480.

class Solution:
    def subsetXORSum(self, nums: list[int]) -> int:
        # Función recursiva para calcular el total de XOR
        def dfs(index: int, current_xor: int) -> int:
        #index es el índice actual en nums
        #current_xor es el valor XOR actual acumulado.
        # Si hemos procesado todos los elementos (index es igual a la longitud de nums) devolver el XOR actual
            if index == len(nums):
                return current_xor
            
            #no incluir el número actual en el XOR
            without_current = dfs(index + 1, current_xor)

            #incluir el número actual en el XOR
            with_current = dfs(index + 1, current_xor ^ nums[index])

            #devolver la suma de las dos opciones
            return without_current + with_current
        
        #Comenzamos la recursión con el índice 0 y el XOR inicial 0.
        return dfs(0, 0)
    
print(Solution().subsetXORSum([1, 3]))  # Salida: 6
print(Solution().subsetXORSum([5, 1, 6]))  # Salida: 28
print(Solution().subsetXORSum([3, 4, 5, 6, 7, 8]))  # Salida: 480

#los subconjuntos son: [], [a], [b], [a, b].
#para nums[] = [1, 3], los subconjuntos son:

#[] → XOR total: 0
#[1] → XOR total: 1
#[3] → XOR total: 3
#[1, 3] → XOR total: 1 XOR 3 = 2
# 0 + 1 + 3 + 2 = 6.
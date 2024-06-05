"""
Dadas dos matrices ordenadas nums1 y nums2 de tamaño m y n respectivamente, retorno la mediana de las dos matrices clasificadas.

La complejidad general del tiempo de ejecución debe ser O(log (m+n)).

Ejemplo 1:

Entrada: nums1 = [1,3], nums2 = [2]
Salida: 2.00000
Explicación: matriz fusionada = [1,2,3] y la mediana es 2.
Ejemplo 2:

Entrada: nums1 = [1,2], nums2 = [3,4]
Salida: 2.50000
Explicación: matriz fusionada = [1,2,3,4] y la mediana es (2 + 3) /2 = 2.5.

La mediana es el elemento medio de una lista ordenada. Si el tamaño total es impar, la mediana es el elemento en la posición del medio. Si es par, la mediana es el promedio de los dos elementos en el medio.
"""

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Aseguramos que nums1 es la matriz más pequeña
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        
        #son las longitudes de nums1 y nums2.
        m, n = len(nums1), len(nums2)
        #imin y imax definen el rango de búsqueda en nums1.
        #half_len es la mitad del total de elementos más uno, utilizado para determinar las particiones.
        imin, imax, half_len = 0, m, (m + n + 1) // 2
        
        while imin <= imax:
            # Calculamos i y j
            i = (imin + imax) // 2
            j = half_len - i
            
            # Ajustamos el rango de búsqueda
            # hasta que encontramos las particiones correctas donde los elementos de 
            #la izquierda de ambas particiones son menores o iguales a los elementos de la derecha
            if i < m and nums1[i] < nums2[j-1]:
                # i es pequeño, incrementamos imin
                imin = i + 1
            elif i > 0 and nums1[i-1] > nums2[j]:
                # i es grande, decrementamos imax
                imax = i - 1
            else:
                # i es perfecto
                # Encontramos el max_of_left
                if i == 0:
                    max_of_left = nums2[j-1]
                elif j == 0:
                    max_of_left = nums1[i-1]
                else:
                    max_of_left = max(nums1[i-1], nums2[j-1])
                
                # Si el total de elementos es impar
                if (m + n) % 2 == 1:
                    return max_of_left
                
                # Encontramos el min_of_right
                if i == m:
                    min_of_right = nums2[j]
                elif j == n:
                    min_of_right = nums1[i]
                else:
                    min_of_right = min(nums1[i], nums2[j])
                
                # Si el total de elementos es par
                return (max_of_left + min_of_right) / 2.0
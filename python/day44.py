"""
El bitwise Y de una matriz nums es el AND bit a bit de todos los enteros en nums.

Por ejemplo, para nums = [1, 5, 3], el bitwise AND es igual a 1 & 5 & 3 = 1.
Además, para nums = [7], el bitwise AND es 7.
Se le da una serie de enteros positivos candidates. Evaluar el bitwise Y de cada combinación de números de candidates. Cada número en candidates solo se puede usar una vez en cada combinación.

Devolución el tamaño de la más grande combinación de candidates con un poco de AND mayor que 0.

Ejemplo 1:
Entrada: candidatos = [16,17,71,62,12,24,14]
Salida: 4
Explicación: La combinación [16,17,62,24] tiene un BITwise AND de 16 y 17 y 62 y 24 = 16 > 0.
El tamaño de la combinación es 4.
Se puede demostrar que ninguna combinación con un tamaño mayor que 4 tiene un bitwise AND mayor que 0.
Tenga en cuenta que más de una combinación puede tener el tamaño más grande.
Por ejemplo, la combinación [62,12,24,14] tiene un BITwise AND de 62 y 12 y 24 y 14 = 8 > 0.

Ejemplo 2:
Entrada: candidatos = [8,8]
Salida: 2
Explicación: La combinación más grande [8,8] tiene un bitwise AND de 8 y 8 = 8 > 0.
El tamaño de la combinación es 2, por lo que devolvemos 2.
"""

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        max_size = 0

        for bit in range(24):
            count = 0
            for num in candidates:
                #verifica si el bit esta encendido en num
                if num & (1 << bit):
                    count += 1
            #actualizamos el tamano a=maximo si el bit tiene 1 mas en comun
            max_size = max(max_size, count)

        return max_size

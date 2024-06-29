"""
Dada una cadena que contiene dígitos de 2-9 inclusive, devuelva todas las combinaciones de letras posibles que el número podría representar. Devuelve la respuesta en cualquier orden.

A continuación se proporciona un mapeo de dígitos a letras (al igual que en los botones telefónicos). Tenga en cuenta que 1 no se asigna a ninguna letra.

Ejemplo 1:
Entrada: dígitos = "23"
Salida: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Ejemplo 2:
Entrada: dígitos = ""
Salida: []

Ejemplo 3:
Entrada: dígitos = "2"
Salida: ["a","b","c"]

Restricciones:
0 <= digits.length <= 4
digits[i] es un dígito en el rango ['2', '9'].
"""

"""
1. Crear un mapeo de dígitos a letras.
2. Usar recursión o iteración para generar todas las combinaciones posibles.
3.Para cada dígito, considerar todas sus letras correspondientes y combinarlas con las combinaciones de los dígitos restantes.
"""  

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # mapeo de dígitos a letras.
        digit_map = {
            '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
            '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
        }

        # Si no hay digitos retornar lista vacia
        if not digits:
            return []
        
        # Funcion recursiva
        def backtrack(index, path):
            # Si el camino actual tiene la misma longitud que los dígitos, lo añadimos al resultado
            if len(path) == len(digits):
                result.append(''.join(path))
                return
            
            #Obtenemos las letras correspondientes al digito actual
            current_letters = digit_map[digits[index]]

            # Recursión para cada letra
            for letter in current_letters:
                path.append(letter)
                backtrack(index + 1, path)
                # removemos y probamos con otra letra
                path.pop() # Backtracking
            
        result = []
        backtrack(0, [])
        return result
"""
A cuerda elegante es una cuerda donde no tres consecutivo los caracteres son iguales.

Dada una cuerda s, eliminar el mínimo posible número de caracteres de s para hacerlo elegante.

Devolución la cadena final después de la eliminación. Se puede demostrar que la respuesta siempre será único.

Ejemplo 1:
Entrada: s = "leeetcétera"
Salida: "leetcode"
Explicación:
Eliminar una 'e' del primer grupo de 'e's para crear "leetcode".
No hay tres caracteres consecutivos iguales, así que devuelve "leetcode".

Ejemplo 2:
Entrada: s = "aaabaaaa"
Salida: "aabaa"
Explicación:
Elimina una 'a' del primer grupo de 'a's para crear "aabaaaa".
Elimina dos 'a's del segundo grupo de 'a's para crear "aabaa".
No hay tres caracteres consecutivos iguales, así que regresa "aabaa".

""""

class Solution:
    def makeFancyString(self, s: str) -> str:
        result = [] #lista para construir la cadena final
        
        for char in s:
            #verificamos si agregar el caracter 
            if len(result) >= 2 and result[-1] == result[-2] == char:
                # salta al siguiente ciclo evitando agregar a result
                continue
            result.append(char) #de lo contrario agregamos a result

        return ''.join(result) #convertimos a cadena


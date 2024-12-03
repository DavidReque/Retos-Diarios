"""
Te dan un 0-indexado cuerda s y a 0-indexado matriz entera spaces eso describe los índices en la cadena original donde se agregarán espacios. Cada espacio debe ser insertado antes el carácter en el índice dado.

Por ejemplo, dado s = "EnjoyYourCoffee" y spaces = [5, 9], colocamos espacios antes 'Y' y 'C', que están en los índices 5 y 9 respectivamente. Así, obtenemos ."Enjoy Your Coffee"
Devoluciónla cadena modificada después los espacios se han añadido.

Ejemplo 1:
Entrada: s = "LeetcodeHelpsMeLearn", espacios = [8,13,15]
Salida: "Leetcode Me Ayuda a Aprender"
Explicación: 
Los índices 8, 13 y 15 corresponden a los caracteres subrayados en "LeetcodeHelfosMeLganar".
Luego colocamos espacios antes que esos personajes.

Ejemplo 2:
Entrada: s = "icodeinpython", espacios = [1,5,7,9]
Salida: "codigo en py thon"
Explicación:
Los índices 1, 5, 7 y 9 corresponden a los caracteres subrayados en "icodayonpython".
Luego colocamos espacios antes que esos personajes.

Ejemplo 3:
Entrada: s = "espaciado", espacios = [0,1,2,3,4,5,6]
Salida: "s p a c i n g"
Explicación:
También podemos colocar espacios antes del primer carácter de la cuerda.
"""

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        #lista para construir la nueva cadena
        result = []
        spaces_index = 0 #indice que recorre la lista 'spaces'

        #recorrer cada caracter de la cadena 's'
        for i, char in enumerate(s):
            # si el indice actual esta en la lista
            if spaces_index < len(spaces) and i == spaces[spaces_index]:
                #agregamos el espacio y avanzamos al siguiente indice
                result.append(" ")
                spaces_index += 1

            result.append(char) # agregamos el caracter actual

        return "".join(result)

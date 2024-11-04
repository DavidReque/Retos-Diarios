"""
Dada una cuerda word, comprimirlo usando el siguiente algoritmo:

Comience con una cadena vacía comp. Mientras word es no vacío, utilice la siguiente operación:
Eliminar un prefijo de longitud máxima de word hecho de un carácter único c repitiendo como máximo 9 Veces.
Añadir la longitud del prefijo seguido de c a comp.
Devuelve la cadena comp.

Ejemplo 1:
Entrada: palabra = "abcde"
Salida: "1a1b1c1d1e"
Explicación:
Inicialmente, comp = "". Aplique la operación 5 veces, eligiendo "a", "b", "c", "d", y "e" como prefijo en cada operación.
Para cada prefijo, apéndice "1" seguido por el personaje a comp.

Ejemplo 2:
Entrada: palabra = "aaaaaaaaaaaaaaabb"
Salida: "9a5a2b"
Explicación:
Inicialmente, comp = "". Aplique la operación 3 veces, eligiendo "aaaaaaaaa", "aaaaa", y "bb" como prefijo en cada operación.

Para prefijo "aaaaaaaaa", apéndice "9" seguido de "a" a comp.
Para prefijo "aaaaa", apéndice "5" seguido de "a" a comp.
Para prefijo "bb", apéndice "2" seguido de "b" a comp.
"""

class Solution:
    def compressedString(self, word: str) -> str:
        comp = "" # cadena comprimida

        while word:
            #tomar el primer carácter como prefijo
            char = word[0]

            #contar cuantos caracteres son iguales a 9
            prefix_length = 0
            for i in range(min(len(word), 9)):
                if word[i] == char:
                    prefix_length += 1 
                else:
                    break

            #agregar el prefijo comprimido a la cadena comp
            comp += str(prefix_length) + char

            #eliminar el prefijo de la cadena word
            word = word[prefix_length:]

        return comp

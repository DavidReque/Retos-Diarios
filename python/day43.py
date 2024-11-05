"""
Te dan un 0-indexado cadena binaria s tener una longitud uniforme.

Una cuerda es hermoso si es posible dividirlo en una o más subcadenas de tal manera que:

Cada subcadena tiene un incluso longitud.
Cada subcadena contiene solo 1es o solo 0es.
Puedes cambiar cualquier personaje en s a 0 o 1.

Devolución el mínimo número de cambios necesarios para realizar la cadena s hermoso.

Ejemplo 1:
Entrada: s = "1001"
Salida: 2
Explicación: Cambiamos s[1] a 1 y s[3] a 0 para obtener la cadena "1100".
Se puede ver que la cadena "1100" es hermosa porque podemos dividirla en "11|00".
Se puede demostrar que 2 es el número mínimo de cambios necesarios para que la cadena sea hermosa.

Ejemplo 2:
Entrada: s = "10"
Salida: 1
Explicación: Cambiamos s[1] a 1 para obtener la cadena "11".
Se puede ver que la cadena "11" es hermosa porque podemos dividirla en "11".
Se puede demostrar que 1 es el número mínimo de cambios necesarios para que la cadena sea hermosa. 
"""

class Solution:
    def minChanges(self, s: str) -> int:
        # Verificamos cada subcadena de longitud 2
        n = len(s)
        changes = 0
        
        # Iteramos la cadena de 2 en 2 caracteres
        for i in range(0, n, 2):
            # Tomamos los dos caracteres actuales
            pair = s[i:i+2]
            
            # Contamos cuántos 1s y 0s hay en el par
            ones = pair.count('1')
            zeros = pair.count('0')
            
            # Necesitamos el mínimo número de cambios para hacer
            # que ambos caracteres sean iguales
            changes += min(ones, zeros)
            
        return changes

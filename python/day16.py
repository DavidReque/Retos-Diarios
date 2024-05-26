#Se te dan tres cuerdas: s1, s2, y s3. En una operación puede elegir una de estas cadenas y eliminar su derecho carácter. Tenga en cuenta que usted no vacía completamente una cuerda.

#Devuelve el número mínimo de operaciones requerido para hacer las cuerdas iguales. Si es imposible hacerlos iguales, regrese -1.

#Ejemplo 1:
#Entrada: s1 = "abc", s2 = "abb", s3 = "ab"
#Salida: 2
#Explicación: Eliminar el carácter más a la derecha de ambos s1 y s2 dará como resultado tres cadenas iguales.

#Ejemplo 2:
#Entrada: s1 = "dac", s2 = "bac", s3 = "cac"
#Salida: -1
#Explicación: Desde las primeras letras de s1 y s2 difieren, no se pueden hacer iguales.

class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        # Obtenemos las longitudes de las cadenas
        len1, len2, len3 = len(s1), len(s2), len(s3)

        # Inicializamos los índices para recorrer las cadenas desde el final
        i, j, k = len1 - 1, len2 - 1, len3 - 1

        # Contador para las operaciones necesarias
        operations = 0

        # Continuamos mientras los índices estén dentro de los límites
        while i >= 0 and j >= 0 and k >= 0:
         # Si los caracteres en la posición actual de las tres cadenas son iguales
            if s1[i] == s2[j] == s3[k]:
                #movemos los tres indices a la izquierda
                i -= 1
                j -= 1
                k -= 1
            else:
                # Si los caracteres no son iguales, eliminamos el carácter de una de las cadenas
                #elegimos la cadena cuyos caracteres no coinciden
                if s1[i] != s2[j]:
                    if s1[i] != s3[k]:
                        i -= 1 #eliminamos de s1
                    else:
                        j -= 1 #eliminamos de s2
                else:
                    k -= 1 #eliminamos de s3
                #incrementamos las operaciones
                operations += 1
        
        # Si alguno de los índices es negativo, verificamos si es posible igualarlas
        if i < 0 or j < 0 or k < 0:
            # Si uno de los índices es negativo pero los otros no, no es posible igualarlas
            if i >= 0 or j >= 0 or k >= 0:
                return -1
            
        #devolvemos el numero de operaciones realizadas
        return operations

print(Solution.findMinimumOperations("abc", "abb", "ab"))  # Salida: 2
print(Solution.findMinimumOperations("dac", "bac", "cac")) # # Salida: -1

#Ejemplo 1:

#Entrada: s1 = "abc", s2 = "abb", s3 = "ab"
#Salida: 2
#Explicación:
#Eliminar el carácter más a la derecha de s1 ("abc" -> "ab").
#Eliminar el carácter más a la derecha de s2 ("abb" -> "ab").
#Las tres cadenas resultantes son iguales ("ab")
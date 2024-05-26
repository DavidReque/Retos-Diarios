/*
Se te dan tres cuerdas: s1, s2, y s3. En una operación puede elegir una de estas cadenas y eliminar su derecho carácter. Tenga en cuenta que usted no vacía completamente una cuerda.

Devuelve el número mínimo de operaciones requerido para hacer las cuerdas iguales. Si es imposible hacerlos iguales, regrese -1. 

Ejemplo 1:
Entrada: s1 = "abc", s2 = "abb", s3 = "ab"
Salida: 2
Explicación: Eliminar el carácter más a la derecha de ambos s1 y s2 dará como resultado tres cadenas iguales.

Ejemplo 2:
Entrada: s1 = "dac", s2 = "bac", s3 = "cac"
Salida: -1

Explicación: Desde las primeras letras de s1 y s2 difieren, no se pueden hacer iguales.
*/

#include <iostream>
#include <string>
#include <algorithm>

int min_operations_to_make_equal(std::string s1, std::string s2, std::string s3) {
    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
    int i = len1 - 1, j = len2 - 1, k = len3 - 1;
    int operations = 0;

    while (i >= 0 && j >= 0 && k >= 0) {
        if (s1[i] == s2[j] && s1[i] == s3[k]) {
            i--;
            j--;
            k--;
        } else {
            if (s1[i] != s2[j]) {
                if (s1[i] != s3[k]) {
                    i--;
                } else {
                    j--;
                }
            } else {
                k--;
            }
            operations++;
        }
    }

    if (i < 0 || j < 0 || k < 0) {
        return -1;
    }

    return operation;
}
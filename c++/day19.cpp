/*
Dada una cuerda s, encuentra la longitud de la más largo 
subcadena
sin repetir caracteres.

Ejemplo 1:

Entrada: s = "abcabcbb"
Salida: 3
Explicación: La respuesta es "abc", con la longitud de 3.
Ejemplo 2:

Entrada: s = "bbbbb"
Salida: 1
Explicación: La respuesta es "b", con la longitud de 1.
Ejemplo 3:

Entrada: s = "pwwkew"
Salida: 3
Explicación: La respuesta es "wke", con la longitud de 3.
Observe que la respuesta debe ser una subcadena, "pwke" es una subsecuencia y no una subcadena.

Intuición
La intuición detrás de las 3 soluciones es encontrar iterativamente la subcadena más larga sin repetir caracteres manteniendo un enfoque de ventana deslizante
*/

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // realiza un seguimiento de la longitud de la subcadena más larga encontrada hasta ahora.
        int maxLenght = 0;
        // charSet para realizar un seguimiento de los caracteres únicos en la subcadena actual.
        unordered_set<char> charSet;
        //left y right para mantener los limites de la subcadena
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            // Si el carácter actual no está  en el conjunto (charSet), significa que tenemos un nuevo carácter único.
            if (charSet.count(s[right]) == 0)
            {
                // Insertamos el carácter en el conjunto y actualizamos el maxLength si es necesario.
                charSet.insert(s[right]);
                maxLenght = max(maxLenght, right - left)
            // Si el carácter ya está presente en el conjunto, indica un carácter repetitivo dentro de la subcadena actual.
            } else {
                while (charSet.count(s[right]))
                {
                    // movemos left, puntero hacia delante
                    //eliminando caracteres del conjunto hasta que el carácter repetitivo ya no esté presente.
                    charSet.erase(s[left]);
                    left++
                }
                charSet.insert(s[right]);
            }
        }
        return maxLenght;
    }
};
/*
Dada una cuerda s, regreso el más largo 
palindrómico(Una cuerda es palindrómico si lee lo mismo hacia adelante y hacia atrás.)
 
Palíndromo: Una cadena es palindrómica si se lee igual hacia adelante y hacia atrás. 
Por ejemplo, "abba" y "racecar" son palíndromos

subcadena
 en s.

Ejemplo 1:

Entrada: s = "babad"
Salida: "bab"
Explicación: "aba" es también una respuesta válida.

Ejemplo 2:
Entrada: s = "cbbd"
Salida: "bb"
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        // si la cadena tiene un solo carácter, devolvemos la cadena misma
        if (s.size() == 1) return s;

        // Inicializamos las variables para guardar el inicio del palíndromo más largo y su longitud
        int start = 0, maxLength = 1;

        // Función lambda para expandir desde el centro
        auto expandAroundCenter = [&](int left, int right) {
            // Expandimos hacia afuera mientras los caracteres sean iguales
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--; // Movemos el puntero izquierdo a la izquierda
                right++; // Movemos el puntero derecho a la derecha
            }
            // Calculamos la longitud del palíndromo encontrado
            int length = right - left - 1;

            // Si la longitud encontrada es mayor que la longitud máxima conocida, actualizamos start y maxLength
            if (length > maxLength) {
                start = left + 1; // Ajustamos el inicio al primer carácter del palíndromo encontrado
                maxLength = length;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            // Expansión para los palíndromos con centro único (ej. "aba")
            expandAroundCenter(i, i);
            // Expansión para los palíndromos con centro doble (ej. "abba")
            expandAroundCenter(i, i + 1);
        }

        // Devolvemos la subcadena palindrómica más larga encontrada
        return s.substr(start, maxLength);
    }
};

/*
La idea es que cada carácter (y cada par de caracteres) en la cadena puede ser el centro de un palíndromo. Desde cada centro, expandimos hacia afuera mientras los caracteres a la izquierda y derecha sean iguales. Este enfoque considera tanto palíndromos de longitud impar (ej. "aba") como de longitud par (ej. "abba").
*/
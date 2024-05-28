/*
Te dan dos cuerdas s y t de la misma longitud y un número entero maxCost.

Quieres cambiar s a t. Cambiando el carácter de a carácter de costos (es decir, la diferencia absoluta entre los valores ASCII de los caracteres).ithsitht|s[i] - t[i]|

Devolución la longitud máxima de una subcadena de s que se puede cambiar para que sea la misma que la subcadena correspondiente de t con un costo menor o igual a maxCost. Si no hay subcadena de s que se puede cambiar a su subcadena correspondiente desde t, regreso 0.

Ejemplo 1:

Entrada: s = "abcd", t = "bcdf", maxCost = 3
Salida: 3
Explicación: "abc" de s puede cambiar a "bcd".
Eso cuesta 3, por lo que la longitud máxima es 3.
Ejemplo 2:

Entrada: s = "abcd", t = "cdef", maxCost = 3
Salida: 1
Explicación: Cada carácter en s cuesta 2 cambiar a carácter en t, por lo que la longitud máxima es 1.
Ejemplo 3:

Entrada: s = "abcd", t = "acde", maxCost = 0
Salida: 1
Explicación: No puede hacer ningún cambio, por lo que la longitud máxima es 1.

Entrada: s = "abcd", t = "bcdf", maxCost = 3

Costo de cambiar:
'a' a 'b' = |97 - 98| = 1
'b' a 'c' = |98 - 99| = 1
'c' a 'd' = |99 - 100| = 1
'd' a 'f' = |100 - 102| = 2
La subcadena "abc" de s se puede cambiar a "bcd" de t con un costo total de 3.
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //longitud de las cadenas s y t
        int n = s.size();
        //longitud máxima de la subcadena encontrada.
        int maxLength = 0;
        //costo actual de cambiar la subcadena 
        int currentCost = 0;
        //índice de la izquierda de la ventana.
        int left = 0;

        for (int right = 0; right < n; right++)
        {   
            // Agregar el costo de cambiar s[right] a t[right]
            currentCost += abs(s[right] - t[right]);

            //Si currentCost excede maxCost, ajustamos la ventana moviendo 
            //left hacia la derecha hasta que currentCost sea menor o igual a maxCost.
            while (currentCost > maxCost)
            {
                // Reducir el costo quitando el carácter s[left]
                currentCost -= abs(s[left] - t[left]);
                left++; // Mover la izquierda de la ventana
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    cout << sol.equalSubstring("abcd", "bcdf", 3) << endl;  // Salida: 3
    cout << sol.equalSubstring("abcd", "cdef", 3) << endl;  // Salida: 1
    cout << sol.equalSubstring("abcd", "acde", 0) << endl;  // Salida: 1
    return 0;
}
/*La cuerda "PAYPALISHIRING" está escrito en un patrón en zigzag en un número determinado de filas como esta: (es posible que desee mostrar este patrón en una fuente fija para una mejor legibilidad)

P A H N
A P L S I I G
Y I R
Y luego leer línea por línea: "PAHNAPLSIIGYIR"

Escriba el código que tomará una cadena y realice esta conversión dado un número de filas:

cadena convert(cadena s, int numRows);
 

Ejemplo 1:

Entrada: s = "PAYPALISHIRING", numRows = 3
Salida: "PAHNAPLSIIGYIR"
Ejemplo 2:

Entrada: s = "PAYPALISHIRING", numRows = 4
Salida: "PINALSIGYAHRPI"
Explicación:
P I N
A L S I G
Y A H R
P I
Ejemplo 3:

Entrada: s = "A", numRows = 1
Salida: "A"
En este problema, reorganizamos una cadena en un patrón en zigzag según el número de filas especificado. Un patrón en zigzag significa que escribimos los caracteres de la cadena en filas de arriba a abajo, y cuando alcanzamos la última fila, cambiamos la dirección para ir de abajo hacia arriba, y así sucesivamente.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // si solo hay una fila o la longitud de la cadena es menor 
        //que el número de filas
        if (numRows == 1 || numRows >= s.length()) return s;
        
        // Vector de cadenas para almacenar cada fila
        vector<string> rows(min(numRows, int(s.size())));

        // Variables para seguir la fila actual
        int currRow = 0;

        //Para saber si nos estamos moviendo hacia abajo o hacia arriba.
        bool goingDown = false;

        // Iterar sobre cada carácter en la cadena
        for (char c : s) {
            cout << "Adding character " << c << " to row " << currRow << endl;
            rows[currRow] += c; //anadir el caracter a la fila actual

            // Cambiar de dirección si estamos en la primera o última fila
            if (currRow == 0 || currRow == numRows - 1) {
                goingDown = !goingDown;
                cout << "Changing direction: " << (goingDown ? "down" : "up") << endl;
            }
            //mover a la siguiente fila
            currRow += goingDown ? 1 : -1;
            cout << currRow << endl;
        }

        // Concatenar todas las filas para obtener la cadena resultante
        string result;
        for (int i = 0; i < rows.size(); ++i) {
            cout << "Row " << i << ": " << rows[i] << endl;
            result += rows[i];
        }

        return result;
    }
};

int main()
{
    Solution solution;
    
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Entrada: s = \"" << s1 << "\", numRows = " << numRows1 << endl;
    cout << "Salida: \"" << solution.convert(s1, numRows1) << "\"" << endl;

    return 0;
}

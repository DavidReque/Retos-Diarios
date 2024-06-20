/*Dada una cadena de entrada s y un patrón p, implementar la coincidencia de expresión regular con soporte para '.' y '*' dónde:

'.'Coincide con cualquier personaje.
'*'Coincide con cero o más del elemento anterior.
El emparejamiento debe cubrir el entero cadena de entrada (no parcial).

Ejemplo 1:

Entrada: s = "aa", p = "a"
Salida: falso
Explicación: "a" no coincide con toda la cadena "aa".
Ejemplo 2:

Entrada: s = "aa", p = "a*"
Salida: cierto
Explicación: '*' significa cero o más del elemento precedente, 'a'. Por lo tanto, repitiendo 'a' una vez, se convierte en "aa".
Ejemplo 3:

Entrada: s = "ab", p = ".*"
Salida: cierto
Explicación: ".*" significa "cero o más (*) de cualquier carácter (.)".*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // Creamos una tabla de dimensiones (m+1) x (n+1)
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // Una cadena vacía coincide con un patrón vacío
        dp[0][0] = true;

        // Inicializamos la tabla para patrones que tienen '*' y pueden coincidir con una cadena vacía
        for (int j = 1; j <= n; j++)
        {
            // Si encontramos un * en el patrón p, puede representar cero ocurrencias del carácter anterior
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Rellenando la tabla dp
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};
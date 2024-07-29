/*
 Dadas dos cuerdas needle y haystack, devuelve el índice de la primera ocurrencia de needle en haystack, o -1 si needle no es parte de haystack.

Ejemplo 1:
Entrada: haystack = "sadbutsad", aguja = "triste"
Salida: 0
Explicación: "triste" ocurre en los índices 0 y 6.
La primera ocurrencia es en el índice 0, por lo que devolvemos 0.

Ejemplo 2:
Entrada: haystack = "leetcode", aguja = "leeto"
Salida: -1
Explicación: "leeto" no ocurrió en "leetcode", así que volvemos -1.
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
          int j;

          for (j = 0; j < m; j++) {
            if (haystack[i + j] != needle[j]) {
              break;
            }
          }
          if (j == m) {
            return i;
          }
        }

        return -1;
    }
};

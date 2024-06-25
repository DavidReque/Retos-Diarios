/*Se le da una matriz entera height de longitud n. Hay n líneas verticales dibujadas de tal manera que los dos puntos finales de la la línea es y .ith(i, 0)(i, height[i])

Encuentre dos líneas que, junto con el eje x, formen un recipiente, de modo que el recipiente contenga la mayor cantidad de agua.

Devolución la cantidad máxima de agua que un recipiente puede almacenar.

Aviso para que no incline el contenedor.

Entrada: altura = [1,8,6,2,5,4,8,3,7]
Salida: 49
Explicación: Las líneas verticales anteriores están representadas por la matriz [1,8,6,2,5,4,8,3,7]. En este caso, el área máxima de agua (sección azul) que puede contener el recipiente es 49.
Ejemplo 2:

Entrada: altura = [1,1]
Salida: 1*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() -1;
        int maxArea = 0;

        while (left < right)
        {
            // Calcular el área actual
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth;
            maxArea = max(maxArea, currentArea);

             // Mover el puntero que apunta a la línea más corta
             // Actualizar maxArea si el área actual es mayor
             if (height[left] < height[right])
             {
                ++left;
             } else
             {
                --right;
             }
        }

        return maxArea;
    }
};
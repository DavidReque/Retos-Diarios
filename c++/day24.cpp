/*Dado un entero firmado de 32 bits x, regreso x con sus dígitos invertidos. Si se invierte x hace que el valor salga del rango entero firmado de 32 bits , luego regresa .[-231, 231 - 1]0

Suponga que el entorno no le permite almacenar enteros de 64 bits (firmados o sin firmar).

 

Ejemplo 1:

Entrada: x = 123
Salida: 321
Ejemplo 2:

Entrada: x = -123
Salida: -321
Ejemplo 3:

Entrada: x = 120
Salida: 21*/

#include <iostream>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0)
        {
            // Extraemos el último dígito (pop) usando el operador %.
            int pop = x % 10;
            // Eliminamos el último dígito de x dividiéndolo por 10.
            x /= 10;

            // Verificar desbordamiento antes de agregar el dígito
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
            {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
            {
                return 0;
            }

            // Actualizamos el número invertido
            rev = rev * 10 + pop;

            // Debug output para ver el proceso paso a paso
            std::cout << "Pop: " << pop << ", Rev: " << rev << ", x: " << x << std::endl;
        }
        return rev;
    }
};

int main(int argc, const char** argv) {
    Solution solution;

    int test2 = 123;
        std::cout << "Entrada: " << test1 << ", Salida: " << solution.reverse(test1) << std::endl;
    return 0;
}
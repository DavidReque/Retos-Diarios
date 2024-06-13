/*Implementar el myAtoi(string s) función, que convierte una cadena en un entero firmado de 32 bits.

El algoritmo para myAtoi(string s) es el siguiente:

Espacio blanco: Ignora cualquier espacio en blanco líder (" ").

Firmación: Determine el signo comprobando si el siguiente carácter es '-' o '+', suponiendo que la positividad no está presente.

Conversión: Lea el número entero omitiendo ceros principales hasta que se encuentre un carácter no dígito o se alcance el final de la cadena. Si no se leyeron dígitos, entonces el resultado es 0.

Redondeo: Si el número entero está fuera del rango entero firmado de 32 bits , luego redondear el número entero para permanecer en el rango. Específicamente, enteros menores que debe redondearse a , y enteros mayores que debe redondearse a .[-231, 231 - 1]-231-231231 - 1231 - 1
Devuelve el número entero como resultado final. 

Ejemplo 1:
Entrada: s = "42"
Salida: 42
Explicación:

Los caracteres subrayados son lo que se lee y el cuidado es la posición actual del lector.
Paso 1: "42" (no se leen caracteres porque no hay espacios en blanco principales)^
Paso 2: "42" (no se leen caracteres porque no hay ni un '-' ni '+')^
Paso 3: "42" ("42" se lee en)^

Ejemplo 2:
Entrada: s = " -042"
Salida: -42
Explicación:

Paso 1: "   -042" (el espacio en blanco líder se lee e ignora)^
Paso 2: "   -042" ('-' se lee, por lo que el resultado debe ser negativo)^
Paso 3: " -042" ("042" se lee, llevando ceros ignorados en el resultado)^

Ejemplo 3:
Entrada: s = "1337c0d3"
Salida: 1337
Explicación:
Paso 1: "1337c0d3" (no se leen caracteres porque no hay espacios en blanco principales)^
Paso 2: "1337c0d3" (no se leen caracteres porque no hay ni un '-' ni '+')^
Paso 3: "1337c0d3" ("1337" se lee en; la lectura se detiene porque el siguiente carácter no es un dígito)^

Ejemplo 4:
Entrada: s = "0-1"
Salida: 0
Explicación:
Paso 1: "0-1" (no se leen caracteres porque no hay espacios en blanco principales)^
Paso 2: "0-1" (no se leen caracteres porque no hay un '-' ni '+')^
Paso 3: "0-1" ("0" se lee en; la lectura se detiene porque el siguiente carácter no es un dígito)^
Ejemplo 5:

Entrada: s = "palabras y 987"

Salida: 0

Explicación:

La lectura se detiene en el primer personaje no dígito 'w'.*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    int myAtoi(string s) {
        int index = 0, n = s.length();

        // Ignorar espacios en blanco iniciales
        while (index < n && s[index] == ' ')
        {
            index++;
        }

        // Verificar si la cadena está vacía después de eliminar los espacios en blanco
        if (index == n) return 0;

        // Determinar el signo
        int sign = 1;
        if (s[index] == '-')
        {
            sign = -1;
            index++;
        } else if (s[index] == '+')
        {
            index++;
        }

        // Leer dígitos y formar el número
        long result = 0;
        while (index < n && isdigit(s[index]))
        {
            // Convierte el carácter en su valor numérico. Por ejemplo, si s[index] es '5', entonces '5' - '0' es 5.
            int digit = s[index] - '0';
            result = result * 10 + digit;
            cout << "Digit: " << digit << ", Result: " << result << endl;
            // Verificar desbordamiento y subdesbordamiento
            if (sign * result > INT_MAX) return INT_MAX;
            if (sign * result < INT_MIN) return INT_MIN;
            index++;
        }

        // Devolver el resultado con el signo
        return sign * result; 

    }
};

int main(int argc, const char** argv) {
    Solution solution;
    string entrada = "45";

        cout << "Entrada: \"" << entrada << "\", Salida: " << solution.myAtoi(entrada) << endl;

    return 0;
}

/*
*result = result * 10 + digit;
*/
/*Supongamos que s es "123":
result inicialmente es 0.
Lees 1, result = 0 * 10 + 1 = 1.
Lees 2, result = 1 * 10 + 2 = 12.
Lees 3, result = 12 * 10 + 3 = 123.*/
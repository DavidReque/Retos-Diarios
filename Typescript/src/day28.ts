/*Siete símbolos diferentes representan los números romanos con los siguientes valores:
Símbolo Valor
I 1
V 5
X 10
L 50
C 100
D 500
M 1000
Los números romanos se forman añadiendo las conversiones de los valores decimales de 
mayor a menor. La conversión de un valor decimal a un número romano tiene las 
siguientes reglas:

Si el valor no comienza con 4 o 9, selecciona el símbolo del valor máximo que se puede restar de la entrada, añade ese símbolo al resultado, resta su valor, y convierte el resto a número romano.
Si el valor comienza con 4 o 9, usa la forma sustractiva representando un símbolo 
restado del siguiente símbolo, por ejemplo, 4 es 1 (I) menos que 5 (V): IV y 9 es 1 
(I) menos que 10 (X): IX. Solo se utilizan las siguientes formas sustractivas: 4 
(IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) y 900 (CM).
Solo las potencias de 10 (I, X, C, M) se pueden añadir consecutivamente como máximo 3 veces para representar múltiplos de 10. No se puede añadir 5 (V), 50 (L), o 500 (D) varias veces. Si necesitas añadir un símbolo 4 veces, usa la forma sustractiva.

Dado un número entero, conviértelo en un número romano.*/

function intToRoman(num: number): string {
    // Contiene los valores decimales en orden descendente, incluyendo los valores para las formas sustractivas.
    const values: number[] = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    // Simbolos romanos
    const symbols: string[] = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"];
    let result: string = "";

    // Continúa mientras haya elementos en el array y num sea mayor que 0
    for (let i = 0; i < values.length && num > 0; i++) {
        // num mayor o igual al array de values
        while (num >= values[i]) {
            // restamos el valor de la entrada (num) con values[i]
            num -= values[i];
            result += symbols[i];
        }
    }

    return result

};
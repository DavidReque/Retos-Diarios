/**
 Dado un número entero x, regreso true si x es a 
palíndromo
, y false de otra manera.

Ejemplo 1:

Entrada: x = 121
Salida: cierto
Explicación: 121 se lee como 121 de izquierda a derecha y de derecha a izquierda.
Ejemplo 2:

Entrada: x = -121
Salida: falso
Explicación: De izquierda a derecha, se lee - 121. De derecha a izquierda, se convierte en 121-. Por lo tanto, no es un palíndromo.
Ejemplo 3:

Entrada: x = 10
Salida: falso
Explicación: Lee 01 de derecha a izquierda. Por lo tanto, no es un palíndromo.
 */

function isPalindrome(x: number): boolean {
    const str = x.toString() //convertir el numero a cadena
    const reverseStr = str.split('').reverse().join('') //revertir la cadena
    // Comparar la cadena original con su reverso
    return str === reverseStr
};

console.log(isPalindrome(121));
console.log(isPalindrome(-121));


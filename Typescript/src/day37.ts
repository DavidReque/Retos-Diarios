/*
Dados dos enteros dividend y divisor, divide dos enteros sin uso de multiplicación, división y operador de mod.

La división entera debe truncar hacia cero, lo que significa perder su parte fraccional. Por ejemplo, 8.345 sería truncado a 8, y -2.7335 sería truncado a -2.

Devolución el cociente después de dividir dividend por divisor.

Nota: Supongamos que estamos tratando con un entorno que solo podría almacenar enteros dentro del 32 Bits rango entero firmado: . Para este problema, si el cociente es estrictamente mayor que, luego regresa , y si el cociente es estrictamente menos que, luego regresa .[−231, 231 − 1] 231 - 1231 - 1 -231-231

Ejemplo 1:
Entrada: dividendo = 10, divisor = 3
Salida: 3
Explicación: 10/3 = 3.33333.. que se trunca a 3.

Ejemplo 2:
Entrada: dividendo = 7, divisor = -3
Salida: -2
Explicación: 7/-3 = -2.33333.. que se trunca a -2.
*/

function divide(dividend: number, divisor: number): number {
  // constantes para los limites de rango de 32 Bits
  const INT_MAX: number = 2147483647; // 2^31 - 1
  const INT_MIN: number = -2147483648;

  if (dividend === INT_MIN && divisor === -1) {
    return INT_MAX;
  }

  // Determinar el signo del resultado
  const sign: number = (dividend < 0) !== (divisor < 0) ? -1 : 1;

  // Convertir a valores absolutos
  let absDividend: number = Math.abs(dividend);
  let absDivisor: number = Math.abs(divisor);

  let quotient: number = 0;

  // Realizar la división utilizando restas y desplazamientos
  while (absDividend >= absDivisor) {
    let temp: number = absDivisor;
    let multiple: number = 1;
    while (absDividend >= (temp << 1) && (temp << 1) > 0) {
      temp <<= 1;
      multiple <<= 1;
    }
    absDividend -= temp;
    quotient += multiple;
  }

  return sign * quotient;
};

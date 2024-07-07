/*Dado n pares de paréntesis, escriba una función para genere todas las combinaciones de paréntesis bien formados.

Ejemplo 1:
Entrada: n = 3
Salida: ["((()))","(()())","(())()","()(())","()()()"]

Ejemplo 2:
Entrada: n = 1
Salida: ["()"]
 */

function generateParenthesis(n: number): string[] {
  const result: string[] = [];

  function backtrack(current: string, open: number, close: number) {
    // Caso base: si la longuitud la cadena actual es 2n, la agregamos al resultado
    if (current.length === 2 * n) {
      result.push(current);
      return;
    }

    // Añadimos un paréntesis de apertura si aun no hemos usado todos
    if (open < n) {
      backtrack(current + '(', open + 1, close);
    }

    // Añadimos un paréntesis de cierre si es valido (cierre < open)
    if (close < open) {
      backtrack(current + ')', open, close + 1);
    }
  }

  // Iniciamos el backtracking con una cadena vacia y sin paréntesis usados
  backtrack('', 0, 0);

  return result;
};

"""
Te dan una cuerda s compuesto por los personajes 'a', 'b', y 'c' y un número entero no negativo k. Cada minuto, puede tomar cualquiera de los dos izquierdo carácter de s, o el derecho carácter de s.

Devolución el mínimo número de minutos necesarios para que usted tome al menos k de cada personaje, o retorno -1 si no es posible tomar k de cada personaje.

Ejemplo 1:
Entrada: s = "aabaaaacaabc", k = 2
Salida: 8
Explicación: 
Toma tres personajes de la izquierda de s. Ahora tienes dos personajes 'a' y un personaje 'b'.
Toma cinco caracteres de la derecha de s. Ahora tienes cuatro personajes 'a', dos personajes 'b' y dos personajes 'c'.
Se necesita un total de 3 + 5 = 8 minutos.
Se puede demostrar que 8 es el número mínimo de minutos necesarios.

Ejemplo 2:
Entrada: s = "a", k = 1
Salida: -1
Explicación: No es posible tomar una 'b' o 'c' así que regrese - 1.
"""

class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        # contar los caracteres en 's'
        total_count = Counter(s) # cuenta los valores a, b, c, las veces que cada caracter aparece
 
        # verificar si es posible cumplir el requisito
        # si uno de los caracteres aparece menos de k retorna -1
        if total_count['a'] < k or total_count['b'] < k or total_count['c'] < k:
            return -1

        # ventana deslizante
        n = len(s)
        max_window_size = 0
        left = 0
        window_count = Counter()

        for right in range(n):
            window_count[s[right]] += 1

            # mantener valida la ventana 
            # representa cuantos caracteres hay fuera de la ventana
            while (total_count['a'] - window_count['a'] < k or
                   total_count['b'] - window_count['b'] < k or
                   total_count['c'] - window_count['c'] < k):
                window_count[s[left]] -= 1
                left += 1

            # actualizar el tamano maximo de la ventana
            max_window_size = max(max_window_size, right - left + 1)

        # calcular el resultado
        return n - max_window_size
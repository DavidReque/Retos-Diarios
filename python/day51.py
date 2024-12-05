"""
Te dan dos cuerdas start y target, ambos de longitud n. Cada cadena consiste solo de los personajes 'L', 'R', y '_' dónde:

Los personajes 'L' y 'R' representa piezas, donde una pieza 'L' puede moverse al izquierda solo si hay un en blanco espacio directamente a su izquierda, y una pieza 'R' puede moverse al correcto solo si hay un en blanco espacio directamente a su derecha.
El personaje '_' representa un espacio en blanco que puede ser ocupado por cualquiera de la 'L' o 'R' piezas.
Devolución true si es posible obtener la cadena target moviendo las piezas de la cuerda cualquiera número de veces. De lo contrario, regresa .start false

Ejemplo 1:
Entrada: iniciar = "_L__R__R_", target = "L______RR"
Salida: cierto
Explicación: Podemos obtener el objetivo de la cadena desde el principio haciendo los siguientes movimientos:
- Mueva la primera pieza un paso hacia la izquierda, el inicio se vuelve igual a "L___R__R_".
- Mueva la última pieza un paso a la derecha, el inicio se vuelve igual a "L___R___R".
- Mueva la segunda pieza tres pasos a la derecha, el inicio se vuelve igual a "L______RR".
Dado que es posible obtener el objetivo de cadena desde el principio, devolvemos verdadero.

Ejemplo 2:
Entrada: iniciar = "R_L_", target = "__LR"
Salida: falso
Explicación: La pieza 'R' en el inicio de la cadena puede moverse un paso hacia la derecha para obtener "_RL_".
Después de eso, ya no se pueden mover piezas, por lo que es imposible obtener el objetivo de la cadena desde el principio.

Ejemplo 3:
Input: start = "_R", target = "R_"
Output: false
Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
"""

class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Primero, verificamos que start y target tengan la misma longitud 
        # y el mismo número de 'L' y 'R'
        if len(start) != len(target):
            return False
    
        if start.replace('_', '') != target.replace('_', ''):
            return False

        # Verificamos las reglas de movimiento para 'L' y 'R 
        n = len(start)

        start_L = [i for i in range(n) if start[i] == 'L']
        target_L = [i for i in range(n) if target[i] == 'L']
    
        # Índices de 'R' en start y target
        start_R = [i for i in range(n) if start[i] == 'R']
        target_R = [i for i in range(n) if target[i] == 'R']

        # Verificamos que las 'L' solo se muevan a la izquierda
        for s, t in zip(start_L, target_L):
            if s < t:
                return False

        # Verificamos que las 'R' solo se muevan a la derecha
        for s, t in zip(start_R, target_R):
            if s > t:
                return False


        return True

/**
 Se le da una matriz people donde people[i] es el peso de la persona, y un número infinito de barcos donde cada barco puede llevar un peso máximo de . Cada barco transporta como máximo dos personas al mismo tiempo, siempre que la suma del peso de esas personas sea como máximo .ithlimitlimit

Devolución el número mínimo de barcos para transportar a cada persona.
Ejemplo 1:

Entrada: personas = [1,2], límite = 3
Salida: 1
Explicación: 1 barco (1, 2)
Ejemplo 2:

Entrada: personas = [3,2,2,1], límite = 3
Salida: 3
Explicación: 3 Barcos (1, 2), (2) y (3)
Ejemplo 3:

Entrada: personas = [3,5,3,4], límite = 5
Salida: 4
Explicación: 4 Barcos (3), (3), (4), (5)

el objetivo de este ejercicio es determinar el número mínimo de barcos necesarios para transportar a todas las personas dadas, donde cada barco puede llevar como máximo dos personas y el peso total de las personas en cada barco no puede exceder un límite dado.

Entrada:
personas = [1, 2]
límite = 3

Salida esperada:
1

Explicación:
En este caso, tenemos dos personas con pesos 1 y 2, respectivamente. El límite de peso por barco es 3.
Podemos transportar a ambas personas juntas en un solo barco, ya que su peso total es menor o igual al límite del barco.
Por lo tanto, necesitamos solo 1 barco para transportar a todas las personas.

 */
function numRescueBoats(people, limit) {
    //Ordenamiento del array de personas
    //ordenamos el array de personas en orden ascendente, podemos comenzar desde la persona mas liviana
    people.sort((a, b) => a - b);
    //inicializamos dos punteros, uno al principio (izquierda) y otro al final (derecha) del array ordenado
    //uno en el índice 0 y otro en el índice final.
    let left = 0;
    let right = people.length - 1;
    //Inicializamos una variable para contar el número mínimo de barcos necesarios. Comenzamos con cero.
    let boats = 0;
    /*bucle mientras los punteros no se crucen. Dentro de este bucle, comprobamos si la
    suma de los pesos de las personas señaladas por los punteros no excede el límite
    del barco. Si no excede el límite, podemos transportar a ambas personas en un
    barco, por lo que avanzamos ambos punteros hacia el centro.*/
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            left++;
            right--;
        }
        else {
            // Si no, solo podemos transportar a la persona más pesada, avanzamos el puntero de la derecha
            right--;
        }
        boats++;
    }
    return boats;
}
;
const personas = [3, 2, 2, 1];
const límite = 3;
console.log(numRescueBoats(personas, límite));
const personas2 = [1, 2];
const límite2 = 3;
console.log(numRescueBoats(personas2, límite2));
const personas3 = [3, 5, 3, 4];
const límite3 = 5;
console.log(numRescueBoats(personas3, límite3));
export {};
//# sourceMappingURL=day3.js.map
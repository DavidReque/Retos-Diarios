/*
Se le da una matriz entera ordenada arr conteniendo 1 y primo números, donde todos los enteros de arr son únicos. También se le da un número entero k.

Para cada i y j donde 0 <= i < j < arr.length, consideramos la fracción arr[i] / arr[j].

Devolución el fracción más pequeña considerada. Devuelva su respuesta como una matriz de enteros de tamaño , donde y .kth 2answer[0] == arr[i]answer[1] == arr[j]

Ejemplo 1:

Entrada: arr = [1,2,3,5], k = 3
Salida: [2,5]
Explicación: Las fracciones a considerar en orden ordenado son:
1/5, 1/3, 2/5, 1/2, 3/5 y 2/3.
La tercera fracción es 2/5.
Ejemplo 2:

Entrada: arr = [1,7], k = 1
Salida: [1,7]

Restricciones:

2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 104
arr[0] == 1
arr[i] es a primo número para i > 0.
Todos los números de arr son único y ordenado estrictamente aumentando orden.
1 <= k <= arr.length * (arr.length - 1) / 2

Seguimiento: Puede resolver el problema con mejor que complejidad?O(n2)
*/

function kthSmallestPrimeFraction(arr: number[], k: number): number[] {
    // matriz para almacenar las fracciones generadas
    const fractions: number[][] = []

    // generar fracciones
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length; j++) {
            // Generar la fracción arr[i] / arr[j] y almacenarla en la matriz de fracciones
            fractions.push([arr[i], arr[j]])
        }
    }

    //Ordenar fracciones en orden ascendente
    fractions.sort((a, b) => (a[0] / a[1] - b[0] / b[1]))

    return fractions[k - 1]
};

console.log(kthSmallestPrimeFraction([1,2,3,5], 3));
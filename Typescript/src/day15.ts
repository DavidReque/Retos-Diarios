/**
 Dada una lista de words, lista de single letters (podría repetirse) y score de cada personaje.

Devuelve la puntuación máxima de cualquiera conjunto válido de palabras formadas usando las letras dadas (words[i] no se puede usar dos o más veces).

No es necesario usar todos los caracteres en letters y cada letra solo se puede usar una vez. Puntuación de letras 'a', 'b', 'c', ... ,'z' está dado por score[0], score[1], ... , score[25] respectivamente.

Ejemplo 1:

Entrada: palabras = ["dog","cat","dad","good"], letras = ["a","a","c","d","d","g","o","o"], puntuación = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0
Salida: 23
Explicación:
Puntuación a=1, c=9, d=5, g=3, o=2
Dadas las letras, podemos formar las palabras "papá" (5+1+5) y "bueno" (3+2+2+5) con una puntuación de 23.
Las palabras "papá" y "perro" solo obtienen una puntuación de 21.
Ejemplo 2:

Entrada: palabras = ["xxxz","ax","bx","cx"], letras = ["z","a","b","c","x","x","x"]], puntuación = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
Salida: 27
Explicación:
Puntuación a=4, b=4, c=4, x=5, z=10
Dadas las letras, podemos formar las palabras "ax" (4+5), "bx" (4+5) y "cx" (4+5) con una puntuación de 27.
La palabra "xxxz" solo obtiene una puntuación de 25.
Ejemplo 3:

Entrada: palabras = ["leetcode"], letras = ["l","e","t","c","o","d"], puntuación = [0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0
Salida: 0
Explicación:
La letra "e" solo se puede usar una vez.

El objetivo es encontrar la puntuación máxima que se puede obtener formando conjuntos válidos de palabras. Cada palabra solo puede usarse una vez y cada letra en la lista de letras solo puede usarse una vez.

Contiene una lista de palabras que se pueden formar.
Ejemplo: ["dog", "cat", "dad", "good"].

Contiene las letras que se pueden usar para formar las palabras.
Ejemplo: ["a", "a", "c", "d", "d", "g", "o", "o"].

Contiene la puntuación de cada letra del alfabeto inglés.
Ejemplo: [1,0,9,5,0,0,3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0] significa que:
'a' tiene una puntuación de 1
'b' tiene una puntuación de 0
'c' tiene una puntuación de 9
'd' tiene una puntuación de 5
Y así sucesivamente.

Podemos formar las palabras "dad" y "good" que suman:
"dad" = 5 (d) + 1 (a) + 5 (d) = 11
"good" = 3 (g) + 2 (o) + 2 (o) + 5 (d) = 12
Total = 11 + 12 = 23
 */

function maxScoreWords(words: string[], letters: string[], score: number[]): number {
    //Creamos un objeto para contar cuántas veces aparece cada letra en la lista letters.
    const letterCount: {[key: string]: number} = {}

    for (const letter of letters) {
        if (!letterCount[letter]) {
            letterCount[letter] = 0
        }
        letterCount[letter]++
    }

    // función para calcular la puntuación total de una palabra basándonos en la lista score.
    // calcular la puntuación de una palabra
    const wordScore = (word: string): number => {
         let scoreSum = 0
         for (const char of word) {
            scoreSum += score[char.charCodeAt(0) - 'a'.charCodeAt(0)]
         }
         return scoreSum
    }

    // Función para verificar si una palabra se puede formar con las letras disponibles
    const canFormWord = (word: string, availableLetters: {[key: string]: number}): boolean => {
        const currentCount: {[key: string]: number} = {...availableLetters}
        for (const char of word) {
            if (!currentCount[char] || currentCount[char] === 0) {
                return false
            }
            currentCount[char]--
        }
        return true
    }

    // Función recursiva para generar todos los subconjuntos de palabras y calcular la puntuación máxima
    const findMaxScore = (index: number, availableLetters: { [key: string]: number }): number => {
        if (index === words.length) {
            return 0
        }

        // Opción 1: No incluir la palabra actual
        let maxScore = findMaxScore(index + 1, availableLetters)

        // Opción 2: Incluir la palabra actual (si es posible)
        if (canFormWord(words[index], availableLetters)) {
            const newAvailableLetters = {...availableLetters}
            for (const char of words[index]) {
                newAvailableLetters[char]--
            }
            maxScore = Math.max(maxScore, wordScore(words[index]) + findMaxScore(index + 1, newAvailableLetters))
        }
        return maxScore
    }

    return findMaxScore(0, letterCount)
};

console.log(maxScoreWords(["dog","cat","dad","good"], ["a","a","c","d","d","g","o","o"], [1,0,9,5,0,0,3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0])); // Salida: 23
console.log(maxScoreWords(["xxxz","ax","bx","cx"], ["z","a","b","c","x","x","x"], [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10])); // Salida: 27
console.log(maxScoreWords(["leetcode"], ["l","e","t","c","o","d"], [0,0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0])); // Salida: 0

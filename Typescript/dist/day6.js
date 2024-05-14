/*
Se le da una matriz entera score de tamaño n, donde score[i] es la puntuación de la atleta en una competencia. Todos los puntajes están garantizados único.ith

Los atletas son colocado en función de sus puntajes, donde el el atleta de lugar tiene la puntuación más alta, el lugar atleta tiene el puntuación más alta, y así sucesivamente. La colocación de cada atleta determina su rango:1st2nd2nd

El el rango de atleta de lugar es .1st"Gold Medal"
El el rango de atleta de lugar es .2nd"Silver Medal"
El el rango de atleta de lugar es .3rd"Bronze Medal"
Para el lugar para el coloque al atleta, su rango es su número de colocación (es decir, el el rango de atleta de lugar es ).4thnthxth"x"
Devolver una matriz answer de tamaño n donde answer[i] es el rango de la atleta.ith

Ejemplo 1:

Entrada: puntuación = [5,4,3,2,1]
Salida: ["Medalla de Oro","Medalla de Plata","Medalla de Bronce","4","5"]
Explicación: Las ubicaciones son [1st, 2nd, 3rd, 4, 4el, 5el].
Ejemplo 2:

Entrada: puntuación = [10,3,8,9,4]
Salida: ["Medalla de Oro","5","Medalla de Bronce","Medalla de Plata","4"]
Explicación: Las ubicaciones son [1st, 5el, 3rd, 2nd, 4, 4el].
*/
function findRelativeRanks(score) {
    // Ordenar puntajes en orden descendente (mayor a menor)
    const sortedScore = [...score].sort((a, b) => b - a);
    // Diccionario rankMap asigna el rango de cada atleta según su posición en la clasificación
    const rankMap = {};
    for (let i = 0; i < sortedScore.length; i++) {
        const score = sortedScore[i];
        switch (i) {
            case 0:
                rankMap[score] = "Gold Medal";
                break;
            case 1:
                rankMap[score] = "Silver Medal";
                break;
            case 2:
                rankMap[score] = "Bronze Medal";
                break;
            default:
                rankMap[score] = (i + 1).toString();
        }
    }
    const answer = [];
    for (const scores of score) {
        answer.push(rankMap[scores]);
    }
    return answer;
}
console.log(findRelativeRanks([5, 4, 3, 2, 1]));
console.log(findRelativeRanks([10, 3, 8, 9, 4]));
export {};
//# sourceMappingURL=day6.js.map
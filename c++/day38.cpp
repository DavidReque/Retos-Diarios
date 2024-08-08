/*
 Te dan una cuerda s y una serie de cuerdas words. Todas las cuerdas de words son de la misma longitud.

A cuerda concatenada es una cadena que contiene exactamente todas las cadenas de cualquier permutación de words concatenado.

Por ejemplo, si words = ["ab","cd","ef"], entonces "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", y "efcdab" son todas las cuerdas concatenadas. "acdbef" no es una cadena concatenada porque no es la concatenación de ninguna permutación de words.
Devuelve una matriz de los índices iniciales de todas las subcadenas concatenadas en s. Puedes devolver la respuesta en cualquier orden.

Ejemplo 1:
Entrada: s = "barfoothefoobarman", palabras = ["foo","bar"]
Salida: [0,9]
Explicación:
La subcadena que comienza en 0 es "barfoo". Es la concatenación de ["bar","foo"] que es una permutación de words.
La subcadena que comienza en 9 es "foobar". Es la concatenación de ["foo","bar"] que es una permutación de words.

Ejemplo 2:
Entrada: s = "wordgoodgoodgoodbestword", palabras = ["word","good","best","word"]
Salida: []
Explicación:
No hay subcadena concatenada.

Ejemplo 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
*/

class Solution {
    // Este es el mapa de referencia.
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;

        // Longitud de cada palabra en words.
        unsigned int length = words[0].size();

        // Inicialización del mapa de referencia.
        map.clear();
        for (const std::string& word : words)
            map[word]++;

        // Iteramos para cada desplazamiento
        // tantas veces como caracteres en cada palabra.
        for (unsigned int offset = 0; offset < length; ++offset) {
            // Tamaño de la ventana deslizante.
            unsigned int size = 0;
            // Memoria de la ventana deslizante.
            std::unordered_map<std::string, unsigned int> seen;

            // Iteramos sobre la cadena, con el paso igual a length.
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                // Esta es la palabra que vamos a verificar.
                std::string sub = s.substr(i, length);

                // Si la palabra está ausente en el mapa de referencia,
                // limpiamos la ventana deslizante y continuamos.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Incrementamos el número de ocurrencias
                // de la palabra en el mapa seen.
                ++seen[sub];
                ++size;

                // Para asegurarnos de que la ventana deslizante es válida,
                // necesitamos verificar solo la ocurrencia reciente
                // contra el mapa de referencia,
                // porque las ocurrencias anteriores
                // se verificaron en iteraciones anteriores.
                while (seen[sub] > itr->second) {
                    // Si la cantidad de ocurrencias excede
                    // la cantidad de referencia,
                    // reducimos la ventana desde la izquierda hasta
                    // que la ventana vuelva a ser válida.

                    // Una palabra al comienzo de la ventana deslizante actual.
                    std::string first = s.substr(i - (size - 1) * length, length);

                    // Eliminamos la ocurrencia de la ventana,
                    // reduciéndola desde la izquierda.
                    --seen[first];
                    --size;
                }

                // Si usamos todas las palabras del array words,
                // hemos encontrado el lugar correcto
                // y necesitamos calcular el índice de inicio
                // de la ventana deslizante actual.
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};


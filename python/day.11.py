class Solution:
    @staticmethod
    def longestCommonPrefix(strs: list[str]) -> str:
        if not strs:
            return ""

        # Inicializamos el prefijo común con el primer string
        prefix = strs[0]

        # Iteramos sobre los strings en la lista empezando desde el segundo string
        for s in strs[1:]:
            # Reducimos el prefijo mientras no sea el comienzo del string actual
            while s.find(prefix) != 0:
                # Acortar el prefijo eliminando el último carácter
                prefix = prefix[:-1]
                # Si el prefijo se vuelve vacío, no hay prefijo común
                if not prefix:
                    return ""

        # Devolvemos el prefijo común más largo encontrado
        return prefix

    
print(Solution.longestCommonPrefix(["flower", "flow", "flight"]))  # Salida: "fl"
print(Solution.longestCommonPrefix(["dog", "racecar", "car"]))    # Salida: ""

#Supongamos que strs = ["flower", "flow", "flight"].

#Inicialización:

#prefix = "flower"
#Primera Iteración (s = "flow"):

#s.find("flower") es -1, porque "flower" no está en "flow".
#Reducimos prefix: "flower"[:-1] es "flowe".
#s.find("flowe") es -1.
#Reducimos prefix: "flowe"[:-1] es "flow".
#s.find("flow") es 0, porque "flow" es el inicio de "flow".
#Salimos del while.
#Segunda Iteración (s = "flight"):

#s.find("flow") es -1, porque "flow" no está en "flight".
#Reducimos prefix: "flow"[:-1] es "flo".
#s.find("flo") es -1.
#Reducimos prefix: "flo"[:-1] es "fl".
#s.find("fl") es 0, porque "fl" es el inicio de "flight".
#Salimos del while.
#Después de todas las iteraciones, prefix es "fl", que es el prefijo común más largo #entre todas las cadenas de la lista.
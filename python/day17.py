class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        maxLength = 0
        currentCost = 0
        left = 0
        
        for right in range(n):
            currentCost += abs(ord(s[right]) - ord(t[right]))  # Calcular costo actual
            
            while currentCost > maxCost:  # Si el costo actual excede maxCost
                currentCost -= abs(ord(s[left]) - ord(t[left]))  # Reducir costo quitando s[left]
                left += 1  # Mover la izquierda de la ventana
            
            maxLength = max(maxLength, right - left + 1)  # Actualizar longitud máxima
        
        return maxLength

# Ejemplos de prueba
sol = Solution()
print(sol.equalSubstring("abcd", "bcdf", 3))  # Salida: 3
print(sol.equalSubstring("abcd", "cdef", 3))  # Salida: 1
print(sol.equalSubstring("abcd", "acde", 0))  # Salida: 1

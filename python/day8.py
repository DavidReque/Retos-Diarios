class Solution:
    def romanToInt(self, s: str) -> int:
        roman_values = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        } 
        
        #variable total para almacenar el valor total del número romano
        total = 0
        #prev_value para almacenar el valor del símbolo romano anterior
        prev_value = 0

        for char in s:
            #valor del caracter actual del diccionario
            value = roman_values[char]
            # Si el valor del caracter actual es mayor que el valor del caracter anterior,
            # significa que estamos tratando con un caso como IV o IX, donde la resta se aplica
            if value > prev_value:
                # Restamos dos veces el valor anterior del valor actual y lo agregamos al total
                total += value - 2 * prev_value
            else:
                # Si no estamos en un caso de resta, simplemente sumamos el valor al total
                total += value
            # Actualizamos el valor previo para el próximo caracter
            prev_value = value
            
        return total

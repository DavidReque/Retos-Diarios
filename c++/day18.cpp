/*
Te dan dos no vacío listas enlazadas que representan dos enteros no negativos. Los dígitos se almacenan en orden inverso, y cada uno de sus nodos contiene un solo dígito. Agregue los dos números y devuelva la suma como una lista vinculada.

Puede asumir que los dos números no contienen ningún cero principal, excepto el número 0 en sí.

Entrada: l1 = [2,4,3], l2 = [5,6,4]
Salida: [7,0,8]
Explicación: 342 + 465 = 807.
Ejemplo 2:

Entrada: l1 = [0], l2 = [0]
Salida: [0]
Ejemplo 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include <iostream>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {    
            int sum = carry;

            // sumar valor actual del nodo si existe
            if (l1 != nullptr)
            {
                sum += li->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // Actualizar el acarreo y el valor del nodo actual

            // sum / 10: Calcula el acarreo para la siguiente posición dividiendo la suma entre 10 y tomando la parte entera.
            carry = sum / 10;
            //sum % 10: Obtiene el dígito actual (unidad) de la suma tomando el residuo de la división entre 10.
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        // La nueva lista enlazada comienza después del nodo dummy
        return dummy->next;
    }
};

/*
Primera Iteración (Unidades):

sum = 2 (l1) + 5 (l2) + 0 (carry) = 7
carry = 7 / 10 = 0 (No hay acarreo)
current->next = new ListNode(7 % 10 = 7)
Segunda Iteración (Decenas):

sum = 4 (l1) + 6 (l2) + 0 (carry) = 10
carry = 10 / 10 = 1 (Acarreo 1)
current->next = new ListNode(10 % 10 = 0)
Tercera Iteración (Centenas):

sum = 3 (l1) + 4 (l2) + 1 (carry) = 8
carry = 8 / 10 = 0 (No hay acarreo)
current->next = new ListNode(8 % 10 = 8)
Resultado: [7, 0, 8], que representa 807.
*/
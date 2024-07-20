/*
 Dada una lista vinculada, cambie cada dos nodos adyacentes y devuelva su cabeza. Debe resolver el problema sin modificar los valores en los nodos de la lista (es decir, solo los nodos pueden cambiarse)

Ejemplo 1:
Entrada: cabeza = [1,2,3,4]
Salida: [2,1,4,3]

Ejemplo 2:
Entrada: cabeza = []
Salida: []

Ejemplo 3:
Entrada: cabeza = [1]
Salida: [1]

 Restricciones:
El número de nodos en la lista está en el rango [0, 100].
0 <= Node.val <= 100
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         // Si la lista exta vacia o tiene un nodo, no hay cambios
         if (!head || !head->next) return head;

         // Usamos un nodo dummy para simplificar el manejo de primer par 
         ListNode dummy(0);
         dummy.next = head;
         // puntero que siempre apunta al nodo anterior
         ListNode* prev = &dummy;

         while (prev->next && prev->next->next) {
           // Nodos a intercambiar
           ListNode* first = prev->next;
           ListNode* second = first->next;

           // realizamos el intercambio
           first->next = second->next;
           second->next = first;
           prev->next = second;

           // movemos para el siguiente par
           prev = first;
         }

         return dummy.next;
    }
};

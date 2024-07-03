/*Dado el head de una lista vinculada, elimine el nodo
 * desde el final de la lista y devuelva su cabeza.nth

Ejemplo 1:
Entrada: cabeza = [1,2,3,4,5], n = 2
Salida: [1,2,3,5]

Ejemplo 2:
Entrada: cabeza = [1], n = 1
Salida: []

Ejemplo 3:
Entrada: cabeza = [1,2], n = 1
Salida: [1]*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Crear un nodo dummy para manejar el caso de eliminar el primer nodo
        ListNode* dummy =  new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Mover fast n posiciiones adelante
        for (int i = 0; i < n; i++) {
          fast = fast->next;
        }

        // Mover ambos punteros hasta que fast llegue al final
        while (fast->next != nullptr) {
          fast = fast->next;
          slow = slow->next;
        }

        // Eliminar el nodo
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // Liberar memoria del nodo eliminado
        
        ListNode* result = dummy->next;
        delete dummy; // liberar memoria del nodo dummy-
        return result;
    
  }
};

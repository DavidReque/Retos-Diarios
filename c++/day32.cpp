
/**You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

 *
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // comparador para el heap
        // Este comparador se usa para ordenar los elementos en la cola de prioridad.
        // ordena los nodos de menor a mayor
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);

        // Agregar los nodos iniciales al heap
        for (ListNode* list : lists) {
          if (list) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // construir la lista resultante
        while (!pq.empty()) {
          // Extraemos el nodo con el valor más pequeño
          ListNode* node = pq.top();
          pq.pop();

          // Lo agregamos a nuestra lista resultante
          tail->next = node;
          tail = tail->next;

          // Si este nodo tiene un siguiente, lo añadimos a la cola de prioridad.
          if (node->next) {
            pq.push(node->next);
          }
        }

        return dummy.next;
    }
};

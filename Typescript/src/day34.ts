/*Dado el head de una lista vinculada, invierta los nodos de la lista k a la vez, y volver la lista modificada.
k es un número entero positivo y es menor o igual a la longitud de la lista vinculada. Si el número de nodos no es un múltiplo de k luego, los nodos izquierdos, al final, deben permanecer como están.
No puede alterar los valores en los nodos de la lista, solo se pueden cambiar los nodos.

Ejemplo 1:
Entrada: cabeza = [1,2,3,4,5], k = 2
Salida: [2,1,4,3,5]

Ejemplo 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Supongamos que la fila es [1, 2, 3, 4, 5] y k = 2:

Tomamos los primeros 2: [1, 2] y los invertimos: [2, 1]
Luego los siguientes 2: [3, 4] y los invertimos: [4, 3]
Queda 1 persona [5], que es menos que k=2, así que la dejamos.
Resultado final: [2, 1, 4, 3, 5]

*/

// Definition for singly-linked list.
class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function reverseKGroup(head: ListNode | null, k: number): ListNode | null {
  // Si la lista esta vacia o k es 1, no hay cambios
  if (!head || k === 1) return head;

  const dummy = new ListNode(0);
  dummy.next = head;
  // Usamos prev para mantener un enlace al nodo anterior al grupo actual.
  let prev = dummy;

  while (head) {
    let tail = prev;
    // verificar si hay k nodos disponibles
    for (let i = 0; i < k; i++) {
      // avanzamos tail k posiciones
      tail = tail.next!;
      // Si no hay k nodos, terminamos y devolvemos la lista
      if (!tail) {
        return dummy.next;
      }
    }

    // Guardamos la referencia al nodo después del grupo actual
    const next = tail.next;

    // Invertimos el grupo actual y obtenemos la nueva cabeza y cola
    [head, tail] = reverseList(head, tail);

    // Reconectar la lista invertida
    prev.next = head;
    tail.next = next;

    // nos preparamos para el siguiente grupo
    prev = tail;
    head = tail.next;
  }

  return dummy.next;
};

// function auxiliar para invertir la lista.
function reverseList(head: ListNode, tail: ListNode): [ListNode, ListNode] {
  // Comenzamos con prev apuntando al nodo después de tail
  let prev = tail.next;
  let current = head;
  while (prev !== tail) {
    // Guardamos la referencia al siguiente nodo.
    const next = current.next!;

    // invertimos el enlace
    current.next = prev;

    // movemos prev
    prev = current;

    // avanzamos al siguiente nodo
    current = next;
  }
  return [tail, head];
}

/**
Te dan el head de una lista vinculada.

Elimine cada nodo que tenga un nodo con un valor mayor en cualquier parte del lado derecho del mismo.

Devolución el head de la lista vinculada modificada.

Ejemplo 1:

Entrada: cabeza = [5,2,13,3,8]
Salida: [13,8]
Explicación: Los nodos que deben eliminarse son 5, 2 y 3.
El nodo 13 está a la derecha del nodo 5.
El nodo 13 está a la derecha del nodo 2.
El nodo 8 está a la derecha del nodo 3.
Ejemplo 2:

Entrada: cabeza = [1,1,1,1]
Salida: [1,1,1,1]
Explicación: Cada nodo tiene un valor 1, por lo que no se eliminan nodos.
 */


 class ListNode {
      val: number
      next: ListNode | null
      constructor(val?: number, next?: ListNode | null) {
          this.val = (val===undefined ? 0 : val)
          this.next = (next===undefined ? null : next)
        }
}

function removeNodes(head: ListNode | null): ListNode | null {
    if (!head) return null

    let current = head //apunta al nodo actual durante el recorrido de la lista
    let maxNode = null // apunta al nodo más grande hasta el momento en el lado derecho de la lista

    while (current) { //recorremos la lista hasta que llegue al final
        if (!maxNode || current.val > maxNode.val) { // Si maxNode es null o el valor actual es mayor que el valor de maxNode
            maxNode = current // Actualiza maxNode con el nodo actual
        } else { // Si el valor actual no es mayor que el valor de maxNode
            let temp = current
            
            //Recorre todos los nodos a la derecha de current hasta encontrar un nodo 
            //cuyo valor sea mayor o igual que el valor de maxNode
            while (temp.next !== null && temp.next.val < maxNode.val) { 
                temp = temp.next; // Avanza al siguiente nodo
            }
            // Elimina todos los nodos a la derecha de current cuyo valor sea menor que el valor de maxNode
            current.next = temp.next
        }
        current = current.next // avanza al siguiente nodo
    }

    return head
};
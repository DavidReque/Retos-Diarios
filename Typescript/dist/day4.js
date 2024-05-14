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
    constructor(val, next) {
        this.val = (val === undefined ? 0 : val);
        this.next = (next === undefined ? null : next);
    }
}
function removeNodes(head) {
    //Se inicializa un stack (pila) vacío para almacenar los valores de los nodos
    const stack = [];
    // Se agrega el valor del primer nodo al stack
    stack.push(head.val);
    head = head.next; // Se avanza al siguiente nodo
    while (head) {
        // mantener el stack en orden no-decreciente
        //Si el valor del nodo actual es mayor que el de la cima(ultimo elemento) del 
        //stack se elimina el elemento superior del stack (stack.pop()) hasta que se cumpla la condición.
        while (stack.length && head.val > stack[stack.length - 1]) {
            stack.pop();
        }
        //Se agrega el valor del nodo actual al stack
        stack.push(head.val);
        // se avanza al siguiente nodo
        head = head.next;
    }
    //Construcción de la nueva lista vinculada a partir del stack
    let res; // Variable para almacenar el nodo cabeza de la nueva lista vinculada
    while (stack.length) {
        //Se crea un nuevo nodo con el valor extraído y el nodo res como su next
        let newHead = new ListNode(stack.pop(), res);
        res = newHead; //Se actualiza res para que apunte al nuevo nodo creado
    }
    return res;
}
export {};
//# sourceMappingURL=day4.js.map
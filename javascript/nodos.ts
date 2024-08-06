class Node {
  data: number;
  next: Node | null;

  constructor(data: number) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  head: Node | null;

  constructor() {
    this.head = null;
  }

  append(data: number): void {
    const newNode = new Node(data);
    if (!this.head) {
      this.head = newNode;
      return;
    }

    let lastNode = this.head;
    while (lastNode.next) {
      lastNode = lastNode.next;
    }
    lastNode.next = newNode;
  }

  insertAt(index: number, data: number): void {
    const newNode = new Node(data);

    if (index === 0) {
      newNode.next = this.head;
      this.head = newNode;
      return;
    }

    let currentNode = this.head;
    let currentIndex = 0;

    while (currentNode && currentIndex < index - 1) {
      currentNode = currentNode.next;
      currentIndex++;
    }

    if (!currentNode) {
      return; // Índice fuera de rango
    }

    newNode.next = currentNode.next;
    currentNode.next = newNode;
  }

  display(): void {
    let currentNode = this.head;
    while (currentNode) {
      console.log(currentNode.data);
      currentNode = currentNode.next;
    }
  }
}

// Ejemplo de uso
const list = new LinkedList();
list.append(1);
list.append(2);
list.append(4);

console.log("Lista original:");
list.display();

list.insertAt(2, 3);

console.log("Lista después de insertar:");
list.display();

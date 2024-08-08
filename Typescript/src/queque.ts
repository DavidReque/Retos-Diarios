class Queue<T> {
  private items: T[] = [];

  // Agrega un elemento al final de la cola
  enqueue(element: T) {
    this.items.push(element);
  }

  // Elimina y devuelve el primer elemento de la cola
  dequeue(): T | undefined {
    return this.items.shift();
  }

  // Devuelve el primer elemento de la cola sin eliminarlo
  front(): T | undefined {
    return this.items[0];
  }

  // Devuelve si la cola está vacía
  isEmpty(): boolean {
    return this.items.length === 0;
  }

  // Devuelve el tamaño de la cola
  size(): number {
    return this.items.length;
  }

  // Vacía la cola
  clear() {
    this.items = [];
  }
}

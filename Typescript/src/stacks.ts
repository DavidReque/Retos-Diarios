class Stack<T> {
  private items: T[] = [];

  // agrega un elemento a la pila 
  push(element: number | string): T | undefined {
    this.items.push(element);
  }

  // Elimina y devuelve elemento
  pop(): T | undefined {
    return this.items.pop();
  }

  // devuelve si .
  isEmpty(): boolean {
    return this.items.length === 0;
  }
}

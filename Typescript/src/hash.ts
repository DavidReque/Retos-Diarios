class HashTable<K, V> {

  private table: { [key: string]: V } = {};

  // calcula el Hash de una tabla
  private hash(key: K): string {
    return key.toString();
  }


  // Agrega un par clave-valor a la tabla Hash
  set(key: K, value: V) {
    const hashKey = this.hash(key);
    this.table[hashKey] = value;
  }

  // Devuelve el valor asociado a una clave
  get(key: K): V | undefined {
    const hashKey = this.hash(key);
    return this.table[hashKey];
  }

  remove(key: K): boolean {
    const hashKey = this.hash(key);
    if (this.table[hashKey] !== undefined) {
      delete this.table[hashKey];
      return true;
    }
    return false;
  }
}

function wordFrequency(text: string): HashTable<string, number> {
  const words = text.toLowerCase().split(/\W+/);
  const frequencyTable = new HashTable<string, number>;

  words.forEach(word => {
    if (word) {
      const count = frequencyTable.get(word) || 0;
      frequencyTable.set(word, count + 1)
    }
  })
  return frequencyTable;
}

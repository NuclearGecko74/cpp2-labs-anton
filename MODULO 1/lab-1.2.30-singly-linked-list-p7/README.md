[⬅️ Volver al inicio](../../)

# LAB 1.2.24-30: Singly linked list

## 📝 Descripción
Este extenso proyecto de siete partes cubre la implementación de una de las estructuras de datos más fundamentales en ciencias de la computación: la **lista enlazada simple** (Singly Linked List). El desarrollo es incremental, comenzando con operaciones básicas y avanzando progresivamente para incluir gestión de memoria, optimizaciones de eficiencia, acceso por índice y, finalmente, la correcta gestión de copias de objetos, abordando conceptos clave de C++ como la "Regla de los Tres".

---

## ⚙️ Ejemplo de Ejecución
*A continuación se muestra una sesión de la versión final del programa (Parte 7), que demuestra el funcionamiento del constructor de copia. Observa cómo `list1` y `list2` se modifican de forma independiente después de la copia, probando que es una copia profunda.*

**Output del Programa:**
```

list1
list[0] == 4
list[1] == 3
list[2] == 2
list[3] == 1

list2
list[0] == 4
list[1] == 3
list[2] == 2
list[3] == 1

list1
list[0] == 4
list[1] == 6
list[2] == 3
list[3] == 2
list[4] == 1

list2
list[0] == 4
list[1] == 3
list[2] == 1

```

---

## 🧠 Evolución del Proyecto y Conceptos Aplicados
La construcción de la lista enlazada se realizó paso a paso, introduciendo un nuevo concepto en cada parte.

### Parte 1-2: Fundación y Gestión de Memoria
Se sentaron las bases de la estructura.
* **Conceptos:** Se crearon las clases `Node` (el bloque de construcción) y `LinkedList` (el gestor). Se implementaron `push_front` y `pop_front`, que le dan a la lista un comportamiento de **Pila (LIFO)**. Inmediatamente después, se implementó el **destructor (`~LinkedList`)**, un paso crucial para iterar sobre la lista y liberar cada nodo, previniendo así **fugas de memoria (memory leaks)**.

### Parte 3-4: Funcionalidad de Cola y Eficiencia
Se expandió la funcionalidad y se analizó la eficiencia.
* **Conceptos:** Se añadió un método `size()` con una implementación **O(1)** (tiempo constante) al mantener un contador de longitud, lo cual es muy eficiente. Luego, se implementó `push_back` para añadir elementos al final, permitiendo un comportamiento de **Cola (FIFO)**. Inicialmente, esta operación era **O(n)** (tiempo lineal), ya que requería recorrer toda la lista.

### Parte 5: Optimización con Puntero a la Cola (`tail`)
Esta fue una mejora clave de rendimiento.
* **Conceptos:** Se añadió un puntero `tail` a la clase `LinkedList` que siempre apunta al último nodo. Esto transformó la operación `push_back` de O(n) a una operación **O(1)** altamente eficiente. También se implementó `pop_back`, que, debido a la naturaleza de una lista simplemente enlazada, debe seguir siendo O(n) al necesitar encontrar el penúltimo nodo. 
### Parte 6: Acceso por Índice
Se implementaron métodos para interactuar con la lista de manera similar a un array.
* **Conceptos:** Se añadieron `at(index)`, `insert_at(index, value)` y `remove_at(index)`. Estas funciones resaltan el principal compromiso de las listas enlazadas: a cambio de inserciones y eliminaciones flexibles, el acceso a un elemento por su índice es una operación **O(n)**, ya que requiere un recorrido desde el principio.

### Parte 7: El Constructor de Copia (Deep Copy)
La fase final abordó un concepto avanzado y vital de C++.
* **Conceptos:** Se explicó el peligro del constructor de copia por defecto, que realiza una **copia superficial (shallow copy)**. En una lista enlazada, esto resultaría en dos objetos `LinkedList` apuntando a los mismos nodos, llevando a corrupción de datos y dobles liberaciones de memoria.
* **Solución:** Se implementó un **constructor de copia** personalizado que realiza una **copia profunda (deep copy)**. Este constructor itera a través de la lista original y crea un `Node` completamente nuevo por cada elemento, asegurando que la lista copiada sea una entidad totalmente independiente. ✅

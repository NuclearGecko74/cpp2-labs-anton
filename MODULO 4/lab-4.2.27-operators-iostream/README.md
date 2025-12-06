[⬅️ Volver al inicio](../../)

# LAB 4.2.27: Operators: iostream (Binary Tree)

## 📝 Descripción

Este laboratorio se enfoca en la implementación de una estructura de datos de tipo **Árbol Binario de Búsqueda (BST)** y la sobrecarga del operador de flujo de salida (`<<`) para visualizar su contenido. El objetivo es diseñar una clase contenedora `BinaryTree` donde cada nodo tiene un valor y punteros a sus hijos izquierdo y derecho.

La característica principal es la implementación del recorrido **In-Order** (Izquierda -\> Raíz -\> Derecha) dentro de la sobrecarga del operador `<<`, lo que permite imprimir los valores del árbol ordenados de forma ascendente simplemente enviando el objeto al flujo `std::cout`.

-----

## ⚙️ Ejemplo de Ejecución

*El programa inserta valores en desorden y el operador de impresión los muestra ordenados.*

### Input (Código en Main)

```cpp
tree.add(3);
tree.add(5);
tree.add(2);
```

### Output

**Output del Programa:**

```text
2
3
5
```

*(Nota: Al ser un recorrido In-Order en un Árbol Binario de Búsqueda, los elementos se imprimen ordenados de menor a mayor).*

-----

## 🧠 Conceptos Aplicados

  * **Árbol Binario de Búsqueda (BST):** Implementación lógica donde los valores menores se insertan a la izquierda y los mayores a la derecha. Esto permite que el recorrido In-Order produzca una secuencia ordenada.
  * **Smart Pointers (`std::unique_ptr`):** Uso de punteros inteligentes para la gestión automática de la memoria de los nodos (`m_left`, `m_right`). Esto elimina la necesidad de usar `delete` manualmente y previene fugas de memoria, modernizando la gestión de recursos respecto a los punteros crudos tradicionales.
  * **Sobrecarga de Operadores Globales:** Implementación de `operator<<` como una función global `friend`. Esto permite acceder a los miembros privados (`m_root`) para iniciar el recorrido recursivo, manteniendo la sintaxis natural de C++ (`cout << tree`).
  * **Recursividad:** Uso de métodos auxiliares recursivos (`insert` y `printInOrder`) para navegar y modificar la estructura jerárquica del árbol.
  * **Encapsulamiento y `friend` classes:** La clase `Node` declara como `friend` a `BinaryTree`, permitiendo que el árbol gestione los datos internos de los nodos mientras estos permanecen privados para el resto del programa.

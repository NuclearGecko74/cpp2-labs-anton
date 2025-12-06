[⬅️ Volver al inicio](../../)

# LAB 4.2.29: Operators: complex classes

## 📝 Descripción

Este laboratorio avanza en la Programación Orientada a Objetos utilizando **herencia** y **sobrecarga de operadores** en una jerarquía de clases. El objetivo es implementar una estructura de base `BinaryTree` que gestione la lógica de inserción y almacenamiento, y tres clases derivadas (`InOrder`, `PostOrder`, `PreOrder`) que especialicen la forma en que se recorre y visualiza el árbol.

Cada clase derivada sobrecarga:

  * El operador `<<` para imprimir el árbol en el orden correspondiente (In-order, Pre-order, Post-order).
  * El operador `[]` para acceder a un elemento específico según el orden secuencial de dicho recorrido.

-----

## ⚙️ Ejemplo de Ejecución

*El programa crea tres instancias de árboles (una por cada tipo de recorrido), inserta los mismos valores `3, 5, 6, 1` y muestra cómo cambia la salida según la clase utilizada.*

### Input (Código en Main)

```cpp
// Se insertan los mismos valores en las 3 clases derivadas
tree.add(3);
tree.add(5);
tree.add(6);
tree.add(1);
```

### Output

**Output del Programa:**

```text
Inorder: 1 3 5 6 
Postorder: 1 6 5 3 
Preorder: 3 1 5 6 
```

-----

## 🧠 Conceptos Aplicados

  * **Herencia:** Uso de una clase base `BinaryTree` para compartir la lógica común (nodos, punteros, método `add`) y clases derivadas para especializar el comportamiento.
  * **Estrategias de Recorrido de Árboles:**
      * **In-Order:** Izquierda -\> Raíz -\> Derecha (Produce valores ordenados).
      * **Post-Order:** Izquierda -\> Derecha -\> Raíz.
      * **Pre-Order:** Raíz -\> Izquierda -\> Derecha.
  * **Sobrecarga de Operadores en Clases Derivadas:** Implementación específica de `operator<<` y `operator[]` en cada subclase para reflejar su estrategia de recorrido única.
  * **Recolección de Datos (Flattening):** Uso de vectores auxiliares dentro de los operadores para "aplanar" el árbol en una lista lineal según el orden requerido, facilitando tanto la impresión como el acceso por índice.
  * **Smart Pointers:** Gestión de memoria automatizada mediante `std::unique_ptr` en la clase base para asegurar que la estructura del árbol se libere correctamente sin fugas de memoria.

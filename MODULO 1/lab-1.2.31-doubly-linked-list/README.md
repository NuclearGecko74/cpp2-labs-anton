[⬅️ Volver al inicio](../../)

# LAB 1.2.31: Doubly linked list

## 📝 Descripción
Este laboratorio es la evolución natural del proyecto de la lista simplemente enlazada. Consiste en la implementación de una **lista doblemente enlazada**, una estructura de datos más potente y flexible. La diferencia fundamental es la adición de un puntero al nodo **anterior (`prev`)** en cada `Node`, además del puntero al **siguiente (`next`)**. Esta modificación permite el recorrido bidireccional, lo que simplifica la lógica y optimiza drásticamente el rendimiento de varias operaciones clave.

---

## ⚙️ Ejemplo de Ejecución
*El programa de prueba es idéntico al de la fase final de la lista simple, demostrando que la nueva implementación mantiene una interfaz compatible y es completamente funcional.*

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

## 🧠 Mejoras Clave sobre la Lista Simplemente Enlazada
La adición del puntero `prev` desbloquea varias ventajas significativas en términos de eficiencia y simplicidad.

### 1. Recorrido Bidireccional
A diferencia de la lista simple, que solo puede ser recorrida hacia adelante, una lista doblemente enlazada puede ser atravesada en ambas direcciones. Esto es la base para las siguientes optimizaciones.

### 2. Eliminación Eficiente desde el Final (`pop_back` en O(1))
Esta es la mejora de rendimiento más importante.
* En la lista simple, `pop_back` era una operación **O(n)** porque para eliminar el último nodo, necesitábamos encontrar el *penúltimo* nodo, lo que requería un recorrido completo desde `head`.
* En la lista doble, `pop_back` es una operación **O(1)** (tiempo constante). Podemos saltar directamente al `tail`, y desde ahí acceder al nuevo último nodo en un solo paso usando `tail->prev`. 
### 3. Búsqueda Optimizada (`at` / `get`)
Se implementó una optimización inteligente para el acceso por índice. El método ahora comprueba si el índice está en la primera o segunda mitad de la lista.
* Si el índice está en la primera mitad, recorre hacia adelante desde `head`.
* Si está en la segunda mitad, recorre hacia atrás desde `tail` usando los punteros `prev`.
Esto reduce el tiempo máximo de búsqueda a la mitad (sigue siendo O(n), pero un O(n) más rápido en la práctica).

### 4. Inserciones y Eliminaciones Simplificadas (`insert_at`, `remove_at`)
Aunque la lógica de punteros es más densa (hay más punteros que actualizar), el algoritmo en sí es más directo. Una vez que se localiza el nodo para una operación, se tiene acceso instantáneo a sus vecinos en ambas direcciones (`current->prev` y `current->next`), lo que simplifica el proceso de "recableado" de la lista sin necesidad de un puntero "seguidor" adicional durante el recorrido.

En resumen, la lista doblemente enlazada ofrece mejoras sustanciales de rendimiento y flexibilidad a cambio de un ligero aumento en el uso de memoria (un puntero extra por nodo) y una gestión de punteros más meticulosa. ✅

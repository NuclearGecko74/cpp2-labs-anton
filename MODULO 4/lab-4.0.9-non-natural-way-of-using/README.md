[⬅️ Volver al inicio](../../)

# LAB 4.0.9: Operators: non-natural way of using

## 📝 Descripción

Este laboratorio explora el uso de la **sobrecarga de operadores** para manipular una estructura de datos tipo **Pila (Stack)** de una forma no convencional ("non-natural"). En lugar de usar métodos explícitos en el `main` o dejar que las excepciones suban, se utilizan los operadores de flujo para realizar las operaciones lógicas y el manejo de errores:

  * El operador `>>` realiza la operación **Push** (agregar elementos).
  * El operador `<<` realiza la operación **Pop** (extraer e imprimir elementos) y **captura excepciones internamente** si la pila está vacía.

-----

## ⚙️ Ejemplo de Ejecución

*El programa solicita la cantidad de elementos a ingresar, los lee, y luego solicita la cantidad de elementos a extraer.*

### Input

**Input del Usuario:**

```text
3
10
20
30
4
```

*(Se agregan 3 números y se intenta extraer 4 veces).*

### Output

**Output del Programa:**

```text
Cuantos elementos deseas agregar: Cuantos elementos deseas sacar: 30
20
10
Exception: stack is empty.
```

-----

## 🧠 Conceptos Aplicados

  * **Sobrecarga de Operadores con Efectos Secundarios:** Se redefinen `operator<<` y `operator>>` para modificar el estado interno del objeto (agregando o eliminando datos de la pila), lo cual difiere del uso estándar de solo lectura/escritura.
  * **Manejo de Excepciones Encapsulado:** El operador de salida (`<<`) implementa un bloque `try-catch`. Intenta obtener el valor (`top`) y eliminarlo (`pop`); si la pila está vacía, atrapa el error ahí mismo y muestra el mensaje, evitando que el programa principal colapse.
  * **Separación de Lógica (`top` vs `pop`):** Implementación de métodos robustos: `top()` (const) para inspección con validación de errores, y `pop()` (void) para modificación de estado.
  * **Uso de `std::vector`:** Gestión de memoria segura y dinámica utilizando contenedores estándar de C++ en lugar de punteros crudos.

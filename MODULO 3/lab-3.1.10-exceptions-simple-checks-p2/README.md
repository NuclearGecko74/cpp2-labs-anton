[⬅️ Volver al inicio](../../)

# LAB 3.1.10-11: Exceptions: Simple Checks

## 📝 Descripción

Este proyecto de dos partes se enfoca en un uso crítico de las excepciones: **validar el estado interno de un objeto y hacer cumplir sus reglas lógicas (invariantes)**.

A diferencia de los laboratorios anteriores que se centraban en la entrada del usuario (como la división por cero), estos laboratorios implementan la lógica de excepciones *dentro* de los métodos de la clase, especialmente en los constructores y métodos de operación.

1.  **Parte 1 (3.1.10):** Se crea una clase `Matrix` que lanza excepciones si se intenta crear con dimensiones inválidas o si se suman matrices de tamaños incompatibles.
2.  **Parte 2 (3.1.11):** Se crea una clase `ValueHolder` que mantiene un valor dentro de límites (`min`/`max`) y lanza excepciones si se intenta crear o modificar el valor fuera de esos límites.

-----

## ⚙️ Ejemplo de Ejecución

### Parte 1 (3.1.10): Matrix Simple Checks

**Input del Usuario:**

```
2
2
2
2
3
3
```

**Output del Programa:**

```
0 0
0 0
Matrices don't fit.
Matrices don't fit.
```

### Parte 2 (3.1.11): ValueHolder Simple Checks

**Input del Usuario:**

```
5 0 10
9 0 100
15
15
90
```

**Output del Programa:**

```
Value could exceed limit.
Value could exceed limit.
5
24.
```

-----

## 🧠 Conceptos Aplicados: Validación de Invariantes de Clase

Ambos laboratorios ilustran un conjunto de principios fundamentales para escribir código C++ robusto y seguro.

  * **Lanzar en Constructores (Throwing in Constructors):**
    Este es el concepto más importante del proyecto. Tanto `Matrix(rows, cols)` como `ValueHolder(value, min, max)` realizan validaciones *dentro* del constructor. Si los argumentos de entrada no son válidos (p.ej., `rows <= 0` o `value < minLimit`), lanzan una excepción.

      * **Impacto:** Esto previene que un objeto se cree en un estado inválido o "zombie". Si el constructor falla, no se crea ningún objeto, evitando errores posteriores.

  * **Lanzar en Métodos (Protección de Invariantes):**
    Los métodos de las clases también protegen el estado del objeto.

      * `Matrix::add()` comprueba la compatibilidad de dimensiones *antes* de realizar la suma.
      * `ValueHolder::add()` y `ValueHolder::subtract()` calculan el `newValue` y lo validan *antes* de asignarlo a `m_value`. Si la nueva operación violara los límites, la excepción se lanza y el estado de `m_value` permanece sin cambios. Esto dota a los métodos de un comportamiento **transaccional** (todo o nada).

  * **Excepciones Personalizadas con Estado:**
    Ambos laboratorios crean sus propias clases de excepción (`MatrixException`, `ValueException`). Lo clave es que ambas tienen un constructor que acepta un `std::string` y un miembro privado `m_message`. Esto permite que el código que lanza la excepción (`throw ValueException("Valor excede el límite.");`) pase un mensaje dinámico y contextual, haciendo que el manejo de errores sea mucho más informativo.

  * **Manejo Granular de Errores (Nested Try...Catch):**
    El `main` de la Parte 1 (Matrix) es un ejemplo excelente de manejo granular. Hay un bloque `try...catch` externo para la *construcción* de las matrices (un error aquí es fatal para el resto del programa) y bloques `try...catch` *internos* para cada operación `add()`. Esto permite que si `a.add(c)` falla, el programa pueda recuperarse y continuar para intentar `b.add(c)`.
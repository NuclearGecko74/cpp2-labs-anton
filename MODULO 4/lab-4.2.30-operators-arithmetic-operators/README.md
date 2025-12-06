[⬅️ Volver al inicio](../../)

# LAB 4.2.30: Operators: arithmetic operators

## 📝 Descripción

Este laboratorio tiene como objetivo implementar una clase `Matrix` completa que soporte operaciones de **álgebra lineal** mediante la sobrecarga de operadores aritméticos estándar (`+`, `-`, `*`). El programa debe ser capaz de realizar operaciones tanto entre dos matrices como entre una matriz y un valor escalar.

Un componente crucial de este ejercicio es el **manejo de errores**: el código debe validar rigurosamente las dimensiones de las matrices antes de cualquier operación y lanzar excepciones (`std::exception`) si las dimensiones son incompatibles (por ejemplo, sumar una matriz de $2\times2$ con una de $3\times3$).

-----

## ⚙️ Ejemplo de Ejecución

*El programa inicializa matrices de prueba (una llena de 1s y otra de 3s), realiza cálculos aritméticos y finalmente fuerza errores para demostrar el sistema de excepciones.*

### Input (Código en Main)

```cpp
// Se crean matrices hardcoded según las instrucciones del escenario
Matrix A(2, 2, 1);
Matrix B(2, 2, 3);
Matrix C(3, 3, 5); // Matriz de diferente tamaño para causar errores

// Operaciones válidas e inválidas
cout << (A + B);
Matrix error = A + C; // Esto lanzará excepción
```

### Output

**Output del Programa:**

```text
Matrix A:
   1   1
   1   1
Matrix B:
   3   3
   3   3
A + B:
   4   4
   4   4
...
--- Exception Tests ---
Trying A + C...
Exception caught: Matrix dimensions must match for addition.
Trying A * C...
Exception caught: Matrix A columns must match Matrix B rows for multiplication.
```

-----

## 🧠 Conceptos Aplicados

  * **Sobrecarga de Operadores Aritméticos:** Implementación de `operator+`, `operator-` y `operator*` para permitir una sintaxis matemática natural e intuitiva en C++.
  * **Operaciones Matriciales y Escalares:**
      * **Matriz-Matriz:** Suma, resta y multiplicación siguiendo las reglas del álgebra lineal.
      * **Matriz-Escalar:** Operaciones elemento a elemento (ej. multiplicar cada celda por 2).
  * **Manejo de Excepciones (`std::invalid_argument`):** Uso de bloques `try-catch` para gestionar errores de lógica de negocio (validación de dimensiones) sin detener la ejecución abruptamente.
  * **Contenedores STL (`std::vector`):** Uso de vectores de vectores (`vector<vector<int>>`) para crear una estructura de matriz dinámica y segura en memoria.

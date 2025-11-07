[⬅️ Volver al inicio](../../)

# LAB 3.0.9: Exceptions: divide by zero

## 📝 Descripción

Este laboratorio profundiza en el manejo de excepciones introduciendo **clases de excepción personalizadas**. El objetivo es refactorizar el manejo de errores de división por cero para que, en lugar de lanzar un simple `const char*`, se lance un objeto de una clase específica (`DivideByZeroException`) que herede de la clase base `std::exception` de C++.

-----

## ⚙️ Ejemplo de Ejecución

*El programa solicita dos números para realizar una división.*

### Input Válido

**Input del Usuario:**

```
4
2
```

**Output del Programa:**

```
2
```

### Input Inválido

**Input del Usuario:**

```
4
0
```

**Output del Programa:**

```
Your input is not valid, you can't divide by zero.
```

-----

## 🧠 Conceptos Aplicados

  * **Clases de Excepción Personalizadas:** El concepto central es la creación de nuestra propia clase de error, `DivideByZeroException`.
  * **Herencia de `std::exception`:** La clase personalizada hereda de `std::exception`, que es la práctica estándar en C++. Esto permite que los manejadores de excepciones genéricos (p.ej., `catch(const std::exception& e)`) también puedan atrapar este error si fuera necesario.
  * **Sobrescritura de `what()`:** Se sobrescribe (`override`) el método virtual `what() const noexcept` de la clase base. Este método es el estándar para obtener un mensaje descriptivo del error.
  * **`throw` de Objetos:** En lugar de `throw "mensaje"`, ahora se lanza una instancia de la clase de excepción: `throw DivideByZeroException();`.
  * **Catch por Referencia Constante:** El bloque `catch` se actualiza para atrapar el tipo de objeto específico por referencia constante (`catch (const DivideByZeroException& e)`). Esta es la forma canónica de atrapar excepciones en C++, ya que evita copias innecesarias y previene el *slicing* del objeto.
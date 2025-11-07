[⬅️ Volver al inicio](../../)

# LAB 3.1.9: Exceptions: catch block

## 📝 Descripción

Este laboratorio avanza en el concepto de clases de excepción personalizadas al demostrar cómo **pasar información adicional** al objeto de la excepción en el momento en que se lanza.

El escenario consiste en calcular el área de dos figuras (cuadrado y rectángulo). Las funciones de cálculo validan sus argumentos (las longitudes de los lados) y, si son inválidos (menores o iguales a cero), lanzan una excepción `NegativeAreaException`. La clave es que, al crear esta excepción, se le pasa un `std::string` con el mensaje de error específico, el cual es almacenado dentro de la excepción misma.

-----

## ⚙️ Ejemplo de Ejecución

*El programa solicita dos números que se usarán para calcular las áreas.*

### Input Válido

**Input del Usuario:**

```
2
1
```

**Output del Programa:**

```
4
2
```

### Input Inválido

**Input del Usuario:**

```
-10
6
```

**Output del Programa:**

```
Your input is not valid. The area can't be negative.
```

-----

## 🧠 Conceptos Aplicados

  * **Excepciones con Estado (Datos):** Este es el concepto central. La clase `NegativeAreaException` ahora tiene un constructor `NegativeAreaException(std::string message)` y un miembro privado `std::string m_message`.
  * **Paso de Información:** Cuando la excepción es lanzada (p. ej., `throw NegativeAreaException("El área no puede ser negativa");`), el mensaje se pasa al constructor, se almacena en `m_message`, y luego el método `what()` lo devuelve.
  * **Separación de Lógica:** Las funciones de cálculo (`squareArea`, `rectangleArea`) son responsables de *detectar* el error y *lanzar* la excepción con la información relevante. La función `main` es responsable de *capturar* el error y *presentar* la información al usuario (`std::cout << e.what()`). Esto crea un diseño limpio y desacoplado.
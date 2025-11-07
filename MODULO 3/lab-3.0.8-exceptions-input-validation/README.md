[⬅️ Volver al inicio](../../)

# LAB 3.0.8: Exceptions: input validation

## 📝 Descripción

Este laboratorio introduce el manejo básico de excepciones en C++. El objetivo es modificar un programa simple para que valide el input del usuario.

En lugar de permitir un error de división por cero en tiempo de ejecución, el programa debe detectar proactivamente la entrada inválida (un cero) y **lanzar (`throw`) manualmente una excepción** para gestionar el error de forma controlada y específica.

-----

## ⚙️ Ejemplo de Ejecución

*El programa prueba dos escenarios: una entrada válida para la división y una entrada inválida (cero).*

### Input Válido

**Input del Usuario:**

```
2
```

**Output del Programa:**

```
4
```

### Input Inválido

**Input del Usuario:**

```
0
```

**Output del Programa:**

```
Your input is not valid, you can't divide by zero.
0
```

*(Nota: El `0` final se imprime porque la variable `c` se inicializa en `0` y la línea de impresión está fuera del bloque `try...catch`)*

-----

## 🧠 Conceptos Aplicados

  * **Bloques `try...catch`:** Se utiliza un bloque `try` para encapsular la lógica "peligrosa" (la validación y la división). El bloque `catch` se prepara para "atrapar" cualquier excepción que pueda ocurrir dentro del `try`.
  * **Validación y `throw` Manual:** Este es el concepto clave del laboratorio. No esperamos que el sistema operativo lance una excepción de hardware; en su lugar, usamos una **validación lógica** (`if (b == 0)`). Si la validación falla, usamos la palabra clave `throw` para lanzar intencionalmente una excepción y transferir el control al `catch`.
  * **Tipo de Excepción (`const char*`)**: En este ejercicio simple, la excepción que se lanza es un literal de cadena de C (`const char*`). El bloque `catch (const char* errorMsg)` está diseñado para atrapar este tipo específico de dato, permitiendo que el mensaje de error sea capturado y mostrado al usuario.
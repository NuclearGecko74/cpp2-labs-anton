[⬅️ Volver al inicio](../../)

# LAB 3.1.8: Exceptions: input validation

## 📝 Descripción

Este laboratorio se centra en la **refactorización del manejo de errores**. El objetivo es migrar un programa desde un estilo de C "clásico" (que usa códigos de retorno booleanos y parámetros de salida por referencia) a un manejo de excepciones moderno y robusto en C++.

El programa original tenía una función `div(float &res, float arg1, float arg2)` que devolvía `bool`. Se ha refactorizado a `float div(float arg1, float arg2)`, que **retorna el resultado directamente**. Si la validación de entrada (denominador == 0) falla, la función ahora **lanza (`throw`)** una excepción personalizada, `DivideByZeroException`.

-----

## ⚙️ Ejemplo de Ejecución

*El programa lee dos números en un bucle, mostrando el resultado o un error.*

### Input Válido

**Input del Usuario:**

```
2
1
```

**Output del Programa:**

```
2
```

### Input Inválido

**Input del Usuario:**

```
6
0
```

**Output del Programa:**

```
Are you kidding me?
Your input is not valid. You can't divide by zero.
```

-----

## 🧠 Conceptos Aplicados

  * **Refactorización de Manejo de Errores:** Este es el concepto clave. Se elimina el patrón de "código de retorno" (`bool success = div(...)`) y se reemplaza por un bloque `try...catch`, que es más limpio y el estándar en C++ moderno.
  * **Valores de Retorno vs. Excepciones:** La función `div` ahora tiene un propósito más claro: su valor de retorno es *siempre* el resultado de la división. Los errores se comunican "fuera de banda" (out-of-band) a través del sistema de excepciones.
  * **Propagación de Excepciones:** La función `div` *detecta* el error y *lanza* la excepción. La función `main` (el *llamante*) es responsable de *capturar* y *manejar* esa excepción. Esto desacopla claramente la detección del error de su manejo.
  * **Excepciones Personalizadas:** Se utiliza la clase `DivideByZeroException` para proveer un mensaje de error detallado y multi-línea (gracias al `\n` en el `what()`), mejorando la información de diagnóstico para el usuario.
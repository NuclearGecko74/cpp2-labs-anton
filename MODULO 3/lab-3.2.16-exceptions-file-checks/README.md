[⬅️ Volver al inicio](../../)

# LAB 3.2.16: Exceptions: file checks

## 📝 Descripción

Este laboratorio se enfoca en el manejo de excepciones de E/S (Entrada/Salida) de archivos. El objetivo es implementar una clase `Matrix` con métodos `loadMatrix` y `saveMatrix`.

La clave del ejercicio es configurar los objetos `std::ifstream` y `std::ofstream` para que, en lugar de usar códigos de error pasivos (flags), **lancen (`throw`) excepciones automáticamente** en caso de un fallo (como no encontrar un archivo o no tener permisos). El laboratorio también requiere que, al capturar una excepción, se imprima un mensaje y luego **se vuelva a lanzar (re-throw)** la excepción.

-----

## ⚙️ Ejemplo de Ejecución

*El programa simula dos escenarios de error: intentar leer un archivo que no existe e intentar escribir en un archivo sin permisos.*

**Output del Programa:**

```
Simulate both situations handled:

File not found at: path
No rights to write to file: path
```

-----

## 🧠 Conceptos Aplicados

  * **Configuración de Excepciones en Streams:** Este es el concepto central. Se utiliza el método `.exceptions()` (p. ej., `inFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);`). Esto instruye a los objetos `ifstream` y `ofstream` para que dejen de usar el manejo de errores pasivo y, en su lugar, lancen activamente una excepción `std::ios_base::failure` si ocurre un error.
  * **Manejo Específico de `std::ios_base::failure`:** Los bloques `try...catch` están diseñados para atrapar la excepción E/S específica (`const std::ios_base::failure& e`), permitiendo un manejo de errores robusto y específico para E/S de archivos.
  * **Re-lanzamiento de Excepciones (`throw;`):** Dentro de los métodos `loadMatrix` y `saveMatrix`, después de imprimir el mensaje de error, se utiliza la instrucción `throw;`. Esto **re-lanza** la misma excepción que se acaba de capturar. Es una técnica crucial que permite a una función intermedia (como `loadMatrix`) registrar un error, pero sin "tragarse" la excepción, permitiendo que el código que la llamó (`main`) también sepa que la operación falló.
  * **Simulación con `catch(...)`:** En la función `main`, se usan bloques `try...catch(...)` para llamar a los métodos de simulación. El `catch(...)` (catch-all) se usa aquí para atrapar la excepción que fue re-lanzada, permitiendo que el programa no se termine y pueda continuar para simular el segundo escenario de error.
[⬅️ Volver al inicio](../../)

# LAB 3.4.13: Exceptions: using in program (Tower of Hanoi)

## 📝 Descripción

Este laboratorio aplica el manejo de excepciones para **reforzar la lógica y las reglas de un programa**. El escenario es una simulación del juego de las Torres de Hanoi.

El objetivo no es solo manejar errores de entrada, sino utilizar excepciones como el mecanismo principal para prevenir movimientos inválidos en el juego. Para esto, se crean **tres clases de excepción personalizadas** (`InvalidTowerException`, `InvalidMoveException`, `EmptyTowerException`) que son lanzadas por el método `moveDisk` si se viola alguna regla del juego.

-----

## ⚙️ Ejemplo de Ejecución

*El programa lee códigos de movimiento (p.ej., 13 = mover de torre 1 a 3) hasta que se introduce 0.*

**Input del Usuario:**

```
13
12
32
13
21
23
13
0
```

**Output del Programa:**

```
tower_1: empty
tower_2: empty
tower_3: 3 2 1
```

*(Nota: El input de muestra del lab `13, 12, ... 13` resuelve el puzzle. La salida muestra el estado final después de que se introduce `0`)*

-----

## 🧠 Conceptos Aplicados

  * **Excepciones para Lógica de Negocio/Juego:** Este es el concepto central. Las excepciones no solo se usan para errores del sistema (como E/S o memoria), sino para hacer cumplir las reglas de la aplicación. El método `moveDisk` usa `throw` para señalar que una regla del juego fue violada.
  * **Múltiples Clases de Excepción Personalizadas:** Se crean tres clases distintas (`InvalidTowerException`, `InvalidMoveException`, `EmptyTowerException`), todas heredando de `std::exception`. Esto permite que el código que llama distinga *por qué* falló un movimiento.
  * **Manejo de Excepciones Múltiples:** La función `main` utiliza un solo bloque `try` para la operación `game.moveDisk()`, pero lo sigue con **múltiples bloques `catch`**.
    ```cpp
    try {
        game.moveDisk(source, dest);
    }
    catch (const InvalidTowerException& e) { ... }
    catch (const InvalidMoveException& e) { ... }
    catch (const EmptyTowerException& e) { ... }
    ```
    Este patrón es fundamental en C++ y permite al programa reaccionar de forma diferente a cada tipo de error lógico.
  * **Función `moveDisk` como "Guardia":** El método `moveDisk` actúa como un "guardia" del estado del objeto. Realiza todas sus validaciones (rango de torre, torre vacía, tamaño de disco) al principio. Solo si *todas* las validaciones pasan, procede a modificar el estado del juego (mover el disco). Si alguna validación falla, lanza una excepción y el estado del juego permanece intacto.
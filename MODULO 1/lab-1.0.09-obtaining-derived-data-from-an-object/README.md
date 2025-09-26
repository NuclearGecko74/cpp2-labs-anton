[⬅️ Volver al inicio](../../)

# Laboratorio 1.0.9: Obtaining derived data from an object

## 📝 Descripción
Este laboratorio explora dos estrategias diferentes para manejar y obtener **datos derivados**: información que se calcula a partir de otros atributos de un objeto (como el `área` a partir del `lado` de un cuadrado). El objetivo es comparar un enfoque de cálculo "al momento" contra un enfoque de "evaluación perezosa" para entender el balance entre el **costo computacional** y el **uso de memoria**.

---

## ⚙️ Salida del Programa
*El programa no requiere ninguna entrada (input) por parte del usuario.*

**Output:**
```

Area = 16
Lazy Area = 36
Area = 25
Area in LazySquare updated within 'get\_area' function.
Lazy Area = 49

```

---

## 🧠 Explicación y Conceptos Aplicados
El ejercicio se implementó a través de dos clases, cada una representando una estrategia distinta para gestionar el cálculo del área.

### Estrategia 1: Cálculo Ad Hoc (`AdHocSquare`)
Este enfoque se basa en la simplicidad y el ahorro de memoria.
* **Concepto:** El valor del área **nunca se almacena** como un atributo dentro del objeto. Solo se guarda el dato fundamental (`side`).
* **Implementación:** El método `get_area()` realiza el cálculo `side * side` y devuelve el resultado **cada vez que es invocado**.
* **Ventajas:** Consume menos memoria, ya que no necesita un atributo adicional para el área.
* **Desventajas:** Puede ser ineficiente si el área se solicita muchas veces sin que el lado cambie, ya que la operación de cálculo se repite innecesariamente en cada llamada. Es como un cocinero que recalcula el costo total de una receta desde cero cada vez que alguien le pregunta, en lugar de anotarlo.

### Estrategia 2: Evaluación Perezosa o "Lazy Evaluation" (`LazySquare`)
Este enfoque prioriza la eficiencia computacional, especialmente para cálculos costosos.
* **Concepto:** El valor del área **sí se almacena** como un atributo, pero solo se recalcula cuando es estrictamente necesario.
* **Implementación:** La clase utiliza un "flag" o bandera booleana (`side_changed`).
    1.  Cuando se llama a `set_side()`, se actualiza el lado y se levanta la bandera (`side_changed = true`), marcando el valor del área almacenada como "obsoleto".
    2.  Cuando se llama a `get_area()`, primero se revisa la bandera. Si es `true`, se recalcula el área, se actualiza el valor almacenado y se baja la bandera (`side_changed = false`).
    3.  Si la bandera es `false`, simplemente se devuelve el valor del área ya almacenado, sin realizar ningún cálculo. * **Ventajas:** Es muy rápido y eficiente si el área se solicita múltiples veces, ya que el cálculo solo se realiza una vez tras un cambio.
* **Desventajas:** Consume más memoria al necesitar atributos adicionales para el área y para la bandera.

La salida del programa demuestra perfectamente este comportamiento: `LazySquare` solo imprime el mensaje de actualización la segunda vez que se pide el área, porque fue en ese momento cuando detectó el cambio y realizó el recálculo. ✅

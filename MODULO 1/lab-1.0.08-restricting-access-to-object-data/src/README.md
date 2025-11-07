[⬅️ Volver al inicio](../../../)

# Laboratorio 1.0.8: Restricting access to object data

## 📝 Descripción
El objetivo de este laboratorio era corregir los problemas de una clase `Square` inicial, implementando el principio de **encapsulamiento**. El código base permitía la modificación directa de sus atributos, lo que podía llevar a estados inconsistentes (el área no se actualizaba al cambiar el lado) o inválidos (un lado con valor negativo).

---

## ⚙️ Salida del Programa
*El programa no requiere ninguna entrada (input) por parte del usuario.*

**Output:**
```

Square: side=4 area=16
Square: side=2 area=4
Square: side=2 area=4

```

---

## 🧠 Explicación y Conceptos Aplicados
El código inicial presentaba una falla de diseño fundamental: al tener sus miembros `side` y `area` como `public`, cualquier parte del programa podía modificarlos sin control. Esto se demostraba al cambiar `s.side = 2.0`, lo que dejaba el valor de `area` desactualizado. Peor aún, permitía asignar un valor ilógico como `s.side = -33.0`.

La solución implementada resuelve estos problemas aplicando el concepto de **encapsulamiento** de la siguiente manera:

1.  **Ocultación de Datos (Data Hiding):** Los atributos `side` y `area` se declararon como **`private`**. Esto restringe el acceso directo desde fuera de la clase, protegiendo el estado interno del objeto y evitando modificaciones indeseadas. Ahora, la única forma de interactuar con los datos es a través de la interfaz pública de la clase. 
2.  **Método "Setter" con Validación:** Se creó un método público `setSide(double side)`. Este método actúa como un "guardián" de los datos:
    * **Validación:** Antes de modificar el estado del objeto, comprueba si el valor de `side` es válido (no negativo). Si el valor es inválido, la función simplemente ignora el cambio, asegurando que el objeto nunca entre en un estado ilógico.
    * **Consistencia:** Si el valor es válido, el método se encarga de actualizar **tanto** el `side` como el `area`. Esto garantiza que los datos del objeto siempre sean consistentes entre sí.

3.  **Métodos "Getter":** Para permitir que el código externo (como la función `print`) pueda leer los valores de los atributos ahora privados, se añadieron los métodos `getSide()` y `getArea()`. Estos métodos proporcionan un acceso de solo lectura controlado a los datos internos del objeto.

Al final, la tercera llamada a `print` muestra `side=2` y no `side=-33`, demostrando que la lógica de validación en el *setter* funcionó correctamente, protegiendo al objeto de datos inválidos. ✅

[⬅️ Volver al inicio](../../)

# LAB 1.2.19-21: Points in 2D

## 📝 Descripción
Este proyecto de tres partes se centra en la construcción de una pequeña biblioteca de geometría computacional. El desarrollo comienza con una clase fundamental para representar un punto en un plano 2D (`Point2D`) y luego utiliza este bloque para construir una clase más compleja (`Line2D`). El objetivo es demostrar la **composición de objetos** (una clase que contiene objetos de otra clase) y la interacción entre ellos para resolver problemas como el cálculo de la ecuación de una recta y la verificación de colinealidad.

---

## ⚙️ Ejemplo de Ejecución
*A continuación se muestra una sesión interactiva con la versión final del programa (Parte 3), que determina si tres puntos dados son colineales.*

**Input del Usuario:**
```

Enter point 1 (x1 y1): 0 0
Enter point 2 (x2 y2): 3 6
Enter point 3 (x3 y3): -2 -4

```
**Output del Programa:**
```

-----

## A line has been generated from the points: y = 2x

Enter point 3 (x3 y3):
Checking if point (-2, -4) is collinear to the line...

The point is collinear

```

---

## 🧠 Evolución del Proyecto y Conceptos Aplicados
El proyecto fue construido de manera incremental, añadiendo capas de funcionalidad en cada parte.

### Parte 1: La Clase Fundamental (`Point2D`)
Todo el sistema se basa en la clase `Point2D`, que modela un punto en el espacio bidimensional.
* **Conceptos:** Se definió la clase con sus atributos `private` `x` e `y`. Su principal funcionalidad es el método `distanceTo()`, que toma otro objeto `Point2D` y calcula la distancia euclidiana entre ellos aplicando el teorema de Pitágoras. Esta clase es el bloque de construcción elemental de todo el proyecto.

### Parte 2: Composición de Objetos con `Line2D`
Esta fase introdujo una clase de nivel superior que se "compone" de objetos de la clase base.
* **Conceptos:** Se creó la clase `Line2D`, que no almacena coordenadas primitivas, sino que contiene **dos objetos de tipo `Point2D`**. Este es un ejemplo clave del principio de **composición** (una relación "tiene un"). * **Datos Derivados:** El constructor de `Line2D` toma estos dos puntos y calcula los datos derivados que definen la recta: la **pendiente (`slope`)** y la **ordenada al origen (`y-intercept`)**, correspondientes a `m` y `b` en la ecuación `y = mx + b`.

### Parte 3: Interacción y Precisión Numérica
La fase final implementó la lógica de interacción entre la recta y un nuevo punto.
* **Conceptos:** Se añadió el método `contains(const Point2D& other)`. Este método demuestra la **interacción entre objetos** de tipos diferentes: un objeto `Line2D` determina si un objeto `Point2D` pertenece a la recta que representa.
* **Manejo de Precisión (Técnica Avanzada):** Un aspecto muy destacable de la implementación es el manejo cuidadoso de los números de punto flotante. Comparar `floats` o `doubles` directamente con `==` es propenso a errores de precisión. La solución utiliza funciones auxiliares como `approximatelyEqualAbsRel` para verificar si un punto satisface la ecuación de la recta "con una tolerancia muy pequeña". Esta es una técnica robusta y esencial en la computación científica y gráfica para evitar resultados incorrectos debidos a la naturaleza de la aritmética de punto flotante. ✅

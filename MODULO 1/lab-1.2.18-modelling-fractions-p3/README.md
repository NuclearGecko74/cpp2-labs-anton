[⬅️ Volver al inicio](../../)

# LAB 1.2.16-18: Modelling fractions

## 📝 Descripción
Este proyecto de tres partes consistió en el diseño y la implementación de una clase `Fraction` robusta en C++. El objetivo era modelar el concepto matemático de una fracción, permitiendo una representación limpia, operaciones aritméticas y comparaciones lógicas. El proyecto es un ejercicio práctico y profundo sobre la **sobrecarga de operadores**, una de las características más potentes de C++ para crear tipos de datos intuitivos y expresivos.

---

## ⚙️ Ejemplo de Ejecución
*La versión final del programa ofrece un menú para elegir entre dos modos de operación. A continuación se muestra un ejemplo de cada uno.*

### Modo 1: Operaciones Aritméticas
**Input del Usuario:**
```

Enter your choice: 1
Enter the first fraction (n/d): 3/4
Enter the second fraction (n/d): 1/3

```
**Output del Programa:**
```

3/4 + 1/3 = 13/12
3/4 - 1/3 = 5/12
3/4 \* 1/3 = 1/4
3/4 / 1/3 = 9/4

```

### Modo 2: Comparación de Fracciones
**Input del Usuario:**
```

Enter your choice: 2
Enter the first fraction (n/d): 3/4
Enter the second fraction (n/d): 1/3

```
**Output del Programa:**
```

Comparing fractions...
3/4 \> 1/3

```

---

## 🧠 Evolución del Proyecto y Conceptos Aplicados
El desarrollo de la clase `Fraction` se estructuró en tres fases progresivas.

### Parte 1: El Modelo de Datos y Representación
La base del proyecto fue crear una representación funcional de una fracción.
* **Conceptos:** Se definió la clase `Fraction` con sus atributos `private` (`numerator`, `denominator`). Se implementaron métodos para obtener diferentes representaciones (`toString`, `toDecimal`) y, de forma notable, se realizó la **sobrecarga del operador de inserción (`<<`)**. Esto permite imprimir objetos `Fraction` directamente en la consola (p. ej., `std::cout << miFraccion;`), lo cual es mucho más limpio y natural que llamar a un método `print()`.

### Parte 2: Aritmética y Simplificación
Esta fase añadió la funcionalidad matemática principal.
* **Conceptos:** El núcleo de esta parte fue la **sobrecarga de operadores aritméticos (`+`, `-`, `*`, `/`)**. Al sobrecargar estos operadores, los objetos `Fraction` pueden ser utilizados en expresiones matemáticas de la misma manera que los tipos numéricos nativos (p. ej., `frac3 = frac1 + frac2;`). Esto hace que el código que utiliza la clase sea extremadamente legible. * **Simplificación Automática:** Se implementó el **Algoritmo de Euclides** en una función auxiliar para encontrar el Máximo Común Divisor (MCD). Se añadió un método `reduce()` que utiliza este MCD para simplificar cada fracción. Al llamar a `reduce()` dentro del constructor, se garantiza que todas las fracciones se mantengan siempre en su forma más simple automáticamente.

### Parte 3: Lógica de Comparación y Estructura del Programa
La última fase completó la funcionalidad de la clase y mejoró la estructura general del programa.
* **Conceptos:** Se aplicó la **sobrecarga de operadores de comparación (`<`, `>`)**. Esto permite comparar dos objetos `Fraction` de forma intuitiva en estructuras de control (p. ej., `if (frac1 > frac2)`).
* **Mejora Estructural:** El programa `main` fue refactorizado para incluir un **menú de usuario** y se dividió la lógica en **funciones auxiliares** (`getFractions`, `compareFractions`, etc.). Esta modularización no solo hace el código más organizado y fácil de leer, sino que también representa una práctica de diseño de software mucho más robusta. ✅

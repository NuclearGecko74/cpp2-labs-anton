[⬅️ Volver al inicio](../../)

# LAB 2.2.2-4: Polimorfismo en C++

## 📝 Descripción

Este proyecto de tres partes explora el concepto fundamental de **polimorfismo** en C++. A través de tres escenarios prácticos y distintos (dibujo de figuras, lógica de un juego de damas y validación de direcciones IP), se diseña e implementa una jerarquía de clases que utiliza funciones virtuales, clases base abstractas y sobrescritura de métodos para lograr un comportamiento dinámico y flexible.

-----

## ⚙️ Ejemplo de Ejecución

*Cada parte del laboratorio tenía su propio programa y salida esperada.*

### Parte 1: Dibujo de Árboles (Salida)

```
Drawing 1: 
 /\
//\\
Drawing 2: 
 /\
/**\
Drawing 3: 
 /\
/++\
```

### Parte 2: Movimientos de Damas (Salida)

*Pruebas: Man (b1-\>c2), King (b1-\>d3), Man (b1-\>d3)*

```
true
true
false
```

### Parte 3: Validación de IP (Entrada y Salida)

**Input del Usuario:**

```
1.2.3.4
999.29.29.29
199.29.29.29
```

**Output del Programa:**

```
1.2.3.4
999.29.29.29 - Not Correct
199.29.29.29 - Correct
```

-----

## 🧠 Evolución del Proyecto y Conceptos Aplicados

El desarrollo se estructuró en tres fases para explorar diferentes facetas del polimorfismo.

### Parte 1 (2.2.2): Polimorfismo Básico con Punteros

La base del proyecto fue implementar una jerarquía de clases simple.

  * **Conceptos:** Se definió una clase base `BaseTree` con una **función virtual** `draw()`. Tres clases derivadas (`SimpleTree`, `StarTree`, `PlusTree`) heredaron y proporcionaron su propia implementación de `draw()`. El concepto clave se demostró en `main` al crear un array de **punteros a la clase base** (`BaseTree* trees[3]`). Al iterar sobre este array y llamar a `trees[i]->draw()`, el polimorfismo en tiempo de ejecución de C++ se encarga de invocar la versión correcta del método `draw()` correspondiente a la clase derivada que realmente se está apuntando.

### Parte 2 (2.2.3): Clases Abstractas y Funciones Puras

Esta fase introdujo el concepto de interfaces forzadas mediante la abstracción.

  * **Conceptos:** El escenario de las damas requería una **Clase Base Abstracta (ABC)**. La clase `Piece` se definió con una **función virtual pura** (`virtual bool check_move(...) = 0;`). Esto convierte a `Piece` en una clase abstracta que no se puede instanciar, y lo que es más importante, *obliga* a todas las clases derivadas (`Man`, `King`) a implementar su propia lógica de `check_move`. Esto garantiza una interfaz común robusta.
  * **Modernización:** El `main` se actualizó para usar **punteros inteligentes** (`std::unique_ptr<Piece>`) en lugar de punteros crudos. Esto demuestra cómo el polimorfismo funciona perfectamente con las prácticas modernas de gestión de memoria de C++, eliminando la necesidad de `delete` manuales.

### Parte 3 (2.2.4): Sobrescritura de Métodos y Extensión

La última fase se centró en cómo las clases derivadas pueden extender y reutilizar la funcionalidad de la clase base.

  * **Conceptos:** Se aplicó la **sobrescritura de métodos (overriding)**. La clase derivada `IPAddressChecked` heredó de `IPAddress` y sobrescribió el método `print()`. La parte crucial es que la nueva implementación de `print()` *reutiliza* el código de la clase base llamando explícitamente a `IPAddress::print()`. Después de ejecutar la lógica base, la clase derivada añade su propia funcionalidad (imprimir " - Correct" o " - Not Correct"). Esta es una técnica esencial de POO para extender clases sin duplicar código. ✅
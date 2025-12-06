[⬅️ Volver al inicio](../../)

# LAB 4.0.8: Operators: iostream and operators

## 📝 Descripción

Este laboratorio se centra en la **sobrecarga de operadores** para facilitar la entrada y salida de datos en clases personalizadas. El objetivo es implementar una clase `Matrix2D` que encapsule una matriz de 2x2 y permitir su manipulación directa mediante `std::cin` y `std::cout`, integrando la clase de forma natural con los flujos estándar de C++.

-----

## ⚙️ Ejemplo de Ejecución

*El programa espera 4 valores numéricos para llenar la matriz y luego la imprime con el formato especificado.*

### Input

**Input del Usuario:**

```text
3
4
5
6
```

### Output

**Output del Programa:**

```text
3 4 
5 6 
```

-----

## 🧠 Conceptos Aplicados

  * **Sobrecarga de Operadores de Flujo (`<<`, `>>`):** Se implementan funciones globales para sobrecargar los operadores de inserción (`<<`) y extracción (`>>`), permitiendo leer y escribir objetos `Matrix2D` directamente.
  * **Funciones `friend`:** Los operadores se declaran como `friend` dentro de la clase para permitirles acceso a los miembros privados (el `m_buffer`), ya que estos operadores no son métodos de la clase, sino funciones externas.
  * **Const Correctness (Corrección de Constantes):** El operador de salida (`operator<<`) recibe la matriz como `const Matrix2D&`. Esto asegura que la impresión no modifique el objeto, garantizando la integridad de los datos.
  * **`std::array` anidado:** Uso de contenedores estándar modernos (`std::array<std::array<...>>`) para gestionar la matriz 2x2 de forma segura y eficiente.
  * **Iteración por Referencia (`const auto&`):** Uso de bucles `for` basados en rango con referencias constantes para recorrer la matriz eficientemente sin realizar copias innecesarias de los datos.

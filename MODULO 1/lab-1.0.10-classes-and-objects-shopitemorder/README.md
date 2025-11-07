[⬅️ Volver al inicio](../../)

# Laboratorio 1.0.10: Classes and objects: ShopItemOrder

## 📝 Descripción
El objetivo de este laboratorio era diseñar e implementar una clase en C++ desde cero para **modelar** una entidad del mundo real: una orden de compra de un solo artículo (`ShopItemOrder`). El ejercicio requería definir sus atributos, encapsularlos y proveer una interfaz pública de métodos para interactuar con el objeto, incluyendo getters, setters y cálculo de datos derivados.

---

## ⚙️ Salida del Programa
*El programa no requiere ninguna entrada (input) por parte del usuario.*

**Output:**
```

3 x 'T-shirt mens black size M' = 70.2
2 x 'Jeans mens blue size M' = 84.4

```

---

## 🧠 Explicación y Conceptos Aplicados
Para resolver el problema, se diseñó la clase `ShopItemOrder` siguiendo los principios de la Programación Orientada a Objetos, enfocándose en el **encapsulamiento** y la robustez.

1.  **Modelado y Encapsulamiento de Datos:** La clase encapsula los tres datos fundamentales de una orden: `name` (nombre), `unitPrice` (precio unitario) y `numberOfItems` (cantidad). Al declararlos como **`private`**, se asegura que el estado interno del objeto no pueda ser modificado de forma directa o inconsistente, protegiendo la integridad de los datos. 
2.  **Interfaz Pública Controlada:** Se expuso una serie de métodos **`public`** para permitir la interacción controlada con el objeto:
    * **Constructor:** Un constructor que acepta los tres atributos permite crear objetos `ShopItemOrder` ya inicializados y en un estado válido desde el principio.
    * **Getters y Setters:** Se proveyó un conjunto completo de métodos `get` (para leer datos) y `set` (para escribirlos).
    * **Validación de Datos:** Los métodos `setUnitPrice` y `setNumberOfItems` incluyen una lógica de validación crucial: solo aceptan valores mayores que cero. Esto hace que la clase sea más robusta, ya que previene la creación de órdenes con precios o cantidades negativas, que no tendrían sentido en un escenario real.

3.  **Cálculo de Datos Derivados:** Se implementó el método `getTotalPrice()`, el cual calcula el precio total (`unitPrice * numberOfItems`) en el momento en que se le solicita (estrategia "Ad Hoc"). Para una operación tan simple y rápida, este enfoque es ideal porque no consume memoria extra para almacenar el total.

4.  **Presentación de la Información:** En lugar de un método de impresión dentro de la clase, se optó por una función externa `printOrder`. Esta función toma un objeto `ShopItemOrder` y utiliza su interfaz pública (los métodos `get`) para acceder a los datos de forma segura y presentarlos en un formato legible para el usuario, demostrando cómo el código cliente interactúa con la clase.

En resumen, la solución crea una clase autocontenida y segura que modela exitosamente una orden de compra, garantizando que sus datos siempre sean válidos y consistentes. ✅

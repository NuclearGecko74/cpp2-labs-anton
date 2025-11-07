[⬅️ Volver al inicio](../../)

# LAB 2.4.3-4: Composición de Objetos ("has-a")

## 📝 Descripción

Este proyecto de dos partes explora el segundo pilar fundamental de la Programación Orientada a Objetos: la **composición**. A diferencia de la herencia (una relación "is-a" o "es-un"), la composición modela una relación **"has-a"** o **"tiene-un"**.

El objetivo es construir objetos complejos no mediante la herencia, sino ensamblándolos a partir de otros objetos más simples. Se exploran dos escenarios:

1.  Una `Network` (Red) que **agrega** múltiples objetos `IpAddress` (Dirección IP).
2.  Un `Car` (Coche) que está **compuesto** por sus partes (`Engine`, `Wheel`, `Body`, etc.).

-----

## ⚙️ Ejemplo de Ejecución

*Cada parte del laboratorio tenía su propio programa y salida esperada.*

### Parte 1: Redes y Direcciones IP

**Input del Usuario:**

```
1.1.1.1
2.2.2.2
3.3.3.3
4.4.4.4
5.5.5.5
```

**Output del Programa:**

```
Network 1:
1.1.1.1
2.2.2.2
3.3.3.3
Network 2:
3.3.3.3
4.4.4.4
5.5.5.5
```

### Parte 2: Composición de un Coche

*(Sin input, los valores están definidos en el constructor)*

**Output del Programa:**

```
Engine: 1.0
Wheel: 16inches
Wheel: 16inches
Wheel: 16inches
Wheel: 16inches
Chassis: Normal
Light: Type 1
Light: Type 1
Light: Type 2
Light: Type 2
Light: Type 3
Light: Type 3
Light: Type 4
Light: Type 4
Light: Type 5
Light: Type 5
Body: Black
```

-----

## 🧠 Evolución del Proyecto y Conceptos Aplicados

El desarrollo se estructuró en dos fases para explorar las variantes de la relación "has-a".

### Parte 1 (2.4.3): Agregación de Objetos (Network)

Esta fase introdujo la **agregación**, una forma de composición donde los objetos contenidos pueden existir independientemente del contenedor.

  * **Conceptos:** Se crearon las clases `IpAddress` y `Network`. La clase `Network` implementa la relación "has-a" al contener un `std::vector<IpAddress>`.
  * **Implementación:** En `main`, se crean cinco objetos `IpAddress`. Notablemente, el objeto `ip3` se añade a *ambas* redes (`networkOne` y `networkTwo`). Esto demuestra la **agregación**: los objetos `IpAddress` no son "propiedad" de una red, sino que la red simplemente mantiene una colección de ellos.

### Parte 2 (2.4.4): Composición Pura (Car)

Esta fase implementó la **composición**, una forma más fuerte de "has-a" donde el ciclo de vida de las partes está ligado al del objeto contenedor.

  * **Conceptos:** Se crearon clases para las partes (`Engine`, `Wheel`, `Chassis`, `Light`, `Body`) y la clase contenedora `Car`.
  * **Implementación:** La clase `Car` *contiene* instancias de todas sus partes como miembros privados (p. ej., `Engine m_engine;`, `std::vector<Wheel> m_wheels;`). El constructor de `Car` es responsable de inicializar todas estas partes. Las partes no existen fuera del coche.
  * **Delegación de Métodos:** El concepto clave fue la **delegación**. El método `Car::print()` no imprime nada por sí mismo; en su lugar, *delega* la responsabilidad de imprimir a cada uno de sus componentes (`m_engine.print()`, `m_chassis.print()`, etc.). Esto demuestra cómo un objeto compuesto puede coordinar a sus partes para realizar una tarea. ✅
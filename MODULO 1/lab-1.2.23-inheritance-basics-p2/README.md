[⬅️ Volver al inicio](../../)

# LAB 1.2.22-23: Inheritance basics

## 📝 Descripción
Este proyecto de dos partes introduce uno de los pilares de la Programación Orientada a Objetos: la **herencia**. La primera parte se enfoca en la sintaxis fundamental y la mecánica de cómo se construyen los objetos derivados. La segunda parte aplica estos conocimientos para crear un programa práctico que modela diferentes tipos de animales de granja, demostrando cómo la herencia permite la reutilización de código y habilita el comportamiento **polimórfico**.

---

## ⚙️ Ejemplo de Ejecución
*El proyecto se desarrolló en dos fases, cada una con una salida característica.*

### Salida de la Parte 1 (Exploración de Constructores)
*Este resultado muestra el orden en que se llaman los constructores de la clase base y las clases derivadas.*
```

FarmAnimal constructor called with argument: 5
FarmAnimal constructor called with argument: 10
DummyAnimal constructor called.
FarmAnimal constructor called with argument: 42
DoublingAnimal constructor called with argument: 21
animalA consumes 5 liters of water.
What about the others?
This animal consumes 10 liters of water
This animal consumes 42 liters of water

```

### Sesión Interactiva de la Parte 2 (Aplicación Final)
**Input del Usuario:**
```

Enter animal and weight (e.g., 'cow 500'). Press Enter on an empty line to finish.
cow 500
sheep 80
horse 400

```
**Output del Programa:**
```

79

```

---

## 🧠 Evolución del Proyecto y Conceptos Aplicados
El laboratorio guió el aprendizaje desde la sintaxis básica hasta una aplicación poderosa de los conceptos de herencia.

### Parte 1: Sintaxis y Cadena de Constructores
La primera fase se centró en entender *cómo* funciona la herencia a nivel de construcción.
* **Concepto de Herencia:** Se estableció una relación "es un" donde clases como `DummyAnimal` y `DoublingAnimal` heredan de `FarmAnimal`. Esto significa que un `DoublingAnimal` **es un** `FarmAnimal` y, por lo tanto, comparte sus características y funcionalidades. * **Cadena de Constructores:** El concepto clave aquí es la **lista de inicializadores de miembros**. Cuando se crea un objeto de una clase derivada (ej. `DoublingAnimal`), su constructor tiene la responsabilidad de llamar explícitamente al constructor de su clase base (`FarmAnimal`). Esto se hace con la sintaxis `: FarmAnimal(valor)`. La salida de la Parte 1 demuestra esta "cadena", mostrando que el constructor de la base siempre se ejecuta antes de que el objeto derivado termine de construirse.

### Parte 2: Polimorfismo y Aplicación Práctica
La segunda fase utilizó la herencia para resolver un problema real, revelando su verdadero poder.
* **Reutilización de Código:** Las clases `Cow`, `Sheep` y `Horse` heredan de `FarmAnimal`. La funcionalidad común (almacenar el `water_consumption`) se define una sola vez en la clase base y es reutilizada por todas las clases derivadas. La lógica específica (cómo calcular ese consumo) se maneja en el constructor de cada animal especializado.
* **Polimorfismo:** Este es el concepto más importante de esta parte. Se creó una clase `ConsumptionAccumulator` con un método `addConsumption(const FarmAnimal& animal)`. Este método puede aceptar **cualquier objeto que herede de `FarmAnimal`** (`Cow`, `Sheep`, `Horse`, etc.). La capacidad de tratar objetos de diferentes tipos a través de una referencia o puntero a su clase base común es el **polimorfismo**. Permite que el acumulador funcione con cualquier tipo de animal sin necesidad de saber su tipo específico, lo que hace que el código sea increíblemente flexible y extensible. ✅

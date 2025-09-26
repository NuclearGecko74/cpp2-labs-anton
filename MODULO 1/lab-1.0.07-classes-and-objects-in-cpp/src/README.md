[⬅️ Volver al inicio](../../)

# Laboratorio 1.0.7: Classes and Objects in C++

## 📝 Descripción
De acuerdo con las instrucciones del laboratorio, el objetivo principal era familiarizarse con la sintaxis básica de **clases y objetos** en C++. El ejercicio consistía en tomar una clase `Person` predefinida, experimentar con ella, añadirle nuevos miembros y crear una nueva instancia para demostrar el acceso a sus atributos.

---

## ⚙️ Salida del Programa
*El programa no requiere ninguna entrada (input) por parte del usuario, ya que los datos están definidos en el código.*

**Output:**
```

Meet Harry
Harry is 23 years old. Height: 1.75 m, Weight: 70.5 kg, Student: no
Jose Carlos is 20 years old. Height: 1.80 m, Weight: 91.2 kg, Student: yes

```

---

## 🧠 Explicación y Conceptos Aplicados
El ejercicio partió de un código base que definía una clase `Person` con solo dos atributos (`name` y `age`) y una función `print` para mostrarlos.

La tarea principal, como indicaba el escenario, fue expandir esta estructura inicial. Se realizaron las siguientes modificaciones para cumplir con los objetivos:

1.  **Añadir nuevos miembros a la clase:** Se expandió la clase `Person` para incluir tres atributos adicionales: `height` (float), `weight` (float) y `bIsStudent` (bool), logrando una representación más completa de una persona.
2.  **Actualizar la función de impresión:** La función `print` fue modificada para que pudiera mostrar los nuevos atributos añadidos. Se utilizó un operador ternario para presentar el valor booleano `bIsStudent` de forma legible ("yes" o "no").
3.  **Crear un nuevo objeto:** En la función `main`, se instanció un segundo objeto de tipo `Person` llamado `chepe`. Se le asignaron valores a todos sus atributos (incluyendo los nuevos) usando el **operador punto (.)**. Finalmente, se llamó a la función `print` para mostrar los datos del nuevo objeto.

Este laboratorio sirvió para poner en práctica los objetivos de aprendizaje de manera directa:
* **Sintaxis de Clases:** Se reforzó cómo se declara una clase y sus miembros públicos.
* **Creación de Objetos:** Se demostró cómo instanciar múltiples objetos (`person` y `chepe`) a partir de una misma clase. * **Acceso a Miembros:** Se utilizó tanto el **operador punto (.)** para asignar valores a los atributos, como el **operador flecha (->)** para leerlos a través de un puntero dentro de la función `print`.

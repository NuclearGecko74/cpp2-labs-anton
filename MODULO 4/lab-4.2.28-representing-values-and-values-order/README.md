[⬅️ Volver al inicio](../../)

# LAB 4.2.28: Operators: representing values and values order

## 📝 Descripción

Este laboratorio implementa una **Máquina de Estados Finitos (FSM)** utilizando Programación Orientada a Objetos en C++. El objetivo es modelar un sistema abstracto que transita entre una serie de estados predefinidos (Inicio, Intermedios, Fin) basándose en valores numéricos de entrada. La interacción principal se realiza mediante la **sobrecarga del operador de inserción (`<<`)**, que actúa como el detonante para las transiciones de estado, simulando un flujo de control dinámico basado en reglas.

-----

## ⚙️ Ejemplo de Ejecución

*El programa comienza en el estado Start (1). Se le inyectan valores secuenciales que guían a la máquina a través de diferentes estados hasta alcanzar el estado Stop (6).*

### Input (Código en Main)

```cpp
fsm << 3;
fsm << 6;
fsm << 4;
```

### Output

**Output del Programa:**

```text
Stop state reached
States visited:
1(Start), 3, 4, 6(Stop)
```

-----

## 🧠 Conceptos Aplicados

  * **Máquina de Estados Finitos (FSM):** Implementación de un modelo computacional que consta de estados y transiciones, donde el sistema solo puede estar en un estado a la vez.
  * **Enumeraciones (`enum class`):** Uso de `enum` para definir los estados de manera robusta y legible (Start, Forward, Stop), encapsulando los valores enteros subyacentes.
  * **Sobrecarga de Operadores (`operator<<`):** Redefinición del operador de flujo para "inyectar" datos a la máquina. En lugar de métodos tradicionales como `updateState()`, se usa una sintaxis de flujo (`fsm << valor`) para provocar las transiciones.
  * **Lógica de Transición Condicional:** Aplicación de reglas lógicas (ej. si el input es `< 5` o `>= 5`) para determinar dinámicamente el siguiente estado en el grafo.
  * **Historial de Navegación:** Uso de contenedores (`std::vector`) para almacenar y rastrear la secuencia completa de estados visitados desde el inicio hasta la finalización.

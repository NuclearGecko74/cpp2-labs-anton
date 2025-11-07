[⬅️ Volver al inicio](../../)

# LAB 2.3.5-7: Interfaces, Polimorfismo y Composición

## 📝 Descripción

Este proyecto de tres partes es una inmersión profunda en los patrones de diseño de C++ y los pilares de la Programación Orientada a Objetos. El objetivo fue diseñar un sistema de validación de cadenas (`string`) flexible y extensible.

Partiendo de una **interfaz** base (una clase abstracta), el proyecto evoluciona desde la implementación de "estrategias" de validación simples hasta la creación de un validador complejo que **compone** múltiples validadores simples. Este laboratorio es un claro ejemplo de los patrones de diseño **Strategy** y **Composite**, y del principio de **Composición sobre Herencia**.

-----

## ⚙️ Ejemplo de Ejecución

*Las tres partes del laboratorio construyen el sistema progresivamente. A continuación se muestra la salida de cada fase.*

### Parte 1: Salida (Interfaz y Estrategia Simple)

*Pruebas: DummyValidator("hello"), ExactValidator("hello"), ExactValidator("secret")*

```
The string 'hello' is valid
The string 'hello' is invalid
The string 'secret' is valid
```

### Parte 2: Salida (Estrategias Múltiples)

*Pruebas: MinLength, MaxLength, y PatternValidator*

```
MinLengthValidator
The string 'hello' is invalid
The string 'welcome' is valid

MaxLengthValidator
The string 'hello' is valid
The string 'welcome' is invalid

PatternValidator
The string 'there are 2 types of sentences in the world' is valid
The string 'valid and invalid ones' is invalid
```

### Parte 3: Salida (Composición de Validadores)

*Pruebas: PasswordValidator con 5 reglas (longitud, mayúscula, minúscula, dígito, especial)*

```
The string 'short' is invalid
The string 'nouppercase1!' is invalid
The string 'NOLOWERCASE1!' is invalid
The string 'NoDigitUpper!' is invalid
The string 'NoSpecial1Upper' is invalid
The string 'ValidPass1!' is valid
```

-----

## 🧠 Evolución del Proyecto y Conceptos Aplicados

El desarrollo se estructuró en tres fases para demostrar la potencia de la abstracción.

### Parte 1 (2.3.5): Definición de la Interfaz (Strategy Pattern)

La base del proyecto fue definir el "contrato" que todos los validadores deben cumplir.

  * **Conceptos:** Se creó la clase abstracta `StringValidator`. El núcleo de esta clase es la **función virtual pura** (`virtual bool isValid(std::string input) = 0;`).
  * **Impacto:** Esto establece una **interfaz** formal. Obliga a cualquier clase que herede de `StringValidator` a implementar su propia lógica `isValid`. Este es el fundamento del **Strategy Pattern**: definimos una familia de algoritmos (validadores) y los hacemos intercambiables.
  * **Implementación:** Se crearon las primeras estrategias concretas: `DummyValidator` y `ExactValidator`.

### Parte 2 (2.3.6): Implementación de Estrategias Concretas

Esta fase demostró la flexibilidad de la interfaz al añadir reglas más complejas.

  * **Conceptos:** Se crearon nuevas clases que implementan la misma interfaz `StringValidator`: `MinLengthValidator`, `MaxLengthValidator` y el más complejo, `PatternValidator`.
  * **Impacto:** El código "cliente" (como la función `printValid`) puede usar estas nuevas clases sin necesidad de modificación alguna. No le importa *cómo* un validador funciona, solo sabe que puede llamar a `isValid()`. Esto desacopla el código de forma limpia.

### Parte 3 (2.3.7): Composición de Objetos (Composite Pattern)

Esta es la fase culminante del proyecto, donde se combinan múltiples estrategias en una sola.

  * **Conceptos:** Se aplicó el **Principio de Composición sobre Herencia**. Se creó la clase `PasswordValidator`, que a su vez implementa la interfaz `StringValidator`.
  * **Implementación:** En lugar de heredar de todas las reglas, `PasswordValidator` **contiene** un vector de punteros a otras estrategias de validación (`std::vector<std::unique_ptr<StringValidator>> m_rules;`).
  * **Impacto:** Este es el **Composite Pattern** en acción. El `PasswordValidator` *es un* `StringValidator` (interfaz), pero también *tiene* otros `StringValidator` (composición). Su propio método `isValid()` simplemente itera sobre su colección de reglas y las comprueba todas. Esto permite construir validadores complejos de forma dinámica, combinando piezas simples como bloques de Lego. ✅
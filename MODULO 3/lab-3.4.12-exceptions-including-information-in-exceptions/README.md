[⬅️ Volver al inicio](../../)

# LAB 3.4.12: Exceptions: including information in exceptions

## 📝 Descripción

Este laboratorio combina varios conceptos de manejo de excepciones en un escenario práctico. El objetivo es crear una clase `IpHeader` que, en su **constructor**, valide dos cadenas de `string` (`sourceIp` y `destinationIp`).

La clave es que el constructor debe lanzar una excepción personalizada, `IpException`, que contenga **información específica sobre cuál de las dos IP falló la validación**. Esto se logra reutilizando una única función de validación privada a la que se le pasa un parámetro extra para identificar el campo.

-----

## ⚙️ Ejemplo de Ejecución

*El programa lee dos direcciones IP por línea y las valida.*

### Input Válido

**Input del Usuario:**

```
212.112.212.11
212.112.212.12
```

**Output del Programa:**

```
Valid IP Header.
```

### Input Inválido (Fuente Inválida)

**Input del Usuario:**

```
212.112.212.333
212.112.212.33
```

**Output del Programa:**

```
Invalid IP Header - Source IP Address is invalid.
```

-----

## 🧠 Conceptos Aplicados

  * **Validación en el Constructor:** El constructor de `IpHeader` es el único responsable de asegurar la validez de los datos. Si la validación de *cualquier* IP falla, lanza una excepción, previniendo que el objeto `IpHeader` se cree en un estado inválido.
  * **Reutilización de Código de Validación:** En lugar de duplicar la lógica de validación, se crea un método privado `validateIp(const std::string& ipString, const std::string& ipType)`. Este método se llama dos veces desde el constructor.
  * **Excepciones con Información Contextual:** Este es el concepto central. El método `validateIp` toma un segundo argumento (`ipType`) que es "Source IP Address" o "Destination IP Address". Si la validación falla, este `ipType` se usa para construir el mensaje de error (`throw IpException("Invalid IP Header - " + ipType + " is invalid.");`).
  * **Manejo Detallado de Errores de String:** La función de validación es robusta. No solo usa `std::stoi` dentro de un `try...catch` para detectar caracteres no válidos, sino que también comprueba `charsProcessed` para rechazar entradas como "255a", y comprueba si hay segmentos vacíos (como en "1.2..3.4").
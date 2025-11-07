[⬅️ Volver al inicio](../../)

# LAB 3.2.17: Exceptions: checking strings

## 📝 Descripción

Este laboratorio aplica el manejo de excepciones a un escenario de análisis y validación de cadenas (`string`) más complejo. El objetivo es crear una clase `IpAddress` que sea robusta y se auto-valide en dos puntos críticos:

1.  **En el Constructor:** Al crear un objeto `IpAddress` a partir de un `std.string`, se debe realizar una validación exhaustiva de la cadena IP.
2.  **En los Métodos:** Al llamar a métodos como `printSubnet(int range)`, se deben validar los argumentos (en este caso, que `range` sea una potencia de 2 válida).

Si alguna de estas validaciones falla, se debe lanzar una excepción personalizada (`IpException`).

-----

## ⚙️ Ejemplo de Ejecución

*El programa lee la IP y el rango en un bucle. A continuación se muestran los escenarios de error.*

### Input con Rango Inválido

**Input del Usuario:**

```
212.113.212.128 6
```

**Output del Programa:**

```
Exception - invalid range.
```

### Input con IP Inválida

**Input del Usuario:**

```
212.114.212.328 4
```

**Output del Programa:**

```
Exception - Invalid IP number.
```

-----

## 🧠 Conceptos Aplicados

  * **Lanzar Excepciones en el Constructor:** Este es el concepto central. El constructor `IpAddress(const std::string& ipString)` delega la validación a un método privado `validateIpString`. Si esta validación falla (p.ej., un octeto es \> 255 como "328"), el constructor lanza una `IpException`. Esto garantiza el principio de C++ de que un objeto **nunca puede ser creado en un estado inválido**.
  * **Lanzar Excepciones en Métodos:** El método `printSubnet(int range)` también realiza validaciones. Comprueba que el `range` recibido esté en una lista predefinida de valores válidos (potencias de 2) usando `std::find`. Si no se encuentra (como el `6`), lanza una `IpException` en lugar de proceder con lógica errónea.
  * **Validación de String Robusta:** La función de validación de IP es exhaustiva. No solo usa `std::stringstream` y `std::stoi`, sino que también comprueba inteligentemente la variable `charsProcessed` de `std::stoi` para asegurarse de que no haya caracteres no numéricos (p.ej., rechaza "255a").
  * **Excepción Personalizada con Estado:** La clase `IpException` almacena un `std::string` en su constructor. Esto permite que el código que lanza la excepción (`throw IpException("Mensaje específico");`) pase un mensaje de error claro y contextual, mejorando enormemente la depuración y la retroalimentación al usuario.
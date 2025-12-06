[⬅️ Volver al inicio](../../)

# LAB 4.1.4: Enums: representing values

## 📝 Descripción

Este laboratorio se centra en el uso de **Enumeraciones (Enums)** para representar valores semánticos (como días de la semana y meses) y en la implementación de lógica matemática precisa para el cálculo de fechas. El objetivo es crear una clase `Calendar` que pueda:

  * Calcular el día de la semana para cualquier fecha dada.
  * Calcular la cantidad exacta de días transcurridos desde la época UNIX (1 de enero de 1970).
  * Manejar correctamente los años bisiestos y la validación de fechas históricas.

-----

## ⚙️ Ejemplo de Ejecución

*El programa solicita una fecha (día, mes, año) e imprime el formato largo con el día de la semana y los días transcurridos.*

### Input

**Input del Usuario:**

```text
13
3
2016
```

### Output

**Output del Programa:**

```text
13 March 2016 - Sunday - 16873 days since 1st January 1970
```

-----

## 🧠 Conceptos Aplicados

  * **Enums (Enumeraciones):** Uso de `enum` para asignar nombres legibles a valores enteros secuenciales (ej. `Thursday = 0`, `Friday`, etc.), facilitando la conversión de cálculos matemáticos a representaciones de texto.
  * **Aritmética de Fechas:** Implementación de un algoritmo para sumar días considerando la longitud variable de los meses y los años.
  * **Lógica de Años Bisiestos:** Aplicación de la regla gregoriana para determinar si un año es bisiesto: `(año % 4 == 0 y año % 100 != 0) o (año % 400 == 0)`.
  * **Operador Módulo (`%`):** Uso del módulo 7 para determinar el día de la semana basándose en un día de referencia conocido (1 de enero de 1970 fue Jueves).
  * **Validación de Excepciones:** Uso de `throw std::invalid_argument` para prevenir cálculos con fechas anteriores a la fecha de referencia (1970).

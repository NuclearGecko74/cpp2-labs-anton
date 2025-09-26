[⬅️ Volver al inicio](../../)

# Laboratorio: Sistema de Reserva de Vuelos (Partes 1-3)

## 📝 Descripción
Este proyecto fue un laboratorio iterativo dividido en tres partes, diseñado para construir un sistema de reserva de vuelos a través de la línea de comandos. El desarrollo comenzó con la creación de una clase simple para un solo vuelo, evolucionó para incorporar reglas de negocio e interacción con el usuario, y culminó en un sistema capaz de gestionar múltiples vuelos simultáneamente. El proyecto demuestra el proceso de **desarrollo orientado a objetos**, desde el modelado básico hasta la gestión de colecciones de objetos.

---

## ⚙️ Ejemplo de Ejecución
*A continuación se muestra un ejemplo de la interacción con la versión final del programa (Parte 3), que incluye todos los comandos implementados.*

**Input del Usuario:**
```

create 101 400
create 307 180
add 101 404
add 307 9
cancel 101 200
delete 101
quit

```

**Output del Programa:**
```

No flights in the system
What would you like to do?: Flight 101 : 0/400 (0%) seats reserved
What would you like to do?: Flight 307 : 0/180 (0%) seats reserved
What would you like to do?: Flight 101 : 404/400 (101%) seats reserved
What would you like to do?: Flight 307 : 9/180 (5%) seats reserved
What would you like to do?: Flight 101 : 204/400 (51%) seats reserved
What would you like to do?: Flight 101 deleted successfully.
What would you like to do?:

```

---

## 🧠 Evolución del Proyecto y Conceptos Aplicados
El desarrollo del sistema se realizó en tres fases incrementales.

### Parte 1: Creación de la Clase Base (`FlightBooking`)
La primera fase se centró en establecer el modelo de datos fundamental.
* **Objetivo:** Modelar un único vuelo, encapsulando su información esencial.
* **Implementación:** Se creó la clase `FlightBooking` con atributos `private` para `id`, `capacity`, y `reserved`, demostrando el **encapsulamiento**. Se implementó un constructor para inicializar el objeto y un método `printStatus` para mostrar un reporte, el cual calculaba el porcentaje de ocupación como un **dato derivado**.

### Parte 2: Lógica de Negocio e Interacción
La segunda fase introdujo reglas operativas y permitió la interacción del usuario.
* **Objetivo:** Añadir lógica de negocio y un medio para modificar el estado del vuelo.
* **Implementación:** Se mejoró el constructor y se añadieron métodos (`reserveSeats`, `cancelReservations`) con **validación de datos**. Estas reglas prevenían reservas negativas, cancelaciones excesivas y limitaban el "overbooking" a un máximo del 105% de la capacidad. El `main` fue modificado para incluir un **bucle de aplicación** que procesaba comandos simples del usuario (`add`, `cancel`, `quit`), transformando el programa en una herramienta interactiva. 
### Parte 3: Gestión de Múltiples Vuelos
La fase final escaló el sistema para manejar una flota de vuelos.
* **Objetivo:** Expandir la aplicación de un solo objeto a una colección de objetos.
* **Implementación:** El `main` fue completamente rediseñado para gestionar un `std::array` de objetos `FlightBooking`. Esto requirió una lógica más compleja para:
    * **Gestión de Colecciones:** Añadir y eliminar vuelos del array.
    * **Búsqueda de Objetos:** Iterar sobre el array para encontrar un vuelo por su `id` antes de realizar una operación.
    * **Interfaz de Comandos (CLI) Avanzada:** Se expandió el set de comandos (`create`, `delete`, `add`, `cancel`) para operar sobre vuelos específicos, simulando un sistema de gestión real.

En conclusión, este proyecto fue un ejercicio práctico sobre el crecimiento de una aplicación, comenzando con un objeto de datos simple y terminando con un pequeño sistema interactivo que gestiona el ciclo de vida y estado de múltiples objetos. ✅

[⬅️ Volver al inicio](../../)

# LAB 1.2.15: Gym membership management system

## 📝 Descripción
Este proyecto consiste en construir desde cero una aplicación de línea de comandos para gestionar las suscripciones de los miembros de un gimnasio. Basándose en conceptos de laboratorios anteriores, el programa modela una entidad del mundo real (`GymMembership`), aplica reglas de negocio mediante la validación de datos y gestiona una colección de múltiples objetos. El resultado es un sistema interactivo para crear, actualizar y eliminar los registros de los miembros.

---

## ⚙️ Ejemplo de Ejecución
*A continuación se muestra un ejemplo de una sesión interactiva con el programa, basado en los datos de muestra del laboratorio.*

**Programa Output & User Input:**

```
No members in the system
Enter a command: create 7 John Doe
Success! Member created: Member 7 : John Doe, subscription valid for 0 months

Current members:
Member 7 : John Doe, subscription valid for 0 months
Enter a command: create 8 Jane Doe
Success! Member created: Member 8 : Jane Doe, subscription valid for 0 months

Current members:
Member 7 : John Doe, subscription valid for 0 months
Member 8 : Jane Doe, subscription valid for 0 months
Enter a command: extend 7 6
Subscription updated for member 7: Member 7 : John Doe, subscription valid for 6 months

Current members:
Member 7 : John Doe, subscription valid for 6 months
Member 8 : Jane Doe, subscription valid for 0 months
Enter a command: extend 8 12
Subscription updated for member 8: Member 8 : Jane Doe, subscription valid for 12 months

Current members:
Member 7 : John Doe, subscription valid for 6 months
Member 8 : Jane Doe, subscription valid for 12 months
Enter a command: cancel 8
Subscription canceled for member 8: Member 8 : Jane Doe, subscription valid for 0 months

Current members:
Member 7 : John Doe, subscription valid for 6 months
Member 8 : Jane Doe, subscription valid for 0 months
Enter a command: delete 7
Member 7 has been deleted.

Current members:
Member 8 : Jane Doe, subscription valid for 0 months
Enter a command: quit
Exiting the program. Goodbye!

```
---

## 🧠 Explicación y Conceptos Aplicados
Este programa integra todos los conceptos clave de POO aprendidos hasta ahora en una sola aplicación funcional.

### Diseño de la Clase (`GymMembership`)
La clase `GymMembership` actúa como el plano para cada registro de miembro. Utiliza correctamente el **encapsulamiento** al mantener sus datos principales (`id`, `name`, `subscriptionMonths`) como **`private`**. Todas las interacciones se manejan a través de una interfaz **`public`** de métodos:
* `extendSubscription(months)`: Este método incluye **validación de datos** para rechazar números no positivos, asegurando que el estado del objeto se mantenga lógico.
* `cancelSubscription()`: Un método simple para reiniciar la suscripción, aplicando una regla de negocio.
* `printStatus()`: Proporciona una forma consistente de mostrar la información del objeto. 

[Image of a personal ID card layout]


### Gestión de la Colección
El sistema utiliza un `std::array` para almacenar la colección de objetos `GymMembership`. Esta elección impone directamente la restricción de un máximo de 10 miembros y proporciona un almacenamiento de memoria contiguo y eficiente. Un contador (`numMembers`) realiza un seguimiento del número actual de miembros activos en el array.

### Motor de Comandos y Experiencia de Usuario
La función `main` contiene la lógica central de la aplicación: un bucle de procesamiento de comandos que sirve como motor. Para cada comando:
1.  **Análisis (Parsing):** El programa lee el comando del usuario (p. ej., `create`, `extend`).
2.  **Búsqueda:** Para los comandos que modifican miembros existentes, una función de búsqueda (`findMemberIndex`) se utiliza para localizar el objeto correcto en el array por su ID único. Este es un paso crítico para la integridad de los datos.
3.  **Ejecución:** Se llama al método apropiado en el objeto `GymMembership` (p. ej., `members[index].extendSubscription(months)`).

Notablemente, la implementación va más allá de los requisitos básicos del laboratorio al proporcionar retroalimentación clara y amigable para el usuario, tanto para operaciones exitosas como para errores (p. ej., "Miembro no encontrado", "ID ya existe"). La adición de un comando `help` mejora aún más la usabilidad, haciendo que el programa final sea robusto y fácil de navegar. ✅

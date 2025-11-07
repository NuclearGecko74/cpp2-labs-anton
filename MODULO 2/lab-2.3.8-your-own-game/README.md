[⬅️ Volver al inicio](../../)

# LAB 2.3.8: Tu Propio Juego - Blackjack

## 📝 Descripción

Este laboratorio fue una tarea de formato libre para diseñar e implementar un juego desde cero. Se eligió el **Blackjack**, un clásico juego de cartas. El proyecto requería modelar todas las entidades del juego (cartas, mazos, manos, jugadores) utilizando los principios de la Programación Orientada a Objetos (POO) en C++.

El resultado es una aplicación de consola interactiva y jugable que demuestra cómo la **composición** (un juego *tiene-una* baraja, un jugador *tiene-una* mano) y el **polimorfismo** (una `PlayerHand` y una `DealerHand` *son-un* tipo de `Hand`) pueden usarse juntos para crear un sistema lógico, mantenible y robusto.

-----

## ⚙️ Ejemplo de Ejecución

*El juego es interactivo. El usuario juega contra la casa (Dealer) e introduce sus decisiones por consola. A continuación se muestra un flujo de juego típico.*

**Inicio de Partida:**

```
--- NEW GAME: BLACKJACK ---
-------------------------
DEALER'S HAND:
[?] [7♦]   Total: ?

PLAYER'S HAND:
[5♣] [4♥]  Total: 9
-------------------------
```

**Turno del Jugador (Input 'h'):**

```
Hit (h) or Stand (s)? h

-------------------------
DEALER'S HAND:
[?] [7♦]   Total: ?

PLAYER'S HAND:
[5♣] [4♥] [J♠]  Total: 19
-------------------------
```

**Turno del Jugador (Input 's') y Turno del Dealer:**

```
Hit (h) or Stand (s)? s

DEALER'S TURN:
-------------------------
DEALER'S HAND:
[K♣] [7♦]  Total: 17

PLAYER'S HAND:
[5♣] [4♥] [J♠]  Total: 19
-------------------------
Dealer stands.
```

**Resultados y Fin:**

```
--- FINAL RESULTS ---
Dealer: 17
Player: 19
You win!

Play again (y/n)? n
Thanks for playing!
```

-----

## 🧠 Diseño y Conceptos Aplicados

El diseño del juego se centra en una clara separación de responsabilidades, utilizando un fuerte modelo de POO.

  * **`enum class`:** Se utilizan enumeraciones con tipo (`Suit`, `Rank`) para modelar los palos y rangos de las cartas de forma segura y expresiva, evitando el uso de "números mágicos" o `char`/`int` simples.

  * **Composición ("has-a"):** Este es el principio de diseño central del proyecto.

      * La clase `BlackjackGame` **tiene-un** `Deck`, una `PlayerHand` y una `DealerHand`.
      * La clase `Deck` **tiene-una** colección (`std::vector`) de `Card`.
      * Las clases `Hand` **tienen-una** colección (`std::vector`) de `Card`.
      * Esto demuestra el principio de **Composición sobre Herencia**: el juego se *compone* de sus partes (Baraja, Manos), en lugar de heredar de ellas.

  * **Polimorfismo ("is-a"):** El segundo pilar clave del diseño.

      * Se crea una clase base abstracta `Hand` que define una interfaz común, incluyendo una **función virtual pura** (`virtual void print() const = 0;`).
      * Las clases `PlayerHand` y `DealerHand` heredan de `Hand` (una `PlayerHand` *es-una* `Hand`) y **sobrescriben** (`override`) el método `print()` con su comportamiento específico.
      * Notablemente, `DealerHand::print()` está sobrecargado (`print(bool showFirstCard)`) para manejar la lógica de ocultar la primera carta, demostrando una especialización de la clase derivada mientras sigue cumpliendo el contrato de la interfaz.

  * **Gestión de Estado y Lógica:** La clase `BlackjackGame` actúa como el "motor" del juego, orquestando la lógica principal: baraja el `Deck`, reparte cartas a las `Hand`, maneja el `playerTurn()` (con validación de input `h`/`s`), el `dealerTurn()` (con la regla de "plantarse en 17") y finalmente compara los totales para determinar el ganador. ✅
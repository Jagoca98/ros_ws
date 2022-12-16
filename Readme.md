# 🤖 Interaccion 🤖

Welcome to the Interaccion ROS project! 🎉

This project consists of several ROS nodes that allow you to input and display information about a user, including their name, age, language skills, and current emotional state. The nodes also provide a way to specify the user's position in 3D space and perform basic mathematical operations on their age.


----

## 📦 Nodes 📦

Here is a brief overview of the different nodes in the project:

### 🗣 informacion_personal_nodo 🗣

This node asks the user to input their name, age, and languages spoken using the keyboard. The information is stored in a message called `inf_personal_usuario.msg`, which contains the following fields:

- `nombre` (string): the user's name
- `edad` (int): the user's age
- `idiomas` (array of strings): the languages spoken by the user

The message is then published on the `/inf_pers_topic` topic.

### 😄 emocion_usuario_nodo 😄

This node asks the user to input their current emotional state using the keyboard. The emotional state is a string and is published on the `/emocion_topic` topic.

### 📍 Posicion_node 📍

This node asks the user to input their position in 3D space using the keyboard. The position is stored in a message called `pos_usuario.msg`, which contains the following fields:

- `x` (int): the X position of the user
- `y` (int): the Y position of the user
- `z` (int): the Z position of the user

The message is then published on the `/pos_usuario_topic` topic.

### 📦 empaquetador_node 📦

This node combines the information received from the `/inf_pers_topic`, `/emocion_topic`, and `/pos_usuario_topic` topics into a single message called `usuario.msg`. The `usuario.msg` message has the following fields:

- `pos_usuario.msg`: a message containing the user's position
- `std_msgs/String`: the user's current emotional state
- `inf_personal_usuario.msg`: a message containing the user's name, age, and language skills

The combined message is then published on the `/user_topic` topic.

### 💬 dialogo_nodo 💬

This node displays the message received from the `empaquetador_node` on the terminal. It subscribes to the `/user_topic` topic and also calls a service called `multiplicador.srv` with the user's age as input. When it publishes its first message on the `/user_topic` topic, it sends a message on the `/start_topic` topic, and when it receives subsequent messages on the `/user_topic` topic, it sends a message on the `/reset_topic` topic. In addition, the node subscribes to the `/still_alive` topic and displays the message "the clock is still alive" on the terminal. It also has a text-to-speech (TTS) function that synthesizes everything that is published on the terminal.

### 🕰 reloj_nodo 🕰

This node is activated by a message sent by the `dialogo_nodo` called `/start_topic`. This message is sent when the `dialogo_nodo` receives information from the `empaquetador_node` and the `matematico_node`. The first time it sends a message on the `/start_topic` topic, and subsequent times it sends a message on the `/reset_topic` topic.

When the `reloj_nodo` receives the start message, it begins displaying the current time (in both UTC and local formats) on the screen at a rate of 3 times per second. It also displays the number of seconds elapsed since the current instant until the last `/start` or `/reset` message was received.

The `reloj_nodo` also has a Timer that expires every minute. Once the Timer expires, the node sends a message on the `/still_alive` topic and resets the Timer.

----

## 🏹 Services 🏹

The Interaccion project also includes the following service:

### 💻 matematico_node 💻

This node provides a service called `multiplicador.srv` that takes an integer as input and returns the result of multiplying it by 2.

----
## 📜 Messages 📜

The Interaccion project uses the following messages:

### `inf_personal_usuario.msg`

This message contains the user's name, age, and language skills. It has the following fields:

- `nombre` (string): the user's name
- `edad` (int): the user's age
- `idiomas` (array of strings): the languages spoken by the user

### `pos_usuario.msg`

This message contains the user's position in 3D space. It has the following fields:

- `x` (int): the X position of the user
- `y` (int): the Y position of the user
- `z` (int): the Z position of the user


----

## 🚀 Launch Files 🚀

The Interaccion project includes the following launch file:

### `interaccion.launch`

This launch file starts all of the nodes in the Interaccion project. To start the nodes, use the following command:

```bash
roslaunch interaccion interaccion.launch


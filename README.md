# 🏎️ Car Dodging Game (C++ Console)

A simple yet entertaining console-based game written in C++ using Windows-specific libraries. The objective is to control your car and dodge the enemy cars falling from the top of the screen. Rack up your score as long as you survive!

---

## 🔍 Overview

In this classic car dodging game, you play as a car moving left or right to avoid oncoming vehicles. The game is rendered entirely in the console using ASCII art and the Windows API.

---

## 🎯 Gameplay Features

* ⬅️ **Move Left:** Press `A`
* ➡️ **Move Right:** Press `D`
* ⬆️ **Increase Speed:** Press `I`
* ⬇️ **Decrease Speed:** Press `K`
* ❌ **Exit Game:** Press `ESC`
* ⚔️ **Collision Detection:** Ends game if you hit an enemy car
* ✅ **Score Tracking:** Increases as you successfully dodge cars

---

## 📚 How It Works

* **Enemy Cars:** Randomly generated positions and fall from the top
* **Player Car:** Controlled by the player from a fixed bottom position
* **Game Loop:** Continuously checks for input, moves cars, detects collisions
* **Graphics:** Rendered using ASCII art and positioned with the Windows console cursor

---

## 🚀 Getting Started

### Prerequisites

* Windows OS
* A C++ compiler (like MinGW or Visual Studio)

### Compilation (Using g++)

```bash
g++ -o CarDodger main.cpp
```

### Running the Game

```bash
./CarDodger
```

---

## 🌐 Project Structure

```bash
.
├── main.cpp        # Game source code
├── README.md       # Game documentation
```

---

## 📅 License

This project is licensed under the MIT License. Feel free to use, modify, and distribute!

---

## 🚀 Future Improvements (Suggestions)

* Add high score tracking
* Implement difficulty levels
* Add sound effects (using WinMM or external libs)
* Support for more car skins or themes

---

## 🙌 Acknowledgments

Created for fun and educational purposes to demonstrate real-time game logic in console applications using C++.

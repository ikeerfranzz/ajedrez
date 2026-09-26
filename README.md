
# ♟️ Ajedrez (Console Chess Engine)

<p>
  <img alt="Language" src="https://img.shields.io/badge/C%2B%2B-00599C?logo=cplusplus&logoColor=white">
  <img alt="Platform" src="https://img.shields.io/badge/Platform-Windows%20Console-lightgrey">
  <img alt="Status" src="https://img.shields.io/badge/Status-In%20Development-orange">
</p>

A two-player chess game implemented from scratch in **C++**, running entirely in the console. No engine, no external chess libraries — every piece's legal-move logic, turn handling, and check detection is hand-written and driven by simple text input.

This repository was built collaboratively with a course partner (hence the project name **Davoid**). See [My Contribution](#-my-contribution) for the parts I focused on.

---

## 📋 Table of Contents

- [Gameplay](#-gameplay)
- [Features](#-features)
- [Tech Stack](#-tech-stack)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [How to Play](#-how-to-play)
- [Known Limitations](#-known-limitations)
- [My Contribution](#-my-contribution)
- [Status & License](#-status--license)

---

## 🎮 Gameplay

- **Standard 8×8 board**, rendered as text, with rank/file numbers printed along the edges for easy coordinate input.
- **Full piece set** — pawn, rook, knight, bishop, queen, and king, each with its own legal-move rules (including pawn double-step, diagonal captures, and promotion to queen).
- **Turn-based play** — the game alternates between White and Black, rejecting any move made with the wrong color's piece.
- **Check detection** — after every move, the board is scanned to determine whether either king is currently in check, with a message printed to the console.
- **Win condition** — the game ends when a king is captured, declaring the opposing side the winner.

## ✨ Features

- Move validation per piece type: straight-line path checking for rooks/bishops/queens (blocked by any piece in the way), L-shaped knight moves, single-square king moves, and full pawn rules (forward move, initial double move, diagonal capture, promotion)
- Capture logic that respects piece color (a piece can't capture its own side)
- A single `enJaque` (check) routine that generalizes attack-pattern detection across pawns, knights, rooks/queens (orthogonal), and bishops/queens (diagonal)
- Simple coordinate-based input (row/column in, row/column out) instead of algebraic notation, keeping the console UI minimal

## 🛠️ Tech Stack

| Category | Technology |
|---|---|
| Language | C++ |
| Build System | Visual Studio (`.sln` / `.vcxproj`) |
| I/O | Standard console I/O (`iostream`), `system("cls")` for screen refresh |

## 📁 Project Structure

```
ajedrez/
├── Ajedrez-Davoid.sln              # Visual Studio solution
└── Ajedrez-Davoid/
    ├── Ajedrez-Davoid.cpp          # Entry point: board setup, game loop, turn/check/win handling
    ├── fichas.cpp                  # Per-piece move logic + check detection (moverPeon, moverTorre, ...)
    ├── Func.h                      # Shared declarations (board size, function prototypes)
    └── leeme.txt                   # Original dev notes between collaborators
```

## 🚀 Getting Started

### Prerequisites

- Windows with **Visual Studio** (2019 or later recommended) and the "Desktop development with C++" workload

### Build & Run

1. Clone the repository:
   ```bash
   git clone https://github.com/ikeerfranzz/ajedrez.git
   ```
2. Open `Ajedrez-Davoid.sln` in Visual Studio
3. Build and run (`F5` / `Ctrl+F5`)

## 🕹️ How to Play

The game prompts for coordinates using **1-indexed row/column** input, board displayed with row 8 (Black's back rank) at the top:

```
Turno BLANCAS
Fila origen: 2      → row the piece is currently on
Columna origen: 5   → column the piece is currently on
Fila destino: 4     → row to move it to
Columna destino: 5  → column to move it to
```

- Uppercase letters = White pieces, lowercase = Black pieces
- `T`/`t` = Rook, `H`/`h` = Knight, `B`/`b` = Bishop, `Q`/`q` = Queen, `K`/`k` = King, `P`/`p` = Pawn
- `*` = empty square

## ⚠️ Known Limitations

This is a course prototype focused on core move validation rather than full tournament rules. Not (yet) implemented:

- Castling and en passant
- Checkmate/stalemate detection (the game currently ends on king capture, not checkmate)
- Preventing a move that would leave your own king in check

## 👨‍💻 My Contribution

I (**Iker Franzoni**) refactored the initial single-block prototype into a function-based architecture (`Func.h` + `fichas.cpp`) so the logic for each piece could be developed and changed independently, and implemented/iterated on the piece-movement rules and the check-detection routine (`enJaque`, built with some AI-assisted logic for the attack-pattern scanning, as noted in-code).

## 📄 Status & License

This project is a **course exercise / work in progress**, not a commercial release. It is shared privately as a portfolio piece; no open-source license is granted. Please reach out before reusing any part of this code.

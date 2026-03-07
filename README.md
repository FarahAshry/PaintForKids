# 🎨 Paint for Kids

A C++ graphical drawing application built for the **Programming Techniques (CMPS102)** course — Cairo University, Faculty of Engineering, Spring 2025.

Kids can draw colorful shapes, edit them, and play shape-recognition mini-games — all through a mouse-driven GUI window.

> Built on a partial OOP framework provided by the course, which we extended and completed.

---

## 🖼️ Application Preview

The window is split into three areas:

```
┌──────────────────────────────────────┐
│              Toolbar                 │  ← Click icons to choose actions
├──────────────────────────────────────┤
│                                      │
│           Drawing Area               │  ← Figures appear here
│                                      │
├──────────────────────────────────────┤
│              Status Bar              │  ← Messages & figure info
└──────────────────────────────────────┘
```

---

## ✅ What's Implemented

### 🖊️ Draw Mode

| Feature | Who |
|---|---|
| Add Rectangle, Square, Triangle, Hexagon, Circle | Maya |
| Select (single & multi-select, highlight) | Maya |
| Save Graph to file | Maya |
| Copy Figure | Dai Khaled |
| Cut Figure (grays out until pasted) | Dai Khaled |
| Paste Figure | Dai Khaled |
| Load Graph from file | Farah |
| Matching Pairs | Farah |
| Missing Shapes | Farah |
| Swap two figures' positions | Nada |
| Delete selected figure(s) | Nada |
| Clear All | Nada |
| Switch to Play / Draw Mode | Nada |
| Exit | Nada |



## 🏗️ Architecture

This project follows a strict OOP design enforced by the course:

```
ApplicationManager          ← The maestro. Only class that touches FigList directly.
├── Input                   ← ALL user input goes through here (mouse clicks)
├── Output                  ← ALL GUI output goes through here (drawing, messages)
│
├── CFigure  (abstract)     ← Base for all shapes
│   ├── CRectangle
│   ├── CSquare
│   ├── CTriangle
│   ├── CHexagon
│   └── CCircle
│
└── Action   (abstract)     ← Base for all operations
    ├── AddRectAction / AddSqrAction / AddTriAction / AddHexAction / AddCircAction
    ├── Select / Delete / ClearAll / Swap / Rotate
    ├── COPY / CUT / PASTE
    ├── SaveAction / LoadAction
    ├── SwitchToPlay / SwitchToDraw
    └── Matching / Missing
```

**Every user action follows 4 steps:**
1. `Input` detects a click → returns an `ActionType` enum value
2. `ApplicationManager::ExecuteAction()` creates the matching `Action` object
3. `Action::Execute()` reads parameters and does the work
4. `ApplicationManager::UpdateInterface()` redraws everything

The design enforces that each class only does **its own job** — `Output` draws, `Input` reads, figures save themselves, and `ApplicationManager` only delegates.

---

## 💾 Save File Format

```
<total_figure_count>
<TYPE> <ID> <coordinates...> <draw_color> <fill_color | NO_FILL>
```

Example:
```
3
RECT 1 100 200 17 30 BLUE NO_FILL
CIRC 2 300 250 50 RED GREEN
TRI 3 10 20 70 30 220 190 BLACK YELLOW
```

Shape type tokens: `RECT`, `SQR`, `TRI`, `HEX`, `CIRC`

---

## 🛠️ Tech Stack

- **Language:** C++
- **Graphics Library:** CMU Graphics (provided by course — Windows only)
- **IDE:** Visual Studio
- **Platform:** Windows

---

## 🚀 Getting Started

```bash
git clone https://github.com/your-username/paint-for-kids.git
```

Then open `PT-Project.sln` in Visual Studio and build.

> ⚠️ The CMU Graphics Library is Windows-specific. The project won't run on macOS or Linux.

---

## 👥 Team

| Member | Features |
|---|---|
| **Maya Moatasem** | Add Figure, Select, Save Graph |
| **Dai Khaled** | Copy, Cut, Paste |
| **Farah Ashry** | Load Graph, Matching Pairs, Missing Shapes |
| **Nada A. AbdelHalim** | Swap, Delete, Clear All, Switch to Play/Draw, Exit |

---

## 📚 Course Info

**Programming Techniques — CMPS102**  
Cairo University · Faculty of Engineering · Spring 2025  
Phase 1 (25%): Input/Output classes · Phase 2 (75%): Full application

# Assignment 1 — Bit Manipulation Tasks

All 15 tasks were merged from separate `Task_1/` .. `Task_15/` folders into
a single, professionally organized 3-file project. Behavior is 100%
identical to the original programs (verified against the original code).

## Structure

| File      | Purpose                                                              |
|-----------|-----------------------------------------------------------------------|
| `file.h`  | Declares all 15 task functions (the shared interface).               |
| `file.c`  | Implements the logic for all 15 tasks.                                |
| `main.c`  | Entry point — shows a menu and calls the chosen task function.        |

## Build & Run

```bash
gcc file.c main.c -o app
./app
```

On Windows (VS Code), use the provided build task in `.vscode/tasks.json`
(Ctrl+Shift+B), which produces `app.exe`.

## Usage

Running the program shows a menu (1–15) to pick any task, or `0` to exit.
Each option behaves exactly like the original standalone Task_X program did.

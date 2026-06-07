# Linux + CMake + GDB Quick Reference

## Navigation

Show current directory:

```bash
pwd
```

List files:

```bash
ls
```

List recursively:

```bash
ls -R
```

Enter directory:

```bash
cd folder_name
```

Go up one level:

```bash
cd ..
```

Go to home directory:

```bash
cd ~
```

---

## File Operations

Create directory:

```bash
mkdir my_project
```

Create nested directories:

```bash
mkdir -p src inc build
```

Create/edit file:

```bash
nano main.c
```

Move file:

```bash
mv source destination
```

Rename file:

```bash
mv old_name new_name
```

Copy file:

```bash
cp source destination
```

Delete file:

```bash
rm file_name
```

Delete empty directory:

```bash
rmdir directory_name
```

Delete directory and contents:

```bash
rm -r directory_name
```

---

## Project Structure

Typical project:

```text
project/
│
├── CMakeLists.txt
├── src/
│   ├── main.c
│   └── module.c
│
├── inc/
│   └── module.h
│
└── build/
```

---

## GCC

Compile manually:

```bash
gcc src/main.c src/module.c -Iinc -o hello
```

Run:

```bash
./hello
```

---

## CMake

Create build files:

```bash
cmake -S . -B build
```

Meaning:

```text
Source directory = .
Build directory  = build
```

Build project:

```bash
cmake --build build
```

Run executable:

```bash
./build/robot
```

Delete build directory and rebuild:

```bash
rm -r build

cmake -S . -B build

cmake --build build
```

---

## Typical CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.10)

project(RobotProject)

include_directories(inc)

add_executable(
    robot
    src/main.c
    src/battery.c
    src/motor.c
)
```

Debug build:

```cmake
set(CMAKE_BUILD_TYPE Debug)
```

---

## Git

Check status:

```bash
git status
```

Add all files:

```bash
git add .
```

Commit:

```bash
git commit -m "message"
```

Push:

```bash
git push origin main
```

View commit history:

```bash
git log
```

---

## GDB

Start debugger:

```bash
gdb build/robot
```

Set breakpoint at main:

```gdb
break main
```

Run program:

```gdb
run
```

Execute one line:

```gdb
next
```

Show variable value:

```gdb
print variable_name
```

Example:

```gdb
print battery
```

Continue execution:

```gdb
continue
```

Quit debugger:

```gdb
quit
```

or

```gdb
q
```

---

## Development Workflow

```text
Edit Code
    ↓
cmake --build build
    ↓
./build/robot
    ↓
Fix Errors
    ↓
Repeat
```

For debugging:

```text
Edit Code
    ↓
cmake --build build
    ↓
gdb build/robot
    ↓
break main
    ↓
run
    ↓
next
    ↓
print variable
```


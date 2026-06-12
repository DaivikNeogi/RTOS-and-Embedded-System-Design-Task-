# Module 01 - Debugging and File Management

## Purpose

Writing software is only part of software development.

Real engineering work often involves understanding why software is not behaving as expected.

This module introduces the tools and techniques used to investigate software behavior and identify bugs.

The goal is not to memorize debugger commands.

The goal is to learn how professional engineers observe, inspect, and reason about software execution.

By the end of this module, learners should be able to:

* Understand the purpose of debugging
* Use GDB to inspect a running program
* Set breakpoints
* Step through program execution
* Inspect variables and program state
* Understand the role of debugging in software development
* Navigate project files efficiently
* Search source code using Linux command-line tools

---

## Why Are We Doing This?

Many beginners write code and immediately assume:

```text
Code compiled successfully
=
Code works correctly
```

In practice, most software development time is spent investigating:

```text
Unexpected behavior
Crashes
Incorrect output
Logic errors
Integration problems
```

Professional engineers rarely solve these problems by guessing.

Instead they use tools that allow them to inspect the program while it is running.

Debugging is the process of understanding:

```text
What the software is doing
Why it is doing it
What it should be doing instead
```

---

## The Debugging Workflow

Throughout this curriculum, debugging will follow a consistent process:

```text
Observe Problem
        ↓
Reproduce Problem
        ↓
Inspect Program State
        ↓
Identify Root Cause
        ↓
Implement Fix
        ↓
Verify Fix
```

The goal is to understand the root cause rather than simply making symptoms disappear.

---

## Tools Introduced

### GDB

GNU Debugger.

Allows inspection of a program while it is running.

Capabilities include:

* Breakpoints
* Single-step execution
* Variable inspection
* Call stack inspection
* Program state analysis

GDB is one of the most widely used debugging tools in software and embedded development.

---

### Linux Search Tools

Large projects may contain hundreds or thousands of files.

Engineers must be able to locate:

* Functions
* Variables
* Source files
* Configuration files

Efficient searching becomes increasingly important as project size grows.

Examples include:

```text
grep
find
```

These tools will be used extensively in future modules when exploring FreeRTOS and other large codebases.

---

### File Navigation

Software projects are collections of files and directories.

Engineers must be comfortable:

* Navigating directory structures
* Organizing project files
* Locating source code
* Understanding project layouts

These skills become critical when working with large frameworks and RTOS source trees.

---

## Learning Outcomes

After completing this module, learners should be able to:

* Use GDB to investigate program behavior
* Set and remove breakpoints
* Execute programs step-by-step
* Inspect variables during execution
* View function call stacks
* Locate files in a project
* Search source code efficiently
* Develop a systematic debugging process

---

## Why This Matters for Embedded Systems

Debugging becomes significantly more difficult once software runs on embedded hardware.

Unlike PC applications, embedded systems may have:

```text
Limited visibility
No display
No keyboard
No operating system
Timing-sensitive behavior
Hardware interactions
```

Learning debugging techniques on a PC provides a safe environment before moving to microcontrollers and RTOS-based systems.



Every future project will eventually require debugging.

The ability to systematically investigate software behavior is one of the most valuable engineering skills to develop early.

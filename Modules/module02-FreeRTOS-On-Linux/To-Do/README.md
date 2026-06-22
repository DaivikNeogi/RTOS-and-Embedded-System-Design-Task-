# Module 02 - FreeRTOS Tasks and Safety Monitoring

## Lesson Objectives

This module builds upon concepts introduced in Module 01.

### Concepts from Previous Module

* Abstraction
* Layered Software Architecture
* Separation of Application and Hardware Layers

### New Concepts

* FreeRTOS Tasks
* Task Priorities
* Task Scheduling
* Blocking with `vTaskDelay()`
* Safety Monitoring

---

## Objective

The objective of this exercise is to run a FreeRTOS application using the provided files and implement the required functionality using FreeRTOS tasks.

You must build upon the architecture created in the previous module.

---

## Problem Statement

In Module 01, you created software modules that allowed the application layer to access hardware functionality without directly interacting with the MCU layer.

The system currently provides:

* Sensor readings
* Battery monitoring

In many embedded systems, monitoring data is not sufficient. The software must also continuously check for safety-related conditions and respond appropriately.

Your task is to convert the existing application into a FreeRTOS-based application and introduce a new safety monitoring task.

---

## Existing Modules

You should reuse the modules created in the previous exercise.

Examples:

```text
sensor.c
sensor.h

battery.c
battery.h
```

These modules should continue to be used by the application tasks.

---

## New Requirement

Create a new module:

```text
emergency.c
emergency.h
```

This module will be responsible for checking the system status.

The MCU layer provides the following API:

```c
MCU_ReadStatusRegister();
```

Use this API inside your new module.

The application layer must access status information through:

```c
EmergencyStatus();
```

or an equivalent interface designed by you.

---

## Important Rule

The application layer must not directly include:

```c
fake_mcu.h
```

The application layer must not directly call:

```c
MCU_ReadADC();
MCU_ReadBatteryVoltage();
MCU_ReadStatusRegister();
```

Application tasks must only interact with higher-level modules such as:

```text
sensor.c
battery.c
emergency.c
```

---

## Required Tasks

Create the following FreeRTOS tasks:

```text
SensorTask
BatteryTask
EmergencyTask
```

---

### SensorTask

This task should periodically read sensor data using the existing sensor module.

---

### BatteryTask

This task should periodically read battery information using the existing battery module.

---

### EmergencyTask

This task should periodically check system status using the emergency module.

This task represents a safety monitoring function and must be assigned the highest priority in the system.

---

## Task Priorities

Assign priorities such that:

```text
EmergencyTask     Highest Priority
SensorTask        Medium Priority
BatteryTask       Lowest Priority
```

---

## FreeRTOS Requirements

The application must use FreeRTOS tasks.

The application must not use:

```c
sleep()
usleep()
```

or any operating system delay function.

Use only FreeRTOS timing functions.

Example:

```c
vTaskDelay()
```

---

## Expected Learning Outcomes

After completing this exercise, learners should understand:

* Reusing an existing software architecture
* Creating FreeRTOS tasks
* Assigning task priorities
* Task scheduling
* Task blocking using `vTaskDelay()`
* Safety monitoring concepts
* Maintaining abstraction boundaries in embedded software

---

## Submission

Submit your solution through GitHub.

1. Fork the repository
2. Clone your fork
3. Implement the required tasks
4. Commit your changes
5. Push your work
6. Open a Pull Request

The Pull Request should describe:

```text
Implemented SensorTask
Implemented BatteryTask
Implemented EmergencyTask
Verified task scheduling
Verified task priorities
Maintained abstraction boundaries
```

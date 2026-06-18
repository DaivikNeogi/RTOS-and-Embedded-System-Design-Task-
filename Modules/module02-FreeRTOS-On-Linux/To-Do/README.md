# Module 02 Task - FreeRTOS Task Scheduling and Priorities

## Objective

In embedded systems, multiple activities often need to run at the same time.

Examples include:

* Reading sensors
* Monitoring battery voltage
* Sending telemetry
* Controlling motors

A Real-Time Operating System (RTOS) allows these activities to be split into independent tasks and scheduled according to their priority.

Your task is to create a simple FreeRTOS application that demonstrates task scheduling, blocking, and preemption using multiple tasks.

---

# Problem Statement

You are developing a simplified embedded controller.

The controller performs three independent functions:

1. Periodically reading sensors
2. Monitoring system health
3. Handling emergency checks

Each function should execute in its own FreeRTOS task.

---

# Requirements

Create the following tasks:

```text
SensorTask
HealthMonitorTask
EmergencyTask
```

---

## Sensor Task

This task represents a sensor acquisition system.

The task should:

```text
Print: Reading Sensors
```

and execute periodically every:

```text
500 ms
```

using:

```c
vTaskDelay()
```

---

## Health Monitor Task

This task represents a heartbeat or status LED task commonly found in embedded systems.

The task should:

```text
Print: System Healthy
```

and execute periodically every:

```text
1000 ms
```

using:

```c
vTaskDelay()
```

---

## Emergency Task

This task represents a high-priority safety monitoring function.

The task should:

```text
Print: EMERGENCY CHECK
```

and execute periodically every:

```text
3000 ms
```

using:

```c
vTaskDelay()
```

This task must have the highest priority in the system.

---

# Task Priorities

Assign priorities as follows:

```text
EmergencyTask       Highest Priority
SensorTask          Medium Priority
HealthMonitorTask   Lowest Priority
```

Example:

```c
EmergencyTask       Priority 3
SensorTask          Priority 2
HealthMonitorTask   Priority 1
```

---

# Important Rules

All functionality must be implemented using FreeRTOS tasks.

The application must not use:

```c
sleep()
usleep()
```

or any operating system delay function.

Only FreeRTOS timing functions should be used.

Example:

```c
vTaskDelay()
```

---

# Architecture

The software should follow the structure below:

```text
+---------------------------+
|      Emergency Task       |
|      Priority Highest     |
+-------------+-------------+
              |
+-------------v-------------+
|        Sensor Task        |
|      Priority Medium      |
+-------------+-------------+
              |
+-------------v-------------+
|    Health Monitor Task    |
|      Priority Lowest      |
+---------------------------+
```

---

# Expected Behaviour

When the application runs, all tasks should periodically print messages.

Example output:

```text
Reading Sensors
System Healthy

Reading Sensors

EMERGENCY CHECK

Reading Sensors
System Healthy
```

Because the Emergency Task has the highest priority, it should immediately run whenever it becomes ready.

Observe the scheduling behaviour and compare it with the lower-priority tasks.

---

# Why Are We Doing This?

In embedded systems, not all software activities are equally important.

Examples:

```text
Motor Control      Critical
Sensor Reading     Important
Debug Logging      Non-Critical
```

An RTOS allows critical tasks to receive CPU time before less important tasks.

This is one of the primary reasons RTOSes are used in embedded systems.

---

# Debugging Task

After implementing the application:

1. Build the project.
2. Run the application.
3. Use GDB to inspect task execution.
4. Verify that:

   * All three tasks are created.
   * Tasks enter the Blocked state after calling vTaskDelay().
   * Higher-priority tasks execute before lower-priority tasks when they become Ready.

Use breakpoints to observe:

```text
SensorTask()
   ↓
vTaskDelay()

HealthMonitorTask()
   ↓
vTaskDelay()

EmergencyTask()
   ↓
vTaskDelay()
```

Observe how task execution changes as different tasks become ready to run.

---

# Provided Files

The following files are provided:

```text
main.c
FreeRTOSConfig.h
Makefile
```

Do not modify the FreeRTOS kernel files.

Your task is to build the application using the FreeRTOS APIs provided.

---

# Expected Learning Outcomes

After completing this task, learners should understand:

* Task creation
* Task priorities
* Task scheduling
* Task preemption
* Blocking using vTaskDelay()
* Basic RTOS architecture
* Debugging FreeRTOS applications using GDB

---

# Submitting Your Solution

After completing the task, submit your work through GitHub.

---

## Step 1 - Fork the Repository

Create your own copy of the repository using GitHub's Fork feature.

```text
Original Repository
        ↓
     Fork
        ↓
Your GitHub Repository
```

---

## Step 2 - Clone Your Fork

Clone your fork to your local machine.

Example:

```bash
git clone <your-fork-url>
```

---

## Step 3 - Create Your Solution

Implement the required FreeRTOS tasks.

Example:

```text
Module02/
│
├── main.c
├── FreeRTOSConfig.h
├── Makefile
│
└── task implementation
```

---

## Step 4 - Commit Your Changes

Add your files to Git.

```bash
git add .
```

Create a commit.

```bash
git commit -m "Completed Module02 FreeRTOS scheduling task"
```

---

## Step 5 - Push Your Changes

Push the solution to your fork.

```bash
git push origin main
```

or

```bash
git push origin <branch-name>
```

depending on your workflow.

---

## Step 6 - Open a Pull Request

From GitHub:

1. Open your fork.
2. Click Pull Request.
3. Compare your changes against the original repository.
4. Create a Pull Request.

The Pull Request should include:

```text
Implemented all required tasks
Configured task priorities
Verified task scheduling behaviour
Verified execution using GDB
```

---

# Learning Goal

This exercise introduces the basic workflow of a FreeRTOS application:

```text
Create Tasks
      ↓
Assign Priorities
      ↓
Run Scheduler
      ↓
Observe Scheduling
      ↓
Debug
      ↓
Commit
      ↓
Push
      ↓
Create Pull Request
```

This workflow forms the foundation for future modules involving queues, semaphores, mutexes, timers, and interrupt-driven systems.


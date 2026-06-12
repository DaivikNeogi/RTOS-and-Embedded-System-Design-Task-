# Fake MCU API

## Purpose

The Fake MCU layer simulates hardware peripherals typically found on a microcontroller.

The goal is to allow learners to practice:

* Multi-file project navigation
* Debugging with GDB
* Layered software architecture
* Driver abstraction concepts

without requiring real hardware.

---

# Software Layers

```text
Application Layer
       ↓
Sensor Driver Layer
       ↓
Fake MCU Layer
```

Applications should interact with the driver layer.

Drivers interact with the Fake MCU layer.

The Fake MCU layer represents hardware.

---

# Available Functions

## MCU_Init

```c
void MCU_Init(void);
```

Initializes the simulated hardware.

Must be called before using any other MCU functions.

---

## MCU_ReadADC

```c
uint16_t MCU_ReadADC(void);
```

Returns a simulated ADC reading.

Characteristics:

* Value changes every call.
* Range: 100–299.
* Intended to represent a sensor ADC conversion result.

Example:

```text
154
289
177
201
```

---

## MCU_ReadBatteryVoltage

```c
uint16_t MCU_ReadBatteryVoltage(void);
```

Returns a simulated battery voltage.

Characteristics:

* Value changes every call.
* Range: 3000–4200 mV.

Example:

```text
3890
4015
3120
```

---

## MCU_ReadStatusRegister

```c
uint8_t MCU_ReadStatusRegister(void);
```

Returns a simulated status register.

Characteristics:

* Value changes every call.
* Range: 0–255.

Example:

```text
0x15
0x8F
0x22
```

---

# Intended Usage

Example:

```c
MCU_Init();

uint16_t adc = MCU_ReadADC();
```

Applications should avoid directly accessing internal variables.

All hardware interaction should occur through the provided API.

This mirrors how real embedded software interacts with hardware abstraction layers and device drivers.

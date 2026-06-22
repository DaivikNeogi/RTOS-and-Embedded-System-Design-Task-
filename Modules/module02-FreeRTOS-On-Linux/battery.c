#include "battery.h"
#include "fake_mcu.h" 
void Battery_Init(void) {
}
int Battery_ReadVoltage(void) {
    return MCU_ReadBatteryVoltage();
}
#include <stdio.h>
#include "sensor.h"
#include "battery.h"
#include "system.h"
#include <unistd.h>

int main(void){
	system_init();

	while(1){
		int sensor = SensorVal();
		int battery = BatteryVal();

		printf("Sensor value: %d\n", sensor);
		printf("Battery Value: %d\n",battery);
		sleep(3); 

	}
	return 0;
}

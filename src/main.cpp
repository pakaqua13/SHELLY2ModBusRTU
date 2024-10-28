#include <Arduino.h>
#include <ModbusRTUSlave.h>

ModbusRTUSlave modbus_slave(Serial);
const uint8_t slaveID = 1;
const uint32_t baud = 9600;

uint16_t holdingRegisters[20] = {0};

int sensor;

void setup() {
  // put your setup code here, to run once:
  modbus_slave.configureHoldingRegisters(holdingRegisters,20);
  modbus_slave.begin(slaveID,baud,SERIAL_8N1);
}

void loop() {
  // put your main code here, to run repeatedly:
  holdingRegisters[0]= 1024 * esp_random();
  modbus_slave.poll();
}

#include <iostream>
#include "C:\myPrgs\Zalubus\tinyxml2\tinyxml2.h"
#pragma once

class SerialSettings
{
public:
    void set(char *Port, uint16_t BaudRate, uint8_t DataBits, uint8_t Parity,
             uint8_t StopBits, uint8_t FlowControl, uint8_t SlaveAddress);
    bool set_from_XML(const char *pth_to_XML);
    void print();

private:
    const char *Port;
    int BaudRate;
    int DataBits;
    int Parity;
    int StopBits;
    int FlowControl;
    int SlaveAddress;
};

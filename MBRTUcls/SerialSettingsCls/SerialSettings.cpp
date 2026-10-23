#include "SerialSettings.h"

void SerialSettings::set(char *Port, uint16_t BaudRate, uint8_t DataBits, uint8_t Parity,
                         uint8_t StopBits, uint8_t FlowControl, uint8_t SlaveAddress)
{
    this->Port = Port;
    this->BaudRate = BaudRate;
    this->DataBits = DataBits;
    this->Parity = Parity;
    this->StopBits = StopBits;
    this->FlowControl = FlowControl;
    this->SlaveAddress = SlaveAddress;
};

bool SerialSettings::set_from_XML(const char *pth_to_XML)
{
    tinyxml2::XMLDocument doc;
    auto load_file_status = doc.LoadFile(pth_to_XML);
    if (load_file_status != tinyxml2::XML_SUCCESS)
    {
        std::cerr << "Ошибка: не удалось открыть файл " << pth_to_XML << std::endl;
        return false;
    }

    tinyxml2::XMLElement *root = doc.FirstChildElement("ModbusConfig");
    if (!root)
    {
        std::cerr << "Ошибка: не найден элемент ModbusConfig" << std::endl;
        return false;
    }

    tinyxml2::XMLElement *serialPort = root->FirstChildElement("SerialPort");
    if (!serialPort)
    {
        std::cerr << "Ошибка: не найден элемент SerialPort" << std::endl;
        return false;
    }

    this->Port = serialPort->FirstChildElement("Port")->GetText();
    this->BaudRate = serialPort->FirstChildElement("BaudRate")->IntText();
    this->DataBits = serialPort->FirstChildElement("DataBits")->IntText();
    this->Parity = serialPort->FirstChildElement("Parity")->IntText();
    this->StopBits = serialPort->FirstChildElement("StopBits")->IntText();
    this->FlowControl = serialPort->FirstChildElement("FlowControl")->IntText();
    this->SlaveAddress = serialPort->FirstChildElement("SlaveAddress")->IntText();

    return true;
};

void SerialSettings::print()
{
    std::cout << "port" << "\t\t" << this->Port << std::endl;
    std::cout << "BaudRate" << "\t" << this->BaudRate << std::endl;
    std::cout << "DataBits" << "\t" << this->DataBits << std::endl;
    std::cout << "Parity" << "\t\t" << this->Parity << std::endl;
    std::cout << "StopBits" << "\t" << this->StopBits << std::endl;
    std::cout << "FlowControl" << "\t" << this->FlowControl << std::endl;
    std::cout << "SlaveAddress" << "\t" << this->SlaveAddress << std::endl;
};
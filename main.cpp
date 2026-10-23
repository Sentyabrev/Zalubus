#include <windows.h>
#include <string>

#include "MBRTUcls\SerialSettingsCls\SerialSettings.h"

using namespace std;

string GetExePath()
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    string path(buffer);
    return path.substr(0, path.find_last_of("\\/"));
}

int main()
{
    string fullPath = GetExePath() + "\\settings.xml";
    const char *xmlPath = fullPath.c_str();

    SerialSettings settings;
    settings.set_from_XML(xmlPath);
    settings.print();

    system("pause");
    return 0;
}
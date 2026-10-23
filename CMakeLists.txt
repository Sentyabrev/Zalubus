cmake_minimum_required(VERSION 3.15)

project(Zalubus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    ${PROJECT_NAME} 
    tinyxml2/tinyxml2.h
    MBRTUcls/SerialSettingsCls/SerialSettings.h
    MBRTUcls/MBRTUcls.h

    tinyxml2/tinyxml2.cpp
    MBRTUcls/SerialSettingsCls/SerialSettings.cpp
    MBRTUcls/MBRTUcls.cpp

    main.cpp
    )
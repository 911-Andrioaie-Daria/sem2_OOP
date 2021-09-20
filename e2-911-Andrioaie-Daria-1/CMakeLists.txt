cmake_minimum_required(VERSION 3.19)
project(e2_911_Andrioaie_Daria_1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

include_directories(Domain Service Repository UI Observer)

add_executable(e2_911_Andrioaie_Daria_1
        main.cpp
        Domain/Building.cpp
        Domain/Building.h
        Domain/Ethnologist.cpp
        Domain/Ethnologist.h
        Repository/Repository.h
        Repository/Repository.cpp Observer/Observer.h Service/Service.cpp Service/Service.h UI/GUI.cpp UI/GUI.h main.cpp UI/EthWindow.cpp UI/EthWindow.h UI/TableModel.cpp UI/TableModel.h UI/MapWindow.cpp UI/MapWindow.h)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

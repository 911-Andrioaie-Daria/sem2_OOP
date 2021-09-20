cmake_minimum_required(VERSION 3.17)
project(a89_911_Andrioaie_Daria)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets Charts)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Charts)

include_directories(Administator_service)
include_directories(Domain)
include_directories(Dynamic_array)
include_directories(Exceptions)
include_directories(Repository)
include_directories(Tests)
include_directories(UI)
include_directories(User_service)
include_directories(Validations)

add_executable(a89_911_Andrioaie_Daria
        Administator_service/AdminService.cpp
        Administator_service/AdminService.h
        Domain/Dog.cpp
        Domain/Dog.h
        Dynamic_array/DynamicArray.h
        Exceptions/CustomException.cpp
        Exceptions/CustomException.h
        Repository/DogRepository.cpp
        Repository/DogRepository.h
        Repository/FileRepository.cpp
        Repository/FileRepository.h
        Tests/AdminServiceTests.cpp
        Tests/AdminServiceTests.h
        Tests/DomainTests.cpp
        Tests/DomainTests.h
        Tests/DynamicArrayTests.cpp
        Tests/DynamicArrayTests.h
        Tests/RepositoryTests.cpp
        Tests/RepositoryTests.h
        Tests/TestAll.cpp
        Tests/TestAll.h
        Tests/UserServiceTests.cpp
        Tests/UserServiceTests.h
        Tests/ValidatorTests.cpp
        Tests/ValidatorTests.h
        UI/ConsoleUI.cpp
        UI/ConsoleUI.h
        User_service/AbstractAdoptionList.cpp
        User_service/AbstractAdoptionList.h
        User_service/UserService.cpp
        User_service/UserService.h
        Validations/DogValidator.cpp
        Validations/DogValidator.h
        main.cpp helloworld.cpp helloworld.h UI/AdminGUI.cpp UI/AdminGUI.h UI/GUI.cpp UI/GUI.h UI/UserGUI.cpp UI/UserGUI.h UI/setFileGUI.cpp UI/setFileGUI.h)


file(COPY AdoptionList.csv
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY AdoptionList.html
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY dogs.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
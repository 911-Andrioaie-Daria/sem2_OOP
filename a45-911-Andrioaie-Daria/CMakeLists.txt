cmake_minimum_required(VERSION 3.17)
project(a45_911_Andrioaie_Daria)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain
                    Dynamic_array
                    Repository
                    Validations
                    Administator_service
                    User_service
                    UI)

add_executable(a45_911_Andrioaie_Daria
        Domain/Dog.cpp
        Domain/Dog.h
        Dynamic_array/DynamicArray.h
        Repository/DogRepository.cpp
        Repository/DogRepository.h
        Validations/DogValidator.cpp
        Validations/DogValidator.h
        Administator_service/AdminService.cpp
        Administator_service/AdminService.h
        User_service/UserService.cpp
        User_service/UserService.h
        UI/ConsoleUI.cpp
        UI/ConsoleUI.h
        main.cpp
        Tests/DomainTests.cpp
        Tests/DomainTests.h Tests/DynamicArrayTests.cpp Tests/DynamicArrayTests.h Tests/RepositoryTests.cpp Tests/RepositoryTests.h User_service/UserService.cpp User_service/UserService.h Tests/AdminServiceTests.cpp Tests/AdminServiceTests.h Tests/UserServiceTests.cpp Tests/UserServiceTests.h Tests/ValidatorTests.cpp Tests/ValidatorTests.h Tests/TestAll.cpp Tests/TestAll.h)

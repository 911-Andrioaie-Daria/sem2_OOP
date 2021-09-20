cmake_minimum_required(VERSION 3.17)
project(a23_911_Andrioaie_Daria)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a23_911_Andrioaie_Daria
        Controller/controller.h
        Domain/offer.c
        Domain/offer.h
        Repository/repository.h
        "User Interface/ui.h" start.c "User Interface/ui.c" Repository/repository.c Controller/controller.c Tests/domain_tests.c Tests/domain_tests.h Tests/repository_tests.c Tests/repository_tests.h Tests/service_tests.c Tests/service_tests.h "Dynamic array/dynamic_array.c" "Dynamic array/dynamic_array.h")

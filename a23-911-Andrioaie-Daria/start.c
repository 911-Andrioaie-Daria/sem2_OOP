//
// Created by daria on 05/03/2021.
//
#include <crtdbg.h>
#include "User Interface/ui.h"
#include "Tests/domain_tests.h"
#include "Tests/repository_tests.h"
#include "Tests/service_tests.h"

int main(){

    run_domain_tests();
    run_repository_tests();
    run_service_tests();

    repo *offer_repository = create_offer_repository();
    service *offer_service = create_offer_service(offer_repository);
    UI* user_interface = create_ui(offer_service);
    start_program(user_interface);

    deallocate_user_interface(user_interface);

    _CrtDumpMemoryLeaks();
    return 0;
}


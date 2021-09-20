////
//// Created by daria on 25/03/2021.
////
//
//#include "UserServiceTests.h"
//#include "UserService.h"
//#include <cassert>
//
//void test_filter_dogs_by_breed(){
//    DogRepository repository;
//    repository.init();
//
//    UserService userService{repository};
//
//    string dog_breed = "Labrador";
//    userService.filter_dogs_by_breed(dog_breed);
//    int filtered_dogs_count = userService.get_dogs_filtered().size();
//    assert(filtered_dogs_count == 2);
//
//    dog_breed = "";
//    userService.filter_dogs_by_breed(dog_breed);
//    filtered_dogs_count = userService.get_dogs_filtered().size();
//    assert(filtered_dogs_count == 10);
//
//}
//
//void test_adopt_dog(){
//    DogRepository repository;
//    repository.init();
//
//    UserService userService{repository};
//    string dog_breed = "Labrador";
//    userService.filter_dogs_by_breed(dog_breed);
//
//    Dog current_dog = userService.get_current_dog();
//    userService.adopt_dog(current_dog);
//
//    vector<Dog>& list_of_adopted_dogs = userService.get_adopted_dogs();
//    assert(list_of_adopted_dogs.size() == 1);
//
//    DogRepository& dog_repository = userService.get_repository();
//    assert(dog_repository.get_size() == 9);
//
//}
//
//void run_all_user_service_tests(){
//    test_filter_dogs_by_breed();
//    test_adopt_dog();
//}
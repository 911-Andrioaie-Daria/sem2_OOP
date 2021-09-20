////
//// Created by daria on 25/03/2021.
////
//
//#include "AdminServiceTests.h"
//#include "AdminService.h"
//#include <cassert>
//
//void test_add_dog_service(){
//    DogRepository repository;
//    repository.init();
//
//    DogValidator validator;
//
//    AdminService adminService{repository, validator};
//
//    /// valid, non-existing dog
//    string dog_breed = "Terrier";
//    string dog_age = "3";
//    string dog_name = "Max";
//    string dog_photograph = "https://max.ro";
//
//    adminService.add_dog(dog_breed, dog_age, dog_name, dog_photograph);
//
//    /// valid, but already existing dog
//    dog_breed = "Labrador";
//    dog_age = "2";
//    dog_name = "Louie";
//    dog_photograph = "https://labrador1.ro";
//
//    try{
//        adminService.add_dog(dog_breed, dog_age, dog_name, dog_photograph);
//        assert(false);
//    }
//    catch(const RepositoryException& add_exception){
//        assert(true);
//    }
//
//
//    /// non-valid dog
//    dog_breed = "123";
//    dog_age = "abcd";
//    dog_name = "456";
//    dog_photograph = "abcd";
//
//    try {
//        adminService.add_dog(dog_breed, dog_age, dog_name, dog_photograph);
//        assert(false);
//    }
//    catch(const CustomException& add_exception){
//        assert(true);
//    }
//
//}
//
//void test_delete_dog_service(){
//    DogRepository repository;
//    repository.init();
//
//    DogValidator validator;
//
//    AdminService adminService{repository, validator};
//    string dog_breed;
//    string dog_name;
//
//    try{
//        /// valid, non-existing dog
//        dog_breed = "Terrier";
//        dog_name = "Max";
//
//        adminService.delete_dog(dog_breed, dog_name);
//        assert(false);
//    }
//    catch(const CustomException& delete_exception){
//        assert(true);
//    }
//
//    /// valid, existing dog
//    dog_breed = "Labrador";
//    dog_name = "Louie";
//
//    adminService.delete_dog(dog_breed, dog_name);
//    try{
//        /// non-valid dog
//        dog_breed = "123";
//        dog_name = "456";
//        adminService.delete_dog(dog_breed, dog_name);
//        assert(false);
//    }
//    catch (const CustomException& delete_exception) {
//        assert(true);
//    }
//
//}
//
//void test_update_dog_service(){
//    DogRepository repository;
//    repository.init();
//
//    DogValidator validator;
//
//    AdminService adminService{repository, validator};
//    string dog_breed;
//    string dog_name;
//    string new_age;
//    string new_photograph;
//
//    try{
//        /// valid, non-existing dog
//        dog_breed = "Terrier";
//        dog_name = "Max";
//        new_age = "10";
//        new_photograph = "https://max.ro";
//
//        adminService.update_dog_age(dog_breed, dog_name, new_age);
//        assert(false);
//
//        adminService.update_dog_photograph(dog_breed, dog_name, new_photograph);
//        assert(false);
//    }
//    catch (const CustomException& update_exception) {
//        assert(true);
//    }
//
//
//    /// valid, existing dog
//    dog_breed = "Labrador";
//    dog_name = "Louie";
//    new_age = "10";
//    new_photograph = "https://new_louie.ro";
//
//    adminService.update_dog_age(dog_breed, dog_name, new_age);
//    adminService.update_dog_photograph(dog_breed, dog_name, new_photograph);
//
//    try{
//        /// non-valid dog
//        dog_breed = "123";
//        dog_name = "456";
//        new_age = "gdd";
//        new_photograph = "abcd";
//
//        adminService.update_dog_age(dog_breed, dog_name, new_age);
//        assert(false);
//
//        adminService.update_dog_photograph(dog_breed, dog_name, new_photograph);
//        assert(false);
//    }
//    catch (const CustomException& update_exception) {
//        assert(true);
//    }
//}
//
//void run_all_admin_service_tests(){
//      //test_getters_service();
//      test_add_dog_service();
//      test_delete_dog_service();
//      test_update_dog_service();
//}
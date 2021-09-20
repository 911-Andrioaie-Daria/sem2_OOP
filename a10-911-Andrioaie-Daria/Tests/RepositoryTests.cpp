////
//// Created by daria on 22/03/2021.
////
//
//#include "RepositoryTests.h"
//#include "DogRepository.h"
//#include <cassert>
//
//void test_initialise_repository(){
//    DogRepository repository;
//    repository.init();
//    int size = repository.get_size();
//    assert(size == 10);
//
//}
//
//void test_add_to_repo(){
//    DogRepository repository;
//    repository.init();
//    Dog new_dog("Husky", 2, "Leon", "https://dasa.ro");
//    repository.add_dog(new_dog);
//
//    try{
//        Dog already_existing_dog("Australian Shepherd", 5, "Milo", "https://australiansheperd2.ro");
//        repository.add_dog(already_existing_dog);
//        assert(false);
//    }
//    catch(const RepositoryException& add_exception){
//        assert(true);
//    }
//
////    Dog already_existing_dog("Australian Shepherd", 5, "Milo", "https://australiansheperd2.ro");
////    assert(repository.add_dog(already_existing_dog) == false);
//
//}
//
//void test_delete_from_repo(){
//    DogRepository repository;
//    repository.init();
//
//    string existing_dog_breed = "Australian Shepherd";
//    string existing_dog_name = "Milo";
//    repository.delete_dog(existing_dog_breed, existing_dog_name);
//
//    try{
//        string non_existent_dog_breed = "Terrier";
//        string non_existent_dog_name = "Max";
//        repository.delete_dog(non_existent_dog_breed, non_existent_dog_name);
//        assert(false);
//    }
//    catch(const RepositoryException& delete_exception){
//        assert(true);
//    }
//    assert(repository.get_size() == 9);
//
//}
//
//void test_update_in_repo(){
//    DogRepository repository;
//    repository.init();
//
//    string existing_dog_breed = "Australian Shepherd";
//    string existing_dog_name = "Milo";
//    repository.update_dog_age(existing_dog_breed, existing_dog_name, 10);
//    repository.update_dog_photograph(existing_dog_breed, existing_dog_name, "https://ddddxsw.ro");
//
//    try{
//        string non_existent_dog_breed = "Terrier";
//        string non_existent_dog_name = "Max";
//        repository.update_dog_age(non_existent_dog_breed, non_existent_dog_name, 10);
//        repository.update_dog_photograph(non_existent_dog_breed, non_existent_dog_name, "https://ddddxsw.ro");
//        assert(false);
//    }
//    catch (const RepositoryException& update_exception) {
//        assert(true);
//    }
//
////    string non_existent_dog_breed = "Terrier";
////    string non_existent_dog_name = "Max";
////    assert(repository.update_dog_age(non_existent_dog_breed, non_existent_dog_name, 10) == false);
////    assert(repository.update_dog_photograph(non_existent_dog_breed, non_existent_dog_name, "https://ddddxsw.ro") == false);
//
//}
//
//void run_all_repository_tests(){
//    test_initialise_repository();
//    test_add_to_repo();
//    test_delete_from_repo();
//    test_update_in_repo();
//}
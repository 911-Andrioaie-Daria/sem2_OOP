//
// Created by daria on 22/03/2021.
//

#include "DynamicArrayTests.h"
#include "DynamicArray.h"
#include <assert.h>

void test_getters_dynamic_array(){
    DynamicArray<int>* integers = new DynamicArray<int>(10);
    int size = integers->getSize();
    assert(size == 0);
    int* elements = integers->get_elements();
    assert(elements != nullptr);

    delete integers;

}

void test_add_dynamic_array(){
    DynamicArray<int>* integers = new DynamicArray<int>(10);
    for(int i=0; i<11; i++){
        integers->add(i);
    }
    int size = integers->getSize();
    assert(size == 11);
    int capacity = integers->get_capacity();
    assert(capacity == 20);

    delete integers;
}

void test_remove_dynamic_array(){
    DynamicArray<int>* integers = new DynamicArray<int>(10);
    for(int i=0; i<10; i++){
        integers->add(i);
    }
    for(int i=0; i<5; i++){
        integers->remove(i);
    }
    int size = integers->getSize();
    assert(size == 5);

    delete integers;
}

void test_update_dynamic_array(){
    DynamicArray<int>* integers = new DynamicArray<int>(10);
    for(int i=0; i<10; i++){
        integers->add(i);
    }
    for(int i=0; i<10; i++){
        integers->update(0, i);
    }
    for(int i=0; i<10; i++){
        assert(integers->get_elements()[i] == 0);
    }

    delete integers;
}

void run_all_dynamic_array_tests(){
    test_getters_dynamic_array();
    test_add_dynamic_array();
    test_remove_dynamic_array();
    test_update_dynamic_array();
}
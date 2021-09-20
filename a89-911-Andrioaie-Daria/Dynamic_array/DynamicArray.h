//
// Created by daria on 20/03/2021.
//

#ifndef A45_911_ANDRIOAIE_DARIA_DYNAMICARRAY_H
#define A45_911_ANDRIOAIE_DARIA_DYNAMICARRAY_H

template<class TElem>
class DynamicArray {

private:
    TElem *elements;
    int size;
    int capacity;

public:
    /// default constructor
    DynamicArray() {
    }

    /// parameter constructor
    DynamicArray(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->elements = new TElem[capacity];
    }

    /// destructor
    ~DynamicArray() {
        delete [] this->elements;
    }

    /// Function adds a new element in the dynamic array.
    void add(TElem new_element) {
        if(this->size == this->capacity)
            resize();
        this->elements[this->size] = new_element;
        this->size++;
    }

    /// Function removes the element at the given position from the dynamic array.
    void remove(int position){
        this->elements[position] = this->elements[this->size - 1];
        this->size--;
    }

    /// Function updates the element at the given position with a new element.
    void update(const TElem &element, int position){
        this->elements[position] = element;
    }

    /// Getter function for the current size of the dynamic array.
    int getSize() const {
        return this->size;
    }

    int get_capacity() const {
        return this->capacity;
    }

    void empty(){
        this->size = 0;
    }

    /// Getter function for the array of elements.
    TElem* get_elements() const {
        return this->elements;
    }

    /// Function that overloads the assignment operator
    DynamicArray &operator=(const DynamicArray &dynamic_array){
        this->capacity = dynamic_array.capacity;
        this->size = dynamic_array.size;
        memcpy(this->elements, dynamic_array.elements, sizeof(TElem)*dynamic_array.capacity);
    }

    /// Function that overloads the [] operator
    TElem &operator [] (int position){
        return this->elements[position];
    }

private:
    /// Function resizes the current DynamicVector, multiplying its capacity by 2.
    void resize() {
        TElem *new_array;
        this->capacity = this->capacity * 2;
        new_array = new TElem[this->capacity];
        for(int i =0; i < this->size; i++){
            new_array[i] = this->elements[i];
        }
        delete[] this->elements;
        this->elements = new_array;
    }
};


#endif //A45_911_ANDRIOAIE_DARIA_DYNAMICARRAY_H
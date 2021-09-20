//
// Created by daria on 22/02/2021.
//
/*
 * a. Compute the approximated value of square root of a positive real number. The precision is provided by the user.
b. Given a vector of numbers, find the longest contiguous subsequence such that the difference of any two consecutive
 elements is a prime number.
b'. Given a vector of numbers, find the longest contiguous subsequence such that any two consecutive elements are relatively prime.
 *
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
 //------------------------------------------- non UI ----------------------------------------------------------------
float approximated_value_of_a_square_root(int number, int precision){
    /// The function finds the approximated value of the square root of parameter number.
    ///Param precision: the precision of the approximation.
    /// Return: the approximated value of the square root.
    float square_root = sqrt(number);

    for(int i=1;i<=precision;i++)
        square_root *=10;

    square_root = (int) square_root;
     for(int i=1;i<=precision;i++)
         square_root /= (float)10;

     return square_root;
}

bool is_prime(int number){
    /// The function checks the primality of a natural number received as a parameter.
    /// Return: True, if the number is prime, false otherwise.
    if (number == 0 || number == 1)
        return false;

    for (int d=2; d<=sqrt(number);d++)
        if (number % d == 0)
            return false;
    return true;
}

bool are_relatively_prime(int number_a, int number_b){
    /// The function checks if two natural numbers are relatively prime, i.e. they don't have any common divisors except
    ///1.
    ///Return: True, if the two numbers are relatively prime, false otherwise
    for(int d=2; d <= number_a && d <= number_b; d++)
        if(number_a % d == 0 && number_b % d == 0)
            return false;
    return true;
}


void longest_subsequence_of_prime_difference(int *array, int size_of_array, int *start_index, int *length){
    /// The function finds the longest contiguous subsequence in the array such that the difference of any two consecutive
    /// elements is a prime number and modifies the memory locations at the addresses start_index and maximum_length
    *start_index = 0;
    *length = 0;
    int length_of_current_subsequence = 1;
    int start_index_of_current_subsequence = 0;


    for (int index = 1; index < size_of_array; index++)
        if(is_prime(abs(array[index]-array[index-1])))
            length_of_current_subsequence++;
        else
        {
            if(length_of_current_subsequence > *length)
            {
                *start_index = start_index_of_current_subsequence;
                *length = length_of_current_subsequence;
            }
            start_index_of_current_subsequence = index;
            length_of_current_subsequence = 1;
        }

    if(length_of_current_subsequence > *length)
    {
        *start_index = start_index_of_current_subsequence;
        *length = length_of_current_subsequence;
    }

}


void longest_subsequence_of_relatively_prime_consecutive_numbers(int *array, int size_of_array, int *start_index, int *length){
    /// The function finds the longest contiguous subsequence in the array such that any two consecutive elements are
    /// relatively prime and modifies the memory locations at the addresses start_index and maximum_length
    *start_index = 0;
    *length = 0;
    int length_of_current_subsequence = 1;
    int start_index_of_current_subsequence = 0;


    for (int index = 1; index < size_of_array; index++)
        if(are_relatively_prime(array[index],array[index-1]))
            length_of_current_subsequence++;
        else
        {
            if(length_of_current_subsequence > *length)
            {
                *start_index = start_index_of_current_subsequence;
                *length = length_of_current_subsequence;
            }
            start_index_of_current_subsequence = index;
            length_of_current_subsequence = 1;
        }

    if(length_of_current_subsequence > *length)
    {
        *start_index = start_index_of_current_subsequence;
        *length = length_of_current_subsequence;
    }

}



//------------------------------------------------ UI -----------------------------------------------------------------

void print_menu(){
    /// The function prints on the screen the options that are available to the user
    printf("Available options:\n");
    printf("\t 1. Read a vector.\n");
    printf("\t 2. Compute the approximated value of the square root of a positive real number.\n");
    printf("\t 3. Find the longest contiguous subsequence in the vector such that the difference of any two consecutive elements is a prime number.\n");
    printf("\t 4. Find the longest contiguous subsequence in the vector such that any two consecutive elements are relatively prime.\n");
    printf("\t 5. Exit.\n");
}

int read_vector(int array[100])
{
    /// The function reads the elements of an array from the keyboard, up until the number 0.
    /// Param array: an already existing array, which will be filled with the numbers read from the keyboard.
    /// Return: the length of the array, meaning how many numbers were read.
    printf("Enter the elements of the vector up to 0:\n");
    int number, index = 0;
    scanf("%d", &number);
    while(number != 0)
    {
        array[index++] = number;
        scanf("%d", &number);
    }
    return index;
}

void approximated_value_of_a_square_root_ui()
{
    /// The function reads from the keyboard 2 natural numbers, calls the function which finds the approximated value of
    /// the square root of the first number with the precision given by the second number and prints on the screen the
    /// returned value.
    int number = 0, precision;
    printf("Enter the number:\n");
    scanf("%d", &number);
    printf("Enter the precision:\n");
    scanf("%d", &precision);

    float approximated_square_root = approximated_value_of_a_square_root(number, precision);
    printf("The approximated value of the square root of the number %d is %g.\n", number, approximated_square_root);
}

void longest_subsequence_ui(int *array, int size_of_array, int property)
{
    ///The function finds the longest contiguous subsequence of an array based on a certain property by calling the
    /// corresponding non-ui function and prints it on the screen.
    int start_index = 0;
    int *start_index_pointer = &start_index;
    int length = 0;
    int *length_pointer = &length;
    if (property == 3)
        longest_subsequence_of_prime_difference(array, size_of_array, start_index_pointer, length_pointer);
    else
        longest_subsequence_of_relatively_prime_consecutive_numbers(array, size_of_array, start_index_pointer, length_pointer);

    if(length > 1) {
        printf("The longest subsequence is:\n");
        for(int index = start_index; index < start_index + length; index++)
            printf("%d ",array[index]);
        printf("\n");
    }
    else
        printf("There is no such subsequence.\n");

}


int main(){

    bool not_finished = true;
    int array[100], size_of_array = 0;
    print_menu();
    while (not_finished)
    {
        int user_option;
        printf("Enter your option:\n");
        scanf("%d", &user_option);
        switch (user_option) {
            case 1:{
                size_of_array = read_vector(array);
                break;
            }

            case 2:{
                approximated_value_of_a_square_root_ui();
                break;
            }

            case 3 :{
                longest_subsequence_ui(array, size_of_array, user_option);
                break;
            }

            case 4:{
                longest_subsequence_ui(array, size_of_array, user_option);
                break;
            }


            case 5: {
                printf("Bye bye!\n");
                not_finished = false;
                break;
            }
            default:{
                printf("Invalid command.\n");
                break;
            }
        }
    }
    return 0;
}
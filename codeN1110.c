// Use C-Lang Static Analyzer to analyze and fix the bugs
// Also review the output generated to find any bugs that the static analyzer misses.
// Hint this code has 2-3 bugs that can be identified using static analyzer, 2 Tasks will have to be completed
//1.. add null pointer check condition for ptr1 in the reverse method for reversing logic.
//2.. Complete reversing Logic using given pointer.
//MACROS
#include<stdio.h>
#include <stdlib.h>

// custom method to reverse a number (without using third variable/pointer) passed to it as arguments from main()
void reverse_number(int *ptr1, char* ptr2){
    int reverse = 0; //will be used as reversing variable.
    printf("Original First Number is : %d \n ", (*ptr1));
    printf("Choice is : %c \n ", (*ptr2));
    // ----------------------- Secure Coding Task -------------------------------////
    // Task 1: Implement a NULL pointer check condition (use if statment) (most important secure coding practice)
    // ------  add null pointer check condition for ptr1 Here-------
    if(ptr1!=NULL){
        if(ptr2 != NULL && *ptr2 == 'Y')
        {
            //Task 2 : complete logic for reversing a number (Hint: required statements 2)
            //----- add logic here ------
            while(*ptr1 > 0)
            {
                //add reversing logic here using ptr1 (which points to the first_number defined in main)
                reverse = (reverse * 10) + (*ptr1 % 10);
                *ptr1 /= 10;
            }
            *ptr1=reverse;
            //print statements
            printf("Reversed First Number is : %d \n", (*ptr1));
            printf("Confirmed choice is : %c \n", (*ptr2));
        }
        else{
            printf("Sorry Not allowed\n");
        }
    }
}

int main(){
    // variable initializations
    int first_number = 4567;
    char choice = 'Y';

    //Note for developers(students): use variables in method using defined pointers (not directly)

    int *ptr_to_first_number = (int *) malloc(sizeof (int ));
    char *ptr_to_char = (char *) malloc(sizeof(char ));
    // Hint:: add and assign the references to the pointers here:
    *ptr_to_first_number = first_number;
    *ptr_to_char = choice;

    //function call statements
    reverse_number(ptr_to_first_number, ptr_to_char);

    return 0;
}

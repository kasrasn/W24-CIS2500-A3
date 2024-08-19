/*
Student Name: Kasra Sina
Student ID: 1266859
Due Date: March 18, 2024
Course: CIS*2500
I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz
I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/
#include "../include/headerA3.h"

void printOne (struct car * headLL, int whichOne){
    char str[20];
    int count = 1;

    for (a3Car * current = headLL; current != NULL; current = current->nextCar) { // loop through the linked list
        if (count == whichOne) { // if the car is found print the details
            printf("    Car ID: %d\n", current->carId);
            printf("    Model: %s\n", current->model);
            printf("    Type: %s\n", current->type);

            sprintf(str, "%.2f", current->price);
            convertPrice(str); // convert the price to the desired format and print

            printf("    Year of manufacture: %d\n", current->year);
            printf("\n");
            return;
        }
        count++;
    }
    printf("Car not found\n\n");// if the car is not found
}
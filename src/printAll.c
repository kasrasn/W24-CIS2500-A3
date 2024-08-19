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

void printAll (struct car * headLL){

    struct car * current = headLL;
    int count = 0;
    char str[20];
    if (current == NULL) { // if the linked list is empty
        printf("No cars found\n\n");
        return;
    }

    while (current != NULL){ // loop through the linked list and print the details
        count++;
        printf("Car #%d:\n", count);
        printf("    Car ID: %d\n", current->carId);
        printf("    Model: %s\n", current->model);
        printf("    Type: %s\n", current->type);

        sprintf(str, "%.2f", current->price);
        convertPrice(str); // convert the price to the desired format and print

        printf("    Year of manufacture: %d\n", current->year);
        current = current->nextCar;
    }

    if (count == 1) { // if there is only one car
    printf("Currently, there is 1 car.\n\n");
    }
    else { // if there are more cars
    printf("Currently, there are %d cars.\n\n", count);
    }
}
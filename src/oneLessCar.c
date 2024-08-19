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

void oneLessCar (a3Car ** headLL, int whichOne){

    if (headLL == NULL || *headLL == NULL) { // if list is empty
        return;
    }
    if (whichOne > countCars(*headLL)) { // if the position is greater than the number of cars
        return;
    }

    a3Car *temp = *headLL;
    a3Car *prev = NULL;

    if (whichOne == 1) { // if the head is to be removed
        *headLL = temp->nextCar; 
        free(temp);
        return;
    }

    //iterate the list with attentioin to the previous node until the wanted node is found
    for (int count = 1; temp != NULL && count < whichOne; count++) {
        prev = temp;
        temp = temp->nextCar;
    }

    prev->nextCar = temp->nextCar;// unlink the node from linked list

    free(temp);
}
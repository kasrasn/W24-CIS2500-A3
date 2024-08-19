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

int lookForCarId (struct car * headLL, int key){
    int count = 1;

    for (a3Car * current = headLL; current != NULL; current = current->nextCar) { // loop through the linked list
        if (current->carId == key) { // if the car is found return position
            return count;
        }
        count++;
    }
    return -1; // if the car is not found
}
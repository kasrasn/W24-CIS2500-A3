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

void sortCarId (struct car ** headLL){
    if(countCars(*headLL) == 0 || countCars(*headLL) == 1) { // if there are 0 or 1 car in the list
        return;
    }

    struct car *sorted = NULL;
    struct car *current = *headLL;
    struct car *next = NULL;
    
    while (current != NULL) { // loop through the linked list
        next = current->nextCar; // remember the next item.
        
        // find the correct place to insert the current node in the sorted part.
        if (!sorted || sorted->carId >= current->carId) { //insert at the beginning of the list
            current->nextCar = sorted;
            sorted = current;
        } 
        else {
            // search for the node in the sorted list after which current node should be inserted.
            struct car *temp = sorted;
            while (temp->nextCar != NULL && temp->nextCar->carId < current->carId) { // Find the place to insert node.
                temp = temp->nextCar;
            }
            
            // insert the current node after the node pointed by temp.
            current->nextCar = temp->nextCar;
            temp->nextCar = current;
        }

        current = next;
    }
    
    *headLL = sorted; // update the head of the original list to the new sorted list.
    printf("The list has been sorted.\n\n");
}
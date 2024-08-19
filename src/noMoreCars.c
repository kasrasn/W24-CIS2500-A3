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

void noMoreCars (a3Car ** headLL){
    char confirmation;

    // get user confirmation
    while (1)
    {
        printf("Are you sure you want to remove all car data? (y for yes, n for no): ");
        scanf(" %c", &confirmation);
        if (confirmation == 'y') // if user confirms
        {
            break;
        }
        else if (confirmation == 'n') // if user cancels, return
        {
            printf("No cars removed\n");
            return;
        }
        else //check for invalid input
        {
            printf("Invalid input. try again\n");
        }
        
    }
    

    // free all nodes
    while (*headLL != NULL) {
        a3Car *temp = *headLL;
        *headLL = (*headLL)->nextCar; 
        free(temp);
    }

    printf("All removed. Linked list is now empty\n\n"); // print success message
}
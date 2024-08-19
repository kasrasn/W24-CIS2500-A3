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

void addNewCar (struct car ** headLL){

    a3Car * newCar = (a3Car *)malloc(sizeof(a3Car)); // allocate memory for the new car

    if (newCar == NULL){ // check if malloc failed
        printf("Error: malloc failed in addNewCar\n");
        exit(1);
    }

    printf("Enter the car model: "); // get the car details
    scanf("%s", newCar->model);
    printf("Enter the car type: ");
    scanf("%s", newCar->type);
    printf("Enter its year of manufacture: ");
    scanf("%d", &newCar->year);
    printf("Enter its price: CDN $ ");
    scanf("%lf", &newCar->price);

    newCar->carId = 0;  // initialize the car id
    for (int i = 0; i < strlen(newCar->model); i++) // add the model ascii to the id
    {
        newCar->carId += newCar->model[i];
    }
    newCar->carId += strlen(newCar->type); // add the length of the type

    srand((unsigned)time(NULL));
    int flag = 0;
    while (!flag) // check if the id is unique
    {
        flag = 1;
        for (a3Car *current = *headLL; current != NULL; current = current->nextCar) { //if not unique -> add random number
            if (current->carId == newCar->carId) { 
                newCar->carId += (rand() % 999) + 1; //add 1-999 randomly to id
                flag = 0; //to repeat the check
                break;
            }
        }
    }

    newCar->nextCar = NULL; // set the next pointer to NULL

    if (*headLL == NULL) // if the list is empty set head to new car
    {
        *headLL = newCar; 
    }

    else // if the list is not empty add the car to the end
    {
        a3Car *current = *headLL;
        while (current->nextCar != NULL) // find the last car
        {
            current = current->nextCar;
        }
        current->nextCar = newCar; // add the new car to end
    }
}
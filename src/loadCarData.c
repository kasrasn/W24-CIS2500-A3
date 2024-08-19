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

void loadCarData (struct car ** headLL, char fileName [MAX_LENGTH]){

    FILE * file = fopen(fileName, "r"); // open the file in read mode
    if (!file) {
        printf("Failed to open file %s\n", fileName);
        return;
    }

    char line[200];
    char *token;

    while (getchar() != '\n') { } // clear the input buffer

    while (fgets(line, sizeof(line), file)) { // read the file line by line
        a3Car *newCar = (a3Car *)malloc(sizeof(a3Car));
        if (newCar == NULL) {
            printf("Memory allocation failed.\n");
            continue;
        }

        // carId
        token = strtok(line, ",");
        newCar->carId = atoi(token);

        // model
        token = strtok(NULL, ",");
        strcpy(newCar->model, token);

        // type
        token = strtok(NULL, ",");
        strcpy(newCar->type, token);

        // year
        token = strtok(NULL, ",");
        newCar->year = atoi(token);

        // price
        token = strtok(NULL, ",");
        newCar->price = atof(token);

        //ensure strings are null terminated
        newCar->model[MAX_LENGTH - 1] = '\0';
        newCar->type[MAX_LENGTH - 1] = '\0';

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

        newCar->nextCar = NULL; // initialize next to NULL.

        if (*headLL == NULL) { // if list empty new car will be the head
            *headLL = newCar; 
        }
        else { // if list not empty new car will be on the end
            a3Car *current = *headLL;
            while (current->nextCar != NULL) {
                current = current->nextCar;
            }
            current->nextCar = newCar;
        }
    }

    printf("data loaded successfully.\n\n"); // print success message
    fclose(file);
}
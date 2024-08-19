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

int main(){

    a3Car * headLL = NULL;
    char fileName [MAX_LENGTH] = "inputFile.txt";

    while(1){ //menu loop until user exits

        //print menu
        printf("1. Add data on a new car\n");
        printf("2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n");
        printf("4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n");
        printf("6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n");
        printf("8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");

        int choice;
        scanf("%d", &choice);

        printf("\n"); 
        switch (choice) // do action based on choice
        {
            case 1: // add new car
                addNewCar(&headLL);
                break;

            case 2: // load data from file
                loadCarData(&headLL, fileName);
                break;

            case 3: // print all cars
                printAll(headLL);
                break;

            case 4: // print one car
                int whichOne = 0;
                while (whichOne < 1 || whichOne > countCars(headLL)) //validate input
                {
                    printf("Enter the position of the car: ");
                    scanf("%d", &whichOne);
                }

                printOne(headLL, whichOne);
                break;

            case 5: // search car by id
                int id;
                printf("Enter a car ID: ");
                scanf("%d", &id);

                int position = lookForCarId(headLL, id);

                if(position == -1){ //if car not found
                    printf("Car not found\n\n");
                }
                else { //if car found
                    printf("Car found at position %d\n\n", position);
                }
                break;

            case 6: // search car by model and type
                char str [100];
 
                while (getchar() != '\n') { } // clear the input buffer

                printf("Enter the model and type you want to search: ");
                fgets(str, sizeof(str), stdin); // read the line
                str[strcspn(str, "\n")] = 0; // remove the newline character
                int pos = lookForCarModelType(headLL, str);

                if(pos == -1){ //if car not found
                    printf("Car not found\n\n");
                }
                else { //if car found
                    printf("Car found at position %d\n\n", pos);
                }
                break;

            case 7: // count cars
                printf("Total number of cars = %d\n\n", countCars(headLL));
                break;

            case 8: // sort the list
                sortCarId(&headLL);
                break;

            case 9: // remove a car
                if (headLL == NULL)
                {
                    printf("list is empty. choose another option.\n\n");
                    break;
                }

                int number = 0;

                while (number < 1 || number > countCars(headLL)) //validate input
                {
                    printf("Enter the number of the car you want to remove: ");
                    scanf("%d", &number);
                }
                oneLessCar(&headLL, number);
                break;

            case 10: // remove all cars
                noMoreCars(&headLL);
                break;

            case 11: // exit
            
                while (headLL != NULL) { // free the linked list to avoid memory leaks
                    a3Car *temp = headLL;
                    headLL = (headLL)->nextCar; 
                    free(temp);
                }

                return 0;
                break;

            default: // invalid choice
                printf("invalid choice. try again\n\n");
                break;
        }
    }
    
    return 0;
}
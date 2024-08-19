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

void convertPrice( char *price) { // format price
    int len = strlen(price);
    int decimalPointIndex = len - 3;
    int commas = (decimalPointIndex - 1) / 3; //number of commas needed
    char *formattedPrice = (char*)malloc(len + commas + 1); // new formatted price
    int formattedIndex = len + commas; // index for the last character in the formatted price

    formattedPrice[formattedIndex--] = '\0'; // null-terminate the string
    
    for (int i = len - 1; i >= decimalPointIndex; --i) { // copy the decimal part
        formattedPrice[formattedIndex--] = price[i];
    }
    
    //integer part
    int commaCounter = 0;
    for (int i = decimalPointIndex - 1; i >= 0; --i) {
        if (commaCounter == 3) { //insert commas
            formattedPrice[formattedIndex--] = ',';
            commaCounter = 0; 
        }
        formattedPrice[formattedIndex--] = price[i]; // copy the integer part
        commaCounter++;
    }
    
    printf("    Price: CDN $%s\n", formattedPrice); // print the formatted price
    free(formattedPrice); // free the memory
    return;
}
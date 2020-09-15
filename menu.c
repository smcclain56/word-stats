/**
Function implementations to get user input for menu item
*/

#include <stdio.h>
#include <string.h>
#include "menu.h"


/**
This method gets the string from the user. I made it's own method so it
can be called again in case 4
*/
 void getString(void){
 	//initialze a temporary string that user adds to
 	char strTemp[MAX_INPUT_LEN];
 	printf("Enter strings (# to stop)\n");
 	do{
 		//store user input in strTempt
 		fgets(strTemp, MAX_INPUT_LEN, stdin);
 		//concatenate str and strTemp
 			strcat(str, strTemp);
 	}
 	//Stop taking input when user types in #
 	while(strcmp(strTemp,"#\n") != 0 );
 	//clear the temporary string for future use
 	strcpy(strTemp, " ");
 }

/**
This method prints out the menu and store whatever option the user chooses
in optionInputted 
@return optionInputted
*/
 int printMenu(void){
 	printf("*** WordStates Menu ***\n");
 	printf("Enter 1 to print vowel and consonant frequency.\n");
 	printf("Enter 2 to print word count.\n");
 	printf("Enter 3 to print histogram.\n");
 	printf("Enter 4 to return to inputting more strings.\n");
 	printf("Enter 5 to quit.\n");

 	//store input in optionInputted and return
 	scanf("%d", &optionInputted);
 	return optionInputted;
}


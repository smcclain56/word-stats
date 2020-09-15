/**
User interaction code. My make file was giving an error so I put all of my code in the main.c
so that it could be run using gcc -Wall -g -o main main.c
@author Sarah McClain
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#include "menu.h"
//#include "stat.h"


#define MAX_INPUT_LEN 128
#define ALPHABET_SIZE 26

typedef struct WordStats{
 	int histo[ALPHABET_SIZE];
 	int wordCount;
 	int vowelCount;
	int consonantCount;
}WordStats;

int optionInputted;
struct WordStats stringStats ={0};
char str[MAX_INPUT_LEN];


void getString(void);
int printMenu(void);
void optionOne(void);
void optionTwo(void);
void optionThree(void);


int main(void){ 
	getString();
	do{
		optionInputted = printMenu();

		switch(optionInputted){
			case 1: 
			//print vowel and consonant frequency
			optionOne();
			break;

			case 2: 
			//print word count
			optionTwo();
			break;

			case 3: 
			//print histogram
			optionThree();
			break;

			case 4:
			//return to inputing strings
			getString();
			break;

			case 5: 
			//quit 			
			break;

			default:
			printf("Error: Unknown option %d. Try again. \n", optionInputted);
			break;
		}
	}while(optionInputted != 5);
	printf("Exiting... \n");
	return 0;
}

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

/**
This method calulates and prints the vowel and consonant frequency amounts.
*/
void optionOne(void){
	//searches string for vowels then updates struct information
	int vowelCount = 0, consonantCount = 0, i;
	for (i=0; str[i] != '\0'; i++){
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
			|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') { 
			vowelCount++;
		}
		else if((str[i]>='a'&& str[i]<='z') || (str[i]>='A'&& str[i]<='Z'))
        {
            consonantCount++;
        }
	}
	//calculate total number of characters and print frequency results
	double total = vowelCount + consonantCount;

	printf("Vowels = %d, (%0.2f%%) ", vowelCount, 100*(vowelCount/total));
	printf("Consonants = %d (%0.2f%%), ", consonantCount, 100*(consonantCount/total)); 
	printf("Total = %0.0f \n", total);

	//update struct information and reset local counters to 0
	stringStats.vowelCount = vowelCount;
	stringStats.consonantCount = consonantCount;
	vowelCount = consonantCount = total = 0;

}

/**
This method calculates and prints the number of words in the strings inputted
*/
void optionTwo(void){
	//we want our possible delimiters to be a space, tab, newline and #
	char tempStr[MAX_INPUT_LEN];
 	char delim[] = " \n\t#";
 	strcpy(tempStr, str);

  
    // Returns first token 
    char *token = strtok(tempStr, delim); 
    int numTokens = 1;
  
    // Keep making tokens while one of the delimiters present in str[]. 

    while (token != NULL) { 
        token = strtok(NULL, delim); 
        numTokens++;
    } 
 	
 	//store word count in struct and print 
    stringStats.wordCount = numTokens-1;
    printf("Word count: %d\n",stringStats.wordCount);

}

/**
This fucntion counts the number of times an alphabetical character appears in the strings inputted and 
creates a historgram to represent the data. (The histogram is not stored in the struct because I 
was confused about how to do that)
*/
void optionThree(void){
	int c = 0, count[ALPHABET_SIZE] = {0}, x, j, i;
	char alph[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	//makes an array that keeps track of number of each character in the string
	while(str[c] != '\0'){
		if((str[c] >= 'a' && str[c] <= 'z')){
			x = str[c] - 'a';
			count[x]++;
		}else if((str[c] >= 'A' && str[c] <= 'Z')){
			x = str[c] - 'A';
			count[x]++;
 		}
		c++;
	}

	 int max = count[0];
	 for(i=1; i<ALPHABET_SIZE-1; i++){
	 	if(max < count[i]){
	 		max = count[i];
	 	}
	 }

	//draws the histogram
	for ( j=max; j > 0; j--){ 	
		for(i=0 ; i < ALPHABET_SIZE -1; i++){    
    		if( count[i] >= j ){
    			printf(" *");
     		}
     		else{
        		printf("  ");
     		}
		}
  		printf("\n");
	}
		//prints alphabet below	
 		for ( i=0 ; i<ALPHABET_SIZE-1 ; i++){
     		printf(" %c",alph[i]);
		}
		printf("\n");
		//prints number of occurances for each letter
		for ( i=0 ; i<ALPHABET_SIZE-1; i++){
     		printf(" %d", count[i]);
		}
		printf("\n");
		
} 








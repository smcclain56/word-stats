/**
Functions to update the struct, the histogram. This file includes the functions that the user picks
*/
#include <stdio.h>
#include <string.h>
#include "stat.h"

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


void optionThree(void){
	int c = 0, count[ALPHABET_SIZE] = {0}, x, j, i;
	char alph[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	//makes an array that keeps track of number of each character in the string
	while(str[c] != '\0'){
		if(str[c] >= 'a' && str[c] <= 'z'){
			x = str[c] - 'a';
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



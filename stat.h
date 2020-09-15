/**
Constants, WordStats struct declaration, function declarations
*/
#include "menu.h"

typedef struct WordStats{
	int histo[ALPHABET_SIZE];
	int wordCount;
	int vowelCount;
	int consonantCount;
} WordStats;

struct WordStats stringStats ={0};

//function prototypes
void optionOne(void);
void optionTwo(void);
void optionThree(void);
	
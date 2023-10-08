// Characters and Strings

//Notice the libary Headers included
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 80

// prototype
void charTesting(char c);
void testFgetsOverflow(void);

int main(void)
{

	char sentenceFgets[SIZE]; // create char array
	char sentenceGetChar[SIZE]; // create char array
	int c; // variable to hold character input by user
	size_t lenString = 0; //length of string
	int i = 0; // counter i 
	size_t sizeString = 0;


	// Fig. 8.10: fig08_10.c
	// Using functions fgets 
	puts("Enter a line of text that is read using fgets ");

	// use fgets to read  text
	fgets(sentenceFgets, SIZE, stdin);
	printf("The string entered using fgets: \n%s\n", sentenceFgets);

	
	// length of string entered using fgets
	lenString = strlen(sentenceFgets);
	sizeString = sizeof(sentenceFgets);
	printf("The length of the string is %lu\n ", lenString);
    printf("The size of the string is %lu\n ", sizeString);
	
	// replacing newline character with null character
    //Update the following to check if newline character existws before replacing with null character
	sentenceFgets[strlen(sentenceFgets) -1] = '\0';
	lenString = strlen(sentenceFgets);
	sizeString = sizeof(sentenceFgets);
    printf("The length of the string after removing new line is %lu\n ", lenString);
	printf("The size of the string after removing new line is %lu\n ", sizeString);
	


	// Fig. 8.11: fig08_11.c
	// Using function getchar.
	// prompt user to enter line of text
	puts("\n\nEnter same line of text using getchar to read the information and see if you can figure out the problem");
		
	// use getchar to read each character
	while ((i < SIZE - 1) && (c = getchar()) != '\n')
	{
		sentenceGetChar[i++] = c;
	}
	sentenceGetChar[i] = '\0'; // terminate string
	
	lenString = strlen(sentenceGetChar);
	printf("The length of the string is %lu ", lenString);
	printf("The character array contains %s", sentenceGetChar);

	// use puts to display sentence
	puts("\nThe line entered was:");
	puts(sentenceGetChar);
    
	puts("\nEnter different characters to test the character-handling library :");
    // use getchar to read each character and use char functions
    while ((i < SIZE - 1) && (c = getchar()) != '\n')
    {
        charTesting(c);
        
    }


	//overflow using fgets
	testFgetsOverflow();

	char readString[5];

	//code to clear buffer if more than SIZE of char entered by user
	puts("Enter more than 4 characters");
	fgets(readString, 5, stdin);
	//check if there was overflow meaning what was entered didn't have room  '\n'
	if (strchr(readString, '\n') == NULL)
	{
		while ((getchar()) != '\n');
	}

	return 0;
}

void testFgetsOverflow(void)
{
		//test how fgets works
		char test[5];
		char buffer[5];
		int c; //char 
		puts("Enter char ");
		fgets(test, 5, stdin);
		printf("Test string 4 chars and space for null: \n%s\n", test);
		if (strchr(test, '\n') == NULL)
		{
			puts("Clear buffer");
			//while ((getchar()) != '\n');
			unsigned int i = 0;
			while ((c = getchar()) != '\n')
			{
				buffer[i++] = c;
				printf("char is %d\n", c);
			}
		}
		else
		{
			puts("do not need to clear buffer");
		}

}


void charTesting(char c)
{

   printf("\nchar testing results for char %c\n", c);
   // test each function of the character-handling library
   printf("isblank(\'%c\')  = %d\n", c, isblank(c));
   printf("isdigit(\'%c\')  = %d\n", c, isdigit(c));
   printf("isalpha(\'%c\')  = %d\n", c, isalpha(c));
   printf("isalnum(\'%c\')  = %d\n", c, isalnum(c));
   printf("isxdigit(\'%c\') = %d\n", c, isxdigit(c));
   printf("islower(\'%c\')  = %d\n", c, islower(c));
   printf("isupper(\'%c\')  = %d\n", c, isupper(c));
   printf("tolower(\'%c\')  = %d\n", c, tolower(c));
   printf("toupper(\'%c\')  = %d\n", c, toupper(c));
   printf("isspace(\'%c\')  = %d\n", c, isspace(c));
   printf("iscntrl(\'%c\')  = %d\n", c, iscntrl(c));
   printf("ispunct(\'%c\')  = %d\n", c, ispunct(c));
   printf("isprint(\'%c\')  = %d\n", c, isprint(c));
   printf("isgraph(\'%c\')  = %d\n", c, isgraph(c));
   puts("");
} 


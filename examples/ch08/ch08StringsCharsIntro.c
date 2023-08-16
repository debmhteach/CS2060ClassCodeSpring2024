// Chars Arrays Strings Pointers Exploration
// Read section 6.5 and 7.10
// Add comments to code to explain or ask questions


#include <stdio.h>
#include <stdlib.h>


// prototype
void reviewChar(void);
void exploreStringCharArray(void);
void testStringOverflow(void);
void arrayPointerString(void);


int main(void)
{

	//reviewChar();
	exploreStringCharArray();
	//arrayPointerString(); 

	return 0;
}


//Understanding array of characters (strings)
void exploreStringCharArray(void)
{

	char string1[] = "string1 C";
	char string2a[] = { 'S', 't', 'r', 'i', 'n', 'g', '2', ' ', 'C' }; 
	char string2b[] = { 'S', 't', 'r', 'i', 'n', 'g', '2', ' ', 'C', '\0'};
	char string3[10] = { " " };
	char* string1Ptr = string1;
	char* string3Ptr = string3;
	char* string4Ptr = "String4Ptr C";
	
	printf("string1[] = %s\n", string1);
	printf("string1[0] = %c\n", string1[0]);
	printf("string2a[] = %s\n", string2a);
	printf("string2b[] = %s\n", string2b);
	printf("string3[] = %s\n", string3);
	printf("*string1Ptr = %s\n", string1Ptr);
	printf("*string3Ptr = %s\n", string3Ptr);
	printf("*string4Ptr = %s\n\n", string4Ptr);

	printf("%s", "Enter a string 9 characters or less into string3: ");
	scanf("%9s", string3);
	printf("string3[] = %s\n", string3);
	printf("*string3Ptr = %s\n\n", string3Ptr);

	/*comment this function out after you see what happens and run again*/
	puts("See what happens when the next function is called. Then comment this function.");
	testStringOverflow();

	/*Comment the next  lines of code after you see what happens here and with the next scanf */
	puts("See what happens when the following overslow is scanned and what happens with next scanf");
	puts("Then comment out the following 4 lines of code");
	printf("%s", "Enter a string more than 9 into string3: ");
	scanf("%9s", string3);
	printf("string3[] = %s\n", string3);
	printf("*string3Ptr = %s\n\n", string3Ptr);
	
	
	printf("%s", "Enter a string  into  string3Ptr that is 9 char or less: ");
	scanf("%9s", string3Ptr);
	printf("string3[] = %s\n", string3);
	printf("*string3Ptr = %s\n\n", string3Ptr);

	printf("%s", "Enter a string into  string1[] that is 9 char or less: ");
	scanf("%9s", string1);
	printf("*string4Ptr = %s\n\n", string1);


	/*comment the following code when you see what happens */
	printf("%s", "Enter a string into  string4Ptrthat is 9 char or less: ");
	scanf("%9s", string4Ptr);
	printf("*string4Ptr = %s\n\n", string4Ptr); 


	printf("string1[] sizeof     = %llu\n", sizeof(string1));
	printf("string2a[] sizeof     = %llu\n", sizeof(string2a));
	printf("string2b[] sizeof     = %llu\n", sizeof(string2b));
	printf("string3[] sizeof     = %llu\n", sizeof(string3));
	printf("*string1Ptr sizeof  = %llu\n", sizeof(*string1Ptr));
	printf("*string3Ptr sizeof  = %llu\n", sizeof(*string3Ptr));

}

void testStringOverflow(void)
{
	char string[10] = { " " };

	printf("%s", "Enter a string longer than 9 characters");
	scanf("%s", string);

}

//Understanding Array of pointers to array of characters
void arrayPointerString(void)
{
	// add comment 
	char suitArray[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *suitPtr[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};	
	
	// add comment 
	printf ("*suitPtr size_of    = %llu\n", sizeof(*suitPtr));
	printf ("suitArray[4][9] sizeof    = %zu\n", sizeof(suitArray));

	puts("\nHow do you access an array of pointers?");
	
	// add comment 
	puts("\nWhat is this doing?");
	printf ("&suitPtr[0] = %p\n", &suitPtr[0]);
	printf ("&suitPtr[1] = %p\n", &suitPtr[1]);
	printf ("&suitPtr[2] = %p\n", &suitPtr[2]);
	printf ("&suitPtr[3] = %p\n", &suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("suitPtr[0] = %p\n", suitPtr[0]);
	printf ("suitPtr[1] = %p\n", suitPtr[1]);
	printf ("suitPtr[2] = %p\n", suitPtr[2]);
	printf ("suitPtr[3] = %p\n", suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("suitPtr[0] = %s\n", suitPtr[0]);
	printf ("suitPtr[1] = %s\n", suitPtr[1]);
	printf ("suitPtr[2] = %s\n", suitPtr[2]);
	printf ("suitPtr[3] = %s\n", suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("*suitPtr[0] = %c\n", *suitPtr[0]);
	printf ("*suitPtr[1] = %c\n", *suitPtr[1]);
	printf ("*suitPtr[2] = %c\n", *suitPtr[2]);
	printf ("*suitPtr[3] = %c\n", *suitPtr[3]);

	// add comment
	puts("\nWhat is this doing?");
	printf ("suitPtr[0][0] = %c\n", suitPtr[0][0]);
	printf ("suitPtr[0][1] = %c\n", suitPtr[0][1]);
	printf ("suitPtr[0][2] = %c\n", suitPtr[0][2]);
	printf ("suitPtr[0][3] = %c\n", suitPtr[0][3]);
	printf ("suitPtr[0][4] = %c\n", suitPtr[0][4]);
	printf ("suitPtr[0][5] = %c\n", suitPtr[0][5]);

	printf("%s", "Enter a string to put in suitArray[1]");
	scanf("%s", suitArray[1]);
	printf("suitArray[1] = %s\n", suitArray[1]);

	printf("%s", "Enter a string to put in suitPtr[0]");
	scanf("%s", suitPtr[0]);
	printf("suitPtr[0] = %s\n", suitPtr[0]);

}


//Understanding chacters 
void reviewChar(void)
{

	// add comment 
	char myCharacter = 'm';
	int myCharacter2 = 'm';

	// add comment 
	puts("What is happening?");
	printf("myCharacter = %d\n", myCharacter);
	printf("myCharacter = %c\n", myCharacter);

	// add comment 
	printf("myCharacter = %d\n", myCharacter2);
	printf("myCharacter = %c\n", myCharacter2);

}

 




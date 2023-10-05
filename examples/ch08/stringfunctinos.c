// Fig. 8.18: fig08_18.c
// Using functions strcmp and strncmp
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void stringCompare(void);
void strcpyEx1(void);
void strcpyEx2(void);
void strncpyEx1(void);
void strncpyEx2(void);
void strchrValidateEmail(const char* emailStr);
void numSpace(void);
void memoryFunctions(void);
void letterAnalysis(void);
void wordSize(void);
void wordOccurs(void);

#define SIZE 80
#define LINES 3
#define ALPHABET 26
#define WORDLENGTH 20


int main(void)
{
	
	//strcpyEx1();
	//strcpyEx2();
	//strncpyEx1();
	//strncpyEx2();
	//stringCompare();

	//notice how test data can be sent in a loop so do not need to enter
    //What is missing from the test data that could happen when a user enters the email from the keyboard?
	
    /*
	const char* emailStr[4] = { "test@uccs.edu", "testuccs.edu", "test@uccsedu", "test.ucce@edu"};
	for (size_t i = 0; i < 4; i++)
	{  
		printf("Email: %s\n", emailStr[i]);
		strchrValidateEmail(emailStr[i]);
	
	}
     */
	

	//numSpace();
	//letterAnalysis();
	//wordSize();
	//wordOccurs();
    //memoryFunctions();

}


void strcpyEx1(void)
{
	char str[] = "ab";
    char s3[3] = {""};
 
    strcpy(s3, str);
	printf("Results of strcpy s3: %s \n", s3);
	for (unsigned int i = 0; i < 3; i++)
	{
		printf ("s3[%d] = %c ascii %d\n", i, s3[i], s3[i]);
	}
}

void strcpyEx2(void)
{
	char str[] = "abcd";
    char s3[3] = {""};
	strcpy(s3, str);
	printf("\nResults of strcpy s3:%s \n", s3);
	for (unsigned int i = 0; i < 3; i++)
	{
		printf("s3[%d] = %c ascii %d\n", i, s3[i], s3[i]);
	}
}


void strncpyEx1(void)
{
	char str[] = "ab";
	char s3[3] = { "" };
	strncpy(s3, str, sizeof(s3));
	printf("Results of strncpy s3: %s \n", s3);
	for (unsigned int i = 0; i < 3; i++)
	{
		printf("s3[%d] = %c ascii %d\n", i, s3[i], s3[i]);
	}
}

void strncpyEx2(void)
{
	char str[] = "abcd";
	char s3[3] = { "" };;
	strncpy(s3, str, (sizeof(s3)-1));
	printf("\nResults of strncpy s3:%s \n", s3);
	for (unsigned int i = 0; i < 3; i++)
	{
		printf("s3[%d] = %c ascii %d\n", i, s3[i], s3[i]);
	}
}


// fig 8.18 in the book
// strcmp and strncmp
void stringCompare(void)
{
	const char *s1 = "happy Spring Break"; // initialize char pointer
	const char *s2 = "HappY Spring Break"; // initialize char pointer
	const char *s3 = "Happy Break"; // initialize char pointer

	printf("%s%s\n%s%s\n%s%s\n\n%s%2d\n%s%2d\n%s%2d\n\n",
	       "s1 = ", s1, "s2 = ", s2, "s3 = ", s3,
	       "strcmp(s1, s2) = ", strcmp(s1, s2),
	       "strcmp(s1, s3) = ", strcmp(s1, s3),
	       "strcmp(s3, s1) = ", strcmp(s3, s1));
	printf("%s%2d\n%s%2d\n%s%2d\n",
	       "strncmp(s1, s3, 6) = ", strncmp(s1, s3, 6),
	       "strncmp(s1, s3, 7) = ", strncmp(s1, s3, 7),
	       "strncmp(s3, s1, 7) = ", strncmp(s3, s1, 7));
}


//figure 8.20
void strchrValidateEmail(const char* emailStr)
{
	char character1 = '@'; // initialize character1
	char character2 = '.'; // initialize character2

	if (strchr(emailStr, character1) != NULL) {
		printf("\'%c\' was found in \"%s\".\n",
			character1, emailStr);
	}
	else { // if character1 was not found
		printf("\'%c\' was not found in \"%s\".\n",
			character1, emailStr);
	}
	// if character2 was found in string
	if (strchr(emailStr, character2) != NULL) {
		printf("\'%c\' was found in \"%s\".\n",
			character2, emailStr);
	}
	else { // if character2 was not found
		printf("\'%c\' was not found in \"%s\".\n",
			character2, emailStr);
	}
}


// strchr
void numSpace(void)
{
	char buffer[SIZE];		// Buffer to hold line of text
	int numSpaces = 0;		// Counter for number of spaces
	char *bufferPtr;		// Pointer to move through string

	puts("\n Number of spaces");

	// Use fgets stops reading when encounters newline, end-of-file indicator, or
	// max # characters rea
	puts ("Enter a sentence");
	fgets (buffer, SIZE, stdin);

	// Set pointer to 1st space in buffer
	// Searching through entire line of text and count the number of spaces
	bufferPtr = strchr (buffer, ' ');

	while (bufferPtr != NULL)
	{
		// Count the space and move pointer to next character
		numSpaces++;
		bufferPtr++;

		// Search for next space
		bufferPtr = strchr (bufferPtr, ' ');
	} // while

	printf ("Text entered was - %s\nIt contains %d spaces\n", buffer, numSpaces);
}


void letterAnalysis(void)
{

	char textLines[LINES][SIZE]; // three lines of text
	char letters[ALPHABET] = { 0 }; // letters of the alphabet

	puts("\nLetter analysis");
	puts("Enter three lines of text:");

	// read 3 lines of text
	for (size_t i = 0; i < LINES; ++i)
	{
		fgets(&textLines[i][0], 80, stdin);
		printf("textlines[%llu] is %s ", i, textLines[i] );
	}

	// loop through 3 strings
	for (size_t i = 0; i < LINES ; ++i)
	{
		// loop through each character until null character
		for (size_t j = 0; textLines[i][j] != '\0'; ++j)
		{

			if (textLines[i][j] == '\n')
			{
				printf("newline \\n");
			}
			printf("char is %c ", textLines[i][j]);
			// if letter, update corresponding array element
			if (isalpha(textLines[i][j]))
			{
				// lowercase a is value 97
				// if letter a then a - a is index 0 for alphabet
				// if letter z then z - a 122 - 97 is 25
				printf("\ntextLines[i][j]) - 'a' is %d \n", tolower(textLines[i][j]) - 'a');
				++letters[tolower(textLines[i][j]) - 'a'];
			}
		}
	}

	puts("\nTotal letter counts:");

	// print letter totals
	for (unsigned int i = 0; i < ALPHABET; ++i)
	{
		printf("%c:%3d\n", 'a' + i, letters[i]);
	}
}

void wordSize(void)
{
	char textLines[LINES][SIZE]; // three lines of text
	size_t lengths[WORDLENGTH] = {0}; // array of length counts

	puts("\nWord Size");
	puts("Enter three lines of text:");

	// read 3 lines of text
	for (size_t i = 0; i < LINES; ++i)
	{
		fgets(&textLines[i][0], 80, stdin);
		printf("textLines[%llu] is %s ", i, textLines[i] );
	}

	puts("\nWord Size");
	// loop through each string
	for (size_t i = 0; i < LINES; ++i)
	{

		// first call tokenizes string with delimiters
		//\0 NULL is placed where delimiter was in text line
		// tokens are . space \n
		char *tokenPtr = strtok(&textLines[i][0], ". \n");
		printf ("%s%s\n", "1st call token = ", tokenPtr);

		// while temp does not equal NULL
		while (tokenPtr)
		{
			// increment corresponding array element for length of current word
			++lengths[strlen(tokenPtr)];
			//after first call the next calls take NULL and delimiter
			//NULL tells it to continue tokenizing from the location saved in last call
			tokenPtr = strtok(NULL, ". \n");
			printf ("%s%s\n", "next call = ", tokenPtr);
		}
	}

	puts("");

	// display results in array
	for (size_t i = 1; i < WORDLENGTH; ++i)
	{
		// if length is not zero
		if (lengths[i])
		{
			printf("%llu word%s of length %llu\n",
			       lengths[i], 1 == lengths[i] ? "" : "s", i);
		}
	}
}

void wordOccurs(void)
{

   puts("\n Word Occurance");
   puts("Enter three lines of text:");
   
   char text[3][80]; // 3 strings from user
   
   // read three lines of text
   for (size_t i = 0; i <= 2; ++i) {
      fgets(&text[i][0], 80, stdin);
   } 
      
   char words[100][20] = {""}; // array of words
   unsigned int count[100] = {0}; // array of word counts

   // loop through 3 strings
   for (size_t i = 0; i <= 2; ++i) {
      
      // get first token
      char * temp = strtok(&text[i][0], ". \n");
      
      // while temp does not equal NULL
	  while (temp) {
		 size_t j;

         // loop through words for match
		 for (j = 0; words[j][0] && strcmp(temp,
            &words[j][0]) != 0; ++j) {
            ; // empty body
         } 

         ++count[j]; // increment count
         
         // if temp could not be found in words array
         if (!words[j][0]) {
            strcpy(&words[j][0], temp);
         } 
            
         temp = strtok(NULL, ". \n");
      } 
   } 
   
   putchar('\n');
   
   // loop through words array
   for (size_t j = 0; words[j][0] != '\0' && j <= 99; ++j) {
      printf("\"%s\" appeared %u time%s\n",
            &words[j][0], count[j], 1 == count[j] ? "" : "s");
   }
}

// memset and memcpy
void memoryFunctions(void)
{
    char src[] = "Difference between memcpy and strcpy";
    char dest[SIZE];
	size_t destLength = 0;
	size_t srcLength = 0;

    puts("\nNo difference between memcpy and strcpy for strings");

    // Now copy the string using memcpy
    memset(dest, '\0', sizeof dest);
    printf("Before memcpy dest = %s\n", dest);
    printf("  strlen(dest) = %llu\n", strlen(dest));
    printf("  sizeof dest  = %llu\n", sizeof dest);

    memcpy(dest, src, SIZE);
    printf("After memcpy dest = %s\n", dest);
    printf("  strlen(dest) = %llu\n", strlen(dest));
    printf("  sizeof dest  = %llu\n", sizeof dest);

    puts("");

    destLength = strlen(dest);

    if (dest[destLength] == '\0')
    {
        printf ("dest[%llu] is NULL terminator\n", destLength);
    }
    else
    {
        printf ("dest[%llu] is not NULL terminator\n", destLength);
    }

    puts ("");

    // Now copy the string using strcpy
    memset (dest, '\0', sizeof dest);
    printf ("Before strcpy dest = %s\n", dest);
    printf ("  strlen(dest) = %llu\n", strlen(dest));
    printf ("  sizeof dest  = %llu\n", sizeof dest);
    strcpy (dest, src);

    printf ("After strcpy dest = %s\n", dest);
    printf ("  strlen(dest) = %llu\n", strlen(dest));
    printf ("  sizeof dest  = %llu\n", sizeof dest);

    puts ("");
    srcLength = strlen(src);

    if (src[srcLength] == '\0')
    {
        printf ("src[%llu] is NULL terminator\n", srcLength);
    }
    else
    {
        printf ("src[%llu] is not NULL terminator\n", srcLength);
    }

    puts ("");
    destLength = strlen(dest);

    if (dest[destLength] == '\0')
    {
        printf ("dest[%llu] is NULL terminator\n", destLength);
    }
    else
    {
        printf ("dest[%llu] is not NULL terminator\n", destLength);
    }

    puts ("");

}






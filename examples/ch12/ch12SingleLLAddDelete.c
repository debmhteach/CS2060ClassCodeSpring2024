/*
Example code to create a linked list of structure
Use this code example instead of the book example
Set debug to see what happens when adding and deleting different nodes.
See if you can determine which line of code runs next before stepping.
What happens if you change void insertNode (Node **headPtr, int number)
to void insertNode (Node *headPtr, int number)?

Add comments to explain code
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



//In this example we will just use a generic name node and data to represent a structure
//
typedef struct node
{
	// 
	int data;
	//
	struct node* nextNodePtr;
}Node;

void exploreDoublePointers();
void printList(Node* listPtr);
void insertNode(Node** headPtr, int number);
void deleteNode(Node** headPtr, int numberToDelete);
void freeRemainingNodes(Node** headPtr);
char validateYesNo();


int main(void)
{
	puts("\n\nExplore linked lists");

	//
	Node* headNodePtr = NULL;
	int number = 0;
	char yesOrNo = ' ';

	printList(headNodePtr);

	//
	do
	{
		//Focusing on linked lists so not validating that a number was entered
		printf("%s", "Enter number ");
		scanf("%d", &number);
		while ((getchar()) != '\n');

		// 
		insertNode(&headNodePtr, number);

		// why does insert node pass the address of head pointer but print list does not?
		printList(headNodePtr);
		printf("%s", "\nDo you want to add another number? ");

		yesOrNo = validateYesNo();
	} while (yesOrNo == 'y');

	//
	do
	{
		//Focusing on linked lists so not validating that a number was entered
		printf("%s", "\nEnter number in the  list to delete ");
		scanf("%d", &number);
		while ((getchar()) != '\n');

		//
		deleteNode(&headNodePtr, number);

		// why does deleteNode pass the address of head pointer but print list does not?
		printList(headNodePtr);

		printf("%s", "\nDo you want to delete another number? ");
		yesOrNo = validateYesNo();

	} while ((yesOrNo == 'y') && (headNodePtr != NULL));

	//
	freeRemainingNodes(&headNodePtr);

	// why does freeRemaingingNodes pass the address of head pointer but print list does not?
	printList(headNodePtr);

	puts("Do You want to explore double pointers");
	yesOrNo = validateYesNo();
	if (yesOrNo == 'y')
	{
		exploreDoublePointers();
	}

	return 0;
}

// 
void insertNode(Node** headPtr, int number)
{
	// 
	Node* newNodePtr = malloc(sizeof(Node));

	// 
	if (newNodePtr != NULL)
	{
		//
		newNodePtr->data = number;
		//
		newNodePtr->nextNodePtr = NULL;

		// 
		Node* previousPtr = NULL;
		// 
		Node* currentPtr = *headPtr;

		//
		while (currentPtr != NULL && currentPtr->data <= number)
		{
			//
			previousPtr = currentPtr;
			//
			currentPtr = currentPtr->nextNodePtr;
		}

		// 
		if (previousPtr == NULL)
		{
			//
			*headPtr = newNodePtr;
		}
		// 
		else
		{
			//
			previousPtr->nextNodePtr = newNodePtr;
		}

		//
		newNodePtr->nextNodePtr = currentPtr;
	}
	//
	else
	{
		printf("No memory to create node for %d\n", number);
	}
} // 


// 
void deleteNode(Node** headPtr, int numberToDelete)
{
	// 
	Node* previousPtr = NULL;
	Node* currentPtr = *headPtr;

	// 
	if (*headPtr != NULL)
	{
		if ((*headPtr)->data == numberToDelete)
		{
			//
			*headPtr = (*headPtr)->nextNodePtr;
			// 
			free(currentPtr);
			currentPtr = NULL;
		}
		else //
		{
			//
			while (currentPtr != NULL && currentPtr->data != numberToDelete)
			{
				// 
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextNodePtr;
			}

			//  	
			if (currentPtr != NULL)
			{
				// 
				previousPtr->nextNodePtr = currentPtr->nextNodePtr;
				//
				free(currentPtr);
				currentPtr = NULL;
			}
			//
			else
			{
				puts("Node to delete not found!");
			}
		}
	}
	else // 
	{
		puts("There aren't any nodes in the list!");
	}

} //deleteNode


// 
void printList(Node* listPtr)
{
	// 
	if (listPtr != NULL)
	{
		printf("%s", "The list is: ");
		//
		Node* currentPtr = listPtr;

		//
		while (currentPtr != NULL)
		{
			// display and go to next node
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextNodePtr;
		}
	}
	// 
	else
	{
		puts("List is empty");
	}
} // 


// 
void freeRemainingNodes(Node** headPtr)
{
	Node* currentPtr = *headPtr;
	Node* nextNodePtr = NULL;

	while (currentPtr != NULL)
	{
		nextNodePtr = currentPtr->nextNodePtr;
		free(currentPtr);
		currentPtr = nextNodePtr;
	}

	*headPtr = NULL;
}

//
char validateYesNo() {
	char validYesNo;

	do {
		puts("Please enter (y)es or (n)o:");
		validYesNo = getchar();
		while (getchar() != '\n');

		validYesNo = tolower(validYesNo);

	} while (validYesNo != 'y' && validYesNo != 'n');

	return  validYesNo;
} //End validateYesNo


void exploreDoublePointers()
{
	int n = 20;
	int* nPtr = NULL;
	int** doublenPtr = NULL;

	puts("int n = 20;  \nint* nPtr = NULL;   \nint** doublenPtr = NULL; ");
	printf("&n = %p\n", &n);
	nPtr = &n;
	puts("Assign nPtr = &n;");
	printf("&nPtr = %p\n", &nPtr);
	printf("nPtr = %p\n", nPtr);
	printf("*nPtr = %d\n", *nPtr);
	doublenPtr = &nPtr;
	puts("Assign doublenPtr = &nPtr;");
	printf("Address &doublenPtr= %p\n", &doublenPtr);
	printf("Value stored at *doublenPtr= %p\n", *doublenPtr);
	printf("Value stored at *nPtr =  %d\n", *nPtr);
	printf("Value stored at **doublenPtr =  %d\n\n", **doublenPtr);


	int n2 = 40;
	printf("n2 = 40;  &n2 = %p\n", &n2);
	*doublenPtr = &n2;
	puts("Assign *doublenPtr = &n2;");
	printf("&doublenPtr= %p\n", &doublenPtr);
	printf("*doublenPtr= %p\n", *doublenPtr);
	printf("&nPtr = %p\n", &nPtr);
	printf("nPtr = %p\n", nPtr);
	printf("Value stored at pointer *nPtr =  %d\n", *nPtr);
	printf("Value stored at another pointer **doublenPtr =  %d\n", **doublenPtr);

}






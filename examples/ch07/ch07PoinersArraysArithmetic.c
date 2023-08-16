/* Chaper 7
   Pointers arrays and arithmentic Explorations
   Add comments to explain
*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void)
{

	//Part 1
	puts("****************************************");
	puts("Part 1:");

	size_t arrayLength = 0;
	size_t sizeArr = 0;
	size_t sizeElem = 0;

	int array[SIZE] = { -7, 0, 11, 22, 25};


	sizeArr = sizeof(array);
	sizeElem = sizeof(array[0]);
	arrayLength = sizeof(array) / sizeof(array[0]);
	printf("sizeof(array): %llu\n", sizeArr);
	printf("sizeofarray[0]): %llu\n", sizeElem);
	printf("sizeof(array) / sizeof(array[0]): %llu\n", arrayLength);

	//arrayLength = *(&array + 1) - array;
	//printf("*(&array + 1) - array: %llu\n", arrayLength);

	
	//Part 2
	puts("****************************************");
	puts("Part 2: pointer to an array");
	int* arrayPtr = array;

	puts("int array[SIZE] = { -7, 0, 11, 22, 25 }");
	puts("int* arrayPtr = array");
	printf("array name value %p\n", array);
	printf("arrayPtr name value %p\n", arrayPtr);
	printf("&array[0] is = %p\n", &array[0]);
	printf("&array[1] is = %p\n", &array[1]);
	printf("&array[2] is = %p\n", &array[2]);
	printf("*array = %d\n", *array);
	printf("*arrayPtr = %d\n\n", *arrayPtr);


	//Part 3 
	puts("Part 3: Adding and Subtracting integers to pointers");
	printf("*(array+ 1) = %d\n", *(array + 1));
	printf("*array + 1 = %d\n", *array + 1);
	printf("*(arrayPtr+ 1) = %d\n", *(arrayPtr + 1));
	printf("*arrayPtr + 1 = %d\n", *arrayPtr + 1);
	printf("*(arrayPtr+ 2) =  %d\n", *(arrayPtr + 2));
	printf("*arrayPtr + 2 = %d\n", *arrayPtr + 2);
	printf("*(arrayPtr+ 4) = %d\n", *(arrayPtr + 4));
	printf("*(arrayPtr+ 5) = %d\n", *(arrayPtr + 5));
	printf("*(arrayPtr - 1): =%d\n", *(arrayPtr -1 ));
	printf("*++arrayPtr = %d\n", *++arrayPtr);
	printf("*arrayPtr = %d\n", *arrayPtr);
	printf("*arrayPtr++ = %d\n", *arrayPtr++);
	printf("*arrayPtr = %d\n", *arrayPtr);
	printf("*arrayPtr++ = %d\n", *arrayPtr++);
	printf("*arrayPtr = %d\n", *arrayPtr);
	printf("*--arrayPtr = %d\n", *--arrayPtr);
	printf("*arrayPtr = %d\n", *arrayPtr);
	arrayPtr = array;
	puts("int* arrayPtr = array");
	printf("*arrayPtr = %d\n", *arrayPtr);

	puts("");

	//Part 4 Assign Pointer to another pointer and subtracting pointers
	puts("Assign Pointer to another pointer");
	int* array2Ptr = &array[3];
	puts("int* array2Ptr = &array[3]");
	printf("*array2Ptr = %d\n", *array2Ptr);
	printf("*(array2Ptr +1) = %d\n", *(array2Ptr + 1));
	printf("*(array2Ptr -1) = %d\n", *(array2Ptr - 1));
	printf("array2Ptr - arrayPtr = %llu\n", array2Ptr - arrayPtr);
	printf("arrayPtr - array2Ptr = %llu\n", arrayPtr - array2Ptr);
	puts("Error arrayPtr +array2Ptr = %d\n");


	//Part 5 Refer to Elements in an Array: Pointer Offset and Subscript Notation
	puts("\nPart 5: refer to array elements\n");

	puts("array printed with:\nArray index notation");
	for (size_t i = 0; i < SIZE; ++i)
	{
		printf("array[%llu] = %d\n", i, array[i]);
	}

	puts("\nPointer offset notation");
	for (size_t offset = 0; offset < SIZE; ++offset)
	{
		printf("*(array + %llu) = %d\n", offset, *(array + offset));
	}

	return 0;
}





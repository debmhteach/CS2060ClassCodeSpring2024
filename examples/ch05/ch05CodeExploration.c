/*
Chapter 5 Class Exploration 

Description: Functions, automatic conversions, pass by value
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define function prototypes
int autoConvertToInt (int first, int second);
void swap(int a, int b);
void testStaticVar(void);
void fun(int num1, int num2);


//Add your own comments to explain the code

int main() 
{

	//initialize variables
	int baseNum = 3;
	int powerNum = 4;
	float powerResult = 0;
	
	float first = 10.5;
	float second = 5.5;	
 	float third = 0;
 		
	// AutoConversion
	// Works, no compiler error ? 
    puts("Part 1: Conversion");
	//double pow(double x, double y)
	powerResult = pow(baseNum, powerNum);
	printf("powerResult %f \n", powerResult);
	printf("powerResult %d \n\n", powerResult);
	
	//int autoConvertToInt (int first, int second);
	third = autoConvertToInt(first, second);

	printf("third = %.2f\n", third);
	printf("third= %d\n", third);
			
	// part 2 pass by value
	puts ("\nPart 2 Pass by Value");
	int num1 = 7;
	int num2 = 82;

	//swap function will not change number1 or number2
	fun(num1, num2);
	puts("After fun");
	printf ("num1 = %d\n", num1);
	printf ("num2 = %d\n", num2);
		
	//part 3
    puts("Part 3 static and non-static variables");
	testStaticVar();
	testStaticVar();
	testStaticVar();
	
	return 0;
}

//see how autoconvert works when types do not match
int autoConvertToInt (int first, int second)

{

   return first + second;

}// end autoconvert

// Function to swap two integers values
void fun (int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
	puts("Fun function");
	printf ("num1 = %d\n", num1);
	printf ("num2 = %d\n", num2);	
} 

void testStaticVar(void)
{
	int notStaticVar = 1;
    static int staticVar = 100;
    printf("notStaticVar = %d\n", notStaticVar);
    printf("staticVar = %d\n\n", staticVar);
    notStaticVar++;
    staticVar++;
}









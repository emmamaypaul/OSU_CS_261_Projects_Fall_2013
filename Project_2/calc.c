/* CS261- Assignment 2 - calc.c*/
/* Name: Emma Paul
 * Date: October 20, 2013
 * Solution description: This program demonstrates calculator functions using a stack
 * Note: I worked with and completed my homework with Ian Paul
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"
#include <math.h>
#include <assert.h>



/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{

	if(sizeDynArr(stack) < 2)
	{
		printf("Too Few Operators!!!");
	}

	else
	{

	double a;
	double b;
	//double c;



	a = topDynArr(stack);
	popDynArr (stack);
	b = topDynArr(stack);
	popDynArr (stack);

	if(sizeDynArr(stack)!=0)
	{
		printf("Too Many Operators!!!");
	}
	else
	{
	double c = a + b;

	pushDynArr(stack, c);


	printf("%f + %f =  %f\n", b,a,c);
	}
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{

	//assert(stack->size >=2);

	if(sizeDynArr(stack) < 2)
		{
			printf("Too Few Operators!!!");
		}

		else
		{

		double a;
		double b;
		double c;

		a = topDynArr(stack);
		popDynArr (stack);
		b = topDynArr(stack);
		popDynArr (stack);

		if(sizeDynArr(stack)!=0)
			{
				printf("Too Many Operators!!!");
			}
			else
			{


		c = b-a;

		pushDynArr(stack, c);

		printf("%f - %f =  %f\n", b,a,c);
			}
		}

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 2)
			{
				printf("Too Few Operators!!!");
			}

			else
			{

			double a;
			double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);
			b = topDynArr(stack);
			popDynArr (stack);

			if(sizeDynArr(stack)!=0)
				{
					printf("Too Many Operators!!!");
				}
			else
				{

			c = b/a;

			pushDynArr(stack, c);

			printf("%f / %f =  %f\n", b,a,c);
				}
			}
}

void multiply(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 2)
		{
			printf("Too Few Operators!!!");
		}

	else
		{

			double a;
			double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);
			b = topDynArr(stack);
			popDynArr (stack);

			if(sizeDynArr(stack)!=0)
				{
					printf("Too Many Operators!!!");
				}
			else
				{

			c = a*b;

			pushDynArr(stack, c);

			printf("%f x %f =  %f\n", b,a,c);
				}
			}

}

void power(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 2)
		{
			printf("Too Few Operators!!!");
		}

	else
		{

			double a;
			double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);
			b = topDynArr(stack);
			popDynArr (stack);

	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{

			c = pow(b, a);

			pushDynArr(stack, c);

			printf("%f ^ %f =  %f\n",b,a,c);
		}
	}
}

void square(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}

	else
		{

			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);
	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{


			c =(a*a);

			pushDynArr(stack, c);

			printf("The Square of %f = %f\n", a,c);
		}
	}

}

void cube(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 1)
	{
		printf("Too Few Operators!!!");
	}

	else
	{

			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{


			c = pow(a,3);

			pushDynArr(stack, c);

			printf("The Cube of %f =  %f", a,c);
		}
	}

}

void absolutValue(struct DynArr *stack)
{

	//assert(stack->size >=2);

	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}

	else
		{

			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{

			c = abs(a);

			pushDynArr(stack, c);

			printf("The absolute value of %f =  %f", a,c);
		}
	}

}

void squareRoot(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}

	else
		{


			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);
	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{

			c = sqrt(a);

			pushDynArr(stack, c);

			printf("The Square Root of %f =  %f", a,c);
		}
	}

}

void exponential(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}

	else
		{

			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{

			c = pow(2, a);

			pushDynArr(stack, c);

			printf("The exponential of %f =  %f", a,c);
		}
	}

}


void naturalLog(struct DynArr *stack)
{

	//assert(stack->size >=2);
	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}
	else
		{
			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);


	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{
			c = log(a);

			pushDynArr(stack, c);

			printf("The Natural Log of %f =  %f", a,c);
		}
	}

}

void logFunc(struct DynArr *stack)
{


	//assert(stack->size >= 2);
	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}

	else
		{
			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{

			c = log10(a);

			pushDynArr(stack, c);

			printf("The Log of %f =  %f", a,c);
		}
	}

}

void percentage(struct DynArr *stack)
{

	if(sizeDynArr(stack) < 1)
		{
			printf("Too Few Operators!!!");
		}

	else
		{
			double a;
			double b;

			a = topDynArr(stack) / 100;
			popDynArr (stack);
			b = topDynArr(stack);
	if(sizeDynArr(stack)!=0)
		{
			printf("Too Many Operators!!!");
		}
	else
		{
			b = b * a;
			pushDynArr(stack, b);
		}
	printf("%f is %f of 100",a, b);
}
}
void sineFnc(struct DynArr *stack)
{

	if(sizeDynArr(stack) < 1)
			{
				printf("Too Few Operators!!!");
			}

		else
			{
			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);
		if(sizeDynArr(stack)!=0)
			{
				printf("Too Many Operators!!!");
			}
		else
			{
		c = asin(a);

			pushDynArr(stack, c);

			printf("The sin of %f = %f", a,c);
			}
			}
}
void cosineFnc(struct DynArr *stack)
{

	if(sizeDynArr(stack) < 1)
			{
				printf("Too Few Operators!!!");
			}

		else
			{
			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

			if(sizeDynArr(stack)!=0)
				{
					printf("Too Many Operators!!!");
				}
			else
				{

			c = cos(a);

			pushDynArr(stack, c);

			printf("The cos of %f = %f", a,c);
				}
			}
}
void tanFnc(struct DynArr *stack)
{

	if(sizeDynArr(stack) < 1)
			{
				printf("Too Few Operators!!!");
			}

		else
			{
			double a;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

		if(sizeDynArr(stack)!=0)
			{
				printf("Too Many Operators!!!");
			}
		else
			{

			c = atan(a);
			pushDynArr(stack, c);
			}
		printf("The tan of %f = %f",a, c);
			}
}
void ceilFnc(struct DynArr *stack)
{

	if(sizeDynArr(stack) < 1)
			{
				printf("Too Few Operators!!!");
			}

		else
			{
			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

		if(sizeDynArr(stack)!=0)
			{
				printf("Too Many Operators!!!");
			}
		else
			{

			c = ceil(a);

			pushDynArr(stack, c);

			printf("The ceiling of %f = %f",a, c);
			}
			}
}
void floorFnc(struct DynArr *stack)
{

	if(sizeDynArr(stack) < 1)
			{
				printf("Too Few Operators!!!");
			}

		else
			{
			double a;
			//double b;
			double c;

			a = topDynArr(stack);
			popDynArr (stack);

		if(sizeDynArr(stack)!=0)
			{
				printf("Too Many Operators!!!");
			}
		else
			{

			c = floor(a);

			pushDynArr(stack, c);

			printf("The floor %f = %f  ",a, c);
			}
			}
}
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double n;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)

			multiply(stack);

		else if(strcmp(s, "^") == 0)

			power(stack);

		else if(strcmp(s, "^2") == 0)

			square(stack);

		else if(strcmp(s, "^3") == 0)

			cube(stack);

		else if(strcmp(s, "abs") == 0)

			absolutValue(stack);

		else if(strcmp(s, "sqrt") == 0)

			squareRoot(stack);

		else if(strcmp(s, "exp") == 0)

			exponential(stack);

		else if(strcmp(s, "ln") == 0)

			naturalLog(stack);

		else if(strcmp(s, "log") == 0)

			logFunc(stack);

		else if(strcmp(s, "%") == 0)
			percentage(stack);
		else if(strcmp(s, "asin") == 0)
			sineFnc(stack);
		else if(strcmp(s, "cos") == 0)
			cosineFnc(stack);
		else if(strcmp(s, "atan") == 0)
			tanFnc(stack);
		else if(strcmp(s, "ceil") == 0)
			ceilFnc(stack);
		else if(strcmp(s, "floor") == 0)
			floorFnc(stack);
		else if(strcmp(s, "pi") == 0)
			{
				double pi = 3.14159265;
				pushDynArr(stack, pi);
			}
		else if(strcmp(s, "e") == 0)
			{
				double e = 2.7182818;
				pushDynArr(stack, e);
			}

		else if(strcmp(s, "!") == 0)
			printf("! is not an operator");

		else if(strcmp(s, "@") == 0)
			printf("@ is not an operator");

		else if(strcmp(s, "#") == 0)
			printf("# is not an operator");

		else if(strcmp(s, "$") == 0)
			printf("$ an operator");

		else if(strcmp(s, "&") == 0)
			printf("& is not an operator");

		else if(strcmp(s, "(") == 0)
			printf("( is not an operator");

		else if(strcmp(s, ")") == 0)
			printf(") is not an operator");

		else if(strcmp(s, "a")==0 || strcmp(s, "b")==0 || strcmp(s, "c")==0
				|| strcmp(s, "d")==0|| strcmp(s, "f")==0
				|| strcmp(s, "g")==0|| strcmp(s, "h")==0|| strcmp(s, "i")==0
				|| strcmp(s, "j")==0|| strcmp(s, "k")==0|| strcmp(s, "l")==0
				|| strcmp(s, "m")==0|| strcmp(s, "n")==0|| strcmp(s, "o")==0
				|| strcmp(s, "q")==0|| strcmp(s, "r")==0|| strcmp(s, "s")==0
				|| strcmp(s, "t")==0|| strcmp(s, "u")==0|| strcmp(s, "v")==0
				|| strcmp(s, "w")==0|| strcmp(s, "y")==0|| strcmp(s, "z")==0
				|| strcmp(s, "A")==0|| strcmp(s, "B")==0|| strcmp(s, "C")==0
				|| strcmp(s, "D")==0|| strcmp(s, "E")==0|| strcmp(s, "F")==0
				|| strcmp(s, "G")==0|| strcmp(s, "H")==0|| strcmp(s, "I")==0
				|| strcmp(s, "J")==0|| strcmp(s, "K")==0|| strcmp(s, "L")==0
				|| strcmp(s, "M")==0|| strcmp(s, "N")==0|| strcmp(s, "O")==0
				|| strcmp(s, "P")==0|| strcmp(s, "Q")==0|| strcmp(s, "R")==0
				|| strcmp(s, "S")==0|| strcmp(s, "T")==0|| strcmp(s, "U")==0
				|| strcmp(s, "V")==0|| strcmp(s, "W")==0|| strcmp(s, "Y")==0
				|| strcmp(s, "X")==0|| strcmp(s, "Z")==0)
			printf("Letters are not numbers or operators!");

		else if (isNumber (s, &n) == 0)
			printf("Not a real math function!!!");

		else
			isNumber(s, &n);
			pushDynArr(stack, n);
	}

	result = topDynArr(stack);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;


	calculate(argc,argv);
	return 0;
}


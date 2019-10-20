// main.c
#include <stdio.h>
#include "lib/testlib.h"

main()
{
	float num1, num2;
	char choice;

	printf("first num : ");
	scanf("%f", &num1);

	printf("choice(+,-,*,/) : ");
	scanf(" %c", &choice);

	printf("second num : ");
	scanf("%f", &num2);

	switch(choice){
		case '+':
			printf("result : %.1f\n", add(num1, num2));
			break;
		case '-':
			printf("result : %.1f\n", subtract(num1, num2));
			break;
		case '*':
			printf("result : %.1f\n", multiply(num1, num2));
			break;

		case '/':
			printf("result : %.1f\n", divide(num1, num2));
			break;
		default :
			return 0;
		}
}

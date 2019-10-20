/* dltest.c */
#include <stdio.h>
#include <dlfcn.h>
main()
{
	void *handle;
	float (*add)(float, float), (*subtract)(float, float);
	float (*multiply)(float, float), (*divide)(float, float);
	char *error;

	float num1, num2;
	char choice;

	handle = dlopen ("./lib/libtest.so", RTLD_LAZY);

	if (!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}
	add = dlsym(handle, "add"); 
	if ((error = dlerror()) != NULL) { 
		fprintf (stderr, "%s", error); 
		exit(1); 
	}
	subtract = dlsym(handle, "subtract");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	multiply = dlsym(handle, "multiply");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	divide = dlsym(handle, "divide");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "%s", error);
		exit(1);
	}
	
	printf("first num : ");
	scanf("%f", &num1);

	printf("choice(+,-,*,/) : ");
	scanf(" %c", &choice);

	printf("second num : ");
	scanf("%f", &num2);

	switch(choice){
		case '+':
			printf("result : %.1f\n", (*add)(num1, num2));
			break;
		case '-':
			printf("result : %.1f\n", (*subtract)(num1, num2));
			break;
		case '*':
			printf("result : %.1f\n", (*multiply)(num1, num2));
			break;
		case '/':
			printf("result : %.1f\n", (*divide)(num1, num2));
			break;
		default :
			return 0;
		}

	dlclose(handle);
}

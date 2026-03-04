#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>

typedef struct someData_s {
	int32_t numberOfThings;
	char * someString;
} someData_t;

int main(void) {
	// (1)
	char* someBuffer = malloc(10);
	strcpy(someBuffer, "password");

	// (2)
	char* someOtherBuff = malloc(10);
	
	// (3)
	someData_t* someStructInMemory = malloc(sizeof(someData_t));
	someStructInMemory->someString = malloc(sizeof(char) * 32);

	// (4)
	strcpy(someStructInMemory->someString, "hunter2");
	someStructInMemory->numberOfThings = strlen(someStructInMemory->someString);

	printf("My password is: %s\n", someStructInMemory->someString);
	printf("My password is: %d chars in length\n", someStructInMemory->numberOfThings);

	// now lets suppose that we need to do some work on the 2nd buffer that we created in (2)
	// and by some happenstance we end up writing someBuffer 40 bytes past someOtherBuff
	*(uint64_t*)(someOtherBuff + 40) = (uint64_t)someBuffer;

	// and lets check back in on our password
	printf("My password is: %s\n", someStructInMemory->someString);

    return 0;
}

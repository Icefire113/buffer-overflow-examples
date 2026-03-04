#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>

typedef struct someData_s {
	int32_t numberOfThings;
	char * someString;
} someData_t;

uint64_t hash_fn(uint64_t curHash, char letter) {
	// THIS IS A BAD HASH FUNCTION, DO NOT USE IT
	uint64_t h = curHash;
	h = letter ^ h;
	h += (h << 8) ^ letter;
	return h;
}

int main(void) {
	// (1)
	char* someBuffer = malloc(10);

	// (2)
	someData_t* someStructInMemory = malloc(sizeof(someData_t));
	someStructInMemory->someString = malloc(sizeof(char) * 32);

	// (3)
	strcpy(someStructInMemory->someString, "password");
	someStructInMemory->numberOfThings = strlen(someStructInMemory->someString);
	printf("My password is: %s\n", someStructInMemory->someString);
	printf("My password is: %d chars in length\n", someStructInMemory->numberOfThings);
	
	// Let's hash our password :)
	uint64_t hash = 0;
	for (uint64_t i = 0; i < someStructInMemory->numberOfThings; i++) {
		hash = hash_fn(hash, someStructInMemory->someString[i]);
	}
	printf("Our final hash is %016lX\n", hash);
	
	// now lets update that buffer we created in [1]
	// and lets put the letters A-Z and 0-9 in there
	for (uint64_t i = 0; i <= 36; i++) {
		someBuffer[i] = (char)i + 'A';
	}
	
	// and now lets check in on our password
	printf("My password is: %d chars in length\n", someStructInMemory->numberOfThings);
	
	// and let's update the hash just to re-check it
	hash = 0;
	for (uint64_t i = 0; i < someStructInMemory->numberOfThings; i++) {
		hash = hash_fn(hash, someStructInMemory->someString[i]);
	}
	printf("Our final hash is %016lX\n", hash);

    return 0;
}

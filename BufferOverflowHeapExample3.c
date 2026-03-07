#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>

// A custom implementation of a string type for C
typedef struct string {
	int32_t numberOfThings;
	char * someString;
} string_t;

typedef struct fileHeader_s_OLD {
	char magic[4];
	uint32_t entryCount;
} fileHeader_t_OLD;

// Designed to look like a header on a made up file format
// though it bears some resembelence to some file headers I have created
typedef struct fileHeader_s {
	char magic[4];
	uint32_t version;
	uint64_t entryCount;
	uint64_t dataHash;
	uint64_t flags;
	uint64_t entrySize;
	// a list of some opaque entries in the file
	void* entries;
} fileHeader_t;

int main(void) {
	// (1)
	char* someBuffer = malloc(10);
	strcpy(someBuffer, "password");

	// (2)
	void* someOtherBuff = malloc(sizeof(fileHeader_t_OLD));
	
	// (3)
	string_t* someStructInMemory = malloc(sizeof(string_t));
	someStructInMemory->someString = malloc(sizeof(char) * 32);

	// (4)
	strcpy(someStructInMemory->someString, "hunter2");
	someStructInMemory->numberOfThings = strlen(someStructInMemory->someString);

	printf("My password is: %s\n", someStructInMemory->someString);

	// now lets suppose that we need to do some work on the file header that we created
	// and we need to set the entries to be the buffer that contains our string in (1)
	((fileHeader_t*)someOtherBuff)->entries = someBuffer;

	// and lets check back in on our password
	printf("My password is: %s\n", someStructInMemory->someString);

    return 0;
}

#include<iostream>
#include<vector>
#include<cstdint>

int main() {
	// (1)
	std::vector<uint32_t> vec = {2,4,6,8,10,12,14};
	// lets get the first element
	printf("vec[0]: %d\n", vec[0]);
	// we can also do it like so:
	printf("vec.at(0): %d\n", vec.at(0));
	
	// but what about reading a number from way into our buffer?
	// and to make it more safe, lets try/ catch it
	try {		
		printf("vec[100]: %d\n", vec[100]);
	} catch (std::exception e) {
		printf("ERR! %s\n", e.what());
	}
	
	try {
		printf("vec.at(100): %d\n", vec.at(100));
	} catch (std::exception e) {
		printf("ERR! %s\n", e.what());
	}

    return 0;
}

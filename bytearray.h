#include <string>

typedef unsigned int uint;

class ByteArray {
	struct Data {
		char* data;
		uint size;
	};
	Data d;
public:
	ByteArray(const char *aStr);
	uint getSize();
	char* getString();
};
typedef unsigned int uint;

class ByteArray {
	struct Data {
		char* data;
		uint size;
	};
	Data d;
public:
	ByteArray(char *aStr);
	uint getSize();
	char* getString();
};
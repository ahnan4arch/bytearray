#include <string>

typedef unsigned int uint;

class ByteArray {
	struct Data {
		char* data;
		int size;
	};
	Data d;
public:
	ByteArray(const ByteArray&);
	ByteArray(const char *aStr = 0);

	int size() const;
	const char* data() const;
	ByteArray toHex() const;
	char at(int aI) const { if(aI >= 0 && aI < d.size) return d.data[aI]; };

	/* static */
	static ByteArray fromHex(const ByteArray&);	

	/* operator */
	ByteArray& operator=(const ByteArray&);
};
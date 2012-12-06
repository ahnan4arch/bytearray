#include <string>

#define BA_DEBUG

#ifdef BA_DEBUG
	#include <iostream>
#endif

typedef unsigned int uint;

class ByteArray {
	char *ba_data;
	int ba_size;
public:
	ByteArray(const ByteArray&);
	ByteArray(const int);
	ByteArray(const char *aStr);
	~ByteArray() { 
		delete[] ba_data;
	}

	int size() const { return ba_size; }
	const char* data() const { return ba_data; }

	bool isNull() {
		if(ba_data == NULL) {
			return true;
		}
		return false;
	}
	
	ByteArray toHex() const;

	char at(int aI) const { 
		if(aI >= 0 && aI < ba_size)
			return ba_data[aI]; 
	}

	/* static */
	static ByteArray fromHex(const ByteArray&);	

	/* operator */
	ByteArray& operator=(const ByteArray&);
};
#include "bytearray.h"

ByteArray::ByteArray(const char *aStr) { 
	if(aStr) {
		d.size = std::strlen(aStr);
		d.data = new char[d.size + 1];
		std::strcpy(d.data, aStr);
	}
}

uint 
	ByteArray::getSize() {
		return d.size;
}

char*
	ByteArray::getString() {
		return d.data;
}
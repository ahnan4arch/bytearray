#include "bytearray.h"

ByteArray::ByteArray(char *aStr) { 
	if(aStr) { 
		d.data = aStr; 
		d.size = sizeof( &aStr ); 
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
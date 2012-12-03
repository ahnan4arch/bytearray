#include "bytearray.h"

ByteArray::ByteArray(const char *aStr) { 
	if(aStr) {
		d = new Data;
		d->size = std::strlen(aStr);
		d->data = new char[d->size + 1];
		std::strcpy(d->data, aStr);
	}
	else {
		d = new Data;
		d->size = 0;
		d->data = 0;
	}
}

ByteArray::ByteArray(const int aSize) { 
	if(aSize > 0) {
		d = new Data;
		d->size = aSize;
		d->data = new char[aSize + 1];
	}
	else {
		d = new Data;
		d->size = 0;
		d->data = 0;
	}
}

ByteArray::ByteArray(const ByteArray& aA) {
	d = new Data;
	d->size = aA.size();
	d->data = new char[aA.size() + 1];
	std::strcpy(d->data, aA.data());

	std::cout << d->size;
}

int 
	ByteArray::size() const {
		return d->size;
}

const char*
	ByteArray::data() const {
		return d->data;
}

ByteArray 
	ByteArray::toHex() const {
		ByteArray res(d->size * 2);
		unsigned char *hexData = (unsigned char *)res.d->data;
		for (int i = 0; i < d->size; ++i) {
			int j = (d->data[i] >> 4) & 0xf;
			if (j <= 9)
				hexData[i*2] = (j + '0');
			else
				hexData[i*2] = (j + 'a' - 10);
			j = d->data[i] & 0xf;
			if (j <= 9)
				hexData[i*2+1] = (j + '0');
			else
				hexData[i*2+1] = (j + 'a' - 10);
		}
		return res;
}

/* static */
ByteArray
	ByteArray::fromHex(const ByteArray& aBa) {
		ByteArray res((aBa.size() + 1) / 2);
		unsigned char *encodedData = (unsigned char *)res.d->data;

		for(int j = 0; j < aBa.size(); j++)
		{
			int ret = 0;
			for(int i = j*2; i < j*2+2; i++ )
			{				
				char c = aBa.data()[i];
				int n = 0;
				if( '0' <= c && c <= '9' )
					n = c - '0';
				else if( 'a' <= c && c <= 'f' )
					n = 10 + c - 'a';
				else if( 'A' <= c && c <= 'F' )
					n = 10 + c - 'A';
				ret = n + ret * 16;
			}
			encodedData[j] = (unsigned char)ret;
		}
		return res;
}

/* operator */
ByteArray& 
	ByteArray::operator=(const ByteArray& aBa) {
		if(this != &aBa) {			
			delete[] d->data;
			d->data = new char[aBa.size() + 1];
			std::strcpy(d->data, aBa.data());
			d->size = aBa.size();
		}
		return *this;
}

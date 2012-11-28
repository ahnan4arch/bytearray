#include "bytearray.h"

ByteArray::ByteArray(const char *aStr) { 
	if(aStr) {
		d.size = std::strlen(aStr);
		d.data = new char[d.size];
		std::strcpy(d.data, aStr);
	}
	else {
		d.size = 0;
		d.data = 0;
	}
}

ByteArray::ByteArray(const ByteArray& aA) : d(aA.d) {}

int 
	ByteArray::size() const {
		return d.size;
}

const char*
	ByteArray::data() const {
		return d.data;
}

ByteArray 
	ByteArray::toHex() const {
		unsigned char *rez = new unsigned char[d.size * 2];
		for (int i = 0; i < d.size; ++i) {
			int j = (d.data[i] >> 4) & 0xf;
			if (j <= 9)
				rez[i*2] = (j + '0');
			else
				rez[i*2] = (j + 'a' - 10);
			j = d.data[i] & 0xf;
			if (j <= 9)
				rez[i*2+1] = (j + '0');
			else
				rez[i*2+1] = (j + 'a' - 10);
		}
		return ByteArray((char*)rez);
}

/* static */
ByteArray
	ByteArray::fromHex(const ByteArray& aBa) {
		//ByteArray ba;
		//ba.d.data = 

		unsigned char *rez = new unsigned char[(aBa.size() + 1) / 2];
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
			rez[j] = (unsigned char)ret;
		}
		return ByteArray((char*)rez);
}

/* operator */
ByteArray& 
	ByteArray::operator=(const ByteArray& aBa) {
		if(this != &aBa) {
			char *_t = d.data;
			delete[] _t;
			d.data = new char[aBa.size()];
			d.size = aBa.size();
		}
		return *this;
}

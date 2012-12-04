#include "bytearray.h"

ByteArray::ByteArray(const char *aStr, const int aSize) { 
	if(aStr) {
		ba_size = std::strlen(aStr);
		ba_data = new char[ba_size + 1];
		std::strcpy(ba_data, aStr);
	}
	else {
		ba_size = 0;
		ba_data = 0;
	}
}

ByteArray::ByteArray(const int aSize) { 
	if(aSize > 0) {
		ba_size = aSize;
		ba_data = new char[ba_size + 1];
	}
	else {
		ba_size = 0;
		ba_data = 0;
	}
}

ByteArray::ByteArray(const ByteArray& aA) : ba_size(aA.size()) {
	ba_data = new char[ba_size + 1];
	std::strcpy(ba_data, aA.data());
#ifdef BA_DEBUG
	std::cout << "copy cnstr. size: " << ba_size << "\n";
#endif
}

ByteArray 
	ByteArray::toHex() const {
		ByteArray res(ba_size * 2);
		unsigned char *hexData = (unsigned char *)res.ba_data;
		const unsigned char *data = (const unsigned char *)ba_data;

		for (int i = 0; i < ba_size; ++i) {
			int j = (data[i] >> 4) & 0xf;
			if (j <= 9)
				hexData[i*2] = (j + '0');
			else
				hexData[i*2] = (j + 'a' - 10);
			j = data[i] & 0xf;
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
		ByteArray res(aBa.size() / 2);
		unsigned char *encodedData = (unsigned char*)res.ba_data;

		for(int j = 0; j < aBa.size() / 2; j++)
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
#ifdef BA_DEBUG
		std::cout << "encoded len: " << std::strlen((char*)encodedData) << "\n";
#endif
		return res;
}

/* operator */
ByteArray& 
	ByteArray::operator=(const ByteArray& aBa) {
		if(this != &aBa) {			
			delete[] ba_data;

			ba_size = aBa.size();
			ba_data = new char[ba_size + 1];
			std::strcpy(ba_data, aBa.data());			
		}
		return *this;
}

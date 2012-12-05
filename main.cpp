//#include <iostream>
#include <fstream>

#include "bytearray.h"

static void cp1251_to_utf8(char *out, const char *in) {
    static const int table[128] = {                    
        0x82D0,0x83D0,0x9A80E2,0x93D1,0x9E80E2,0xA680E2,0xA080E2,0xA180E2,
        0xAC82E2,0xB080E2,0x89D0,0xB980E2,0x8AD0,0x8CD0,0x8BD0,0x8FD0,    
        0x92D1,0x9880E2,0x9980E2,0x9C80E2,0x9D80E2,0xA280E2,0x9380E2,0x9480E2,
        0,0xA284E2,0x99D1,0xBA80E2,0x9AD1,0x9CD1,0x9BD1,0x9FD1,               
        0xA0C2,0x8ED0,0x9ED1,0x88D0,0xA4C2,0x90D2,0xA6C2,0xA7C2,              
        0x81D0,0xA9C2,0x84D0,0xABC2,0xACC2,0xADC2,0xAEC2,0x87D0,              
        0xB0C2,0xB1C2,0x86D0,0x96D1,0x91D2,0xB5C2,0xB6C2,0xB7C2,              
        0x91D1,0x9684E2,0x94D1,0xBBC2,0x98D1,0x85D0,0x95D1,0x97D1,            
        0x90D0,0x91D0,0x92D0,0x93D0,0x94D0,0x95D0,0x96D0,0x97D0,
        0x98D0,0x99D0,0x9AD0,0x9BD0,0x9CD0,0x9DD0,0x9ED0,0x9FD0,
        0xA0D0,0xA1D0,0xA2D0,0xA3D0,0xA4D0,0xA5D0,0xA6D0,0xA7D0,
        0xA8D0,0xA9D0,0xAAD0,0xABD0,0xACD0,0xADD0,0xAED0,0xAFD0,
        0xB0D0,0xB1D0,0xB2D0,0xB3D0,0xB4D0,0xB5D0,0xB6D0,0xB7D0,
        0xB8D0,0xB9D0,0xBAD0,0xBBD0,0xBCD0,0xBDD0,0xBED0,0xBFD0,
        0x80D1,0x81D1,0x82D1,0x83D1,0x84D1,0x85D1,0x86D1,0x87D1,
        0x88D1,0x89D1,0x8AD1,0x8BD1,0x8CD1,0x8DD1,0x8ED1,0x8FD1
    };
    while (*in)
        if (*in & 0x80) {
            int v = table[(int)(0x7f & *in++)];
            if (!v)
                continue;
            *out++ = (char)v;
            *out++ = (char)(v >> 8);
            if (v >>= 16)
                *out++ = (char)v;
        }
        else
            *out++ = *in++;
    *out = 0;
}

class boo {
	struct foo {
		char *_a;
		int _b;
	};

	foo f;
public:
	boo() { 
		f._a = new char[std::strlen("fuck the system!")+1];
		std::strcpy(f._a, "fuck the system!");
		//f._a = "fuck the system!";
		f._b = std::strlen("fuck the system!"); 
	}

	boo(std::string str) { 
		f._a = new char[str.length()+1];
		std::strcpy(f._a, str.c_str());
		f._b = str.length(); 
	}

	~boo() { 
		delete[] f._a; 
	}
};

int main() {
	std::string in("cde5eff0e0e2e8ebfcedeee520f1eeeee1f9e5ede8e5204b4f4e5f544d5f484f53544b4e4620eef220d3cad2d121");

	ByteArray uin("d09fd180d0b8d0b2d0b5d18221");

	ByteArray hoo(in.c_str());

	ByteArray joo("JOO");
	joo = hoo;

	hoo.~ByteArray();
	joo.~ByteArray();

	//	ByteArray b(in.c_str());
	//	b = ByteArray::fromHex(b);

	std::cout << uin.data() << "\n";

	uin = ByteArray::fromHex(uin);
	std::cout << uin.data() << "\n";

	uin = uin.toHex();
	std::cout << uin.data() << "\n";

	uin = ByteArray::fromHex(uin);
	std::cout << uin.data() << "\n";

	uin = uin.toHex();
	std::cout << uin.data() << "\n";

	std::cin.get();

	return 0;
}
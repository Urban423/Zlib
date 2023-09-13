#include "zlib.h"
#include <stdio.h>
#include <math.h>


int readBits(unsigned int numberOfBits, BitsData& data)
{
	int x = 0;
	unsigned int i = 0;
	unsigned int twoInPaw = 1;
	
	while(i != numberOfBits)
	{
		x += twoInPaw * ((*data.byte_pointer >> data.bitNumber) & 1);
		
		data.bitNumber++;
		if(data.bitNumber == 8)
		{
			data.bitNumber = 0;
			data.byte_pointer++;
		}
		twoInPaw *= 2;
		i++;
	}
	return x;
}

byte* inflate(byte* data, unsigned int size)
{
	BitsData bits;
	bits.data = data;
	bits.size = size;
	bits.byte_pointer = data;
	bits.bitNumber = 0;
	
	
	unsigned int cm = readBits(4, bits);
	printf("%d ", cm);
	
	unsigned int cinfo = 256 * pow(2, readBits(4, bits));
	printf("%d\n", cinfo);
	
	unsigned int fcheck = readBits(5, bits);
	unsigned int fdict = readBits(1, bits);
	unsigned int flevel = readBits(2, bits);
	
	printf("%d %d %d\n", fcheck, fdict, flevel);
	
	byte bfinal = readBits(1, bits);
	byte btype = readBits(2, bits);
	
	printf("%d %d\n", bfinal, btype);
	
	return new byte(1);
}
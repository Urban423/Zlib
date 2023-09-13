#pragma once

typedef unsigned char byte;

struct BitsData 
{
	byte* data;
	unsigned int size;
	
	byte* byte_pointer;
	unsigned int bitNumber;
};

int readBits(unsigned int numberOfBits, BitsData& data);

byte* inflate(byte* data, unsigned int size);

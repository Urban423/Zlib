#pragma once


typedef unsigned char byte;

struct PNGheader
{
	byte first;
	byte p;
	byte n;
	byte g;
	int trash;
};

struct Chunk
{
	unsigned int length;
	char name[4];
	byte* data;
	int crc;
};

struct IHDR
{
	int width;
	int height;
	byte depth;
	byte colorType;
	byte zipMethod;
	byte FilterMethod;
	byte Interlace;
};


bool compareWithChunkName(const Chunk& head, const char* name);
int normalizeInt(int x);
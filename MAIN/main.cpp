#include <stdio.h>
#include "PNG.h"

int main()
{
	FILE* file = fopen("../Assets/ManSpider.png", "rb");
	PNGheader header;
	fread(&header, sizeof(PNGheader), 1, file);
	printf("%d %c%c%c\n\n", header.first, header.p, header.n, header.g);
	
	IHDR ihdr;
	
	while(!feof(file))
	{
		Chunk chunk;
		fread(&chunk.length, 4, 1, file);
		chunk.length =  normalizeInt(chunk.length);
		fread(&chunk.name, 4, 1, file);
		//printf("%d\n", chunk.length);
		
		chunk.data = new byte[chunk.length];
		fread(chunk.data, chunk.length, 1, file);
		if(compareWithChunkName(chunk, "IHDR"))
		{
			printf("IHDR\n");
			ihdr = reinterpret_cast<IHDR&>(*chunk.data);
			printf("%d %d\n\n", normalizeInt(ihdr.width), normalizeInt(ihdr.height));
			
		}
		else if(compareWithChunkName(chunk, "IEND"))
		{
			printf("IEND\n");
			break;
		}
		else if(compareWithChunkName(chunk, "IDAT"))
		{
			printf("idat\n");
			byte* result = inflate(chunk.data, chunk.length);
			break;
		}
		
		fread(&chunk.crc, 4, 1, file);
		delete[] chunk.data;
	}
	
	fclose(file);
	return 0;
}
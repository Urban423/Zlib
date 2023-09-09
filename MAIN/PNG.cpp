#include "PNG.h"

bool compareWithChunkName(const Chunk& head, const char* name)
{
	for(int i = 0; i < 4; i++)
	{
		if(head.name[i] != name[i])
		{
			return false;
		}
	}
	return true;
}

int normalizeInt(int x)
{
	int res = x;
	char* tmp = (char*)&res;
	int temp = tmp[0];
	tmp[0] = tmp[3];
	tmp[3] = temp;
	
	temp = tmp[1];
	tmp[1] = tmp[2];
	tmp[2] = temp;
	
	return res;
}
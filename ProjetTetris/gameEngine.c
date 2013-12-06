#include "gameTetris.h"
#include "gameEngine.h"

void moveObject()
{
	unsigned char tmp = 0x01;
	unsigned char i,j;

	j = mapi.ob.y + 5;
	
	// On Teste les différents niveaux à y+5, y+4, Y+3
	tmp = calculateTMP(j);
	if(testLine(j, tmp))
	{
		tmp = calculateTMP(j-1);
		if(testLine(j-1, tmp))
		{
			tmp = calculateTMP(j-2);
			if(testLine(j-2, tmp))
			{
				// 0% de chances qu'un bloc soient libre à y+2, on stoppe donc le bloc et on valide les lignes
				validateLines(j);
				eraseObjectFromMap();
				mapi.ob = generateObject(rand()%4);
			}
			else
				scrollObject();
		}
		else
			scrollObject();
	}
	else
		scrollObject();
}

void scrollObject()
{
	eraseObjectFromMap();
	mapi.ob.y++;
	printObjectOnMap();
}

char testLine(unsigned char y, unsigned char tmp)
{
	return tmp << y%8;
}

void validateLines(unsigned char y)
{
	// NOT IMPLEMENTED YET
}

unsigned char readUserEntry()
{
	// NOT IMPLEMENTED YET
}
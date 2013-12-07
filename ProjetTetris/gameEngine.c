
#include "gameEngine.h"


		///////////////////////////////////////////////////////////
		// MOVING OBJECTS ROUTINES
		// USER ENTRY ROUTINE
		//////////////////////////////////////////////////////////


		// Moving the Object into the screen
		void moveObject();
		void moveObjectLateral(unsigned char dir);

		unsigned char calculateTMP(unsigned char y);
		char testLine(unsigned char x, unsigned char y);
		void scrollObject();
		void validateLines(unsigned char y);

		// Read user Entry
		unsigned char readUserEntry();

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
	if(mapi.ob.y > 5)
		mapi.ob = generateObject(rand()%4);
	else{
		eraseObjectFromMap();    
		mapi.ob.y++;
	}
}

char testLine(unsigned char y, unsigned char tmp)
{
	return '0';
}
unsigned char calculateTMP(unsigned char j)
{
	return 0x01 << j%8;
}

void validateLines(unsigned char y)
{
	// NOT IMPLEMENTED YET
}

unsigned char readUserEntry()
{
	if (PORTAbits.RA0)
	{
		mapi.ob.x++;
		eraseObjectFromMap();
	}
}


//---------------------------	Include		-----------------------------------

#include "gameTetris.h"
#include <p18f4550.h>
#include "ks108.h"
#include <delays.h>	
#include "main.h"
#include "affichageGLCD.h"
//#include "gameEngine.h"

extern void initialiseMap();
extern unsigned char printObjectOnMap();
extern void printMapOnScreen();
 void moveObject();
Map mapi;

//---------------------------	CONFIG		-----------------------------------

#pragma config FOSC = HS 		//oscillator HS
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF 		//Disable watchDog
#pragma config LVP = OFF 		//Disable low voltage programmig
#pragma config DEBUG = ON		//Debug ON


//---------------------------	MAIN		-----------------------------------
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
	eraseObjectFromMap();
	mapi.ob.y++;
	// printObjectOnMap();
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
void main(void)
{

/************	INIT	************/			


//Init port
	ADCON1 = 0x0F;
	TRISAbits.TRISA0 = 1;

	TRISB = 0;				//PORTB output
	PORTB = 0; 				//Reset PORTB


	TRISD = 0xff;			//PORTD input
	PORTD = 0; 				//Reset PORTD

	TRISC = 0xff;			//PORTC input

	//GLCD intialization	
	glcd_Init(1);

glcd_Image();
initialiseMap();

mapi.ob=generateObject(rand()%4);
quickDisplay();


	while(1)			
	{
		// moveObject();
		scrollObject();
		readUserEntry();
		quickDisplay();
		Delay10TCYx(10);
	}	
}

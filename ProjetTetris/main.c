

//---------------------------	Include		-----------------------------------


#include <p18f4550.h>
#include <timers.h>
#include <delays.h>
#include "gameTetris.h"	
#include "ks108.h"
#include "main.h"
#include "affichageGLCD.h"
#include "gameEngine.h"

Map mapi;

//---------------------------	CONFIG		-----------------------------------

#pragma config FOSC = HS 		//oscillator HS
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config WDT = OFF 		//Disable watchDog
#pragma config LVP = OFF 		//Disable low voltage programmig
#pragma config DEBUG = ON		//Debug ON


//---------------------------	MAIN		-----------------------------------
 
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
	glcd_Init(1); // Inits the GLCD and Setting RAM input in 0,0

    glcd_Image(); // Prints starting Image
    initialiseMap(); // Initialize the Tetris Memory Map

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
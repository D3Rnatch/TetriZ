#ifndef __Engine_H
#define __Engine_H

#include "gameTetris.h"
#include "affichageGLCD.h"

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

#endif
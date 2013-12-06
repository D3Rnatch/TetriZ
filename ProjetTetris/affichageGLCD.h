#ifndef AFF8GLCD
#define AFF8GLCD		 

		void initialiseMap();
         Object generateObject(char type);
         Object drawSquare();
         Object drawL();
         Object drawP();
         Object drawLong();
         void printMapOnScreen();
         void displayBlocks(char x, char page);
         unsigned char testPositionBit(char x,char page,char bpos);
         void displayBlock(unsigned char posx,unsigned char posy,unsigned char color);
         unsigned char printObjectOnMap ();
	     unsigned char eraseObjectFromMap();
         char findBitOnPage(char find,char n,char pos);
         unsigned char findBit(char find);
         unsigned char findPage(char find);
          void quickDisplay();
          void updateDisplay();

#endif
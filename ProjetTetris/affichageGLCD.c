
#include "affichageGLCD.h"



/******************************************* Display on the SCREEN ********************************************/




// find the page by y-asis
unsigned char findPage(char find)
{
 return find/8;
}

//find the position of a bit on page
unsigned char findBit(char find)
{
 return find%8;
}

//find the position of the bit set to 1 on the page
char findBitOnPage(char find,char n,char pos)
{
 unsigned char r=1;
 unsigned char compte=0b10000000;
 compte=compte>>n;

 if(mapi.ob.type[pos]&compte)
 {
  r=r<<(find%8);
 }

 else
  r=0;

 return r;
}

//print object on the Map
//the x and y asis  is defined before (position Object)
unsigned char printObjectOnMap ()
{
 unsigned char i=0,j=0,pos=0,n=0;
 unsigned char success=1;

 for(i=0;i<TOBJECT;i++)
 {
  for(j=0;j<TOBJECT;j++){
   if(mapi.ob.x+i<NBLOCKS_W && mapi.ob.y+j<NBLOCKS_H){
    mapi.tab[mapi.ob.x+i][findPage(mapi.ob.y+j)]=mapi.tab[mapi.ob.x+i][findPage(mapi.ob.y+j)]^findBitOnPage(mapi.ob.y+j,n+j,pos);
   }
   else
    success=0;
  }
  if(n==4)
  {
   n=0;
   pos=1;
  }
  else
   n=4;
 }
 return success;
}

unsigned char eraseObjectFromMap ()
{
 unsigned char i=0,j=0,pos=0,n=0;
 unsigned char success=1;

 for(i=0;i<TOBJECT;i++)
 {
  for(j=0;j<TOBJECT;j++){
   if(mapi.ob.x+i<NBLOCKS_W && mapi.ob.y+j<NBLOCKS_H){
    mapi.tab[mapi.ob.x+i][findPage(mapi.ob.y+j)]=mapi.tab[mapi.ob.x+i][findPage(mapi.ob.y+j)]^findBitOnPage(mapi.ob.y+j,n+j,pos);
   }
   else
    success=0;
  }
  if(n==4)
  {
   n=0;
   pos=1;
  }
  else
   n=4;
 }
 return success;
}

//print the block on the position x and y
void displayBlock(unsigned char posx,unsigned char posy,unsigned char color)
{
 unsigned char i=0,j=0;

 for(i=0;i<TBLOCK_W;i++){
  for(j=0;j<TBLOCK_H;j++){
    glcd_PlotPixel(posx+i,posy+j,color);

  }
 }
}

 //test if a bit is set to 1 on the page and returns the position
 //this function need the column where it's working so the x-asis and the page
 //and the position you want test
 unsigned char testPositionBit(char x,char page,char bpos)
 {
   unsigned char t;
   unsigned char r=1;
    t=mapi.tab[x][page];
    r=r<<bpos;

  return t&r;
 }

//display bits on the screen
//this function receive the width and the page to find the column
 void displayBlocks(char x, char page)
 {
  char i=0;
  unsigned char py=0;
  unsigned char px=0;
  unsigned char p=0;
  unsigned char pos=0;

  for(i=0;i<8;i++)
  {
   p=testPositionBit(x,page,i);
   py=(i+page*8)*TBLOCK_H;
   px=POSITIONSCREEN+x*TBLOCK_W;

   if(p!=0)    //if the block exist you can print
    displayBlock(px,py,1);
   else
     displayBlock(px,py,0);
  }
 }

//print Map on the SCREEN
void printMapOnScreen()
{
 unsigned char i,j;


 for(i=0;i<NBLOCKS_W;i++){
  for(j=0;j<NPAGEMAX;j++){
   displayBlocks(i,j);
   }
  }

}

void updateDisplay()
{
 printObjectOnMap();
Delay10TCY();
 printMapOnScreen();
}

/***************************************************** draw an object ****************************************/

//draw square
Object drawSquare()
{
 Object ob;
 //initialization
 ob.type[0]=0b00001100;
 ob.type[1]=0b11000000;
 ob.x=0;
 ob.y=0;

 return ob;
}

Object drawL()
{
 Object ob;

 ob.type[0]=0b00000000;
 ob.type[1]=0b11100010;
 ob.x=0;
 ob.y=0;
 return ob;
}

Object drawP()
{
 Object ob;

 ob.type[0]=0b01001100;
 ob.type[1]=0b01000000;
 ob.x=0;
 ob.y=0;
 return ob;
}


Object drawLong()
{
 Object ob;

 ob.type[0]=0b00000000;
 ob.type[1]=0b11110000;
 ob.x=0;
 ob.y=0;
 return ob;
}

// generate Object
Object generateObject(char type)
{
 Object ob;
 switch(type)
 {
  //square by default
  default :
  case 0 :
  ob=drawSquare();
  break;

  // L
  case 1 :
  ob=drawL();
  break;

  // the long  : |
  case 2 :
  ob=drawLong();
  break;

  case 3 :
  ob=drawP();
  break;
 }
 return ob;
}

void quickDisplay()
{
 updateDisplay();
 Delay10TCY();
 updateDisplay();
}
/**************************************************Rotation************************************************/

/*void rotation()
{

 mapi.ob.type[];

}   */

void nextBlockDisplay()
{
 unsigned char i=0,j=0,pos=0,n=0;
 unsigned char success=1;
 unsigned char previous[TBLOCK_W][TBLOCK_H];

 for(i=0;i<TOBJECT;i++)
 {
  for(j=0;j<TOBJECT;j++){
   if(mapi.ob.x+i<NBLOCKS_W && mapi.ob.y+j<NBLOCKS_H){
    if(findBitOnPage(10+j,n+j,pos)){
     glcd_PlotPixel(80,10,1);
    }
    else
       glcd_PlotPixel(80,10,0);
   }
  
  }
  if(n==4)
  {
   n=0;
   pos=1;
  }
  else
   n=4;
 }

}

/*************************************************Initialise Map*************************************/

//initialise Map
void initialiseMap()
{
 unsigned char i=0,j=0;
  //initialization screen and score

 for(i=0;i<NBLOCKS_W;i++)
  for(j=0;j<NPAGEMAX;j++)
  {
   mapi.tab[i][j]=0;
  }

 mapi.score=0;

}

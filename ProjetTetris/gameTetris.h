


       /**                MEMORY ORGANISATION : RAM (size 128o)
        block size : 3 o
        object size : 12 o
        map size : 12 + 1 + 18 + 12 = 43 octets
        Size left :  octets
**/

/**                RECAP des TYPES
        Archi TYPE :
                 COL D | COL G | COL G | COL D |
           0b    0000    0000    0000    0000
        Carre : TYPE = 0b 0000 1100 1100 0000
        le L standart : TYPE = 0b 0000 1110 0010 0000
        L inverse : TYPE = 0b 0000 1000 1110 0000
        Ligne : TYPE = 0b 0000 0000 1111 0000
**/


/***
    carre:      L:       esacalier:    pyramide:    long:
    0110        0100     0100          0010         0010
    0110        0100     0110          0111         0010
    0000        0110     0010          0000         0010
    0000        0000     0000          0000         0010

**/

        // SCREEN'S DEFINES
        #define NTYPE 1
        #define TOBJECT 4 // 4 blocks
        #define TBLOCK_W 4
        #define TBLOCK_H 4
        #define NPAGEMAX 8/TBLOCK_H
        #define NBLOCKS_H 64/TBLOCK_H
        #define NBLOCKS_W 10
        // #define OCTET 8
        #define POSITIONSCREEN 19
        // #define SPEED 3

// STRUCTURE DEFINITION

        // x ==> Coordonnée du  TSCREEN (aire de jeu) sur le GLCD.
        // y ==> Coordonnee du TSCREEN (aire de jeu) sur le GLCD
        // Première vrai objet dessiner : un block carré composé de 4 carrés
        typedef struct object
        {
         unsigned char type[2];
         unsigned char x; // Position en x du block en haut à gauche
         unsigned char y; // Position en y du block en haut à gauche
        } Object;

        // MEMORY MAP
        typedef struct map
        {
         Object ob;
         unsigned char score;
         unsigned char tab[NBLOCKS_W][NPAGEMAX];
        }Map;

        //la map est une variable globale
        //elle servira pour toutes les fonctions
          extern Map mapi;

		
		


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COLUMN 30

char function1 ( char [ROW] [COLUMN]) ;


int main( void )
{

char randchar_array [ROW] [COLUMN];
srandom ( (unsigned) time (NULL) );

printf( "\n Welcome User.\n\n" ) ;

function1 (randchar_array);

printf("\n\n Thank you for using this program.\n\n" ) ;


return ( 0 ) ;

}

char function1 (char randchar_array[ROW] [COLUMN])

{
int r = 0 ;
int c = 0 ;
char nextchar = 'A';

   for (r = 0; r < ROW ; r++)
   {
       for (c = 0; c < COLUMN ; c++)
       {
          nextchar = 'A' + random() % 26;
          randchar_array [r] [c] = nextchar;
          printf(" %c", nextchar);
       }

      printf("\n");
    }

   return (randchar_array [ROW] [COLUMN]);
 }

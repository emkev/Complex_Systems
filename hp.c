
/* 2016.08.06 , simulate the hodgepodge machine . */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int width = 30 , height = 10 ;
int states = 100 , wrap = 1 , steps = 100 ;
double k1 = 2 , k2 = 3 , g = 34 ;

int option_length = 8 ;

typedef enum opt_type {
  opt_int , opt_double , opt_string
} opt_type ;

typedef struct option {
  char *name ;
  opt_type type ;
  void *ptr ;
} option ;

option options[] = {
  { "-height" , opt_int , &height } ,
  { "-width"  , opt_int , &width  } ,
  { "-state"  , opt_int , &state  } ,
  { "-steps"  , opt_int , &steps  } ,
  { "-wrap"   , opt_int , &wrap   } ,
  { "-k1"     , opt_double , &k1  } ,
  { "-k2"     , opt_double , &k2  } ,
  { "-g"      , opt_double , &g   }
} ;

void update_cell(int **oldstate , int **newstate , int x , int y)
{
  int nx , ny , i , j , numinf , numill , sum ;

  numinf = numill = sum = 0 ;
  sum = oldstate[x][y] ;

  for(i = -1 ; i <= 1 ; i++)
  {
    for(j = -1 ; j <= 1 ; j++)
    {
      if(i == 0 && j == 0) continue ;

      /*  skip diagonals  */
      if(fabs(i) + fabs(j) == 2) continue ;

      nx = x + i ;
      my = y + j ;

      if(!wrap)
      {
        if(nx < 0 || nx > width - 1 || ny < 0 || ny > height - 1)
          continue ;
      }
      else
      {
        nx = (nx < 0) ? width - 1 : ((nx > width - 1) ? 0 : nx) ;
        ny = (ny < 0) ? height - 1 : ((ny > height - 1) ? 0 : ny) ;
      }

    } /*  for(j = -1 ; j <= 1 ; j++)  */
  } /*  for(i = -1 ; i <= 1 ; i++)  */

}

int main(int argc , char **argv)
{
  int ar ;

  ar = 1 ;
  while(ar < argc)
  {

  }

  printf("hp !\n");
  exit(0);
}

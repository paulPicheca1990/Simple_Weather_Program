#include "../libs/random_number.h"
unsigned short int init_count = 0;

void seed_random_function(){
  time_t t;
  srand((unsigned)time(&t));
}

int get_random_number( int max ) {        
  if( init_count++ <= 0 )
    seed_random_function();
    
  return( rand() % max + 1 );
}

float get_random_numberf( int max ){
  if( init_count++ <= 0 )
    seed_random_function();

  int whole_part, decimal_part;

  whole_part = get_random_number(max);
  decimal_part = get_random_number(max);

  return (float)whole_part + (float)decimal_part / (float)((log10(decimal_part) + 1) * 10);
}

double get_random_numberd( int max ){
  return (double)get_random_numberf( max );
}
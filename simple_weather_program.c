#include <stdio.h>
#include <stdarg.h>
#include "./libs/rainfall_data_t.h"

int main( int argc, char **argv ){
  Rainfall_Data_t data = gather_rainfall_data();
  data = gather_yearly_running_totals( data );  
  data = gather_yearly_average( data );
  data = gather_monthly_averages( data );

  return 0;
} 
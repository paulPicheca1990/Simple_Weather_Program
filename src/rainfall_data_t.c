#include "../libs/rainfall_data_t.h"
#include "../libs/rainfall_lib.h"

Rainfall_Data_t Rainfall_Data_T() {
  return (Rainfall_Data_t) {.MONTHS_IN_YEAR=MAX_MONTHS, .NUMBER_OF_YEARS=MAX_YEARS, .THIS_YEAR=CURRENT_YEAR};
}

Rainfall_Data_t gather_rainfall_data( ) {
  Rainfall_Data_t data = Rainfall_Data_T();
  initialize_rainfall_amounts( data.NUMBER_OF_YEARS, data.MONTHS_IN_YEAR, (float *)data.rainfall_amounts );

  printf( "The Data:\n\n" );    
  print_rainfall_amounts( data.NUMBER_OF_YEARS, data.MONTHS_IN_YEAR, (float *)data.rainfall_amounts );

  return data;
}

Rainfall_Data_t gather_yearly_running_totals( Rainfall_Data_t data ) {  
  get_yearly_running_total( data.NUMBER_OF_YEARS, data.MONTHS_IN_YEAR, (float *)data.rainfall_amounts, (float *)data.yearly_running_totals );

  printf( "Yearly Running Totals:\n\n" );  
  print_yearly_running_total( data.NUMBER_OF_YEARS, (float *)data.yearly_running_totals );  

  return data;
}

Rainfall_Data_t gather_yearly_average( Rainfall_Data_t data ) {
  data.yearly_average = get_yearly_average( data.NUMBER_OF_YEARS, data.MONTHS_IN_YEAR, (float *)data.rainfall_amounts );

  printf( "Yearly Average:\n\n" );  
  printf( "%26s %8.2f inches/year\n\n", "The Yearly Average is:", data.yearly_average );

  return data;
}

Rainfall_Data_t gather_monthly_averages( Rainfall_Data_t data ) {
  get_monthly_averages( data.NUMBER_OF_YEARS, data.MONTHS_IN_YEAR, (float *)data.rainfall_amounts, (float *)data.monthly_averages );
  
  printf( "Monthly Averages:\n\n" );  
  print_monthly_averages( data.MONTHS_IN_YEAR, (float *)data.monthly_averages );  

  return data;
}
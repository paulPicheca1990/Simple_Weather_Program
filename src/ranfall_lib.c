#include "../libs/rainfall_lib.h"
#include "../libs/random_number.h"

void initialize_rainfall_amounts( int years, int months, float *rainfall_amounts ) {
  int year_index, month_index;
  for( year_index = 0; year_index < years; year_index++ )
    for( month_index = 0; month_index < months; month_index++ )
      *( ( rainfall_amounts + year_index * months) + month_index ) = get_random_numberf(MAX_NUMBER);  
}

float get_yearly_average( int years, int months, float *rainfall_amounts ) {
  float running_total = 0.00, result = 0.00;

  int year_index, month_index;
  for( year_index = 0; year_index < years; year_index++ )
    for( month_index = 0; month_index < months; month_index++ ) 
        running_total += *( ( rainfall_amounts + year_index * months) + month_index );

  result = running_total / years;
  return result;  
}

void get_monthly_averages( int years, int months, float *rainfall_amounts, float *monthly_averages ) {
  int year_index, month_index;
  for( month_index = 0; month_index < months; month_index++ )
    monthly_averages[ month_index ] = 0.00;
  
  for( month_index = 0; month_index < months; month_index++ ) 
    for( year_index = 0; year_index < years; year_index++ )    
      monthly_averages[month_index] += *( ( rainfall_amounts + year_index * months) + month_index );      

  for( month_index = 0; month_index < months; month_index++ ) 
    monthly_averages[month_index] /= years;
}

void get_yearly_running_total( int years, int months, float *rainfall_amounts, float *yearly_running_totals ) {
  int year_index, month_index;
  for( year_index = 0; year_index < years; year_index++ )
    yearly_running_totals[ year_index ] = 0.00;
    
  for( year_index = 0; year_index < years; year_index++ ){
    if( year_index > 0 )
      yearly_running_totals[year_index] += yearly_running_totals[year_index - 1];

    for( month_index = 0; month_index < months; month_index++ ) 
      yearly_running_totals[year_index] += *( ( rainfall_amounts + year_index * months) + month_index );      
  }
}

void print_month_headers() {
  int index;
  char *month_list[] = {"Year", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  for( index = 0; index < sizeof( month_list ) / sizeof( month_list[0] ); index++ )       
    printf( "%8s ", month_list[index] );
  printf( "\n" );
}

void print_rainfall_amounts( int years, int months, float *rainfall_amounts ) {  
  print_month_headers();

  int year_index, month_index;
  for( year_index = 0; year_index < years; year_index++ ){
    printf( "%8d ", CURRENT_YEAR - 4 + year_index );
    for( month_index = 0; month_index < months; month_index++ ) {      
      printf( "%8.2f ", *( ( rainfall_amounts + year_index * months) + month_index ) );  
    }
    printf( "\n" );
  }
  printf("\n");
}

void print_monthly_averages( int months, float *monthly_averages ) {
  print_month_headers();

  int month_index;
  printf( "%8s ", "All" );
  for( month_index = 0; month_index < months; month_index++ )
    printf( "%8.2f ", monthly_averages[month_index]);
  printf("\n\n");  
}

void print_yearly_running_total( int years, float *yearly_running_totals ) {  
  printf( "%8s %10s\n", "Year", "Rainfall" );

  int year_index;
  for( year_index = 0; year_index < years; year_index++ )
    printf("%8d %10.2f (inches)\n", (CURRENT_YEAR - 4 + year_index), *( yearly_running_totals + year_index ));
  printf("\n");
}

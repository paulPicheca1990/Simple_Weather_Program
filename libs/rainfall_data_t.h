#ifndef __RAINFALL_DATA_H__
#define __RAINFALL_DATA_H__

#include "./rainfall_lib_defs.h"

typedef struct _Rainfall_Data_t {
  float rainfall_amounts [ MAX_YEARS ][ MAX_MONTHS ];
  float yearly_running_totals[ MAX_YEARS ];
  float monthly_averages [ MAX_MONTHS ];
  float yearly_average;
  int MONTHS_IN_YEAR;
  int NUMBER_OF_YEARS;
  int THIS_YEAR;
} Rainfall_Data_t;

Rainfall_Data_t Rainfall_Data_T();

Rainfall_Data_t gather_rainfall_data();

Rainfall_Data_t gather_yearly_running_totals( Rainfall_Data_t data );

Rainfall_Data_t gather_yearly_average( Rainfall_Data_t data );

Rainfall_Data_t gather_monthly_averages( Rainfall_Data_t data );

#endif //__RAINFALL_DATA_H__
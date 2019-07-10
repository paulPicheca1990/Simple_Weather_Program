#ifndef __RAINFALL_LIB_H__
#define __RAINFALL_LIB_H__

#include <stdio.h>
#include <stdlib.h>
#include "./rainfall_lib_defs.h"

void initialize_rainfall_amounts( int years, int months, float *rainfall_amounts );

float get_yearly_average( int years, int months, float *rainfall_amounts );

void get_monthly_averages( int years, int months, float *rainfall_amounts, float *monthly_averages );

void get_yearly_running_total( int years, int months, float *rainfall_amounts, float *yearly_running_totals );

void print_month_headers();

void print_rainfall_amounts( int years, int months, float *rainfall_amounts );

void print_monthly_averages( int months, float *monthly_averages );

void print_yearly_running_total( int years, float *yearly_running_totals );

#endif //__RAINFALL_LIB_H__
/*
 * lab1.c
 * 
 * Copyright 2015 fei32dobosevych <fei32dobosevych@class>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <math.h>

double f(float b){

return b*b;
}

int main(int argc, char **argv)
{
    double a = 1;
	double b = 2;
	int n = 30;
	double h=(b-a)/n; 
	double x;
	
	
	FILE * in;
    in = fopen("in.txt", "wc");
  double i=0;

   while(i<n){
	   i=i+1;
	   x = a +i*h;
       fprintf(in,"\n %f %f",x,f(x));
   }
      
  
    fclose(in);
	return 0;
}


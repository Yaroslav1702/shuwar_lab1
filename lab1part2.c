/*
 * lab1part2.c
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

int main(int argc, char **argv)
{int n = 30;
	double x[n+1];
	double F[n+1];
	double h[n+1];
	int i = 0 ;
	
	double alpha[n+1];
	double beta [n+1];
	double gamma[n+1];
	double delta[n+1];

	alpha[1] = 0;
	beta[1] = 1;
	gamma[1] = 0;
	delta[1] = 0;
	

	FILE *in; 
	in = fopen("in.txt","r");
	
	for(i = 1; i < n+1; i = i +1){
	fscanf(in,"%lf %lf",&x[i],&F[i]);
}

 for(i = 1;i < n+1;i++){
	h[i] = x[i] - x[i-1];
	}
	
	for(i = 2; i < n-1; i++){
	alpha[i] = h[i-1];
	beta[i] = 2.0*(h[i-1] + h[i]);
	gamma[i] = h[i];
	delta[i] = 3.0*((f[i] - f[i-1]/h[i]) - (f[i-1] - f[i-2]/h[i-1]));	
		} 
	alpha[n] = h[n-1];
	beta[n] = 2.0*(h[n-1] + h[n]);
	gamma[n] = h[n];
	delta[n] = 3.0*((f[n] - f[n-1]/h[n]) - (f[n-1] - f[n-2]/h[n-1]))
	
	double a[n+1];
	double b[n+1];
	
	a[1] = - gama[1]/beta[1];
	b[1] = delta[1]/beta[1];
	
	for(i = 2; i <n-1;i++){
		a[i] = -gama[i] / (alpha[i] * a[i-1] + beta[i]);
		b[i] = (delta[i] - alpha[i]*b[i-1]) / (alpha[i] *a[i-1] + beta[i]); 
		}
	double ci [n+1];
	ci[n] = (delta[n] - alpha[n]*b[n-1])/(alpha[n] * a[n-1] + beta[n]);
	
	for(i = n-1; i > 1 ;i--){
		ci[i] =a[i] * ci[i+1] + b[i]; 
		}
		
		ci[1] = a[1]*ci[2] + b[1];
		
	double ai[n+1];
	double di[n+1];
	double bi[n+1];
	
	for(i = 1; i < n + 1;i++){
	ai[i] = F[i-1];
	}
	
	for(i=0;i<n;i++){
	di[i] = (ci[i+1]-ci[i])/(3*h[i]);
	}
	
	di[n] = -c[n]/(3*h[n]);
	
	for(i=1;i<n;i++){
	bi[i] = (y[i] - y[i-1])/h[i] - h[i]/3 * (ci[i+1] + 2 * ci[i]);
	}
	b[n] = (y[n] - y[n-1])/h[n] - 2/3 *h[n] * ci[n];
 	 
    int N = n * 20;
    double xs[N+1];
    xs[0] = x[1];
    int h = (x[n] - x[1])/N
    for(i = 1;i<N;i++){
    xs[i] = xs[i-1] + h*i;
    } 
    
    double ys[N+1];
    double xser = 0;
    int l = 0;
    
    for(i = 0; i <N;i++){
	l = (int)(i/20);
	ys[i] = a[l] + b[l]*(xs[i] - x[l-1]) + ci[l]*((xs[i] - x[l-1])*(xs[i] - x[l-1]))+ di[i] * ((xs[i] - x[l-1])*(xs[i] - x[l-1])*(xs[i] - x[l-1]));
	}
	 
	FILE * xs;
	xs = fopen("xs.txt","wc");
	for(i = 0; i < n; i = i +1){
		 fprintf(xs,"\n %f",xs[i]);
		 }
		 
		 FILE * ys;
	ys = fopen("ys.txt","wc");
	for(i = 0; i < n; i = i +1){
		 fprintf(ys,"\n %f",ys[i]);
		 }
	return 0;
}


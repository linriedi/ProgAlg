#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main() {
	int npoints = 100000000;
	int sum = 0;
	srand(clock());  
	#pragma omp parallel shared(npoints) reduction(+: sum) num_threads(8) 
	{ 
		int i;   
		double rand_x, rand_y;   
		sum = 0;   
		#pragma omp for   
		for (i = 0; i < npoints; i++) { 
			rand_x = rand() / double(RAND_MAX);    
			rand_y = rand() / double(RAND_MAX);    
			if (((rand_x - 0.5)*(rand_x - 0.5) + (rand_y - 0.5)*(rand_y - 0.5)) < 0.25)     sum++; 
		} 
	} 

	cout << setprecision(10) << 4 * sum / double(npoints) << endl;
}
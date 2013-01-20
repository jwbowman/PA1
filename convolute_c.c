#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define A_HEIGHT 100
#define A_WIDTH  100
#define H_HEIGHT 5
#define H_WIDTH  5
#define O_HEIGHT (A_HEIGHT + H_HEIGHT)
#define O_WIDTH	 (A_WIDTH + H_WIDTH)


typedef float pixel;

pixel a[A_HEIGHT][A_WIDTH];
pixel h[H_HEIGHT][H_WIDTH];
pixel c[O_HEIGHT][O_WIDTH];

void init(void) {
	int i,j;
	
	srand((unsigned) time(NULL)); 	
	
	for(i=0; i<A_HEIGHT; i++) { 
		for(j=0; j<A_WIDTH; j++) {
			a[i][j] = (pixel) rand()/(pixel) RAND_MAX;
		}
	}
	
	for(i=0; i<H_HEIGHT; i++) { 
		for(j=0; j<H_WIDTH; j++) {
			h[i][j] = (pixel) rand()/(pixel) RAND_MAX;
		}
	}
}

void convolute() {
	int m,n;
	int j,k;
	
	for(m=0; m<A_HEIGHT; m++) { 
		for(n=0; n<A_WIDTH; n++) {
			for(j=0; j<H_HEIGHT; j++) {
				for(k=0; k<H_WIDTH; k++) {
					// need to check if indexes are out of bounds i.e. negative
					// need clarification on algorithm and datatype
					c[m+j][n+k]=h[j][k]*a[m-j][n-k];
				}
			} 
			
		}
	}
}

int main(int argc, char* argv[] ) {
	
	init();
	
	convolute();

	return 0;
}

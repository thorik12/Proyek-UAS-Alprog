#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//FUNCTION
int sort(int i, int n, int row1[], int column1[]);

int sort(int i, int n, int row1[], int column1[]){
	int pass, pass1, hold, hold1;
	for(pass = 1; pass<n; pass++){
		for(i=0; i<n-1; i++){
			if(row1[i]>row1[i+1]){
				hold = row1[i];
				row1[i] = row1[i+1];
				row1[i+1] = hold; 
				for(pass1 = 1; pass1<n; pass1++){
					for(i=0; i<n; i++){
						if(column1[i]>column1[i+1]){
							hold1 = column1[i];
							column1[i] = column1[i+1];
							column1[i+1] = hold1;
						}
					}
					
				}
			}
		}
	}
}

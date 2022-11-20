#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int Svertka(int size, int a[], int b[], int c[], int s1, int s2, int C);

int main() {
	int size1, size2, n;
	printf(" Input SIZE of 1st array: ");
	cin>>size1;

	printf("\n Input SIZE of 2nd array: ");
	cin>>size2;

	n = size1 + size2 -1;
	int a[size1], b[size2];
	printf("\n Input %d numbers for 1st array: ", size1);
	for (int i = 0; i< size1; i++) {
		cin>>a[i];
	}
	
	printf("\n Input %d numbers for 2nd array: ", size2);
	for (int i = 0; i< size2; i++) {
		cin>>b[i];
	}

	printf("\n 1st array: \n");
	for (int i = 0; i< size1; i++) {
		cout << a[i] << endl;
	}
	printf("\n 2nd array: \n");
	for (int i = 0; i< size2; i++) {
		cout << b[i] << endl;
	}
	int c[n];
	for (int i = 0 ; i < n ; i++) {
		c[i] = 0;
	}
	int C=0;
	C=Svertka(n, a, b, c, size1, size2, C);
	printf("\n  Results: \n");
	for (int i = 0; i< n; i++) {
		cout << c[i] << endl;
	}
	cout<< "  C = " << C <<endl;
	exit(0);
	return 0;
}

int Svertka(int size, int a[], int b[], int c[], int s1, int s2, int C) {
	for (int i = 0; i < size; i++) {
            for (int k = 0; k < s1; k++) {
                for (int j = 0; j < s2; j++) 
				{
					C++;
                    if(i == (k+j)) 
					{
						
                        if(c[i] != 0)
							C++;
                        c[i] += a[k] * b[j];
                        
                    }
                }
            }
        }
 return C;
}

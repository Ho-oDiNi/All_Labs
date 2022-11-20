#include <stdlib.h>
#include <stdio.h>

int Binar(int x, int *A, int n)
{
    int L = 0, R = n - 1, m;
    while (L < R)
    {
        m = (L + R)/2;
        if (A[m]<x)
            L = m+1; 
        else 
			R = m; 
    }
    if(x == A[R])
    	return R;
	else
		printf("-1");
}

void search(int *A, int *Arr, int n)
{
	int x, ind, i = 0;
	printf("input x:");
	scanf("%d", &x);
	ind = Binar(x, A, n);
    if (ind == -1) {
        printf("Not found\n");
    } 
	else 
	{
		while(A[ind] == x)
		{
			Arr[i] = A[ind];
			i++;
			ind++;	
		}
	}	
}

void FillInc(int *A, int n)
{
    for(int i=0; i<n; i++) 
        A[i]=i;
}

int main() 
{
    int n=10, m;
	int A[n], Arr[n];
	
	FillInc(A,n);
	A[4]=3;
	A[5]=3;
	A[6]=3;
    for(int i = 0; i<n; i++)
    {
    	printf("%d ", A[i]);
    	Arr[i] = 0;
	}
    
    search(A, Arr, n);
    
    for(int i = 0; i<n; i++)
    {
    	printf("%d ", Arr[i]);
	}
	
    return 0;
}


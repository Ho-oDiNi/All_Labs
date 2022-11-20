#include <iostream>
#include <math.h>

using namespace std;
const int N = 3;
const double EPS = 0.000001;

void print_matrix(float A[N][N+1])	
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= N; j++)
			cout << A[i][j] << "\t";
		cout <<"\n";
	}
}
						
void count_gauss(float A[N][N+1], float B[N])
{
	float temp;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
		{
			temp =- A[i][i] / A[j][i];
			for(int k = i; k <= N; k++) 
				A[j][k] = A[j][k] * temp + A[i][k];
		}
    int k = N - 1;    
	for(int i = N-1; k >= 0; i--)
	{
		B[k] = A[k][N] / A[k][i];
		for(int j = 0; j < k + 1; j++)
			A[k - j][N] -= A[k - j][i] * B[k];
		k--;
	}
}

void count_modified_gauss(float A[N][N+1], float B[N])
{
	int tt;
	float temp, temp_matrix[N+1];
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
		{
			for(int t = 0; t < N; ++t)
			if (A[i][i] < A[t][i]) 
				tt = t;
							
			for (int k = 0; k < N+1; ++k)
			{
				temp_matrix[k] = A[i][i];
				A[i][i] = A[tt][i];
				A[tt][i] = temp_matrix[k];
			}
			
			temp =- A[i][i] / A[j][i];
			for(int k = i; k <= N; k++) 
				A[j][k] = A[j][k] * temp + A[i][k];
		}
    int k = N - 1;    
	for(int i = N-1; k >= 0; i--)
	{
		B[k] = A[k][N] / A[k][i];
		for(int j = 0; j < k + 1; j++)
			A[k - j][N] -= A[k - j][i] * B[k];
		k--;
	}
}

void gauss()
{
	float B[N];
	float A[N][N + 1] = 
	{	{-2, -2, 1, 0}, 
		{1, -2, 1, 3}, 
		{-3, 1, 1, -1}
	};
	
	print_matrix(A);
	count_gauss(A, B);
	for(int i = 0; i < N; ++i)                              
		cout <<"\n x" << i+1 <<" = " << B[i];   
}

void modified_gauss()
{
	float B[N];
	float A[N][N + 1] = 
	{	{-2, -2, 1, 0}, 
		{1, -2, 1, 3}, 
		{-3, 1, 1, -1}
	};
	
	print_matrix(A);
	count_modified_gauss(A, B);
	for(int i = 0; i < N; ++i)                              
		cout <<"\n x" << i+1 <<" = " << B[i];   
}

double function(double x)
{
	return (x*x - 3);
}

void binar_method()
{
	int time = 0;
	double a, b, c, funcA, funcB, funcC, eps;
	cout <<"Input (a; b): ";	
	cin >> a;	cin >> b;
	
	do
	{
		c = (a + b)/2;
		funcA = function(a);
		funcB = function(b);
		funcC = function(c);
		eps = (b - a)/2;
		
		if (funcA * funcC < 0)
			b = c;
		else
			a = c;
		time++;	
			
	} while (eps > EPS);
	c = (a + b)/2;
	
	cout <<"\nAnswer: " << c <<" Time: " << time;
}

void chord_method()
{
	int time = 0;
	double a, b, c, c_n, eps;
	cout <<"Input (a; b): ";	
	cin >> a;	cin >> b;
	
	do
	{
		c_n = c;
		c = (a*function(b) - b*function(a)) / (function(b) - function(a));
		if (function(a) * function(c) < 0)
			b = c;
		else
			a = c;
		time++;	
		
	} while (fabs(c_n - c) > EPS);
	c = (a + b)/2;
	
	cout <<"\nAnswer " << c <<" Time: " << time;
}

int main()
{
	binar_method();

	return 0;
}



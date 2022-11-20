#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

const int n = 2;
const double H = 0.2;
const double H2 = 0.1;
const double EPS = 0.0000000001;




double f(double x, double y[n], int i)
{
	if(i == 0)
		return y[n-1];
	else	
	{
		double function = (exp(x) + y[0] + y[1])/3;
		return function;
	}
		
}

double runge4(double x, double y[n], double H)
{
	double k1[n], k2[n], k3[n], k4[n], t[n];
	for(int i = 0; i < n; i++)
		k1[i] = f(x, y, i );
	for(int i = 0; i < n; i++)	
		t[i] = y[i] + H/2 * k1[i];
	
	for(int i = 0; i < n; i++)
		k2[i] = f(x + H/2, t, i );
	for(int i = 0; i < n; i++)
		t[i] = y[i] + H/2 * k2[i];

	for(int i = 0; i < n; i++)
		k3[i] = f(x + H/2, t, i );
	for(int i = 0; i < n; i++)	
		t[i] = y[i] + H * k3[i];
		
	for(int i = 0; i < n; i++)
		k4[i] = f(x + H, t, i );
	
	for(int i = 0; i < n; i++)
		y[i] = y[i] + H/6 * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
		
	return y[0];
}


void Conversion(double x_main, double y_main[n], double y_slave[n], double y_new[n], double h)
{
	double x_new = 0;
	double h0 = h/2;
	if(y_main[0]-y_slave[0] < 15*EPS)
	{
		cout<<"\t";
		printf("y = %.10f\ty\' = %.10f\t\n", y_main[0], y_main[1]);
	}
	else
	{
		while(x_new < x_main)
		{
			runge4(x_new, y_new, h0);
			x_new += h0;
		}
		printf("y = %.10f\ty\' = %.10f\n", y_new[0], y_new[1]);
	}
	
}


int DU()
{
	double x = 0, x2 = 0, x3 = 0, y[n] = {1, 1}, y2[n] = {1, 1}, y3[n] = {1,1}, h0 = H2;
	int k = 0;
	
	printf("RUNGE-KUTT 4\n");
	printf("\t\t\t H = 0.2");
	for(int i = 0; i<6; i++)
		cout<<"\t";
	printf("H = 0.1");
	for(int i = 0; i<7; i++)
		cout<<"\t";	
	cout<<"H = 0.05:\n";
		
	printf("x = %.10f\t y = %.10f\ty\' = %.10f\t\ty = %.10f\ty\' = %.10f\t\ty = %.10f\ty\' = %.10f\n", x, y[0], y[1], y2[0], y2[1], y3[0], y3[1]);
	while (x2 < 0.9)                                     
	{	
		if(k%2==1)
		{
			runge4(x, y, H);
			x += H;
			printf("x = %.10f\t y = %.10f\ty\' = %.10f\t\t", x, y[0], y[1]);
		}
		
		runge4(x2, y2, H2);
		x2 += H2;
		if(k%2==1)
		{
			printf("y = %.10f\ty\' = %.10f\t\t", y2[0], y2[1]);
			Conversion(x2, y2, y, y3, H2);
		}	
		
		k++;		
	}	
	
	
	
	
	system("PAUSE");
	return 0;	
}

int main()
{
	DU();	
	return 0;
}


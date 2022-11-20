#include <array>
#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS  pow(10,-10)
#define E    2.7182818284


using namespace std;

const int n = 2;

double f(double x, double y[n],int i)
{
	if(i == 0)
		return y[n-1];
	else	
		return (pow(E,x) + y[0] + y[1])/3;	
}

double runge4 (double xz, double yz[2], bool Equal)
{ 
	double Hz = 0.2;
	double counter, yz2[2];
	while (counter !=1 /(2*Hz))
	{
		counter=0;
		yz[0] = {1};
		yz[1] = {1};
		xz=0;

		if(Equal)
		{
			printf("%.7f    ",xz);
			printf("%.7f    ",yz[0]);
			printf("%.7f    ",yz[1]);
			printf("\n");
		}
	
		for (xz = 0; xz < 1-Hz+ EPS; xz+= Hz)
		{
			yz2[1]=yz[1];
			double k1[n], k2[n], k3[n], k4[n], t[n];
			for(int i = 0; i < n; i++)
				k1[i] = f(xz, yz,i);
			for(int i = 0; i < n; i++)	
				t[i] = yz[i] + Hz/2 * k1[i];
			
			for(int i = 0; i < n; i++)
				k2[i] = f(xz + Hz/2, t ,i);
			for(int i = 0; i < n; i++)
				t[i] = yz[i] + Hz/2 * k2[i];
		
			for(int i = 0; i < n; i++)
				k3[i] = f(xz + Hz/2, t,i);
			for(int i = 0; i < n; i++)	
				t[i] = yz[i] + Hz * k3[i];
				
			for(int i = 0; i < n; i++)
				k4[i] = f(xz + Hz, t,i);
			
			for(int i = 0; i < n; i++)
				yz[i] = yz[i] + Hz/6 * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
		
			if(Equal)
			{
				printf("%.7f    ",xz+Hz);
				printf("%.7f    ",yz[0]);
				printf("%.7f    ",yz[1]);
				printf("\n");
			}
			if (fabs(yz[1] - yz[0] ) < 15 * EPS)
				counter++;									
		}
		if(Equal)
		{
			printf("h = %f    ",Hz);
			printf("\n");
		}
		Hz/=2;			
	}
	
	return yz[1];
}


int main()
{
	
	double Hz = 0.2;
	double yz[2] = {1, 1};
	double xz=0;
	runge4(xz, yz, Hz);
			    	

	return 0;
}
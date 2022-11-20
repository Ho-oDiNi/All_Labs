#include <iostream>
#include <cmath>
#define EPS  pow(10,-10)


using namespace std;

const int n = 2;

double f(double x, double y[n], int i)
{
	if(i == 0)
		return y[n-1];
	else	
		return (exp(x) + y[0] + y[1])/3;	
}

void runge4 (double x, double y[2], bool Equal)
{ 
	double H = 0.2;
	double counter, y2[2];
	while (counter!=1/(2*H))
	{
		counter=0;
		y[0] = 1;
		y[1] = 1;
		x = 0;

		if(Equal)
		{	printf("\nH = %f\n\n", H);
			printf("x = %.5f    y = %.10f    y\' = %.10f\n", x, y[0], y[1]);
		}
	
		for (x = 0; x < 1-H+EPS; x+=H)
		{
			y2[1] = y[1];
			double k1[n], k2[n], k3[n], k4[n], t[n];
			for(int i = 0; i < n; i++)
				k1[i] = f(x, y,i);
			for(int i = 0; i < n; i++)	
				t[i] = y[i] + H/2 * k1[i];
			
			for(int i = 0; i < n; i++)
				k2[i] = f(x + H/2, t ,i);
			for(int i = 0; i < n; i++)
				t[i] = y[i] + H/2 * k2[i];
		
			for(int i = 0; i < n; i++)
				k3[i] = f(x + H/2, t,i);
			for(int i = 0; i < n; i++)	
				t[i] = y[i] + H * k3[i];
				
			for(int i = 0; i < n; i++)
				k4[i] = f(x + H, t,i);
			
			for(int i = 0; i < n; i++)
				y[i] = y[i] + H/6 * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
		
			if(Equal)
				printf("x = %.5f    y = %.10f    y\' = %.10f\n", x + H, y[0], y[1]);
			
			if (fabs(y[1] - y[0] ) < 15 * EPS)
				counter++;									
		}
		H/=2;			
	}
}


int main()
{
	
	double H = 0.2;
	double y[2] = {1, 1};
	double x = 0;
	runge4(x, y, H);
			    	

	return 0;
}
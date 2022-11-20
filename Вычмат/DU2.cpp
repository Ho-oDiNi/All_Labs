#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

const int n = 2;
const double H = 0.2;
const double EPS = 0.001;




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

double* ayler(double x, double y[n], double H)
{
	double t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
		
	for(int i = 0; i < n; i++)
		t[i] = y[i] + H * f(x, y, i );
		
	for(int i = 0; i < n; i++)
		y[i] = t[i];
	return y;	
}

double runge2t(double x, double y[n], double H)
{
	double y_05[n], t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
			
	for(int i = 0; i < n; i++)
		y_05[i] = y[i] + H/2 * f(x, y, i );
		
	for(int i = 0; i < n; i++)
		t[i] += H * f(x + H/2, y_05, i );
		
	for(int i = 0; i < n; i++)	
		y[i] = t[i];
	return y[0];
}

double runge2y(double x, double y[n], double H)
{
	double y_1[n], t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
		
	for(int i = 0; i < n; i++)
		y_1[i] = y[i] + H * f(x, y, i); //H/2
	
	for(int i = 0; i < n; i++)
		t[i] += H/2 * (f(x, y, i ) + f(x + H, y_1, i));
		
	for(int i = 0; i < n; i++)	
		y[i] = t[i];
	return y[0];
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

double Conversion(double*(*func)(double X, double Y[n], double H_), double x, double y[n], double h, int t) 
{
	double I1, I2, I3;
	double *temp;
	temp = func(x, y, h);
	I2 = temp[0];
	//I2=func(x, y, h);
    do {
        I1=I2;
        temp = func(x, y, h);
		I2 = temp[0];
        //I2=func(x, y, h/2); 
        h=h/2;
    } while((I1-I2)>(t*EPS));
    
    return I2;
}



int DU()
{
	double x = 0, y[n] = {1, 1}, t_y[n], Y;
	int t;	
	cin >> t;
	switch(t)
	{
		case 1:
		printf("EILER.\n");
		
			printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0], y[1]);
			while (x < 0.9)
			{
				for(int i=0; i<n; i++)
					t_y[i] = y[i];
				Y = Conversion(ayler, x, t_y, H, 3);	
				ayler(x, y, H);	
				x += H;
				printf("x = %.7f\t y = %.7f\ty\' = %.7f\t After D.C.\t y = %.7f\n", x, y[0], y[1], Y);	
			}
			cout<<"\n";
		
		x = 0; y[0] = 1; y[1] = 1;
		system("PAUSE");
		break;
		
		
		
		
		
		case 2:
		printf("\nRUNGE-KUTT t.\n");
		printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0],  y[1]);
			while (x < 0.9)
			{
				runge2t(x, y, H );
				x += H;
				printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0],  y[1]);	
				
			}
			cout<<"\n";
		x = 0; y[0] = 1; y[1] = 1;
		system("PAUSE");
		break;
		
		
		
		
		
		
		case 3:
		printf("\nRUNGE-KUTT y\'.\n");
		printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0],  y[1]);
			while (x < 0.9)
			{
				runge2y(x, y, H );
				x += H;
				printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0],  y[1]);
				
			}
			cout<<"\n";
		x = 0; y[0] = 1; y[1] = 1;
		system("PAUSE");
		break;
		
		
		
		
		
		
		case 4:
		printf("\nRUNGE-KUTT 4 .\n");
		printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0],  y[1]);
			while (x < 0.9)
			{
				runge4(x, y, H );
				x += H;
				printf("x = %.7f\t y = %.7f\ty\' = %.7f\n", x, y[0],  y[1]);
				
			}
			cout<<"\n";
		x = 0; y[0] = 1; y[1] = 1;
		system("PAUSE");
		break;
	}
	return t;
}

int main()
{
	system("cls");
	cout << "Press: \n";
	cout << "1 - EILER\n";
	cout << "2 - RUNGE-KUTT t\n";
	cout << "3 - RUNGE-KUTT y\'\n";
	cout << "4 - RUNGE-KUTT 4\n";
	int t =1;
	
	while(t)
	{
		t = DU();	
		system("cls");
		cout << "Press: \n";
		cout << "1 - EILER\n";
		cout << "2 - RUNGE-KUTT t\n";
		cout << "3 - RUNGE-KUTT y\'\n";
		cout << "4 - RUNGE-KUTT 4\n";
	}				
	
}


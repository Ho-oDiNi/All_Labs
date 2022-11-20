#include <iostream>
#include <windows.h>
#include <math.h>
#define a 1
#define b 2
#define h0 0.1
#define EPS 0.001


using namespace std;
const int N = 4;

void print_matrix(double A[N][N+1])	
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= N; j++)
			printf("\t%2.2f ", A[i][j]);
		cout <<"\n";
	}
}

double maxmC(double A[N][N+1], double maxC[N+1])
{
	maxC[N]=0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) 
            maxC[i] += abs(A[i][j]);         
        if(maxC[N] < maxC[i])
            maxC[N] = maxC[i];            
    }
	if(maxC[N] >= 1) {
        printf("\nError");
        return 0;
    }
    printf("||C|| = %4.3f\n", maxC[N]);
    
    return maxC[N];
}

double maxmB(double A[N][N+1])
{
	double maxB = 0;
    for(int i = 0; i < N; i++) 
	{
        if(maxB < A[i][N]) 
            maxB = abs(A[i][N]);
    }
    printf("||B|| = %4.3f\n", maxB);
    return maxB;
}

void MPI()
{
	cout << "MPI:\n";
    double temp, maxC[N+1], maxB = 0, B[N], C[N][N], YM[N] = {0, 0, 0}, X[N] = {0,0,0};
  
    double A[N][N+1]={
		{5, -1, -1, 3},
        {-1, -3, 0, -7},
        {1, 1, 4, 3}
	}; 
    print_matrix(A);
    
    for(int i = 0, j = 0; i < N; i++, j++)	
    {   
        temp = A[i][j];
        for(int k = 0; k < N+1; k++)  
        {
            A[i][k] = A[i][k] / temp;
        }
        A[i][j] = 0;
    }
      
    printf("\nMatrix: \n\n");
    print_matrix(A);
    for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++)
        C[i][j] = A[i][j];
    for(int i = 0; i < N; i++) 
        B[i] = A[i][N];
    
    
    maxC[N] = maxmC(A, maxC); 
	maxB = maxmB(A); 
    int shagINT = (log((EPS * (1 - maxC[N])) / maxB ) / log(maxC[N])) + 1;   
    printf("N = %d\n",shagINT);
    
    for(int k = 0; k < shagINT; k++) 
	{         
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)  
            YM[i] = YM[i] + C[i][j] * X[j]; 

        for(int i = 0; i < N; i++) 
		{
            X[i] = B[i] - YM[i];
            YM[i] = 0;
        } 
    }
	
    cout << "\nAnswer:\n";
    for(int i = 0; i < N; i++) 
        printf("\nX%d = \t%2.3f", i, X[i]);
         
}

void ZEID()
{
	cout << "ZEIDEL:\n";
	
	double maxC[N+1], maxB = 0, X[N] = {0,0,0};
	double temp, B[N], C[N][N];
	 
	double A[N][N+1]={
		{5, -1, -1, 3},
        {-1, -3, 0, -7},
        {1, 1, 4, 3}
	}; 
    print_matrix(A);
    
    for(int i = 0,j = 0 ; i < N; i++, j++)	
    {   
        temp = A[i][j];
        for(int k = 0; k < N+1; k++)  
            A[i][k] = A[i][k] / temp;
            
        A[i][j] = 0;
    }
      
    for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++)
        C[i][j] = A[i][j];
        
    for(int i = 0; i < N; i++) 
        B[i] = A[i][N];
    
    printf("\nMatrix: \n\n");
    for(int i = 0; i < N; i++) 
	{
        for(int j = 0; j < N; j++) 
            printf("\t%2.2f ", C[i][j]);
        cout << "\n";
    }  

	maxC[N] = maxmC(A, maxC); 
	maxB = maxmB(A);
	int shagINT = (log((EPS * (1 - maxC[N])) / maxB ) / log(maxC[N])) + 1; 
	printf("N = %d\n",shagINT);
	
    for(int k = 0; k < shagINT; k++) 
	for(int i = 0; i < N; i++) 
	{   
        X[i] = B[i];
        for(int j = 0; j < N; j++) 
		{
            if(j == i)  continue; 
            X[i] = X[i] - C[i][j] * X[j];
        }
    } 
    
    
    cout << "\nAnswer:\n";
    for(int i = 0; i < N; i++) 
        printf("\nX%d = \t%2.3f", i, X[i]);  
}

///////////////////////////////////////////////////////////////////////////////
double lagr(double X, double x[N+1], double y[N+1]) {

    double P = 0, q;
    for (int j = 0; j < N+1; j++) 
	{
        q = 1;
        for (int i = 0; i < N+1; i++) 
            if (i != j) q *= ((X - x[i])/(x[j] - x[i]));
			      
        P += y[j] * q;
    }
    return P;
}

void Lagrange()
{
	double x[N+1], y[N+1];
	double  P, X;
    cout << "Lagrange\nInput X: ";
    cin >> X;
    
    for (int i = 0; i < N+1; i++) 
	{
        x[i] = i;
        y[i] = sqrt(x[i]);
        cout << x[i] << " " << y[i] << "\n";
    }
    P = lagr(X, x, y);
    printf("\nP = %.2lf", P);
}


void etk(double X, double x[N+1], double y[N+1])
{
	for(int j = 1; j < N; j++)
	{
		for (int i = 0; i < N - j; ++i) 
		{
			int l = i + j;
			y[i] = ((y[i]*(X - x[l]) - y[i+1] * (X - x[i])) / (x[i] - x[l]));
			cout << y[i]<< " "; 
		}
		cout <<  "\n"; 
	}
		
}

void Etken()
{
	double x[N+1], y[N+1];
	double  P, X;
    cout << "Etken\nInput X: ";
    cin >> X;
    
    for (int i = 0; i < N; i++) 
	{
        x[i] = i+1;
        y[i] = sqrt(x[i]);
        cout << x[i] << " " << y[i] << "\n";
    }
	
	etk(X, x, y);
}
////////////////////////////////////////////////////////////////////////////////
double func(double x) {
    return 1/x;
}

double simp(float h) {

	double n, x, y_nch, y_ch, I;

	n = (b-a)/h; 
	y_nch = y_ch = 0;
	
    for(int i=1; i<(int)n; i++) 
	{
        x=a+i*h;
        if(i%2==0)	
			y_ch+=func(x);
        else		
			y_nch+=func(x);      
    }

    I = (h/3)*(func(a)+func(b) + 4*y_nch + 2*y_ch);
    
    return I;
}

double tr(float h)  
{
    double I, y_sum=0;

    for(double i=a; i<=b; i+=h)
        y_sum+=func(i);
        
    y_sum-=(func(a)-func(b))/2;
    I = h*y_sum;
    
    return I;
}

void Conversion(double(*f)(float h), double H, int t)
{
	double I1, I2, I3;
	I2=f(H);
    do {
        I1=I2;
        I2=f(H/2); ///
        H=H/2;
    } while((I1-I2)>(t*EPS));
	printf("Double Conv. %.7f\n",I2);
	I3=I2+(I2-I1)/t;
    printf("Correction %.7f",I3);
}

void Simpson()
{
    cout << "Simpson\n";
    printf("Formul %.7f\n",simp(h0));
    Conversion(simp, h0, 15);
}

void Trapez()
{
    double H, I1, I2, I3;
    cout << "Trapez\n";
    printf("Formul %.7f\n",tr(h0));
    Conversion(tr, h0, 3);
}

//////////////////////////////////////////////////////////////////////////////

const int n = 2;
const double H = 0.2;

double f(double x, double y[n], int i)
{
	if(i == 0)
		return y[n-1];
	else	
		return (x*y[i] + y[i-1]);
}

void ayler(double x, double y[n], double H)
{
	double t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
		
	for(int i = 0; i < n; i++)
		t[i] += H * f(x, y, i);
		
	for(int i = 0; i < n; i++)
		y[i] = t[i];
}

void runge2t(double x, double y[n], double H)
{
	double y_05[n], t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
			
	for(int i = 0; i < n; i++)
		y_05[i] = y[i] + H/2 * f(x, y, i);
		
	for(int i = 0; i < n; i++)
		t[i] += H * f(x + H/2, y_05, i);
		
	for(int i = 0; i < n; i++)	
		y[i] = t[i];

}

void runge2y(double x, double y[n], double H)
{
	double y_1[n], t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
		
	for(int i = 0; i < n; i++)
		y_1[i] = y[i] + H/2 * f(x, y, i);
	
	for(int i = 0; i < n; i++)
		t[i] += H/2 * (f(x, y, i) + f(x + H, y_1, i));
		
	for(int i = 0; i < n; i++)	
		y[i] = t[i];
	
}

void runge4(double x, double y[n], double H)
{
	double k1[n], k2[n], k3[n], k4[n], t[n];
	for(int i = 0; i < n; i++)
		k1[i] = f(x, y, i);
	for(int i = 0; i < n; i++)	
		t[i] = y[i] + H/2 * k1[i];
	
	for(int i = 0; i < n; i++)
		k2[i] = f(x + H/2, t, i);
	for(int i = 0; i < n; i++)
		t[i] = y[i] + H/2 * k2[i];

	for(int i = 0; i < n; i++)
		k3[i] = f(x + H/2, t, i);
	for(int i = 0; i < n; i++)	
		t[i] = y[i] + H * k3[i];
		
	for(int i = 0; i < n; i++)
		k4[i] = f(x + H, t, i);
	
	for(int i = 0; i < n; i++)
		y[i] = y[i] + H/6 * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);

}


void DU()
{
	double x = 1, y[n] = {2, -1};
		
	printf("EILER.\n");
	while (x < 1.9)
	{
		ayler(x, y, H);
		x += H;
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x, y[0], x , y[1]);	
	}
	x = 1; y[0] = 2; y[1] = -1;
	printf("\nRUNGE-KUTT t.\n");
	while (x < 1.9)
	{
		runge2t(x, y, H);
		x += H;
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x, y[0], x, y[1]);
	}
	x = 1; y[0] = 2; y[1] = -1;
	printf("\nRUNGE-KUTT y\'.\n");
	while (x < 1.9)
	{
		runge2y(x, y, H);
		x += H;
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x, y[0], x, y[1]);
	}
	x = 1; y[0] = 2; y[1] = -1;
	printf("\nRUNGE-KUTT 4 .\n");
	while(x < 1.9)
	{
		runge4(x, y, H);
		x += H;
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x, y[0], x, y[1]);	
	}	
}

int main()
{
	int t, t2;
	cout << "Press: \n";
	cout << "2 - MPI/ZEID\n";
	cout << "5 - Lagrange\n";
	cout << "6 - Etken\n";
	cout << "8 - Integral with double conversion\n";
	cout << "9 - DU\n";
	cout << "0 - Exit\n";
	cin >> t;
	switch(t)
	{
		case 2:
		system("cls");
		cout << "Press: \n";
		cout << "1 - MPI\n";
		cout << "2 - ZEID\n";
		cout << "3 - MPI+ZEID\n";
		cin >> t2;
		switch(t2)
		{
			case 1: 	MPI();			break;				
			case 2:		ZEID();			break;		
			case 3:		MPI(); ZEID();	break;
		}
		break;
	}
	
}


#include <iostream>
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
        {
            if (A[i][j] < 0)
				A[i][j] = -A[i][j];
            maxC[i] += A[i][j];
        }     
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
    for(int i = 0; i < N; i++) {
        if(A[i][N] < 0)
            A[i][N] = -A[i][N];
        if(maxB < A[i][N]) 
            maxB = A[i][N];
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
        {
            A[i][k] = A[i][k] / temp;
        }
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

void lagrange()
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

void Simpson()
{
    double H, I1, I2, I3;
    cout << "Simpson\n";
    printf("Formul %.7f\n",simp(h0));
    H=h0;
    I2=simp(H);
    do {
        I1=I2;
        I2=simp(H/2);
        H=H/2;
    } while((I1-I2)>(15*EPS));
    printf("Double Conversion %.7f\n",I2);
    I3=I2+(I2-I1)/15;
    printf("Correction %.7f",I3);
    
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

void Trapez()
{
    double H, I1, I2, I3;
    cout << "\nTrapez\n";
    printf("Formul %.7f\n",tr(h0));
    H=h0;
    I2=tr(H);
    do {
        I1=I2;
        I2=tr(H/2);
        H=H/2;
    } while((I1-I2)>(3*EPS));
    printf("Double Conversion %.7f\n", I2);
    I3=I2+(I2-I1)/3;
    printf("Correction %.7f", I3);

}
//////////////////////////
const double H = 0.2;
const int n = 2;

double f(double x, double y[n], int i)
{
	if(i == 0)
		return y[n-1];
	else	
		return (x*y[i] + y[i-1]);
}

void ayler(double x, double y[n])
{
	double t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
		
	for(int i = 0; i < n; i++)
		t[i] += H * f(x, y, i);
		
	for(int i = 0; i < n; i++)
		y[i] = t[i];
}

void runge2t(double x, double y[n])
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

void runge2y(double x, double y[n])
{
	double y_1[n], t[n];
	for(int i = 0; i < n; i++)
		t[i] = y[i];
		
	for(int i = 0; i < n; i++)
		y_1[i] = y[i] + H/2 * f(x, y, i);
	
	for(int i = 0; i < n; i++)
		t[i] += H/2 * (f(x, y, i) + f((x+H), y_1, i));
		
	for(int i = 0; i < n; i++)	
		y[i] = t[i];
	
}
/*
double runge4(double x, double y)
{
	double k1, k2, k3, k4, y1;
	k1=f(x, y);
	k2=f(x + H / 2, y + H / 2 * k1);
	k3=f(x + H / 2, y + H / 2 * k2);
	k4=f(x + H, y + H * k3);
	
	y1 = y + H / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	return y1;
}
*/
int main()
{
	double x = 1, y[n] = {2, -1};
	
	printf("EILER.\n");
	while (x < 1.9)
	{
		ayler(x, y);
		x += H;
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x, y[0], x , y[1]);	
	}
	x = 1; 
	y[0] = 2;
	y[1] = -1;
	printf("\nRUNGE-KUTT t.\n");
	while (x < 1.9)
	{
		runge2t(x, y);
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x + H, y[0], x + H, y[1]);
		x += H;
	}
	x = 1; 
	y[0] = 2;
	y[1] = -1;
	printf("\nRUNGE-KUTT y\'.\n");
	while (x < 1.9)
	{
		runge2y(x, y);
		printf("y(%.2f) = %.10f\ty\'(%.2f) = %.10f\n", x + H, y[0], x + H, y[1]);
		x += H;
	}
	x = 1;
	y[0] = 2;
	y[1] = -1;
	printf("\nRUNGE-KUTT 4 .\n");
	/*while(x < 3)
	{
		y = runge4(x, y);
		printf("y(%.2f) = %.10f\n", x + H, y);
		x += H;
	}
	*/
	return 0;
}

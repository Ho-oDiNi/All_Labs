#include <iostream>
#include <math.h>
#define a 1
#define b 2
#define h0 0.1
#define E 0.001

using namespace std;
const int N = 4;
const double EPS = 0.001;

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
    int i, j, k;
    double temp, maxC[N+1], maxB = 0, B[N], C[N][N], YM[N] = {0, 0, 0}, X[N] = {0,0,0};
  
    double A[N][N+1]={
		{5, -1, -1, 3},
        {-1, -3, 0, -7},
        {1, 1, 4, 3}
	}; 
    print_matrix(A);
    
    for(i = 0, j = 0; i < N; i++, j++)	
    {   
        temp = A[i][j];
        for(k = 0; k < N+1; k++)  
        {
            A[i][k] = A[i][k] / temp;
        }
        A[i][j] = 0;
    }
      
    printf("\nMatrix: \n\n");
    print_matrix(A);
    for(i = 0; i < N; i++) 
        for(j = 0; j < (N); j++)
                C[i][j] = A[i][j];
    for(i = 0; i < N; i++) {
            B[i] = A[i][N];
    }
    
    maxC[N] = maxmC(A, maxC); 
	maxB = maxmB(A); 
    int shagINT = (log((EPS * (1 - maxC[N])) / maxB ) / log(maxC[N])) + 1;   
    printf("N = %d\n",shagINT);
    
    for(k = 0; k < shagINT; k++) {         
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)  
                YM[i] = YM[i] + C[i][j] * X[j]; 

        for(i = 0; i < N; i++) {
            X[i] = B[i] - YM[i];
            YM[i] = 0;
        } 
    }
	
    cout << "\nAnswer:\n";
    for(i = 0; i < N; i++) 
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
	{
       for(int i = 0; i < N; i++) 
	   {   
            X[i] = B[i];
            for(int j = 0; j < N; j++) 
			{
                if(j == i)  continue; 
                X[i] = X[i] - C[i][j] * X[j];
            }
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


//



double func(double x) {
    return 1/x;
}


double simp(float h) {
    double t,I,c,n,M1=0,M2=0;
    int i;
    c=(b-a)/h;
    n=c;
    for (i=1; i<=n; i+=2) {
        t=a+i*h;
        M1+=func(t);
    }
    for (i=2; i<n; i+=2) {
        t=a+i*h;
        M2+=func(t);
    }
    I=h/3*(func(a)+func(b) + 4*M1+ 2*M2);
    return I;
}

int main() 
{
    double H,h;
    double I1,I2,I3;
    printf("Formula Simpsona\n\n\n");
    printf("Raschet po formule simpsona %.7f\n\n",simp(h0));
    H=h0;
    I2=simp(H);
    do {
        I1=I2;
        I2=simp(H/2);
        H=H/2;
    } while((I1-I2)>(15*E));
    printf("Po formule nerescheta  %.7f\n",I2);
    I3=I2+(I2-I1)/15;
    printf("Po formule korrekcii   %.7f",I3);
	return 0;
}

double tr(float h)  
{
    double I,S=0,i;
    int n;
    for(i=a;i<=b; i+=h)
        S+=func(i);
    S-=func(a)/2-func(b)/2;
    I=h*S;
    return I;
}

int main() {
    MPI();
    
    return 0;
}



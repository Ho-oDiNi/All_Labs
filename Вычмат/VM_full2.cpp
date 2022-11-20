#include <iostream>
#include <math.h>

using namespace std;
const int N = 3;
const double EPS = 0.001;

void print_matrix(double A[N][N+1])	
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= N; j++)
			cout << A[i][j] << "\t";
		cout <<"\n";
	}
}

int main()
{   

    cout << "Решение СЛАУ методом МПИ:\n";
    int i, j, k;
    double maxC[N+1], maxB = 0, X[N] = {0,0,0};
    double temp, B[N], C[N][N], YM[N] = {0, 0, 0};
  
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
      
    printf("\nMatrix A: \n\n");
    print_matrix(A);
    for(i = 0; i < N; i++) 
        for(j = 0; j < (N); j++)
                C[i][j] = A[i][j]; 

    for(i = 0; i < N; i++) {
            B[i] = A[i][N];
    }
    

    maxC[N]=0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if (A[i][j] < 0)
				A[i][j] = -A[i][j];
            maxC[i] += A[i][j];
        }     
        if(maxC[N] < maxC[i])
            maxC[N] = maxC[i];            
    }
	if(maxC[N] >= 1) {
        printf("\nМатрица не удовлетворяет условиям сходимости");
        return 0;
    }


    printf("\nНормы и количество шагов:\n\n");
    printf("Норма C = %4.3f\n", maxC[N]);
    maxB = 0;
    for(i = 0; i < N; i++) {
        if(A[i][N] < 0)
            A[i][N] = -A[i][N];
        if(maxB < A[i][N]) 
            maxB = A[i][N];
    }
    printf("Норма B = %4.3f\n", maxB);
    
    
    int shagINT;
    shagINT = (log((EPS * (1 - maxC[N])) / maxB ) / log(maxC[N])) + 1; 
    printf("Количество шагов %d\n",shagINT);
    for(k = 0; k < shagINT; k++) {         
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)  
                YM[i] = YM[i] + C[i][j] * X[j]; 

        for(i = 0; i < N; i++) {
            X[i] = B[i] - YM[i];
            YM[i] = 0;
        } 
    }
	
    printf("\nОтвет:\n");
    for(i = 0; i < N; i++) 
        printf("\nX%d = \t%2.3f", i, X[i]);
    
    
	double A1[N][N+1] = {
		{5, -1, -1, 3},
        {-1, -3, 0, -7},
        {1, 1, 4, 3}
	}; 
	
    printf("\n\n\nРешение СЛАУ методом ЗЕЙДЕЛЯ: \n\n");
    printf("\nЗаданная матрица: \n\n");
    print_matrix(A1);
    printf("\nПреобразованная матрица: \n\n");
    
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            printf("%10.3f", C[i][j]);
        }    
        printf("\n");
    }
    for(i = 0; i < N; i++)   
        X[i] = 0;

    //решение методом зейделя
    for(k = 0; k < shagINT; k++) {
       for(i = 0; i < N; i++) {   
            X[i] = B[i];
            for(j = 0; j < N; j++) {
                if(j == i) 
                    continue; 
                X[i] = X[i] - C[i][j] * X[j];
            }
        } 
    }
    printf("\nОтвет:\n");
    for(i = 0; i < N; i++) 
        printf("\nX%d = \t%2.3f", i, X[i]); 
    printf("\n"); 
    
    return 0;
}



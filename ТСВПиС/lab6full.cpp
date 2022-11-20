#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip> 

#define _USE_MATH_DEFINES

using namespace std;

static complex< double > Mi (0, 1);

static int C=0;

void fourier(complex<double> F[],complex<double> A[], int n)
{
  for (int i = 0; i <n;i++)
  {
    for (int j = 0; j <n;j++)
    {
      A[i] += exp((-2*M_PI*i*j)/n * Mi) *F[j];
      C+=5;
    }
    complex< double > Kn (n, 0);
    A[i] = A[i]/Kn;
  }

}

void obrfourier(complex<double> F[],complex<double> A[], int n)
{
	for (int i = 0; i <n;i++)
	{
	    F[i].real(0);
	    F[i].imag(0);
	    for (int j = 0; j <n;j++)
	    {
	    	F[i] += exp((2*M_PI*i*j)/n * Mi)*A[j];
	    	C+=5;
    	}
  	}	
}

int main() 
{
	
	int size1, size2, n;
	printf(" Input SIZE of 1st array: ");
	cin>>size1;

	printf("\n Input SIZE of 2nd array: ");
	cin>>size2;
	
	int temp;
	if(size1<size2)
	{
		temp = size1;
		size1 = size2;
		size2 = temp;
	}
	
	n = 2*size1 -1;
	
	
	complex< double > F1[2*size1];
	complex< double > A1[2*size1];
	complex< double > F2[2*size1];
	complex< double > A2[2*size1];
	
	complex< double > F[2*size1];
	complex< double > A[2*size1];
	  
	printf("\n Input %d numbers for 1st array: ", size1);	  
	for(int i=0; i<size1; i++)
	{
		cin >> temp;
  		F1[i].real(temp); F1[i].imag(0);
	}
	
	printf("\n Input %d numbers for 2nd array: ", size2); 
	for(int i=0; i<size2; i++)
	{
		cin >> temp;
  		F2[i].real(temp); F2[i].imag(0);
	}
	
	
	for(int i=0; i<size1; i++)
	{
		F1[i+size1].real(0); F1[i].imag(0);
	}
	for(int i=0; i<size1; i++)
	{
		F2[i+size2].real(0); F2[i].imag(0);
	}
	 
	for (int i = 0; i<n;i++)
	{
		cout << F1[i] << "\n";
	}  
	cout << endl <<endl;
	
	for (int i = 0; i<n;i++)
	{
		cout << F2[i] << "\n";
	}  
	cout << endl <<endl;

  	fourier (F1,A1,n);
  	for (int i = 0; i<n;i++)
  	{
   		cout <<fixed <<setprecision(3) << A1[i] << "\n";
  	}
  	cout << endl <<endl;
  	
	fourier (F2,A2,n);
  	for (int i = 0; i<n;i++)
  	{
    	cout <<fixed <<setprecision(3) << A2[i] << "\n";
  	}
  	cout << endl <<endl;
  
	for(int i=0; i<n; i++)
	{
		A[i].real(   n*(A1[i].real() * A2[i].real() -  A1[i].imag() * A2[i].imag())   );
		A[i].imag(   n*(A1[i].imag() * A2[i].real() +  A1[i].real() * A2[i].imag())   );
	}
  	
	for (int i = 0; i<n;i++)
  	{
    	cout <<fixed <<setprecision(3) << A[i] << "\n";
  	}
  	cout << endl <<endl;
  
  	obrfourier(F,A,n);
  	for (int i=0; i<n;i++)
  	{
    	cout <<fixed <<setprecision(2) << F[i] << "\n";
  	}
  
}
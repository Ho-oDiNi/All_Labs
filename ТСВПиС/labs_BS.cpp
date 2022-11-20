#include <iostream>

using namespace std;

void PrintDesk();
void BubbleSort();
void SelectSort();
void MergeSort();
//void DPF();
//void PBPF();
//void ConvolutionSimple();
//void ConvolutionDPF();
//void ConvolutionPBPF();
//void Multiplication();
//void FastMultiplication();
//void Kraskal();
//void FrontBelman();
//void Deykstry();
//void Thief();
//void MultiplicationMatrix();


int main()
{
	int key;
	bool end_flag = 1;
	
	while(end_flag)
	{
		PrintDesk();
		cout << "input key:  ";
		cin >> key;
		system("cls");
		
		switch(key)
		{
			case 1:	BubbleSort(); break;
			case 2: SelectSort(); break;
			case 3: MergeSort(); break;
			
//			case 4: DPF(); break;
//			case 5: PBPF(); break;
//			
//			case 7: ConvolutionSimple(); break;
//			case 8: ConvolutionDPF(); break;
//			case 9: ConvolutionPBPF(); break;
//			
//			case 11: Multiplication(); break;
//			case 12: FastMultiplication(); break;
//			
//			case 13: Kraskal(); break;
//			case 14: FrontBelman(); break;
//			case 15: Deykstry(); break;
//			
//			case 16: Thief(); break;
//			case 17: MultiplicationMatrix(); break;
			
			case 0: end_flag = 0;
		}
		system("PAUSE");
	}
	
	return 0;
}

void PrintDesk()
{
	system("cls");
	cout << "Choose key:\n";
		cout << "\t1 - BubbleSort\n";
		cout << "\t2 - SelectSort\n";
		cout << "\t3 - MergeSort\n\n";
		
		cout << "\t4 - DPF\n";
		cout << "\t5 - PBPF\n\n";
		
		cout << "\t7 - Convolution - simple\n";
		cout << "\t8 - Convolution - DPF\n";
		cout << "\t9 - Convolution - PBPF\n\n";
		
		cout << "\t11 - Multiplication\n";
		cout << "\t12 - Fast Multiplication\n\n";
		
		cout << "\t13 - Kraskal\n";
		cout << "\t14 - Front-Belman\n";
		cout << "\t15 - Deykstry\n\n";
		
		cout << "\t16 - Thief\n";
		cout << "\t17 - Multiplication Matrix\n\n";
		
		cout << "\t0 - EXIT\n";
}

void BubbleSort()
{
	int n;
	cout << "Input n: "; 
	cin >> n;
	
	int *A = new int [n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int temp, M = 0, C = 0;
	for (int i = 0; i < n - 1; i++)
	{
	    for (int j = n - 1; j > i; j--) 
	    {
	      if (A[j - 1] > A[j]) 
	      {
	        temp = A[j - 1]; 
	        A[j - 1] = A[j];
	        A[j] = temp;
	        M+=3;
	      }
	      C++;	      
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\nH = " << C+M << "\n";
}

void SelectSort()
{
	int n;
	cout << "Input n: "; 
	cin >> n;
	
	int *A = new int [n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int temp, min_i, M = 0, C = 0;
	for (int i = 0; i < n - 1; i++) 
	{	
        min_i = i;
    	for (int j = i + 1; j < n; j++) 
    	{
    		C++;
    		if (A[j] < A[min_i]) 
			    min_i = j;
		}	
				  
    	temp = A[i];
   		A[i] = A[min_i];
    	A[min_i] = temp;
    	M+=3;
	}
	
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\nH = " << C+M << "\n";	
}





void MergeSort()
{
	int n;
	cout << "Input n: "; 
	cin >> n;
	
	int *A = new int [n];
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int M = 0, C = 0;
	
	
  	int step = 1;
  	int temp[n];
  	while (step < n)  
  	{
    	int index = 0;
    	int l = 0;
    	int m = l + step;
    	int r = l + step * 2;
    	
	    do
	    {
	    	if(m>n)
	    		m = n;
	    	if(r>n)
	    		r = n;
	    		
	    	int i1 = l, i2 = m; 
	    	while(i1<m && i2<r)
	    	{
	    		C++;
	    		if (A[i1] < A[i2]) 
				{ 
					temp[index++] = A[i1++]; 
					M++;
				}
	    		else 
				{ 
					temp[index++] = A[i2++]; 
					M++;
				}
	    	}
	    	while (i1 < m)
			{
	    		temp[index++] = A[i1++]; 
	    		M++;
			} 
	    	while (i2 < r) 
			{
				temp[index++] = A[i2++];
				M++;	
			}	    	
	    	l += step * 2; 
	    	m += step * 2;
	    	r += step * 2;
	    } while (l < n); 
	    
    	
			
    	step *= 2; 
	}
		
		for (int i = 0; i < n; i++)
		{
    		A[i] = temp[i];
    		M++;
		}
		
	for(int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << "\nH = " << C+M << "\n";		
}



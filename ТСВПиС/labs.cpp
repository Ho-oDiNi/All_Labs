#include <iostream>

using namespace std;

void PrintDesk()
{
	cout << "Choose key:\n";
		cout << "\t1 - BubbleSort\n";
		cout << "\t2 - SelectSort\n";
		cout << "\t3 - MergeSort\n\n";
		
		cout << "\t4 - DPF\n";
		cout << "\t5 - PBPF\n\n";
		
		cout << "\t7 - Сonvolution - simple\n";
		cout << "\t8 - Сonvolution - DPF\n";
		cout << "\t9 - Сonvolution - PBPF\n\n";
		
		cout << "\t11 - Multiplication\n";
		cout << "\t12 - Fast Multiplication\n\n";
		
		cout << "\t13 - Kraskal\n";
		cout << "\t14 - Front-Belman\n";
		cout << "\t15 - Deykstry\n\n";
		
		cout << "\t16 - Thief\n";
		cout << "\t17 - Multiplication Matrix\n\n";
		
		cout << "\t0 - EXIT\n";
}

int main()
{
	int key;
	bool end_flag = 1;
	
	while(end_flag)
	{
		PrintDesk();
		cout << "input key: ";
		cin >> key;
		system("cls");
		
		switch(key)
		{
			case 1:	BubbleSort(); break;
			case 2: SelectSort(); break;
			case 3: MergeSort(); break;
			
			case 4: DPF(); break;
			case 5: PBPF(); break;
			
			case 7: ConvolutionSimple(); break;
			case 8: ConvolutionDPF(); break;
			case 9: ConvolutionPBPF(); break;
			
			case 11: Multiplication(); break;
			case 12: FastMultiplication(); break;
			
			case 13: Kraskal(); break;
			case 14: FrontBelman(); break;
			case 15: Deykstry(); break;
			
			case 16: Thief(); break;
			case 17: MultiplicationMatrix(); break;
			
			case 0: end_flag = 0;
		}
		system("PAUSE");
	}
	
	return 0;
}
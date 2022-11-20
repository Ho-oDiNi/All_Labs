#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

struct record
{

	char Name_depositor[30];
	unsigned short int Deposit; //	%hu
	char Date[10];
	char Name_lawyer[22];
};

int Compare_date(char *A, char *B)
{
	for (int i = 6; i >= 0; i -= 3)
		if (A[i] > B[i])
			return 1;
		else if (A[i] < B[i])
			return -1;
		else if (A[i + 1] > B[i + 1])
			return 1;
		else if (A[i + 1] < B[i + 1])
			return -1;
	return 0;
}

int Compare_deposit(record *A, record *B)
{
	if (A->Deposit > B->Deposit)
		return 1;
	else if (A->Deposit < B->Deposit)
		return -1;
	else
		return Compare_date(A->Date, B->Date);
}

void scan_database(record *Array, FILE *database, int n)
{
	database = fopen("testBase3.dat", "rb");
	fread((record *)Array, sizeof(record), n, database);
	fclose(database);
}

void print_database(struct record *Array,  int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". " << Array[i].Name_depositor << " " << Array[i].Deposit << " " << Array[i].Date << " " << Array[i].Name_lawyer << "\n";
		if ((i % 20 == 0)&&(i!=0))
		{
			cout << "\nContinue? 0/1: ";
			scanf("%d", &temp);
			if (temp == 0) break;
			else system("cls");	
		}
	}
}

void print_info(struct record **A, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". " << A[i]->Name_depositor << " " << A[i]->Deposit << " " << A[i]->Date << " " << A[i]->Name_lawyer << "\n";
		if ((i % 20 == 0)&&(i!=0))
		{
			cout << "\nContinue? 0/1: ";
			scanf("%d", &temp);
			if (temp == 0) break;
			else system("cls");	
		}
	}
}

void Piram(struct record **A, int L, int R)
{
	int j, i;
	struct record *temp;
	temp = A[L];
	i = L;
	while (1)
	{
		j = 2 * i;
		if (j >= R)
			break;
		if (j < R)
		{
			if (Compare_deposit(A[j + 1], A[j]) != -1)
				j++;
		}
		if (Compare_deposit(temp, A[j]) != -1)
			break;

		A[i] = A[j];
		i = j;
	}
	A[i] = temp;
}

void PiramSort(struct record **A, int n)
{
	int i, j, R = n - 1;
	struct record *temp;
	int L = (n - 1) / 2;
	while (L >= 0)
	{
		Piram(A, L, R);
		L--;
	}
	while (R > 0)
	{
		temp = A[R];
		A[R] = A[0];
		A[0] = temp;
		R--;
		Piram(A, 0, R);
	}
}

int main()
{
	SetConsoleCP(1251);

	int n = 4000, ERROR_CLOSE;
	FILE *database;
	struct record Array[n];
	struct record *A[n];

	scan_database(Array, database, n);

	for (int i = 0; i < n; i++)
	{
		A[i] = &Array[i];
	}

	PiramSort(A, n);
	//print_database(Array, n);
	print_info(A, n);

	return 1;
}
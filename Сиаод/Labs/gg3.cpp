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

struct Node {
	record Record;
	Node* next;
};

int Compare_date(char* A, char* B)
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

int Compare_deposit(record* A, record* B)
{
	if (A->Deposit > B->Deposit)
		return 1;
	else if (A->Deposit < B->Deposit)
		return -1;
	else
		return Compare_date(A->Date, B->Date);
}

void scan_database(record* Array, record** A, int n)
{
	FILE* database;
	database = fopen("testBase3.dat", "rb");
	fread((record*)Array, sizeof(record), n, database);
	fclose(database);
	for (int i = 0; i < n; i++)
	{
		A[i] = &Array[i];
	}
}

void print_database(record* A, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". " << A[i].Name_depositor << " " << A[i].Deposit << " " << A[i].Date << " " << A[i].Name_lawyer << "\n";

		if ((i % 20 == 0) && (i != 0))
		{
			cout << "\nContinue? 0/1: ";
			scanf("%d", &temp);
			if (temp == 0) break;
			else system("cls");
		}
	}
}

void print_array(record** A, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". " << A[i]->Name_depositor << " " << A[i]->Deposit << " " << A[i]->Date << " " << A[i]->Name_lawyer << "\n";
		if ((i % 20 == 0) && (i != 0))
		{
			cout << "\nContinue? 0/1: ";
			scanf("%d", &temp);
			if (temp == 0) break;
			else system("cls");
		}
	}
}

void Piram(record** A, int L, int R)
{
	int j, i;
	record* temp;
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

void PiramSort(record** A, int n)
{
	int i, j, R = n - 1;
	record* temp;
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

int Binar(unsigned short int key, record** A, int n)
{
	int L = 0, R = n - 1, m;
	while (L < R)
	{
		m = (L + R) / 2;
		if (A[m]->Deposit < key)
			L = m + 1;
		else
			R = m;
	}
	if (key == A[R]->Deposit)
		return R;
	else
		return -1;
}

void search_array(record** A, Node* root)
{
	Node* p = root;
	for (int i = 0; p->next; i++)
	{
		A[i] = &(p->Record);
		p = p->next;
	}
}

void search_array1(Node* root, int k)
{
	Node* p = root;
	for (int i = 0; p->next; i++)
	{
		cout << i << ". " << p->Record.Name_depositor << " " << p->Record.Deposit << " " << p->Record.Date << " " << p->Record.Name_lawyer << "\n";
		p = p->next;
	}
	cout << k;
	system("pause");
}

void search(record** A, int n)
{
	unsigned short int key;
	Node* head, *tail, *p;
	head = tail = p = NULL;
	
	printf("input key:");
	scanf("%hu", &key);

	int ind = Binar(key, A, n);
	if (ind == -1) {
		printf("Not found\n");
		printf("Press Any Button\n\n");
		system("pause");
	}
	else
	{
		head = new Node;
		head->Record = *A[ind];
		head->next = NULL;
		tail = head;
		int i = ind + 1;
		while (A[i]->Deposit == key)
		{	
			p = new Node;
			tail->next = p;
			p->Record = *A[i];
			p->next = NULL;
			i++;
		}
		int k = i - ind;
		//record* Search_arr[k];
		//search_array(Search_arr, head);
		search_array1(head, k);
		//print_array(Search_arr, k);
	}
}

int main()
{
	SetConsoleCP(1251);

	int n = 4000, ERROR_CLOSE, temp;

	record Array[n];
	record* A[n];

	while (1)
	{
		cout << "1 - Scan BD " << endl;
		cout << "2 - Print BD " << endl;
		cout << "3 - Sort Array " << endl;
		cout << "4 - Print Array " << endl;
		cout << "5 - Search " << endl;
		cout << "0 - End " << endl;
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
			scan_database(Array, A, n);
			break;
		case 2:
			print_database(Array, n);
			break;
		case 3:
			PiramSort(A, n);
			break;
		case 4:
			print_array(A, n);
			break;
		case 5:
			search(A, n);
			break;
		case 0:
			return 1;
		}
		system("cls");
	}
}
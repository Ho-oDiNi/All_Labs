#include <iostream>
#include <stdio.h>
#include <fstream>
#include <Windows.h>

using namespace std;

const int N = 4000;

struct Record
{
	char Name_depositor[30];
	unsigned short int Deposit; //	%hu
	char Date[10];
	char Name_lawyer[22];
};

struct Node 
{
    Record record;
    Node *next;
};

struct Vertex
{
	Record* data;
	Vertex* left;
	Vertex* right;
	int W;
};

////int Compare_date(char* A, char* B)
//{
//	for (int i = 6; i >= 0; i -= 3)
//		if (A[i] > B[i])
//			return 1;
//		else if (A[i] < B[i])
//			return -1;
//		else if (A[i + 1] > B[i + 1])
//			return 1;
//		else if (A[i + 1] < B[i + 1])
//			return -1;
//	return 0;
//}
//
//void print_record(record* Record)
//{
//	cout << Record->Name_depositor
//		<< "  " << Record->Deposit
//		<< "  " << Record->Date
//		<< "  " << Record->Name_lawyer << "\n";
//}
//
//void AddSDPTree(record* D, Vertex*& p)
//{
//	if (p == NULL)
//	{
//		p = new Vertex;
//		p->data = D;
//		p->left = p->right = NULL;
//	}
//	else
//	{
//		if (Compare_date(D->Date, p->data->Date) == -1)
//			AddSDPTree(D, p->left);
//		else
//			AddSDPTree(D, p->right);
//	}
//}
//
////void A1(record** V, Vertex*& root, int k)
//{
//	for(int i = 0; i < k; i++)
//		AddSDPTree(V[i], root);
//}
//
//void rmtree(Vertex* root) {
//	if (root) {
//		rmtree(root->right);
//		rmtree(root->left);
//		delete root;
//	}
//}
//
//void Print_tree(Vertex* p) {
//	static int i = 1;
//	if (p) {
//		Print_tree(p->left);
//		print_record(p->data);
//		Print_tree(p->right);
//	}
//}
//
//void search_in_tree(Vertex* root, char *key) 
//{
//	if (root) 
//	{
//		if (Compare_date(root->data->Date, key) == 1) {
//			search_in_tree(root->left, key);
//		}
//		else if (Compare_date(root->data->Date, key) == -1) {
//			search_in_tree(root->right, key);
//		}
//		else if (Compare_date(root->data->Date, key) == 0) {
//			search_in_tree(root->left, key);
//			printf("\n");
//			print_record(root->data);
//			printf("\n");
//			search_in_tree(root->right, key);
//		}
//	}
//}
//
//void tree(record** arr, int k)
//{
//	Vertex* root = NULL;
//
//	A1(arr, root, k);
//
//	Print_tree(root);
//	char key[10];
//	printf("input key: ");
//	cin >> key;
//	
//	search_in_tree(root, key);
//		
//	system("pause");
//	rmtree(root);
//}
//
////int Compare_deposit(record* A, record* B)
//{
//	if (A->Deposit > B->Deposit)
//		return 1;
//	else if (A->Deposit < B->Deposit)
//		return -1;
//	else
//		return Compare_date(A->Date, B->Date);
//}
//
//void scan_database(record* Array, record** A, int n)
//{
//	FILE* database;
//	database = fopen("testBase3.dat", "rb");
//	fread((record*)Array, sizeof(record), n, database);
//	fclose(database);
//	for (int i = 0; i < n; i++)
//	{
//		A[i] = &Array[i];
//	}
//}
//
//void print_database(record* A, int n)
//{
//	int temp;
//	for (int i = 0; i < n; i++)
//	{
//		cout << i << ". " << A[i].Name_depositor << " " << A[i].Deposit << " " << A[i].Date << " " << A[i].Name_lawyer << "\n";
//
//		if ((i % 20 == 0) && (i != 0))
//		{
//			cout << "\nContinue? 0/1: ";
//			scanf("%d", &temp);
//			if (temp == 0) break;
//			else system("cls");
//		}
//	}
//	system("pause");
//}
//
void print_array(Record* A[])
{
	int temp;
	for (int i = 0; i < N; i++)
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
	system("pause");
}
//
//
//
//int Binar(unsigned short int key, record** A, int n)
//{
//	int L = 0, R = n - 1, m;
//	while (L < R)
//	{
//		m = (L + R) / 2;
//		if (A[m]->Deposit < key)
//			L = m + 1;
//		else
//			R = m;
//	}
//	if (key == A[R]->Deposit)
//		return R;
//	else
//		return -1;
//}
//
//void search_array(record** A, Node* root, int k)
//{
//	Node* p = root;
//	for (int i = 0; i < k; i++)
//	{
//		A[i] = (p->Record);
//		p = p->next;
//	}
//}
//
//void search(record** A, int n, int &k, int &ind)
//{
//	unsigned short int key;
//	Node* head, * tail, * p;
//	head = tail = p = NULL;
//
//	printf("input key:");
//	scanf("%hu", &key);
//
//	ind = Binar(key, A, n);
//	if (ind == -1) {
//		printf("Not found\n");
//		printf("Press Any Button\n\n");
//		system("pause");
//	}
//	else
//	{
//		head = new Node{
//			A[ind], NULL
//		};
//		tail = head;
//		int i = ind + 1;
//		while (A[i]->Deposit == key)
//		{
//
//			tail->next = new Node{
//				A[i], NULL
//			};
//			tail = tail->next;
//			i++;
//		}
//		k = i - ind;
//		record* Search_arr[k];
//		search_array(Search_arr, head, k);
//		print_array(Search_arr, k);
//	}
//}

void digitalSort(Node *&head) {
    int field_len = 22;
    struct Queue {
        Node *tail;
        Node *head;
    } q[256];
    Node *p;

    for (int j = 0; j < field_len; j++) {
        for (auto &i : q) {
            i.tail = i.head = nullptr;
        }
        while (head) {
            int d;
            int ind = 0;
//            for (int i = 0; i < 2; ++i) {
//                while (head->record.Name_lawyer[ind++] != ' ') {}
//            }
            if (ind - j < 0) {
                d = 255 - abs(head->record.Name_lawyer[field_len - j - 1 + ind]);
            } else {
                d = ' ';
            }

            p = q[d].tail;
            if (q[d].head == nullptr)
                q[d].head = head;
            else
                p->next = head;

            p = q[d].tail = head;
            head = head->next;
            p->next = nullptr;
        }
        int i;
        for (i = 0; i < 256; i++) {
            if (q[i].head != nullptr)
                break;
        }
        head = q[i].head;
        p = q[i].tail;
        for (int k = i + 1; k < 256; k++) {
            if (q[k].head != nullptr) {
                p->next = q[k].head;
                p = q[k].tail;
            }
        }
    }
}

Node *load_to_memory() 
{
    ifstream file("testBase3.dat", ios::binary);
    
    Node *root = nullptr;
    for (int i = 0; i < N; ++i) 
	{
        Record record;
        file.read((char *) &record, sizeof(Record));
        root = new Node{record, root};
    }
    file.close();
    return root;
}

void make_index_array(Record *arr[], Node *root, int n = N) {
    Node *p = root;
    for (int i = 0; i < n; i++) {
        arr[i] = &(p->record);
        p = p->next;
    }
}

int main()
{
	SetConsoleCP(1251);

	int temp, ind, k = -1;


	Node *root = load_to_memory();
	Record *A[N], *Array[N];

	make_index_array(A, root);
	digitalSort(root);
    make_index_array(Array, root);
	
	while (1)
	{

		cout << "1 - Print BD " << endl;
		cout << "2 - Print Array " << endl;
		cout << "3 - Search " << endl;
		cout << "4 - Tree " << endl;
		cout << "0 - End " << endl;
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
			print_array(Array);
			break;
		case 2:
			print_array(A);	
			break;
		case 3:
			//search(A, n, k, ind);
			break;
		case 4:
			if(k < 0)
				cout << "Search first\n";
			else
			//	tree(&A[ind], k);
			break;	
		default:
			return 1;
		}
		system("cls");
	}
}
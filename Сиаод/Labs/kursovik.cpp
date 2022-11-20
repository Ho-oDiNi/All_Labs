#include <vector>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <unordered_map>


using namespace std;

struct record
{
	char Name_depositor[30];
	unsigned short int Deposit;
	char Date[10];
	char Name_lawyer[22];
};

struct Node
{
	record* Record;
	Node* next;
};

struct Vertex
{
	record* data;
	Vertex* left;
	Vertex* right;
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

void print_record(record* Record)
{
	cout << Record->Name_depositor
		<< "  " << Record->Deposit
		<< "  " << Record->Date
		<< "  " << Record->Name_lawyer << "\n";
}

void AddSDPTree(record* D, Vertex*& p)
{
	if (p == NULL)
	{
		p = new Vertex;
		p->data = D;
		p->left = p->right = NULL;
	}
	else
	{
		if (Compare_date(D->Date, p->data->Date) == -1)
			AddSDPTree(D, p->left);
		else
			AddSDPTree(D, p->right);
	}
}

void A1(record** Arr, Vertex*& root, int k)
{
	int w[k], index[k], temp;
	for(int i=0; i<k;i++)
	{
		w[i]=rand()%100;
		index[i]=i;
	}
    for( int i = 0; i < k; i++)
        for( int j = 0; j < k - 1; j++){ 
            if(w[index[j]] < w[index[j + 1]]){
                temp = index [j];
                index[j] = index[j + 1]; 
                index[j + 1] = temp; 
            }
        }
	for(int i = 0; i < k; i++)
		AddSDPTree(Arr[index[i]], root);
}

void delete_tree(Vertex* root) 
{
	if (root) {
		delete_tree(root->right);
		delete_tree(root->left);
		delete root;
	}
}

void Print_tree(Vertex* p) 
{
	if (p!=NULL) {
		Print_tree(p->left);
		print_record(p->data);
		Print_tree(p->right);
	}
}

void search_in_tree(Vertex* root, char *key) 
{
	if (root) 
	{
		if (Compare_date(root->data->Date, key) == 1) {
			search_in_tree(root->left, key);
		}
		else if (Compare_date(root->data->Date, key) == -1) {
			search_in_tree(root->right, key);
		}
		else if (Compare_date(root->data->Date, key) == 0) {
			search_in_tree(root->left, key);
			printf("\n");
			print_record(root->data);
			printf("\n");
			search_in_tree(root->right, key);
		}
	}
}

void tree(record** Arr, int k)
{
	Vertex* root = NULL;

	A1(Arr, root, k);

	Print_tree(root);
	char key[10];
	printf("input key: ");
	cin >> key;
	
	search_in_tree(root, key);
		
	system("pause");
	delete_tree(root);
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

void print_database(record* Array, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". " << Array[i].Name_depositor << " " << Array[i].Deposit << " " << Array[i].Date << " " << Array[i].Name_lawyer << "\n";

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

void print_array(record** mas, int n)
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		cout << i << ". " << mas[i]->Name_depositor << " " << mas[i]->Deposit << " " << mas[i]->Date << " " << mas[i]->Name_lawyer << "\n";
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

void search_array(record** Search_arr, Node* root, int k)
{
	Node* p = root;
	for (int i = 0; i < k; i++)
	{
		Search_arr[i] = (p->Record);
		p = p->next;
	}
}

void search(record** Arr, int n, int &k, int &ind)
{
	unsigned short int key;
	Node *head, *tail, *p;
	head = tail = p = NULL;

	printf("input key:");
	scanf("%hu", &key);

	ind = Binar(key, Arr, n);
	if (ind == -1) {
		printf("Not found\n");
		printf("Press Any Button\n\n");
		system("pause");
	}
	else
	{
		head = new Node{
			Arr[ind], NULL
		};
		tail = head;
		int i = ind + 1;
		while (Arr[i]->Deposit == key)
		{

			tail->next = new Node{
				Arr[i], NULL
			};
			tail = tail->next;
			i++;
		}
		k = i - ind;
		record* Search_arr[k];
		search_array(Search_arr, head, k);
		print_array(Search_arr, k);
	}
}

int up(int n, double q, double *array, double *chance) { 
    int i = 0, j = 0;                 
    for (i = n - 2; i >= 1; i--) {
        if (array[i - 1] < q) array[i] = array[i - 1];
        else {
            j = i;
            break;
        }
        if ((i - 1) == 0 && chance[i - 1] < q) {
            j = 0;
            break;
        }
    }
    array[j] = q;
    return j;
}

void down(int n, int j, int *Length, char c[][20]) {
    char pref[20];
    for (int i = 0; i < 20; i++) pref[i] = c[j][i];
    int l = Length[j];
    for (int i = j; i < n - 2; i++) {
        for (int k = 0; k < 20; k++)
            c[i][k] = c[i+1][k];
        Length[i] = Length[i+1];
    }
    for (int i = 0; i < 20; i++) {
        c[n-2][i] = pref[i];
        c[n-1][i] = pref[i];
    }
    c[n-1][l] = '1';
    c[n-2][l] = '0';
    Length[n-1] = l + 1;
    Length[n-2] = l + 1;
}

void huffman(int n, double *array, int *Length, char c[][20], double *chance) {
    if (n == 2) {
        c[0][0] = '0';
        Length[0] = 1;
        c[1][0] = '1';
        Length[1] = 1;
    } else {
        double q = array[n - 2] + array[n - 1];
        int j = up(n, q, array, chance); 
        huffman(n - 1, array, Length, c, chance);
        down(n, j, Length, c);
    }
}

unordered_map<char, int> get_char_counts_from_file(const string &file_name, int &file_size, int n) {
    ifstream file(file_name, ios::binary);
    char ch_arr[sizeof(record) * n];
    for(int i=0; i<sizeof(record) * n; i++)
    	ch_arr[i]='\0';
	
    file.read((char *) ch_arr, sizeof(record) * n);
    file.close();

    unordered_map<char, int> counter_map;
    file_size = 0;
    for (auto ch : ch_arr) {
        counter_map[ch]++;
        file_size++;
    }
    return counter_map;
}

vector<pair<double, char>> calc_probabilities(const unordered_map<char, int> &counter_map, int count) {
    vector<pair<double, char>> probabilities;
    probabilities.reserve(counter_map.size());
    for (auto i : counter_map) {
        probabilities.emplace_back(make_pair((double) i.second / count, i.first));
    }
    return probabilities;
}

void coding(int n) {
    int file_size;
    unordered_map<char, int> counter_map;
    counter_map = get_char_counts_from_file("testBase3.dat", file_size, n);

    auto probabilities = calc_probabilities(counter_map, file_size);
    counter_map.clear();

    sort(probabilities.begin(), probabilities.end(), greater<pair<double, char>>());
    cout << "Probabil.  char\n";
    for (auto i : probabilities) {
        cout << fixed << i.first << " | " << i.second << '\n';
    }

    const int N = (int) probabilities.size();

    char c[N][20];
    int Length[N];
    for (auto &i : Length) {
        i = 0;
    }

    auto p = new double[N];
    double chance_l[N];
    for (int i = 0; i < N; ++i) {
        p[i] = probabilities[i].first;
        chance_l[i] = p[i];
    }

    huffman(N, chance_l, Length, c, p);
    cout << "\nHaffmanCode:\n";
    cout << "\nCh  Prob      Code\n";
    double avg_len = 0;
    double entropy = 0;
    for (int i = 0; i < N; i++) {
        avg_len += Length[i] * p[i];
        entropy -= p[i] * log2(p[i]);
        printf("%c | %.5lf | ", probabilities[i].second, p[i]);
        for (int j = 0; j < Length[i]; ++j) {
            printf("%c", c[i][j]);
        }
        cout << '\n';
    }
    cout << "Average length = " << avg_len << '\n'
         << "Entropy = " << entropy << '\n'
         << "Average length < entropy + 1\n"
         << "N = " << N << "\n\n";
         system("pause");
}

int main()
{
	SetConsoleCP(1251);

	int n = 4000, temp, ind, k = -1;
	
	record Array[n];
	record* Arr[n];

	scan_database(Array, Arr, n);
	PiramSort(Arr, n);
	
	while (1)
	{

		cout << "1 - Print BD " << endl;
		cout << "2 - Print Array " << endl;
		cout << "3 - Search " << endl;
		cout << "4 - Tree " << endl;
		cout << "5 - Coding " << endl;
		cout << "0 - End " << endl;
		scanf("%d", &temp);
		switch (temp)
		{
		case 1:
			print_database(Array, n);
			break;
		case 2:
			print_array(Arr, n);	
			break;
		case 3:
			search(Arr, n, k, ind);
			break;
		case 4:
			if(k < 0)
				cout << "Search first\n";
			else
				tree(&Arr[ind], k);
			break;
		case 5:
			coding(n);
            break;	
		default:
			return 1;
		}
		system("cls");
	}
}

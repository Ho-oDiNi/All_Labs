#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

static int vr = 1;
static int hr = 1;

struct tVertex
{
    int data;
    tVertex* left;
    tVertex* right;
    int balance;
};

typedef struct tVertex pVertex;

struct Massive 
{
    int w;
    int index;
    int data;
};

typedef struct Massive mas;

void AddSDPTree(int D, pVertex*& p)
{
    if (p == NULL)
    {
        p = new pVertex;
        p->data = D;
        p->left = p->right = NULL;
    }
    else
    {
        if (D < p->data)
            AddSDPTree(D, p->left);
        else
            AddSDPTree(D, p->right);
    }
}

void A1(mas *mass, pVertex*& root, int n)
{

    int temp, data;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++) {
            if(mass[mass[j].index].w < mass[mass[j+1].index].w)
            {
                temp = mass[j].index;
                mass[j].index = mass[j+1].index;
                mass[j+1].index = temp;
            }
        }

    for (int i = 0; i < n; i++)
    {
        AddSDPTree(mass[mass[i].index].data, root);
    }
        
}

void A2(mas *mass, int L, int R, pVertex*& root) {
    int wes = 0, sum = 0;
    int i;
    if (L <= R) {
        for (i = L; i <= R; i++)
            wes += mass[i].w;
        for (i = L; i <= R - 1; i++) {
            if ((sum < (wes / 2)) && ((sum + mass[i].w) > (wes / 2))) break;
            sum += mass[i].w;
        }
        AddSDPTree(mass[i - 1].data, root);
        A2(mass, L, i - 1, root);
        A2(mass, i + 1, R, root);
    }
}

void print_tree_left(pVertex* tree)
{
    if (tree != NULL)
    {
        print_tree_left(tree->left);
        printf("%2d ", tree->data);
        print_tree_left(tree->right);
    }
}

void print_tree_down(pVertex* tree)
{
    if (tree != NULL)
    {
        printf("%2d ", tree->data);
        print_tree_down(tree->left);
        print_tree_down(tree->right);
    }
}

void print_tree_up(pVertex* tree)
{
    if (tree != NULL)
    {
        print_tree_up(tree->left);
        print_tree_up(tree->right);
        printf("%2d ", tree->data);
    }
}

int HeightTree(pVertex* p)
{
    int pl = 0;
    int pr = 0;
    if (p == NULL) return 0;
    else
    {
        pl = HeightTree(p->left);
        pr = HeightTree(p->right);
        return 1 + ((pl > pr) ? pl : pr);
    }
}

int AverageHeight(pVertex* p, int L)
{
    if (p == NULL) return 0;
    else return L + AverageHeight(p->left, L + 1) + AverageHeight(p->right, L + 1);
}

int SizeTree(pVertex* p)
{
    if (p == NULL) return 0;
    else return 1 + SizeTree(p->left) + SizeTree(p->right);
}

float AverageHeightTree(pVertex* p)
{
    return(AverageHeight(p, 1) / (float)SizeTree(p));
}

int Control_Sum(pVertex* p)
{
    if (p == NULL) return 0;
    else return p->data + Control_Sum(p->left) + Control_Sum(p->right);
}



int print_all_func(pVertex* root)
{
    int temp, X;
    while (true)
    {
        printf("\nНажмите:");
        printf("\n1 - обход слева-направо");
        printf("\n2 - обход сверху-вниз");
        printf("\n3 - обход снизу-вверх");
        printf("\n4 - высота дерева");
        printf("\n5 - средняя высота дерева");
        printf("\n6 - размер дерева");
        printf("\n7 - контрольная сумма");
        printf("\n0 - выход\n");
        cin >> temp;
        switch (temp)
        {
        case 1:
            print_tree_left(root);
            break;
        case 2:
            print_tree_down(root);
            break;
        case 3:
            print_tree_up(root);
            break;
        case 4:
            printf("Высота дерева: %d", HeightTree(root));
            break;
        case 5:
            printf("Средняя высота дерева: %2.2f", AverageHeightTree(root));
            break;
        case 6:
            printf("Размер дерева %d", SizeTree(root));
            break;
        case 7:
            printf("Контрольная сумма %d", Control_Sum(root));
            break;
        case 0:
            return 1;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    pVertex* root = NULL;
    
    int n, i, temp;
    printf("\n Введите N:");
    cin >> n;

    mas* mass = new mas[n];

    for (i = 0; i < n; i++)
    {
        mass[i].data = i;
        mass[i].index = i;
        mass[i].w = rand() % 100;

        printf("%2d ", mass[i].data);
    }

    printf("\nВведите:");
    printf("\n1 - А1");
    printf("\n2 - А2\n");
    cin >> temp;
    if(temp==1)
        A1(mass, root, n);
    if (temp == 2)
        A2(mass, 1, n, root);

    print_all_func(root);

    return 1;
}
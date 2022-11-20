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

void DbD_add(int D, pVertex *& p)
{
    if (p == NULL) {
        p = new pVertex{ D, NULL, NULL, 0};
        vr = 1;
    }
    else if (p->data > D) 
    {
        DbD_add(D, p->left);
        if (vr == 1) {
            if (p->balance == 0) {
                pVertex* q = p->left;
                p->left = q->right;
                q->right = p;
                p = q;
                q->balance = 1;
                vr = 0;
                hr = 1;
            }
            else {
                p->balance = 0;
                vr = 1;
                hr = 0;
            }
        }
        else {
            hr = 0;
        }
    }
    else if (p->data <= D) 
    {
        DbD_add(D, p->right);
        if (vr == 1) {
            p->balance = 1;
            hr = 1;
            vr = 0;
        }
        else if (hr == 1) {
            if (p->balance == 1) {
                pVertex* q = p->right;
                p->balance = 0;
                q->balance = 0;
                p->right = q->left;
                q->left = p;
                p = q;
                vr = 1;
                hr = 0;
            }
            else {
                hr = 0;
            }
        }
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
    int n, i;
    printf("\n Введите N:");
    cin >> n;

    int* mass = new int[n];
    for (i = 0; i < n; i++)
    {
        mass[i] = i;
        printf("%2d ", mass[i]);
    }

    for (i = 0; i < n; i++)
    {
        DbD_add(mass[i], root);
    }

    print_all_func(root);

    return 1;
}
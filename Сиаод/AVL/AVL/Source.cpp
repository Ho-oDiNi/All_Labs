#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

struct tVertex
{
    int data;
    int balance;
    tVertex* left;
    tVertex* right;
};

typedef struct tVertex pVertex;



pVertex* BalansTree(int L, int R, int* mass)
{
    int m;
    pVertex* p;
    if (L > R) return NULL;
    else
    {
        m = (L + R) / 2;
        p = (pVertex*)malloc(sizeof(pVertex));
        p->data = mass[m];
        p->left = BalansTree(L, m - 1, mass);
        p->right = BalansTree(m + 1, R, mass);
        return p;
    }
}

void AddTree(pVertex** root, int D)
{
    pVertex** p = root;

    while (*p != NULL)
    {
        if (D < (*p)->data)
            p = &((*p)->left);
        else
            p = &((*p)->right);
    }
    if (*p == NULL)
    {
        *p = (pVertex*)malloc(sizeof(pVertex));
        (*p)->data = D;
        (*p)->left = (*p)->right = NULL;
    }
}

pVertex* LL_rotate(pVertex* p)
{
    pVertex* q;
    q = p->left;
    q->balance = 0;
    p->balance = 0;
    p->left = q->right;
    q->right = p;
    return q;
}

pVertex* LR_rotate(pVertex* p)
{
    pVertex* q, * r;
    q = p->left;
    r = q->right;
    if (r->balance < 0)
        p->balance = 1;
    else
        p->balance = 0;
    if (r->balance > 0)
        q->balance = -1;
    else
        q->balance = 0;
    r->balance = 0;
    p->left = r->right;
    q->right = r->left;
    r->left = q;
    r->right = p;
    return r;
}

pVertex* RR_rotate(pVertex* p)
{
    pVertex* q;
    q = p->right;
    q->balance = 0;
    p->balance = 0;
    p->right = q->left;
    q->left = p;
    return q;
}

pVertex* RL_rotate(pVertex* p)
{
    pVertex* q, * r;
    q = p->right;
    r = q->left;
    if (r->balance > 0)
        p->balance = -1;
    else
        p->balance = 0;
    if (r->balance < 0)
        q->balance = 1;
    else
        q->balance = 0;
    r->balance = 0;
    p->right = r->left;
    q->left = r->right;
    r->left = p;
    r->right = q;
    return r;
}

void AvlTree(pVertex* &p, int D)
{
    bool grow = false;
    if (p == NULL)
    {
        p = (pVertex*)malloc(sizeof(pVertex));
        p->data = D;
        p->left = NULL;
        p->right = NULL;
        p->balance = 0;
        grow = true;
    }
    else
    {
        if (p->data > D)
        {
            AvlTree(p->left, D);
            if (grow == true)
                if (p->balance > 0)
                {
                    p->balance = 0;
                    grow = false;
                }
                else if (p->balance == 0)
                {
                    p->balance = -1;
                }
                else
                {
                    if (p->left->balance < 0)  p = LL_rotate(p);
                    else p = LR_rotate(p);
                    grow = false;
                }
        }
        else
        {
            AvlTree(p->right, D);
            if (grow == true)
                if (p->balance > 0)
                {
                    p->balance = 0;
                    grow = false;
                }
                else if (p->balance == 0)
                {
                    p->balance = -1;
                }
                else
                {
                    if (p->right->balance < 0) p = RR_rotate(p);
                    else p = RL_rotate(p);
                    grow = false;
                }
        }
    }
}

pVertex* LL1_rotate(pVertex* p, bool& down)
{
    pVertex* q;
    q = p->left;
    if (q->balance == 0) { p->balance = -1; q->balance = 1; down = false; }
    else { p->balance = 0; q->balance = 0; }
    p->left = q->right;
    q->right = p;
    return q;
}

pVertex* RR1_rotate(pVertex* p, bool& down)
{
    pVertex* q;
    q = p->right;
    if (q->balance == 0) { p->balance = 1; q->balance = -1; down = false; }
    else { p->balance = 0; q->balance = 0; }
    p->right = q->left;
    q->left = p;
    return q;
}


pVertex* BL(pVertex* &p, bool& down)
{
    if (p->balance == -1)  p->balance = 0;
    else if (p->balance == 0) { p->balance = 1; down = false; }
    else if (p->balance == 1)
        if (p->right->balance >= 0)
            p = RR1_rotate(p, down);
        else
            p = RL_rotate(p);
    return p;
}

pVertex* BR(pVertex* p, bool& down)
{
    if (p->balance == 1)  p->balance = 0;
    else if (p->balance == 0) { p->balance = -1; down = false;  }
    else if (p->balance == -1)
        if (p->left->balance <= 0)
            p = LL1_rotate(p, down);
        else
            p = LR_rotate(p);
    return p;
}




void del(pVertex* r, bool& down)
{
    pVertex* q;
    if (r->right != NULL)
    {
        del(r->right, down);
        if (down) r = BR(r, down);
    }
    else
    {
        q = r;
        r = r->left;
        down = true;
    }
}

void DeleteAVL(int x, pVertex* &p, bool& down)
{
    if (p == NULL) {
        cout << "\n����� ���\n";
    }
    else if (p->data > x) {
        DeleteAVL(x, p->left, down);
        if (down) { p = BL(p, down); }
    }
    else if (p->data < x) {
        DeleteAVL(x, p->right, down);
        if (down) { p = BR(p, down); }
    }
    else
    {
        pVertex* q;
        q = p;
        if (q->left == NULL) { p = q->right; down = true; }
        else if (q->right == NULL) { p = q->left; down = true; }
        else {
            del(q->left, down);
            if (down)
                p = BL(p, down);
        }
        delete(q);
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
    int temp, x;
    while (true)
    {
        bool down = false;
        printf("\n�������:");
        printf("\n1 - ����� �����-�������");
        printf("\n2 - ����� ������-����");
        printf("\n3 - ����� �����-�����");
        printf("\n4 - ������ ������");
        printf("\n5 - ������� ������ ������");
        printf("\n6 - ������ ������");
        printf("\n7 - ����������� �����");
        printf("\n8 - ��������");
        printf("\n0 - �����\n");
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
            printf("������ ������: %d", HeightTree(root));
            break;
        case 5:
            printf("������� ������ ������: %2.2f", AverageHeightTree(root));
            break;
        case 6:
            printf("������ ������ %d", SizeTree(root));
            break;
        case 7:
            printf("����������� ����� %d", Control_Sum(root));
            break;
        case 8:
            cout << "Input X:";
            cin >> x;
            DeleteAVL(x, root, down);
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
    printf("\n ������� N:");
    cin >> n;

    int* mass = new int[n];
    for (i = 0; i < n; i++)
    {
        mass[i] = i;
        printf("%2d ", mass[i]);
    }


    for (i = 0; i < n; i++)
    {
        AvlTree(root, mass[i]);
    }

    print_all_func(root);

    return 1;
}
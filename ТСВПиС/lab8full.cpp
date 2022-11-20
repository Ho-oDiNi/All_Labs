#include <iostream>
#define inf 100000

using namespace std;
 
const int Vmax = 1000;
const int Emax = Vmax * (Vmax - 1) / 2;
int i, j, n, e, start;
int edge[Emax][3];
int d[Vmax];

//алгоритм Беллмана-Форда
void bellman_ford(int n, int s)
{
    int i, j;
 
    for (i = 0; i < n; i++) d[i] = inf;
    d[s] = 0;
 
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < e; j++)
            if (d[edge[j][1]] + edge[j][2] < d[edge[j][0]])
                d[edge[j][0]] = d[edge[j][1]] + edge[j][2];
 
    for (i = 0; i < n; i++) if (d[i] == inf)
        cout << endl << start << "->" << i + 1 << "=" << "Not";
    else cout << endl << start << "->" << i + 1 << "=" << d[i];
}
int main()
{
    int w;
 
    cout << "Number of Vertices > "; cin >> n;
    e = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            cout << "Weight " << i + 1 << "->" << j + 1 << " > "; cin >> w;
            if (w != 0)
            {
                edge[e][1] = i;
                edge[e][0] = j;
                edge[e][2] = w;
                e++;
            }
        }
 
    cout << "Starting Vertice > "; cin >> start;
    cout << "Answer: ";
    bellman_ford(n, start - 1);
    
    cout << "\n";
    system("pause");
    return 0;
}
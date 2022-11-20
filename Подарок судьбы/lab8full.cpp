#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 99999;
using namespace std;

int start;

struct edge
{
    int a, b, cost;
};
vector<edge> e;

void back_end(vector<int> p, int n)
{
	for(int j = 0; j < n; j++)
    {
        vector<int> path;
        for(int cur = j; cur != -1; cur = p[cur]) 
        	path.push_back(cur);
		
        reverse(path.begin(), path.end());
        if(start != j)
        {
            if(path.size() > 1)
			{
                cout << "Path from " << start + 1 << " to " << j+1 << ": " << endl;
                for(auto i: path)
                    cout << i+1 << " ";
                cout << endl;
            }
            
        }
    }	
}

void ford_bellman(int n, int k)
{

    vector<int> D (n, INF);
    D[start] = 0;
    
    vector<int> p (n, -1);
    while(true)
    {
        bool any = true;
        for(int j = 0; j < k; ++j)
            if(D[e[j].a] < INF)
                if(D[e[j].b] > D[e[j].a] + e[j].cost)
                {
                    for(int i = 0; i < n; i++)
                        cout << D[i] << " ";
                    cout << endl;
                    D[e[j].b] = D[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = false;
                }
        if(any)
            break;
    }
    cout << endl;
    
    for(int i = 0; i < n; i++)
    {
    	cout << start << "->" << i+1 << " = " << D[i] << "\n";     
	}
    cout << endl;

    back_end(p, n);
}



int main()
{
    int n, k = 0;
    cout << "Enter size: ";
    cin >> n;
    vector<vector<int>> C(n, vector<int>(n, INF));

    cout << "Enter graph:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> C[i][j];
            if(C[i][j])
            {
                e.push_back({i, j, C[i][j]});
                k++;
            }
        }
    }

    cout << "Enter starting point: \n"; cin >> start; start--;

    ford_bellman(n, k);
    
    return 0;

    
    //7 0 3 4 3 255 255 255 3 0 2 255 2 255 4 4 2 0 1 1 1 255 3 255 1 0 255 2 255 255 2 1 255 0 3 1 255 255 1 2 3 0 6 255 4 255 255 1 6 0
}
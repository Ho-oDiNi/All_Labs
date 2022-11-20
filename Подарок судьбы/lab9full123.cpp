#include <vector>
#include <iostream>


using namespace std;

struct item{
	int w;
	int c;
};

void check_num(vector<vector<int>> &items_count, item *t, int n, int temp_i, int w)
{
	for(int i = 0; i < n; i++)
	{
		items_count[w][i] = items_count[w - t[temp_i].w][i];
	}
	items_count[w][temp_i]++;
}

int main()
{
	int temp, temp_i;
	int N, W;
	cout << "Input N:" << endl;
	cin >> N;
	
	item *t = new item[N];
	cout << "Input weight and cost:" << endl;
	for(int i = 0; i < N; i++)
	{
		cin >> t[i].w >> t[i].c;
	}
	
	cout << "Input max weight:" << endl;
	cin >> W;
	
	
	vector <int> dp(W + 1, 0);
	vector <vector <int>> items_count(W + 1, vector<int> (N, 0));

	for(int w = 1; w <= W; w++)
	{
		dp[w] = dp[w - 1];
		for(int i = 0; i < N; i++)
		{
			temp = dp[w];
			if(t[i].w <= w)
			{				
				dp[w] = max(dp[w], dp[w - t[i].w] + t[i].c);
			}
			if(dp[w] != temp)
			{
				temp_i = i;
			}		
		}
		if(dp[w] != dp[w - 1])
		{
			check_num(items_count, t, N, temp_i, w);
			for(int j = 0; j < N; j++)
				items_count[W][j] = items_count[w][j];
		}	
	}
	
	int weigth =0;
	cout << "Max cost for " << W << " kg: " << dp[W] << endl;	
	for(int i = 0; i < N; i++)
	{
		cout << i + 1 << " - item: " << items_count[W][i]  << endl;
		weigth += t[i].w * items_count[W][i];
	}
	cout << "Weight:" << weigth << endl;
	return 0;
}
#include <vector>
#include <iostream>

using namespace std;

int max(int a, int b)
{
	if(a>b)
		return a;
	else 
		return b;	
}

//wts - массив весов, cost - массив стоимостей предметов, W - вместимость рюкзака
//функция возвращает максимальную стоимость, которую можно набрать(решение задачи о рюкзаке
//с повторениями)
//массив dp собственно реализует динамическое программирование
void knapsack(int *wts, int *cost, int *dp, int W, int n)
{
	dp[0] = 0;
	for (int w = 1; w <= W; w++)
	{
		dp[w] = dp[w-1];
		for (int i = 0; i < n; i++)
		{
			if (wts[i] <= w)
			{
				dp[w] = max(dp[w], dp[w - wts[i]] + cost[i]);
			}
		}
	}
}

int main()
{
	int n, W;
	cout << "Input N: "; cin >> n;
		
	cout << "Wts Cost: \n";
	int wts[n]; int cost[n];
	for(int i=0; i<n; i++)
		cin >> wts[i] >> cost[i];
	
	cout << "Input W: "; cin >> W;
	int dp[W + 1];
	knapsack(wts, cost, dp, W, n);
	
	
	
		cout << dp[W];
	
	
	return 0;
}


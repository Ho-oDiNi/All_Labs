#include<iostream>
#include<math.h>

const int N = 4;

using namespace std;

float func(float x)
{
	return (sqrt(x));
}

float lagr(float x, float x0[])
{
	int i, j;
	float y = 0, k;

	for (i = 0; i < N; ++i)
	{
		k = 1;
		for (j = 0; j < N; ++j)
			if (i != j)
				k *= (x - x0[j]) / (x0[i] - x0[j]);
		y += func(x0[i]) * k;
	}
	return (y);
}

int main()
{
	
	int j, i1, x1, y1;
	float y, x;
	float x0[N], y0[N];
	int gd, gm;


	printf ("Input value X: \n");
	for (int i=0; i<N; i++)
	{
		cout << "x" << i << " = ";
		cin >> x0[i];
		y0[i] = func(x0[i]);
	}

	x = 0;
	for(int i = 0; i < 8; i += 0.1)
	{
		y = 0, x += 0.1;
		y = lagr(x, x0);
	}
	
	cout << y;

	return 0;
}
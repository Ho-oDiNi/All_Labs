#include <iostream>

//7 3 4 3 0 0 0 2 0 2 0 4 1 1 1 0 0 2 0 3 1 6

using namespace std;

int main()
{
	cout << "Input N: "; int n; cin >> n;	
	int a[n][n], d[n], v[n];
	int temp, minindex, min;
	int begin_index = 0;


  	for (int i = 0; i<n; i++)
  	{
    	a[i][i] = 0;
    	for (int j = i + 1; j<n; j++) 
		{
      		cout << i+1 << "->" << j+1;
      		cin >> temp;
      		a[i][j] = temp;
      		a[j][i] = temp;
    	}
  	}


  for (int i = 0; i<n; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[begin_index] = 0;
  

  do {
    minindex = 10000;
    min = 10000;
    for (int i = 0; i<n; i++)
    { 
      if ((v[i] == 1) && (d[i]<min))
      { 
        min = d[i];
        minindex = i;
      }
    }

    if (minindex != 10000)
    {
      for (int i = 0; i<n; i++)
      {
        if (a[minindex][i] > 0)
        {
          temp = min + a[minindex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minindex] = 0;
    }
  } while (minindex < 10000);


	cout << "\n";
  	for (int i = 0; i < n; i++) 
		cout << endl << 1 << "->" << i + 1 << "=" << d[i];


  int ver[n]; 
  int end = n - 1; 
  ver[0] = end + 1; 
  int k = 1; 
  int weight = d[end]; 

  while (end != begin_index) 
  {
    for (int i = 0; i<n; i++)
      if (a[i][end] != 0)   
      {
        int temp = weight - a[i][end];
        if (temp == d[i]) 
        {                 
          weight = temp; 
          end = i;     
          ver[k] = i + 1; 
          k++;
        }
      }
  }

	cout << "\n\n";
    for (int i = k - 1; i > 0; i--)
    	cout << ver[i] << "->";
   	cout <<  ver[0] << "\n";

  return 0;
}
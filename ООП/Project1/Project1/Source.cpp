#include <iostream>

using namespace std;

int main()
{
    int t, n, k = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int* a = new int[n];
        for (int j = 0; j < n; j++)
            cin >> a[j];
        for (int j = 1; j < n-2; j++)
        {
            if ((a[j]>a[j+1])&&(a[j] > a[j-1]))
            {
                if (a[j + 2] > a[j])
                    a[j + 1] = a[j + 2];
                else
                    a[j + 1] = a[j];

                k++;
            }

        }
         if ((a[n - 2] > a[n-1]) && (a[n - 2] > a[n - 1]))
            {
                a[n - 2] = a[n - 3];
                k++;
            }

        cout << k << "\n";
        for (int j = 0; j < n; j++)
            cout << a[j] << " ";
        cout << "\n";
        k = 0;
        delete[] a;
    }
    
      

    return 0;
}
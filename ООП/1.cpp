#include <iostream>
 
using namespace std;
 
int main() {
    int t, n,k=0, temp;
    bool flag = true;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int max1 = -2147483648, max2 = -1;
        cin >> n;
        int* a = new int[n];
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        for (int j = 0; j < n; ++j){
         if(a[j]>=max1)
         {
            max2 = max1;
            max1 = a[j];
         }
        }
        if(max2==-1)
        {
            max2= -2147483648;
            for (int j = 1; j < n; ++j)
            {
                if(a[j]>max2)
                max2 = a[j];
            }
        }

        int max = max1+max2; 
        cout << max ;
        cout << "\n";
        
        delete[] a;
    }
    return 0;
}
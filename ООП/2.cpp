#include <string>
#include <iostream>

using namespace std;
 
int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string a;
        cin >> a;
        int k = a.size();
        
        bool flag = true; 
        while(flag)
        {
            flag = false;
            for(int j = 1; j < k; ++j)
            {
                if(a[j]==a[0])
                {
                    for(int t = 0; t<k-1; ++t)
                        a[t] = a[t+1];
                    k--;
                    flag = true;
                    break;
                }
            }
        }
          
        for(int j = 0; j < k; ++j)
            cout << a[j];
        cout << "\n";
    }
    return 0;
}
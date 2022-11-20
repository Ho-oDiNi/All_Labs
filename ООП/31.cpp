#include <iostream>

using namespace std;

int main()
{
    long long t, n, B, x, y, sum;
    cin>>t;
    for(int i=0;i<t; i++)
    {
        sum=0;
        cin>>n>>B>>x>>y;
        long long* a = new long long[n+1];
        a[0]=0;
        for(int j=1; j<=n; j++)
        {
            if((a[j-1]+x)<=B)
                a[j]=a[j-1]+x;
            else
                a[j]=a[j-1]-y;
        }
        for(int j=0; j<=n; j++)
            sum += a[j];
        cout << sum << "\n";    
        delete[] a;
    }

    return 0;
}

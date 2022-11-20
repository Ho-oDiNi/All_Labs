#include<iostream>
 
int main()
{
    int a, b, c, d1, d2, d3, n;
    std::cin >> n;
    for(int i=0; i<n; i++)
	{
    std::cin >> a >> b >> c;
	d1 = b - a;
	d2 = c - a;
	d3 = c - b;
	if(d2%2==0)
		d2/=2;
	else if((a==1)&&(b==c))
	{
		std::cout << "YES\n";
		continue;
	}
	else
	{
		std::cout << "NO\n";
		continue;
	}
	
	if(((a+d2)%b==0) && ((a+d2)/b>0))
	{
		std::cout << "YES\n";
		continue;
	}
	
	if(((b+d1)%c==0) && ((b+d1)/c>0))
	{
		std::cout << "YES\n";
		continue;
	}
	if (((b-d3)%a==0) && ((b-d3)/a > 0))
	{
		std::cout << "YES\n";
		continue;
	}
    std::cout << "NO\n";
        
    continue;	
    }
    return 0;
}
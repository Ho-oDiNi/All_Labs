#include <iostream>


using namespace std;

int main()
{
	int a_digit, b_digit, temp, a_length = 1, b_length = 1;
    cin >> a_digit;
    cin >> b_digit;

    if(a_digit<b_digit)
    {
    	temp = b_digit;
    	b_digit = a_digit;
    	a_digit = temp;
	}
	
	int a = a_digit;
    int b = b_digit;
    temp = a;
    while(temp>9)
    {
    	temp/=10;
    	a_length++;
	}
    temp = b;
    while(temp>9)
    {
    	temp/=10;
    	b_length++;
	}
	int N = a_length+b_length;
	int X[N];	
    for(int i=0; i<N; i++)
    	X[i] = 0;	
    	
    while(b_digit>9)
	{
		a = a_digit;
		b = b_digit%10;
		int n = a_length+1;
    	int x[n], t=0;
		for(int i=0; i<n; i++)
    		x[i] = 0;
		for(int i=0; i<n; i++)
	    {
	    	if( (a%10)*b+t > 9 )
	    	{
	    		temp = (a%10)*b+t;
	    		x[i] = temp%10; temp/=10;
	    		a/=10; 
	    		t = temp%10;
			}
	    	else
			{
				x[i] = (a%10)*b+t;
				a/=10;
				t = 0;
			}	 	
		}
		t = 0;
		for(int i=0; i<N; i++)
		{	
			if(	X[i]+x[i]+t > 9 )
			{
				temp = X[i]+x[i]+t;
				X[i] = temp%10;
				temp/=10;
				t = temp%10;
			}
			else
			{
				X[i] += x[i]+t;
				t = 0;
			}	 
		}
		b_digit/=10;		
	}	
    
	

	
    return 0;
}
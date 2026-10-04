//Illustrate the use of multiple catch statements.
#include<bits/stdc++.h>
using namespace std;
int main()
{
	try
	{
		int n;
		cout<<"Enter 1 or 2 :"<<endl;
		cin>>n;
		if(n==1)
		{
			throw 10;
		}
		else
		{
			throw 110.5;
		}
	}
	catch(int e)
	{
		cout<<"integer exception caught:"<<e<<endl;	
	}
	catch(double e)
	{
		cout<<"double exception caught:"<<e<<endl;	
	}
	return 0;
	
}

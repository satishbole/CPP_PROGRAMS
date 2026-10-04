//OBJECT AS A PARAMETER
#include<bits/stdc++.h>
using namespace std;
class Market
{
	string item;
	public:
		void getdata(Market m)
		{
			cin>>m.item;	
		}
		void Display()
		{
			cout<<"Items:"<<m.item;
		}
		
};
int main()
{
	cout<<"Enter items name:";
	Market m;
	m.getdata(m);
	m.Display();
}

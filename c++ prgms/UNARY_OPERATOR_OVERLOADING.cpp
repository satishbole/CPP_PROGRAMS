//UNARY OPERATOR OVERLOADING
#include<iostream>
using namespace std;
class Counter
{
	int count;
	public:
		Counter()
		{
			count=10;
		}
		// prefix++overload
		void operator++()
		{
			count++;
		}
		void display()
		{
			cout<<"value="<<count<<endl;
		}		
};
int main()
{
	Counter c;
	c.display();
	++c;
	c.display();
}

//Overload Binary Operators using friend function.
#include<bits/stdc++.h>
using namespace std;
class Number
{
	private:
		int x;
	public:
		Number (int a)
		{
			x=a;
		}
		friend Number operator+(Number n1, Number n2);
		void display()
		{
			cout<<"Sum="<<x<<endl;
			
		}
};
Number operator+(Number n1, Number n2)
{
	Number n3(0);
	n3.x=n1.x+n2.x;
	return n3;
}
int main()
{
	Number n1(10),n2(20);
	Number n3=n1+n2;
	n3.display();
	return 0;
}

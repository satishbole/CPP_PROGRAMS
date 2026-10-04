//USING FRIEND FUNCTION
#include<iostream>
using namespace std;
class Demo{
	private:
		int x=0;
		public:
			friend void display(Demo);
};
void display(Demo d)
{
	cout<<"Value of x="<<d.x;
}
int main()
{
	Demo obj;
	display(obj);
	return 0;
}

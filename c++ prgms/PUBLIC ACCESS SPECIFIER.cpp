//PUBLIC ACCESS SPECIFIER
#include<iostream>
using namespace std;
class car
{
	public:
		string brand="BMW";
		string model="V3";
};
main()
{
	car c;
	cout<<"Brand:"<<c.brand<<endl;
	cout<<"Model:"<<c.model;
}

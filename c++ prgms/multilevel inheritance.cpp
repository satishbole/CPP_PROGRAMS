//Implement Program for Multi-level inheritance.
#include<bits/stdc++.h>
using namespace std;
class Grandfather
{
	public:
		void showgrandfather()
		{
			cout<<"GRAND FATHER CLASS"<<endl;
		}
};
class Father: public Grandfather
{
	public:
		void showfather()
		{
			cout<<"FATHER CLASS"<<endl;
		}
};
class Son: public Father
{
	public:
	void showson()
	{
		cout<<"SON CLASS"<<endl;
	}
};
int main()
{
	Son s;
	s.showgrandfather();
	s.showfather();
	s.showson();
	return 0;
}

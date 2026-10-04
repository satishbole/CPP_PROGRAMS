//illustrate the use of constructors and destructors
#include<iostream>
using namespace std;
class Book
{
	public:
	int bid;
	string bname;
	Book()
	{
		cout<<"Default constructor";
	}
	//parametrizezd constructor
	Book(int id, string name)
	{
		bid=id;
		bname=name;
		cout<<"Book id:"<<bid<<"Book name:"<<bname;
	}
	Book(Book &b)
	{
		id=b.bid;
		b.bname=name;
		cout<<"Book id:"<<b.bid<<"Book name:"<<b.bname;	
	}
	~Book()
	{
		cout<<"Its a book destructor";
	}
};
int main()
{
	Book b;
	book(111,"HYPER");
	
}

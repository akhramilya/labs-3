#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

struct Class1
{
	string name;
	Class1(string name="") 
	{
		this->name = name;	
		cout << name << ": Class1()" << endl;
	}
	
	virtual Class1* copy() 
	{
		return new Class1(*this);
	}
	
	virtual ~Class1() 
	{
		cout << name << ": ~Class1()" << endl;
	}
};

struct Class2 : public Class1
{
	Class2(string name="") 
	{
		this->name = name;	
		cout << name << ": Class2()" << endl;
	}
	
	virtual Class1* copy() 
	{
		return new Class2(*this);
	}
	
	virtual ~Class2() 
	{
		cout << name << ": ~Class2()" << endl;
	}
};

void my_copy(vector<Class1*>& data, Class1& obj)
{
	Class1 *p = obj.copy();
	data.push_back(p);
}

int main()
{
	cout << "Automatic variables: " << endl;
	Class1 x1("x1"), x2("x2");
	Class2 y1("y1"), y2("y2");

	vector<Class1*> vec;
	
	my_copy(vec, x1);
	my_copy(vec, x2);
	my_copy(vec, y1);
	my_copy(vec, y2);
	
	// print all objects in vec
	cout << endl;
	cout << "objects in vector: " << endl;
	for(const Class1* p : vec) {
		cout << p->name << " : " << typeid(*p).name() << endl;
	}
	cout << endl;
	
	// free memory
	cout << "Destroy dynamic copies: " << endl;
	for(const Class1* p : vec) {
		delete p;
	}
	
	cout << endl;
	cout << "Destroy auto variables: " << endl;
}

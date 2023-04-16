#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Car
{
protected:
	string model;
public: 
	Car(string m)
	{
		model = m;
	}
	
	virtual ~Car() {}
};

class Mercedes : public Car
{
public: 
	Mercedes(string m) : Car(m)	{}
	~Mercedes()
	{
		cout << "Mercedes " << model << endl;
	}
};


class Lada : public Car
{
public: 
	Lada(string m) : Car(m)	{}
	~Lada()
	{
		cout << "Lada " << model << endl;
	}
};

class Toyota : public Car
{
public: 
	Toyota(string m) : Car(m)	{}
	~Toyota()
	{
		cout << "Toyota " << model << endl;
	}
};


int main()
{
	/*
	vector<Car*> cars = 
	{
		new Mercedes("320"),
		new Lada("Granta"),
		new Toyota("Camry")	
	};
	*/
	
	// Загрузка машин из файла
	vector<Car*> cars;
	ifstream file("cars.txt");
	string brand;
	string model;
	while(file >> brand >> model)
	{
		if(brand == "Mercedes") 
			cars.push_back(new Mercedes(model));
		else if(brand == "Lada")
			cars.push_back(new Lada(model));
		else if(brand == "Toyota")
			cars.push_back(new Toyota(model));
		else 
			cout << "Error: no such brand!" << endl;
	}

	// Вызываем деструктор для каждой машины	
	for(int i=0; i<cars.size(); i++)
	{
		delete cars[i];
	}
	
	return 0;
}

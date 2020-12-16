
#include <iostream>
#include <exception>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Base {
	virtual void print() { cout << "Base" << endl; }
};

class Derived1 : public Base {
	void print() {cout << "Derived1" << endl; }
};

class Derived2 : public Base {
	void print() { cout << "Drived2"  << endl;}
};


class Entity {
	public:
		virtual void PrintName() { cout << "Entity" << endl;}
};

class Player : public Entity {
public:
	//void PrintName() { cout << "Player" << endl; }
};

class Enemy : public Entity {
public:
	void PrintName() { cout << "Enemy" << endl; }
};


class Shape {
	public:
	virtual void draw() const=0;
	virtual ~Shape() {}
};

class Rect :public Shape
{
	public:
	virtual void draw() const {cout << "Rect" << endl; }
};

class Square : public Rect
{
	public:
	virtual void draw() const {cout << "Square" << endl; }
};

class Elipse : public Shape
{
	public:
	virtual void draw() const {cout << "Elipse" << endl; }
};

Shape* randomShape()
{
	switch (rand() % 4) {
		case 0:	return new Rect();
		case 1: 
		case 2: return new Elipse();
		case 3: return new Square();
	}
	return nullptr;
}

vector<Shape*> randomShapes(int num)
{
	vector<Shape*> v;
	for (int i = 0; i < num; ++i) {
		v.push_back(randomShape());
	}
	return v;
}

vector<Rect*> getRects(const vector<Shape*>& all)
{
	vector<Rect*> v;
	for (int i = 0; i < all.size(); ++i)
	{
		Rect* r=dynamic_cast<Rect*> (all[i]);
		if (r != nullptr) {
			v.push_back(r);
		}
		/*cout << i << " " <<  typeid(all[i]).name()  << endl;
		cout << i << " " << typeid(*(all[i])).name() << endl;
		if (typeid(Rect) == typeid(*(all[i]))) {
			v.push_back(static_cast<Rect*>( all[i]));
		}*/
	}
	return v;
}
int main()
{
	vector<Shape*> all=randomShapes(16);

	vector <Rect*> rects= getRects(all);

	for (int i = 0; i < rects.size(); ++i) {
		rects[i]->draw();
	}

	for (int i = 0; i < all.size(); ++i){
		delete all[i];
		}


	cout << endl;
	/////////////////////////////////////////////////////////////////////////////////////////////
	Player * player =new Player();
	Entity * actuallyPlayer= player;
	Entity * actuallyEnemy=new Enemy();

	Player* p0=dynamic_cast<Player*> (actuallyEnemy);
	if (!p0 ) {
		cout << "p0 "  << p0 << endl;
	}
	Player* p1 = dynamic_cast<Player*> (actuallyPlayer);
	if (p1) {
		cout << "p1 " << p1 << endl;
	}


	cout << endl;
	/////////////////////////////////////////////////////////////////////
	Derived1 d1;

	Base *bp=dynamic_cast<Base *> (&d1);

	Derived1 * dp2=dynamic_cast<Derived1*> (bp);
	if (dp2 == nullptr)
		cout << "NULL" << endl;
	else
	{
		cout << "NOT NULL" << endl;
	}

	try {
		Derived1 &r1=dynamic_cast<Derived1&> (d1);
		cout << (&r1) << endl;
		cout << bp << endl;
		}
	catch (std::exception& e) {
		cout << e.what() << endl;
	}

	system("pause");
return 0;
}
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Listener {
public:
	Listener(string name):_name(name){}
	virtual void handleMessage(int msg) = 0;
protected:
	string _name;
};
class Listener1 :public Listener {
public:
	Listener1(string name) :Listener(name) {}
	void handleMessage(int msg)
	{
		cout << _name << endl;
		switch (msg) {
		case 0: cout << "0 msg" << endl; break;
		case 1: cout << "1 msg" << endl; break;
		case 2: cout << "2 msg" << endl; break;
		default:
			break;
		}
	}
};
class Listener2 :public Listener {
public:
	Listener2(string name) :Listener(name) {}
	void handleMessage(int msg)
	{
		cout << _name << endl;
		switch (msg) {
		case 0: cout << "0 msg" << endl; break;
		case 2: cout << "2 msg" << endl; break;
		default:
			break;
		}
	}
};
class Listener3 :public Listener {
public:
	Listener3(string name) :Listener(name) {}
	void handleMessage(int msg)
	{
		cout << _name << endl;
		switch (msg) {
		case 0: cout << "0 msg" << endl; break;
		case 1: cout << "1 msg" << endl; break;
		default:
			break;
		}
	}
};
class Observer {
public:
	typedef map<int, vector<Listener*>> _map;
	void Register(int msgid, Listener *listener) {
		_map::iterator it = _observerMap.find(msgid);
		if (it == _observerMap.end()) {
			vector<Listener*> tmpvec;
			tmpvec.push_back(listener);
			_observerMap[msgid] = tmpvec;
		}
		else {
			it->second.push_back(listener);
		}
	}
	void Dispatch(int msgid) {
		_map::iterator it = _observerMap.find(msgid);
		if (it == _observerMap.end()) {
			return;
		}
		vector<Listener* >::iterator vit = it->second.begin();
		for (;vit != it->second.end();++vit)
		{
			(*vit)->handleMessage(msgid);
		}
	}
private:
	map<int, vector<Listener*>> _observerMap;
};
int main()
{
	Observer obser;
	Listener *p1 = new Listener1("Listener1");
	Listener *p2 = new Listener1("Listener2");
	Listener *p3 = new Listener1("Listener3");

	obser.Register(0, p1);
	obser.Register(1, p1);
	obser.Register(2, p1);
	obser.Register(0, p2);
	obser.Register(2, p2);
	obser.Register(0, p3);
	obser.Register(1, p3);

	int msgid;
	while (true)
	{
		cout << "input msgid" << endl;
		cin >> msgid;
		if (msgid == -1) {
			break;
		}
		obser.Dispatch(msgid);
	}
}

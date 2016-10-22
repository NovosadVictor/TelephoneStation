#include <iostream>
#include <vector>
#include <string>


struct FIVE {
	std::string _name;
	int _x;
	int _y;
	int _r;
};

class SFive {
public:
	SFive(int N) : _mass(new FIVE[N]), _size(0) {}
	int size() { return _size; }
	FIVE & operator[](int i) { return _mass[i]; }
//	int find(const std::string &name);
	void insert(const std::string &name, int x, int y, int r);
	~SFive() { delete[]_mass; _size = 0; }
	
private:
	FIVE *_mass;
	int _size;
};

//int SFive::find(const std::string &name) {
//	int count = 0;
//	for (int i = 0; i < _size; ++i)
//		if (_mass[i]._name == name) // && _mass[i]._x = x && _mass[i]._y == y)
//			++count;
//	return count;
//}
void SFive::insert(const std::string &name, int x, int y, int r) {
	if (_size == 0) {
		_mass[0]._name = name;
		_mass[0]._x = x;
		_mass[0]._y = y;
		_mass[0]._r = r;
	}
	else {
		_mass[_size]._name = name;
		_mass[_size]._x = x;
		_mass[_size]._y = y;
		_mass[_size]._r = r;
	}
	++_size;
}

int main() {
	int N;
	std::cin >> N;
	SFive SF(N);
	std::vector<std::string> v1;
	std::vector<int> v2;

	for (int i = 0; i < N; ++i) {
		std::string name;
		std::cin >> name;
		int x, y, r;
		std::cin >> x >> y >> r;
	//	if (SF.find(name))
			SF.insert(name, x, y, r);
	}
	int x, y;
	std::cin >> x >> y;
	for (int i = 0; i < SF.size(); ++i) {
		bool r = true;
		for (int j = 0; j < v1.size(); ++j)
			if (v1[j] == SF[i]._name)
				r = false;
		if (r) {
			int count = 0;
			for (int j = i; j < SF.size(); ++j)
				if (SF[j]._name == SF[i]._name && ((x - SF[j]._x) * (x - SF[j]._x) + (y - SF[j]._y) * (y - SF[j]._y) <= SF[j]._r * SF[j]._r))
					++count;
				v1.push_back(SF[i]._name);
				v2.push_back(count);
		}
	}
	std::cout << v1.size() << std::endl;
	for (int i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " " << v2[i] << std::endl;
	return 0;
}


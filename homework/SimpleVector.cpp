#include <iostream>
#include <vector>

using namespace std;

// 템플릿 사용
template<typename T>
// 클래스 SimpleVector
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	SimpleVector() : currentCapacity(10), currentSize(0) {
		data = new T[10];
		cout << "기본 생성자가 생성되었습니다." << endl;
		cout << currentSize << endl;
	}

	SimpleVector(int capacity) : currentCapacity(capacity), currentSize(0) {
		cout << "크기를 받는 생성자가 생성되었습니다." << endl;
		resize();
		data = new T[currentCapacity];
	}

	void resize() {
		cout << "input capacity : " << endl;
		cin >> currentCapacity;
		cout << "currnetcapacity is : " << currentCapacity << endl;
	}

	void push_back(const T& value) {
		if (currentSize < currentCapacity) {
			cout << "input push_back : " << value << endl;
			data[currentSize] = value;
			currentSize++;
		}
		else {
			cout << "배열에 남은 공간이 없습니다." << endl;
		}
	}

	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}
		else {
			cout << "배열에 원소가 없습니다." << endl;
		}
	}

	int size() {
		cout << "currentSize is : " << currentSize << endl;
		return currentSize;
	}

	int capacity() {
		cout << "currentCapacity is : " << currentCapacity << endl;
		return currentCapacity;
	}

	~SimpleVector() {
		delete[] data;
	}
};

int main() {
	SimpleVector<int> vec1;
	SimpleVector<int> vec2(0);

	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);

	vec1.capacity();
	vec1.size();

	vec1.pop_back();
	
	vec1.size();

	vec2.push_back(10);
	vec2.push_back(20);

	vec2.capacity();
	vec2.size();

	vec2.pop_back();

	vec2.capacity();
	vec2.size();


	return 0;
}
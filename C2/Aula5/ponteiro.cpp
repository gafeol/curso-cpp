#include <iostream>
using namespace std;

void calcula(int* y) {
	cout << "calcula " << *y << " " << y << endl;
	(*y)++;
	cout << "calcula " << *y << " " << y << endl;
}

int main() {
	int x = 10;
	cout << "main " << x << " " << &x << endl;
	calcula(&x);
	cout << "main " << x << " " << &x << endl;
}
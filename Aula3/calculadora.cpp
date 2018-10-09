#include <iostream> 
using namespace std;

int main() {
	int operacao, x, y;
	cin >> operacao;
	cin >> x;
	cin >> y;

	if(operacao == 1) { 
		cout << x + y;
	}
	else if(operacao == 2) { 
		cout << x - y;
	}
	else if(operacao == 3) { 
		cout << x / y;
	}
	else if(operacao == 4) { 
		cout << x * y;
	}
}

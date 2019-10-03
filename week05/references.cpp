#include <iostream>

using namespace std;

void tipa_modify(int x) {
	/* here x is local variable */
	x = 10;
}

void reference_modify(int &x) {
	/* Here x is reference to variable */
	x = 10;
}

int main() {
	/* simple example of reference */
	int x = 5;
	cout << "Before " << x << "\n";
	tipa_modify(x);
	cout << "After without reference " << x << "\n";
	reference_modify(x);
	cout << "After reference modify " << x << "\n";


	return 0;
}
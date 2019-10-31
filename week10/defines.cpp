#include <iostream>
using namespace std;
const int N = 1000;

#define IS_DEBUG true
#define DEBUG if (IS_DEBUG) cout
// directive, that says
// that I'm gonna replace DEBUG with 'if (IS_DEBUG) cout'
// everywhere on compilation step

int main() {

	// #define FILE false
	// directive, that says
	// that I'm gonna replace FILE by the "false"
	// everywhere on compilation step

	// Try to comment above define

	#ifdef FILE // if FILE is defined (whatever value)
	freopen("in.txt", "r", stdin);
	// file  ^this      ^read  ^this stream reads from in.txt
	freopen("out.txt", "w", stdout);
	// from  ^this      ^write   ^this stream writes to out.txt
	// Note: if FILE is defined, input is expected in file.
	#endif
	string s;
	cin >> s;
	cout << "String '" << s << "' outputed to ";
	#ifdef FILE
		cout << "in.txt\n";
	#else
		cout << "stdout\n";
	#endif

	// this is output for debugging
	DEBUG << "This is debug output.\n";
	// You will see it. Now try to
	// set IS_DEBUG to true, it won't appear

	// this is important output (for ex. answer for problem)
	cout << "I'll will go to retake!\n";


	return 0;
}
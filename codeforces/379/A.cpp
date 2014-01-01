#include <iostream> 
using namespace std;



int main() {
	int a, b;
	cin >> a >> b;
	int h = a;
	int r=a ;
	while ( (a=r/b) && (r=r%b+a) && (h += a) && r>=b)
		cerr << h << " " << a << " " << r <<  endl;
	cout << h;

}

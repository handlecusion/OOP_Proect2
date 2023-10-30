#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main()
{
	inf_int a, e;
	inf_int b(100);
	inf_int c("321111111111122222222222233333333333444444444445");
	inf_int d("200");
	inf_int f=d;
	inf_int g(f);
	string str;

	// cin >> g ;   // not required

//	a=b*c;

	// e=g/f;       // not required
	b=c-d;

	if (f==d) {
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
		cout << "c : " << c << endl;
		cout << "d : " << d << endl;
		cout << "e : " << e << endl;
		cout << "f : " << f << endl;
		cout << "g : " << g << endl;
		cout << "b - d : " << b - d << endl;
	}
	
//	while (true)
//	{
//		string str;
//		cout << "input: ";
//		cin >> str;
//		string li, op, ri;
//		
//		istringstream ss(str);
//		ss >> li >> op >> ri;
//		cout << li << op << ri;
//		inf_int a(li.c_str());
//		inf_int b(ri.c_str());
//
//		if (li == "0")
//			break;
//		if (op == "+")
//			cout << a + b << endl;
//		else if (op == "-")
//			cout << a - b << endl;
//		else if (op == "*")
//			cout << "multi" << endl;
//		else
//			cout << "worng op" << endl;
//
//	}

	
	return 0;
}

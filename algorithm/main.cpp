#include <iostream>
//#include "heapsort.hpp"
#include "heapsort.h"
#include <vector>
using namespace std;

int main()
{
	int a[] = { 50,35,49,33,34,47,42,31,27,22,28,39,37,30,32,15,10,11,13,9,7,15,19,20,21,26,23 };
	for (auto v : a)
		cout << v << " ";
	cout << endl;

	heapsort(a, sizeof(a)/sizeof(int));
	for (auto v : a)
		cout << v << " ";
	cout << endl;
}

#include <iostream>

using std :: cin;
using std :: endl;
using std :: cout;

int main()
{
	unsigned  aCut = 0, eCut = 0, iCut = 0, oCut = 0, uCut = 0;
	char ch;
	while (cin >> ch) {
		switch (ch) {
			case 'a':
				++aCut;
				break;
			case 'e':
				++eCut;
				break;
			case 'i':
				++iCut;
				break;
			case 'o':
				++oCut;
				break;
			case 'u':
				++uCut;
				break;
		}
	}
	cout << "number of vowel a: \t" << aCut << '\n'
		 << "number of vowel e: \t" << eCut << '\n'
	     << "number of vowel i: \t" << iCut << '\n'
		 << "number of vowel o: \t" << oCut << '\n'
		 << "number of vowel u: \t" << uCut << endl;

	return 0;
}

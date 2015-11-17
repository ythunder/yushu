#include <iostream>
#include <string>

using std :: cin;
using std :: string;
int main()
{
	string buf;
	while (cin >> buf && !buf.empty()) {
		switch (buf[0]) {
			case '-':
				for (auto it = buf.begin() + 1; it != buf.end(); ++it) {
					if (*it == ' ')
						break;
				}
				break;
		}
	}
	return 0;
}

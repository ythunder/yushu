#include <iostream>
#include <string>
#include <vector>

using std :: cin;
using std :: cout;
using std :: endl;
using std :: string;
using std :: vector;

int main()
{
	vector<string> text{"ac","ca" ,"gh", "sr", "zk"};
	string sought = "ca";

	auto beg = text.begin();
	auto end = text.end();
	auto mid = text.begin() + (end - beg) / 2;
	while (mid != end && *mid != sought) {
		if(sought < *mid) 
			end = mid;
		else 
			beg = mid + 1;
		mid = beg + (end - beg) / 2;
	}
	if(*mid == sought) 
		cout << "string  " << sought << "  find" << endl;
	else 
		cout << "string  " << sought << "  not find" << endl;
	
	return 0;
}

#include <iostream>
#include <string>

using std :: string;
using std :: cout;
using std :: cin;
using std :: endl;

int main()
{
	const string hexdigits = "0123456789ABCDEF";

	cout << "Enter a series of numbers between 0 and 15" 
		 << " separated by spaces. Hit ENTER whenfinished : " 
		 << endl;

	string result;
	string :: size_type n;
	while(cin >> n) 
		if( n < hexdigits.size())	//忽略无效输入
			result += hexdigits[n];		//得到对应的十六进制数字
	cout << "Your hex number is: " << result << endl;
	return 0;
}

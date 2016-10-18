#include <iostream>
#include <string>
#include <vector>

using std :: string;

string :: size_type find_char (const string &s, char c, string :: size_type &occurs)
{
	auto ret = s.size();	/*auto自动类型推断*/
	occurs = 0;
	for (decltype (ret) i = 0; i != s.size(); i++) {	/*操作符，查询表达式的数据类型*/
		if ( s[i] == c) {
			if (ret == s.size())
				ret = i;
			++ occurs;
		}
	}
	return ret;
}

int main()
{
	char c = 'a';
	string s = "acsdaxxaxswaaa";
	string::size_type  t;
	string::size_type occurs;
	t = find_char(s, c, occurs);
	std :: cout << "s中" << "字符" << c << "的数目是" << occurs << std :: endl; 
	return 0;
}

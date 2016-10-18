#include <iostream>

void change(int *p, int *q)
{
	int t;
	t = *p;
	*p = *q;
	*q = t;
}

int main()
{
	int p = 13, q = 31;
	change(&p, &q);
	std :: cout << "p = " << p << "q = "  << q << std :: endl;
	return 0;
}

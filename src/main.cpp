#include "event.h"
#include <iostream>

void test_func(std::string str)
{
	std::cout << "This is my string: " << str << "\n";
}

void test_func2(std::string str, int i)
{
	std::cout << "This is my string: " << str << "\n"
			  << "This is my int: " << i << "\n";
}

int main()
{
	typedef void my_del(std::string str);
	my_del *func = test_func;
	typedef void my_del_2(std::string str, int i);
	my_del_2 *func2 = test_func2;

	Event<my_del *> event;
	event.AddListener(func);
	event.Call(std::string("ciao"));

	Event<my_del_2 *> event2;
	event2.AddListener(func2);
	event2.Call(std::string("Hello"), 5);

	return 0;
}
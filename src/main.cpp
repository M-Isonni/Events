#include "event.h"
#include <iostream>

void test_func(std::string str)
{
    std::cout<<"This is my string: "<<str<<"\n";
}

int main()
 {
    typedef void my_del(std::string str);
	my_del* func = test_func;

	Event<my_del*> event;
	event.AddListener(func);
	event.Call(std::string("ciao"));

     return 0;
 }
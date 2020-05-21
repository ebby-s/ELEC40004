#include<iostream>
#include "slist.hpp"

using namespace std;

void e1_slist_print(slist *p){
	if(slist_is_empty(p)) return;
	cout << slist_get_front(p);
	e1_slist_print(slist_get_next(p));
}



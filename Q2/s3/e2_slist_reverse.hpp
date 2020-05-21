#include "slist.hpp"

using namespace std;

slist *e2_slist_reverse(slist *p){
	if(slist_is_empty(slist_get_next(p))) return p;
	return slist_append(e2_slist_reverse(slist_get_next(p)),slist_push_front(nullptr,slist_get_front(p)));
}





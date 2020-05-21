#include "slist.hpp"

using namespace std;

bool match(slist *a, slist *b, slist *total){
	if(total==nullptr && a!= nullptr) return 0;
	while(a!=nullptr){
		if(slist_get_front(total)!=slist_get_front(a)) return 0;
		a = slist_get_next(a);
		total = slist_get_next(total);
	}
	while(b!=nullptr && total!= nullptr){
		if(slist_get_front(total)!=slist_get_front(b)) return 0;
		b = slist_get_next(b);
		total = slist_get_next(total);
	}
	return 1;
}

int main(){
	slist *a = slist_push_front(nullptr,8);
	slist *b = slist_push_front(nullptr,0);

	for(int i=1;i<8;i++){
		a = slist_push_front(a,i+8);
		b = slist_push_front(b,i);
	}

	slist *total = slist_append(a,b);

	if(!match(a,b,total)) return 1;
}

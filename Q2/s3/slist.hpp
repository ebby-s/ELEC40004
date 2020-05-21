#ifndef simple_list_hpp
#define simple_list_hpp

#include <cassert>

///////////////////////////////////////////
// Public API

struct slist;

// Returns true if the given list is empty
bool slist_is_empty(slist *p);

// Pushes the given value onto the front of the list and returns the updated list.
// The original list p now points inside the list, and should not be passed to
// functions that change the list structure.
// A typical way of using this would be:
//  p = slist_push_front(p, x);
slist *slist_push_front(slist *p, float x);

// Removes the value at the front of the list and returns the updated list
// This cannot be called on an empty list.
// The original list p will no longer be valid after this function.
// A typical way of using this would be:
//  p = slist_op_front(p, x);
slist *slist_pop_front(slist *p);

// Changes the value at the front of the list
// This cannot be called on an empty list
void slist_set_front(slist *p, float x);

// Gets the value at the front of the list
// This cannot be called on an empty list
float slist_get_front(slist *p);

// Returns the remainder of the list after this node.
// This function does not modify the list, so the input list p remains unchanged.
// It is not allowed to call any functions that change the list structure on
// the return value (e.g. slist_pop_front, slist_push_front, slist_append), as
// it would corrupt the original list p.
// This cannot be called on an empty list.
slist *slist_get_next(slist *p);

// Returns a new list that contains the elements from a followed by the elements from b.
// The lists a and b should be combined into the return list, so this function
// should not perform any allocations.
// After this function completes the lists a and b should be considered invalid
// (as they have been incorporated into the returned list).
slist *slist_append(slist *a, slist *b);

/////////////////////////////////////////////
// Implementation details

struct slist
{
    float value;
    slist *next;
};

bool slist_is_empty(slist *p)
{
    return p==nullptr;
}

float slist_get_front(slist *p)
{
    assert( p != nullptr );
    return p->value;
}

void slist_set_front(slist *p, float x)
{
    assert( p != nullptr );
    p->value = x;
}

// Updated: originally this didn't match the declaration.
slist *slist_push_front(slist *p, float x)
{
    slist *res=new slist[1];
    res->value = x;
    res->next = p;
    return res;
}

slist *slist_pop_front(slist *p)
{
    assert( p != nullptr );
    slist *res=p->next;
    delete[] p;
    return res;
}

slist *slist_get_next(slist *p)
{
    assert( p!=nullptr );
    return p->next;
}

// Updated: originally this didn't match the name given in the declaration.
slist *slist_append(slist *a, slist *b)
{
    slist *out = a;
    while(a->next!=nullptr) a = a->next;
    a->next = b;
    return out;
}

#endif

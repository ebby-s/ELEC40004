#include "network.hpp"

Network R(float v)
{
    return {'R', v, {} };
}

Network C(float v)
{
    return {'C', v, {} };
}

Network L(float v)
{
    return {'L', v, {} };
}


bool operator==(const Network &a, const Network &b)
{
    if(a.type != b.type) return false;
    if(a.value != b.value) return false;
    return a.parts == b.parts;
}

Network operator|(const Network &a, const Network &b)
{
    return Network{'|', 0, {a,b} };
}

Network operator&(const Network &a, const Network &b)
{
    return Network{'&', 0, {a,b} };
}

bool operator<(const Network &a, const Network &b)
{
    if(a.type < b.type){ return true;}
    if(a.value < b.value){ return true;}
    return a.parts < b.parts;
}

bool is_primitive(const Network &a)
{
    return (a.type=='R' || a.type=='C' || a.type=='L');
}

bool is_composite(const Network &a)
{
    return !is_primitive(a);
}


Network canonicalise(const Network &x)
{
    if(is_primitive(x)){ return x; }
    vector<Network> parts = x.parts;
    for(int i=0;i<parts.size();i++){
        parts[i] = canonicalise(parts[i]);
    }

    vector<Network> flat;

    for(int i=0; i<parts.size(); i++){
        if(is_primitive(parts[i])){ flat.push_back(parts[i]); }

        if(is_composite(parts[i])){
            if(x.type == parts[i].type){
                for(int j=0; j<parts[i].parts.size(); j++){
                    flat.push_back(parts[i].parts[j]);
                }
            }else{ flat.push_back(parts[i]); }
        }
    }

    vector<Network> sorted;

    sorted.push_back(flat[0]);

    for(int i=1; i<flat.size(); i++){
        for(int j=0; j<sorted.size(); j++){
            if(flat[i] < sorted[j]){
                sorted.insert(sorted.begin()+j, flat[i]);
                break;
            }
            if(j==sorted.size()-1){
                sorted.push_back(flat[i]);
                break;
            }
        }
    }

    return Network({x.type, 0, sorted});
}


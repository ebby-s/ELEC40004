#include "network.hpp"

istream &operator>>(istream &src, Network &c)
{
    c.value=0;
    c.parts.clear();

    src>>c.type;
    if(src.fail()){
        return src;
    }

    if(c.type=='R' || c.type=='C' || c.type=='L'){
        src>>c.value;
    }else if(c.type=='('){
        c.type=0;
        c.value=0;

        Network x;
        char seperator;
        src>>x>>seperator;
        assert(!src.fail());
        c.parts.push_back(x);

        while(seperator!=')'){
            assert( seperator=='&' || seperator=='|' );
            assert( c.type==0 || c.type==seperator );
            c.type=seperator;
            src>>x>>seperator;
            assert(!src.fail());

            c.parts.push_back(x);
        }

        if(c.parts.size()==1){
            c.type='&';
        }
    }

    return src;
}


ostream &operator<<(ostream &dst, const Network &c)
{
    if(is_primitive(c)){
        dst << c.type << c.value;
        return dst;
    }else{
        dst << '(';
        for(int i=0; i<c.parts.size()-1; i++){
            dst << c.parts[i] << c.type;
        }
        dst << c.parts[c.parts.size()-1] << ')';
        return dst;
    }
}

vector<Network> create_test_networks()
{
	vector<Network> cases;
	cases.push_back(Network({'R',1.4, {}}));
        cases.push_back(Network({'C',2.6, {}}));
        cases.push_back(Network({'L',3.9, {}}));
        cases.push_back(cases[2] | cases[0]);
        cases.push_back(cases[1] & cases[0]);
        cases.push_back(cases[3] | cases[1]);
        cases.push_back(cases[3] & cases[0]);
        cases.push_back(cases[5] | cases[3]);
        cases.push_back(cases[6] & cases[5]);
        cases.push_back(cases[8] | cases[6]);

    return cases;
}


#include "network.hpp"
#include <cmath>

complex<float> impedance(const Network &c, float omega)
{
    complex<float> branch;

    if(c.type=='R'){
        return {c.value, 0};

    }else if(c.type=='C'){
        return {0, -1/(omega*c.value) };

    }else if(c.type=='L'){
	return {0, omega*c.value};

    }else if(c.type=='|'){
	for(int i=0; i<c.parts.size(); i++){
            branch += ((complex<float>)1)/impedance(c.parts[i], omega);
        }
        return ((complex<float>)1)/branch;
    }else if(c.type=='&'){
        for(int i=0; i<c.parts.size(); i++){
            branch += impedance(c.parts[i], omega);
        }
        return branch;
    }

}

vector<complex<float>> transfer_function(const Network &v1, const Network &v2, const vector<float> &omega)
{
    vector<complex<float>> res;

    for(int i=0; i<omega.size(); i++){
        res.push_back(impedance(v2,omega[i])/(impedance(v1,omega[i])+impedance(v2,omega[i])));
    }

    return res;
}

vector<float> make_log10_space(float xLo, float xHi, int points)
{
    vector<float> res;
    double a = (log10(xHi) - log10(xLo))/(points-1);
    for(int i=0; i<points; i++){
        res.push_back(pow(10,log10(xLo) + a*i));
    }

    return res;
}

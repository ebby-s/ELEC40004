#include<string>
#include "ProxyA.hpp"
#include "ProxyA_Impl1.hpp"
#include "ProxyA_Impl2.hpp"

using namespace std;

/*Create an instance of ProxyA, using the given
  string to select the concrete type:
- 'Impl1' : Returns a new ProxyA_Impl1
- 'Impl2' : Returns a new ProxyA_Impl2
*/
ProxyA *ProxyA_factory(const string &type){
        ProxyA *p;
        if(type == (string)"Impl1"){
                p = new ProxyA_Impl1;
        }else{
                p = new ProxyA_Impl2;
        }
        return p;
}


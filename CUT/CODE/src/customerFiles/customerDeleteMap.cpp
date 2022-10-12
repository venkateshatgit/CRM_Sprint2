#include <header.h>

//Releasing dynamically occupied memory 
void deleteMapCustomer(map <string, Customer*> &mapCustomer){
    for(auto it=mapCustomer.begin(); it!=mapCustomer.end(); ++it){
        Customer *temp = it->second;

        delete temp; 
    }
}

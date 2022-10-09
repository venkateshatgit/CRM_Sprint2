#include "../../include/header.h"

//Releasing dynamically occupied memory 
void deleteMapCustomer(map <string, Customer*> &mapCustomer){
    for(auto it=mapCustomer.begin(); it!=mapCustomer.end(); ++it){
        Customer *temp = it->second;
        // it->second->display();
        delete temp; 
        //cout<<"Class deleted"<<endl;
    }
}

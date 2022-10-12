#include <header.h>

//Writing in customer data file
void customerDataWrite(map<string, Customer*> &mapCustomer, char* filePath){

    ofstream file;
    file.open(filePath);

    for(auto it=mapCustomer.begin(); it!=mapCustomer.end(); ++it){
        Customer *temp = it->second;
        file<<(temp->getId())<<"|"<<(temp->getFirstName())<<"|"<<(temp->getLastName())<<"|"<<(temp->getAddress())<<"|"<<(temp->getPhoneNumber())<<"|"<<(temp->getCustomerType())<<"|"<<endl;
    }
    cout<<"Customer data updated in file "<<filePath<<endl;

    file.close();
}

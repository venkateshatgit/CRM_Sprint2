#include <header.h>

//deleting customer from map
void deleteCustomer(map<string, Customer*> &mapCustomer){

    string id;
    cout<<"\nEnter the customer ID for deleting customer: ";
    cin>>id; cin.ignore();

    try{
        if(mapCustomer.find(id)==mapCustomer.end())
            throw id;

        Customer* temp = mapCustomer[id];

        mapCustomer.erase(id);
        cout<<"Customer with the customer ID: "<<id<<" deleted."<<endl;

        delete temp;
    }
    catch(string idThrown){
        cout<<"ERROR! in deleting customer from the database"<<endl;
        cout<<"ERROR MESSAGE: Customer ID entered does not match with any existing IDs"<<endl;
    }
}
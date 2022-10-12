#include <header.h>

Customer::Customer( string id, string fn, string ln, string add, string phn,string cType):
        customerId(id),
        firstName(fn),
        lastName(ln),
        address(add),
        phoneNumber(phn),
        customerType(cType)
{
        //cout<<"Constructor created"<<endl;
    
}

string Customer::getId(){
    return customerId;
}

string Customer::getFirstName(){
    return firstName;
}

string Customer::getLastName(){
    return lastName;
}

string Customer::getAddress(){
    return address;
}

string Customer::getPhoneNumber(){
    return phoneNumber;
}

string Customer::getCustomerType()
{
    return customerType;
}

//string Customer::
void Customer::setFirstName(string fname){
    this->firstName = fname;
}

void Customer::setLastName(string lname){
    this->lastName = lname;
}

void Customer::setAddress(string address){
    this->address = address;
}

void Customer::setPhoneNumber(string phoneNumber){
    this->phoneNumber = phoneNumber;
}

void Customer::setCustomerType(string cType){
    this->customerType = cType;
}


void Customer::display(){
    cout<<"------------ Displaying Customer Data ---------------"<<endl;
    cout<<"CustomerId: "<<customerId<<endl;
    cout<<"Name: "<<firstName<<" "<<lastName<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Phone No: "<<phoneNumber<<endl;
    cout<<"Customer Type: "<<customerType<<endl;
    cout<<endl<<endl;
}
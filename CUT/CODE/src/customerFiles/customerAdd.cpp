#include <header.h>

//Adding customer in map
void addCustomer(map<string, Customer*> &mapCustomer){

    //using inbult map function to get last element
    auto it=mapCustomer.rbegin();
    string lastId = (it->second)->getId(); 

    //using inbuilt function converting string to int
    int lastIdInt = stoi(lastId);
    lastIdInt+=1;

    //Input customer details
    string customerId=to_string(lastIdInt), firstName, lastName, address, phoneNumber,customerType;
    //cout<<"------- Adding New customer -------"<<endl;
    cout<<"Enter the details for New Customer:"<<endl;

    cout<<"First name: "; 
    cin>>firstName; cin.ignore();

    cout<<"Last name: "; 
    cin>>lastName; cin.ignore();

    cout<<"Address:"; 
    getline(cin, address, '\n');
    int temp=0;
    do{
        cout<<"Mobile Number:"; // nnumber validation for 10 digits can be done 
        cin>>phoneNumber; cin.ignore();
        if(phoneNumber.size()==10)
        {
            temp=1;
        }
        else
        {
            cout<<"Please Enter 10 digit mobile number."<<endl;
        }
    }while(temp!=1);

    cout<<"Customer Type (Existing/New) : " ;
    cin>>customerType; // check type validation
    cin.ignore();

    cout<<"Customer with the "<<customerId<<" added succesfully."<<endl;

    //creating customer pointer
    Customer *newCustomer = new Customer(customerId, firstName, lastName, address, phoneNumber,customerType);
    mapCustomer[customerId] = newCustomer;
}


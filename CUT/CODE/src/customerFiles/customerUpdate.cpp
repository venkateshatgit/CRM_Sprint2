#include <header.h>

//updating Customer in map
int updateCustomer(map<string, Customer*> &mapCustomer){

    string id;
    cout<<"\nEnter the customer ID for updating the details: ";
    cin>>id; cin.ignore();


    try{
        if(mapCustomer.find(id)==mapCustomer.end())
            throw id;
    }
    catch(string idThrown){
        cout<<"ERROR! in Updating Customer from database"<<endl;
        cout<<"ERROR MESSAGE: Customer ID entered does not match with any existing IDs"<<endl;
        return 0; // orignally return;
    }
    cout<<"Customer with customer ID: "<<id<<" found."<<endl;
    int opt=0;
    do{
    cout<<"\nEnter your choice."<<endl;
     cout<<"-------------------------------------"<<endl;
    cout<<"1.Update First name\n2.Update Last name\n3.Update Address\n4.Update Mobile number\n5.Update Customer Type";
    cout<<"\n6.Previous Menu"<<endl;
    cout<<"--------------------------------------"<<endl;
    cin>>opt; cin.ignore();

    string str;
    switch(opt)
    {
        case 1:
            cout<<"Enter First name : "<<endl;
            cin>>str;
            cin.ignore();
            mapCustomer[id]->setFirstName(str);
            cout<<"------ First Name Updated Successfully ------"<<endl;
            cout<<"---------------------------------------------"<<endl;
            break;

        case 2:
            cout<<"Enter Last name : "<<endl;
            cin>>str;
            cin.ignore();
            mapCustomer[id]->setLastName(str);
            cout<<"------ Last Name Updated Successfully ------"<<endl;
            cout<<"--------------------------------------------"<<endl;
            break;

        case 3:
            cout<<"Enter Address : "<<endl;
            getline(cin, str, '\n');
            mapCustomer[id]->setAddress(str);
            cout<<"------ Address Updated Successfully ------"<<endl;
            cout<<"-------------------------------------------"<<endl;
            break;
            
        case 4:
            cout<<"Enter Mobile number : "<<endl;
            cin>>str;
            cin.ignore();
            mapCustomer[id]->setPhoneNumber(str);
            cout<<"------ Mobile number Updated Successfully ------"<<endl;
            cout<<"------------------------------------------------"<<endl;
            break;

         case 5:
             cout<<"Enter Customer Type (Existing/New): "<<endl;
             cin>>str;
             mapCustomer[id]->setCustomerType(str);
             cout<<"------ Customer Type Updated Successfully ------"<<endl;
            cout<<"-------------------------------------------------"<<endl;
             break;

        case 6:  cout<<"------- Taking back to Previous menu -------"<<endl;
                cout<<"---------------------------------------------"<<endl;
                return 0;
        default : 
            cout<<"Enter the correct choice option."<<endl; 
            
    }
    }while(opt!=-1);
    return 0;
}
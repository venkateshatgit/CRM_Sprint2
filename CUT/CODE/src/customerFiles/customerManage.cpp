#include <header.h>
#include <functions.h>

int customerManagement(map<string, Customer*> &mapCustomer,char* filename){

        bool flag=true;
        int n,ret;
        do
        {
                cout<<"\n-------- Customer Management Menu ----------"<<endl;
                cout<<"1.Add New Customer\n2.Update Customer\n3.Delete Customer\n4.Exit"<<endl;
                cout<<"-------------------------------------"<<endl;
                cin>>n;
                switch(n)
                {
                        case 1 :addCustomer(mapCustomer);
                                break;

                        case 2 :updateCustomer(mapCustomer);
                                break;

                        case 3 :deleteCustomer(mapCustomer);
                                break;

                        case 4 :cout<<"-----------------------------------------------"<<endl;
                                flag=false;
                                break;
                                
                        default :cout<<"Please enter correct choice. "<<endl;
                }
        }while(flag);
    return 0;
}
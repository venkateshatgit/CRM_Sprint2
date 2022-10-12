#include "../include/header.h"
#include "../include/functions.h"

int main(int argc, char** argv){

    
    map <string, Customer*> mapCustomer;
    ReqDatabase reqDb; 
    
    //Exceptional handling for arguement and file opening
    try{
        if(argc!=3)
            throw argc;

        //Reading customer.txt and request.txt
        extractCustomerData(argv, mapCustomer);
        extractingRequestFile(reqDb, argv);

        bool flag=true;
        int n;
        cout<<"\n***** Welcome to Customer Relationship Management Application *****"<<endl;
        do{
            cout<<"\n----------- Main Menu --------------"<<endl;
            cout<<"1.Manage Customer\n2.Manage Request\n3.Generate Report\n4.Total Request\n5.Exit CRM Application"<<endl;
            cout<<"---------------------------------------"<<endl;
            cin>>n;
            switch(n)
            {
                case 1 :customerManagement(mapCustomer, argv[1]);
                        break;

                case 2 :requestManagement(mapCustomer, reqDb);
                        break;

                case 3 :displayReport(mapCustomer, reqDb);
                        break;

                case 4 :reqDb.totalCount();
                        break;

                case 5 :cout<<"------------- Exiting from CRM application -------------"<<endl;
                        cout<<"\n------------------ THANK YOU --------------------------"<<endl;
                        flag=false;
                        break;
                        
                default :cout<<"Please Enter correct choice. "<<endl;
            }

        }while(flag);

       
        // reqDb.displayReqDatabase();

        //Writing data to files
        customerDataWrite(mapCustomer, argv[1]);
        reqDb.requestDataWrite(argv);

        //delete the customer and request data
        deleteMapCustomer(mapCustomer);
        reqDb.deleteReqDatabase();
    }
    catch(int argc){        
        cout<<"ERROR ! in passing argument"<<endl;
        cout<<"pass argument: './Executable' '<Customer Database file_name>' '<Request Database File Name>'"<<endl;
        return 0;
    }
    catch(char *argv){
        cout<<"ERROR ! opening file"<<endl;
        cout<<"Invalid path given: "<<argv<<endl;
        return 0;
    }
    
return 0;
}

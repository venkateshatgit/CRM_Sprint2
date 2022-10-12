#include <header.h>
#include <functions.h>

int displayReport( map<string, Customer*> &mapCustomer, ReqDatabase &reqDb)
{       
        bool flag=true;
        int n,ret;
        do{
                cout<<"\n--------- Reports Menu -----------"<<endl;
                cout<<"1.Demos scheduled on a given date.\n2.No. of Complaints not addressed as of given date.\n3.How many Service calls are closed for given customer.\n4.List of Service calls closed last month\n5.Exit"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cin>>n;
                switch(n)
                {
                        case 1 : reqDb.FinalReport_1();
                                break;

                        case 2: reqDb.FinalReport_2();
                                break;

                        case 3 : reqDb.FinalReport_3(mapCustomer);
                                break;

                        case 4 : reqDb.FinalReport_4();
                                break;

                        case 5 :cout<<"-------------------------------------------------------"<<endl;
                                flag=false;
                                break;
                        
                        default : cout<<"Please enter correct choice. "<<endl;
                }
        }while(flag);
        return SUCCESS;

}
#include "../../include/header.h"
#include "../../include/functions.h"

int displayReport(ReqDatabase &reqDb)
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
                        case 1 : FinalReport_1(reqDb);
                                break;

                        case 2: FinalReport_2(reqDb);
                                break;

                        case 3 : FinalReport_3(reqDb);
                                break;

                        case 4 : FinalReport_4(reqDb);
                                break;

                        case 5 :cout<<"-------------------------------------------------------"<<endl;
                                flag=false;
                                break;
                        
                        default : cout<<"Please enter correct choice. "<<endl;
                }
        }while(flag);
        return SUCCESS;

}
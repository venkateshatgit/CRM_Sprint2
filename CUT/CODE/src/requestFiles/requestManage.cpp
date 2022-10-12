#include <header.h>
#include <functions.h>

void requestManagement(map<string, Customer*> &mapCustomer, ReqDatabase &reqDb)
{       
        bool flag=true;
        int n,ret;
        do{
                cout<<"\n----- Request Management Menu --------"<<endl;
                cout<<"1.Add Request\n2.Update Request\n3.Delete Request\n4.Exit"<<endl;
                cout<<"------------------------------------"<<endl;
                cin>>n;
                switch(n)
                {
                        case 1 :addRequest(mapCustomer, reqDb);
                                break;

                        case 2: ret = updateRequest(reqDb);
                                if(ret==1)
                                        cout<<"\n Data Successfully Updated in Request Database. "<<endl;
                                else
                                        cout<<"\n Failure in Updating Request "<<endl;     
                                break;

                        case 3 :ret = deleteRequest(reqDb);
                                if(ret==1)
                                        cout<<"\n Request deleted successfully from Request Database. "<<endl;
                                else
                                        cout<<"\n Failure in deleting Request "<<endl;     
                                break;

                        case 4 :cout<<"-----------------------------------------------------"<<endl;
                                flag=false;
                                break;
                        
                        default : cout<<"Please enter correct choice. "<<endl;
                }

        }while(flag);

}

#include <header.h>
#include <functions.h>
// REPORT 1 :

void ReqDatabase::FinalReport_1(){
string date,temp;
int r;
    do{
    cout<<"Enter a date to get Demos scheduled on given date as dd/mm/yyyy."<<endl;
    cin>>date;   cin.ignore();        
    r=dateValidation(date);
    if(r==FAILURE)
    {
        cout<<"Please enter valid date."<<endl;
    }
    }while(r==FAILURE);
    ofstream file;
    int count=0;
    file.open("../Data/Demos_Report_1.txt");
    file<<"Demos scheduled on given date : "<<date<<endl;
    file<<"******************************************************************************"<<endl;
    for (auto it=mapReqDemo.begin();it != mapReqDemo.end(); ++it)
    {
        //Demo *temp = it->second;
        temp = it->second->getDemoDate();
        //cout<<"Date stored "<<temp<<endl;
        if(temp == date)
        {
            //write into file;
                
                file<<"\nRequest ID: "<<(it->second->getRequestID())<<"\nCustomer ID: "<<(it->second->getCustID())<<"\nRequest Type: "<<
                (it->second->getrequestType())<<"\nRequest Date:"<<(it->second->getRequestDate())<<"\nRequest Description: "<<(it->second->getRequestDesc())
                <<"\nRequest Status: "<<(it->second->getRequestStatus())<<"\nDemo Date: "<<(it->second->getDemoDate())<<"\nDemo Address: "<<
                (it->second->getDemoAddress())<<"\nDemo Time: "<<(it->second->getDemoTime())<<endl;
                file<<"-------------------------------------------------------------------------"<<endl;
                count++;

                
        }
    }
    if(count==0)
    {
        cout<<" No Demos scheduled on given date : "<<date<<endl;
        file<<"\n\n No Demos scheduled on given date : "<<date<<endl;
        file<<"\n\n-----------------------------------------------------------------------------------"<<endl;
    }
    else
    {
    cout<<"\nDemos scheduled on given date : "<<date<<" updated in file Demos_Report_1.txt "<<endl;
    file<<"\n\nDemos scheduled on given date : "<<date<<" updated in file Demos_Report_1.txt "<<endl;
    file<<"\n\n-----------------------------------------------------------------------------------"<<endl;
    }
    file.close();
}
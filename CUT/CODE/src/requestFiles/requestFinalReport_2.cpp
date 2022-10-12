#include <header.h>

void ReqDatabase::FinalReport_2(){
    string date2, temp2;
    
    int count=0;
    ofstream file;
    file.open("../Data/Complaint_Report_2.txt");
    file<<"All Complaints not addressed as of today :"<<endl;                              //date2<<" are as listed as below:"<<endl;
    file<<"******************************************************************************"<<endl;             
    //map<string, Complaint*>::iterator it2;
    for(auto it2=mapReqComplaint.begin(); it2!=mapReqComplaint.end(); ++it2)
    {
        //temp2 = mapReqComplaint[it2]->getRequestDate(string reqDate);
        temp2 = it2->second->getRequestStatus();
        string open ="open";
        if(strcasecmp(temp2.c_str(),open.c_str())==0)  
        {
            //Complaint *temp2 = it2->second;
           file<<"\nRequest ID: "<<(it2->second->getRequestID())<<"\nCustomer ID: "<<(it2->second->getCustID())<<"\nRequest Date: "<<(it2->second->getRequestDate())<<"\nRequest Description: "<<
            (it2->second->getRequestDesc())<<"\nRequest Status: "<<(it2->second->getRequestStatus())<<"\nCategory: "<<(it2->second->getCategory())
            <<"\nSub Category: "<<(it2->second->getSubCategory())<<"\nDescription: "<<(it2->second->getDescription())<<endl;
            file<<"-----------------------------------------------------------------------------------------------"<<endl;
            count++;           
        }
    }
    file.close();
    if(count!=0)
    {
    cout << "Reports Generated Successfully and stored in Complaint_Report_2.txt"<<endl;
    }
    else
    {
        cout <<"There are NO Complaints which are NOT addressed on the date "<<date2<<endl;
    }
}

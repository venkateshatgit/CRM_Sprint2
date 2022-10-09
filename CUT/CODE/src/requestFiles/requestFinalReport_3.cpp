#include "../../include/header.h"

void FinalReport_3(ReqDatabase &reqDb){
    string cstmrid, temp3,temp4;
    cout <<"Please Enter the Customer ID for generating Service Call report: "<<endl;
    cin >>cstmrid;
// customer id validation , max no need
    ofstream file;
    file.open("../Data/Servicecalls_Report_3.txt");
    file<<"All Service Calls closed for the Customer ID "<< cstmrid <<" are as listed as below: "<<endl<<endl;
    file<<"*****************************************************************"<<endl;
    for(auto it3=reqDb.mapReqService.begin(); it3!=reqDb.mapReqService.end(); ++it3)
    {
        temp3 = it3->second->getCustID();
        temp4 = it3->second->getRequestStatus();
        string close = "closed";
        if(temp3 == cstmrid && strcasecmp(temp4.c_str(),close.c_str())==0)
        {
            file<<"\nCustomer ID: "<<(it3->second->getCustID())<<"\nRequest ID: "<<(it3->second->getRequestID())<<"\nRequest Date: "<<
            (it3->second->getRequestDate())<<"\nRequest Description: "<<(it3->second->getRequestDesc())<<"\nRequest Status: "<<
            (it3->second->getRequestStatus())<<"\nAMC Date: "<<(it3->second->getAmcDate())<<"\nAMC Duration: "<<(it3->second->getAmcDur())
            <<"\nPurchase Date: "<<(it3->second->getPurchaseDate())<<"\nProduct Name: "<<(it3->second->getProdName())<<endl;
            file<<"-----------------------------------------------------------------------------------------------"<<endl;
            
        }

    }
    file.close();
    cout << "Reports Generated Successfully and stored in Servicecalls_Report_3.txt"<<endl;
}

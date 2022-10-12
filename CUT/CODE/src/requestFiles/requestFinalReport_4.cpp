#include <header.h>
#include <functions.h>

void ReqDatabase::FinalReport_4(){
    int x,r;
string tempDate;
    do{
        cout<<"\nEnter todays date(dd/mm/yyyy) to get service calls report"<<endl;
        cin>>tempDate;    // TODO:date validation& exception handelling
        r=dateValidation(tempDate);
        if(r==FAILURE)
        {
            cout<<"Please enter valid date."<<endl;
        }
    }while(r==FAILURE);
    int mmtemp,yytemp;
    stringstream str(tempDate);
    vector<string> token;
    string tempStr;
   
    while(getline(str,tempStr,'/'))
    {
        token.push_back(tempStr);
     
    }
    int dd = stoi(token[0]);
    int mm = stoi(token[1]);
    int yy = stoi(token[2]); 

    if(mm==1)
    {
        mmtemp=12;
        yytemp=yy-1;
    }
    else
    {
        mmtemp = mm -1;
        yytemp=yy;
    }
    string temp1,temp2,temp3;

    ofstream file;
    file.open("../Data/Last_Month_Report_4.txt");
    file<<"***************************************************************************************"<<endl;
    file<<"Service request recieved in Last 30 days between "<<dd<<"/"<<mmtemp<<"/"<<yytemp<<" to "<<dd<<"/"<<mm<<"/"<<yy<<" : "<<endl;
    file<<"***************************************************************************************"<<endl;

    for (auto it = mapReqService.begin();it != mapReqService.end(); ++it)
    {
        temp1 = it->second->getRequestDate();
         stringstream str1(temp1);
        vector<string> token1;
        string tempStr1;
        try
        {
            while(getline(str1,tempStr1,'/'))
        {
            token1.push_back(tempStr1);

        }
        if(token1.size()==1 || token1.size()>3)
        {
            throw x;
        }
        int dd1 = stoi(token1[0]);
        int mm1 = stoi(token1[1]);
        int yy1 = stoi(token1[2]);

        if(dd1>=dd && mm1>=mmtemp && yy1>=yytemp )
        {
             file<<"\nCustomer ID: "<<(it->second->getCustID())<<"\nRequest ID: "<<(it->second->getRequestID())<<"\nRequest Date:"<<
            (it->second->getRequestDate())<<"\nRequest Description: "<<(it->second->getRequestDesc())<<"\nRequest Status"<<
            (it->second->getRequestStatus())<<"\nAMC Date:"<<(it->second->getAmcDate())<<"\nAMC Duration: "<<(it->second->getAmcDur())
            <<"\nPurchase Date: "<<(it->second->getPurchaseDate())<<"\nProduct Name: "<<(it->second->getProdName())<<endl;
            file<<"-----------------------------------------------------------------------------------------------"<<endl;
        }

        }
        catch(int x)
        {
        cout<<"Invalid Date"<<endl;
        file<<"Invalid Date"<<endl;
        }
    }
    file<<"***************************************************************************************"<<endl;
    file<<"Complaints recieved in Last 30 days between "<<dd<<"/"<<mmtemp<<"/"<<yytemp<<" to "<<dd<<"/"<<mm<<"/"<<yy<<" : "<<endl;
    file<<"***************************************************************************************"<<endl;
    

    for (auto it = mapReqComplaint.begin();it != mapReqComplaint.end(); ++it)
    {
        temp2 = it->second->getRequestDate();
        stringstream str2(temp2);
    vector<string> token2;
    string tempStr2;
    
    while(getline(str2,tempStr2,'/'))
    {
        token2.push_back(tempStr2);
     
    }
    
    int dd2 = stoi(token2[0]);
    int mm2 = stoi(token2[1]);
    int yy2 = stoi(token2[2]);

    if(dd2>=dd && mm2>=mmtemp && yy2>=yytemp )
    {
        file<<"\nRequest ID: "<<(it->second->getRequestID())<<"\nCustomer Id: "<<(it->second->getCustID())<<"\nRequest Date: "<<(it->second->getRequestDate())<<"\nRequest Description: "<<
            (it->second->getRequestDesc())<<"\nRequest Status: "<<(it->second->getRequestStatus())<<"\nCategory: "<<(it->second->getCategory())
            <<"\nSub Category: "<<(it->second->getSubCategory())<<"\n Description: "<<(it->second->getDescription())<<endl;
            file<<"-----------------------------------------------------------------------------------------------"<<endl;
    }        
    }
    file<<"***************************************************************************************"<<endl;
    file<<"Demo request recieved in Last 30 days between "<<dd<<"/"<<mmtemp<<"/"<<yytemp<<" to "<<dd<<"/"<<mm<<"/"<<yy<<" : "<<endl;
    file<<"***************************************************************************************"<<endl;
    for (auto it = mapReqDemo.begin();it != mapReqDemo.end(); ++it)
    {
        temp3 = it->second->getRequestDate();
        stringstream str3(temp3);
        vector<string> token3;
        string tempStr3;
    
        while(getline(str3,tempStr3,'/'))
        {
        token3.push_back(tempStr3);
     
        }
    
        int dd3 = stoi(token3[0]);
        int mm3 = stoi(token3[1]);
        int yy3 = stoi(token3[2]);

        if(dd3>=dd && mm3>=mmtemp && yy3>=yytemp )
        {
        
        file<<"\nRequest ID: "<<(it->second->getRequestID())<<"\nCustomer ID: "<<(it->second->getCustID())<<"\nRequest Type: "<<
        (it->second->getrequestType())<<"\nRequest Date:"<<(it->second->getRequestDate())<<"\nRequest Description: "<<(it->second->getRequestDesc())
        <<"\nRequest Status: "<<(it->second->getRequestStatus())<<"\nDemo Date: "<<(it->second->getDemoDate())<<"\nDemo Address: "<<
        (it->second->getDemoAddress())<<"\nDemo Time: "<<(it->second->getDemoTime())<<endl;
        file<<"-------------------------------------------------------------------------"<<endl;
        
        }

    }
    file.close();
    cout << "Report for Last given period is Generated Successfully and stored in Last_Month_Report_4.txt"<<endl;
   }

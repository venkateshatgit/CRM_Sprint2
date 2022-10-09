#include "../../include/header.h"

void TotalRequestCount(ReqDatabase &reqDb)
{
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Total number of Service requests recieved till now : "<<reqDb.mapReqService.size()<<endl;
    cout<<"Total number of Complaints recieved till now : "<<reqDb.mapReqComplaint.size()<<endl;
    cout<<"Total number of Demo requests recieved till now : "<<reqDb.mapReqDemo.size()<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
}

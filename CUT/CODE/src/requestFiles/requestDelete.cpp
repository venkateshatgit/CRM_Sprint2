#include "../../include/header.h"

//delete request 
int deleteRequest(ReqDatabase &reqDb){

    string rID;
    cout << "Enter Request ID to delete: ";
    cin >> rID; cin.ignore();

    try{
        if(reqDb.mapReqService.find(rID) != reqDb.mapReqService.end()){
            Service *temp = reqDb.mapReqService[rID];
            reqDb.mapReqService.erase(rID);
            delete temp;
        }
        else if (reqDb.mapReqComplaint.find(rID) != reqDb.mapReqComplaint.end()){
            Complaint *temp = reqDb.mapReqComplaint[rID];
            reqDb.mapReqComplaint.erase(rID);
            delete temp;
        }
        else if (reqDb.mapReqDemo.find(rID) != reqDb.mapReqDemo.end()){
            Demo *temp = reqDb.mapReqDemo[rID];
            reqDb.mapReqDemo.erase(rID);
            delete temp;           
        }
        else
            throw rID;
        
    }
    catch(string id){
        cout << "ERROR MESSAGE! Request with Request ID " << id << " not found." << endl;
        return FAILURE;
    }

    return SUCCESS;
}
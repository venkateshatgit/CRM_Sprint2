#include "../../include/header.h"

void requestDataWrite(ReqDatabase &reqDb, char** argv){

    ofstream file;

    try{

        file.open(argv[2]);
        if(file.is_open()){
            //write Service
            for(auto it=reqDb.mapReqService.begin(); it!=reqDb.mapReqService.end(); it++){
                file<<(it->second->getRequestID())<<"|";
                file<<(it->second->getCustID())<<"|";
                file<<(it->second->getrequestType())<<"|";
                file<<(it->second->getRequestDate())<<"|";
                file<<(it->second->getRequestDesc())<<"|";
                file<<(it->second->getRequestStatus())<<"|";
                file<<(it->second->getAmcDate())<<"|";
                file<<(it->second->getAmcDur())<<"|";
                file<<(it->second->getPurchaseDate())<<"|";
                file<<(it->second->getProdName())<<"|";
                file<<endl;
            }

            //write compalint
            for(auto it=reqDb.mapReqComplaint.begin(); it!=reqDb.mapReqComplaint.end(); it++){
                file<<(it->second->getRequestID())<<"|";
                file<<(it->second->getCustID())<<"|";
                file<<(it->second->getrequestType())<<"|";
                file<<(it->second->getRequestDate())<<"|";
                file<<(it->second->getRequestDesc())<<"|";
                file<<(it->second->getRequestStatus())<<"|";
                file<<(it->second->getCategory())<<"|";
                file<<(it->second->getSubCategory())<<"|";
                file<<(it->second->getDescription())<<"|";
                file<<endl;
            }

            //write demo
            for(auto it=reqDb.mapReqDemo.begin(); it!=reqDb.mapReqDemo.end(); it++){
                file<<(it->second->getRequestID())<<"|";
                file<<(it->second->getCustID())<<"|";
                file<<(it->second->getrequestType())<<"|";
                file<<(it->second->getRequestDate())<<"|";
                file<<(it->second->getRequestDesc())<<"|";
                file<<(it->second->getRequestStatus())<<"|";
                file<<(it->second->getDemoDate())<<"|";
                file<<(it->second->getDemoAddress())<<"|";
                file<<(it->second->getDemoTime())<<"|";
                file<<endl;
            }
        }
        else
            throw argv[1];

        file.close();
    }
    catch(string str){
        cout<<"ERROR MESSAGE: Invalid file: "<<argv[1]<<endl;
    }
}
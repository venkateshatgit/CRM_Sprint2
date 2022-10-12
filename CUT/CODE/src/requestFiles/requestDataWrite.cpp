#include <header.h>

void ReqDatabase::requestDataWrite(char** argv){

    ofstream file;

    try{

        file.open(argv[2]);
        if(file.is_open()){
            //write Service
            for(auto it=mapReqService.begin(); it!=mapReqService.end(); it++){
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
            for(auto it=mapReqComplaint.begin(); it!=mapReqComplaint.end(); it++){
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
            for(auto it=mapReqDemo.begin(); it!=mapReqDemo.end(); it++){
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
            cout<<"Request data updated in file "<<argv[2]<<endl;
        }

        else
            throw argv[2];

        file.close();

    }
    catch(string str){
        cout<<"ERROR MESSAGE: Invalid file: "<<argv[2]<<endl;
    }
    
}
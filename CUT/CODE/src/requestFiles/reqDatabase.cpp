#include <header.h>

void ReqDatabase::addToService(Service* s){

    string id = s->getRequestID();
    mapReqService[id] = s;
}

void ReqDatabase::addToComplaint(Complaint* c){

    string id = c->getRequestID();
    mapReqComplaint[id] = c;
}


void ReqDatabase::addToDemo(Demo* d){

    string id = d->getRequestID();
    mapReqDemo[id] = d;
}

void ReqDatabase::updateService(string id, string type, string str){


    if(type==requtDate)
        mapReqService[id]->setRequestDate(str);

    else if(type==requtDesc)
        mapReqService[id]->setRequestDesc(str);

    else if(type==requtStatus)
        mapReqService[id]->setRequestStatus(str);

    else if(type==requtAMCDate)
        mapReqService[id]->setAmcDate(str);

    else if(type==requtAMCDur)
        mapReqService[id]->setAmcDur(str);

    else if(type==requtPurchaseDate)
        mapReqService[id]->setPurchaseDate(str);

    else if(type==requtProdName)
        mapReqService[id]->setProdName(str);

    else
        cout<<"The entered type does not exists"<<endl;
}



void ReqDatabase::updateComplaint(string id, string type, string str){

    if(type==requtDate)
        mapReqComplaint[id]->setRequestDate(str);

    else if(type==requtDesc)
        mapReqComplaint[id]->setRequestDesc(str);

    else if(type==requtStatus)
        mapReqComplaint[id]->setRequestStatus(str);

    else if(type==requtCat)
        mapReqComplaint[id]->setCategory(str);

    else if(type==requtSubCat)
        mapReqComplaint[id]->setSubCategory(str);

    else if(type==requtCmpDesc)
        mapReqComplaint[id]->setDescription(str);

    else
        cout<<"The entered type does not exists"<<endl;
}

void ReqDatabase::updateDemo(string id, string type, string str){

    if(type==requtDate)
        mapReqDemo[id]->setRequestDate(str);

    else if(type==requtDesc)
        mapReqDemo[id]->setRequestDesc(str);

    else if(type==requtStatus)
        mapReqDemo[id]->setRequestStatus(str);

    else if(type==requtDemoDate)
        mapReqDemo[id]->setDemoDate(str);

    else if(type==requtDemoAddress)
        mapReqDemo[id]->setDemoAddress(str);

    else if(type==requtDemoTime)
        mapReqDemo[id]->setDemoTime(str);

    else
        cout<<"The entered type does not exists"<<endl;
}

bool ReqDatabase::deleteRequest(string id){

    if(this->findMap(serviceStr, id)){
        Service *temp = mapReqService[id];
        mapReqService.erase(id);
        delete temp;
    }
    else if(this->findMap(complaintStr, id)){
        Complaint *temp = mapReqComplaint[id];
        mapReqComplaint.erase(id);
        delete temp;
    }
    else if(this->findMap(demoStr, id)){
        Demo *temp = mapReqDemo[id];
        mapReqDemo.erase(id);
        delete temp;
    }
    else
        return false;

    return true;
}


bool ReqDatabase::findMap(string type, string id){
    

    if(type==serviceStr && mapReqService.find(id)!=mapReqService.end())
        return true;
    else if(type==complaintStr && mapReqComplaint.find(id)!=mapReqComplaint.end())
        return true;
    else if(type==demoStr && mapReqDemo.find(id)!=mapReqDemo.end())
        return true;
    else
        return false;
}

void ReqDatabase::totalCount(){

    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"Total number of Service requts recieved till now : "<<mapReqService.size()<<endl;
    cout<<"Total number of Complaints recieved till now : "<<mapReqComplaint.size()<<endl;
    cout<<"Total number of Demo requests recieved till now : "<<mapReqDemo.size()<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

}



string ReqDatabase::generateId(){

    auto it1=mapReqService.rbegin();
    auto it2=mapReqComplaint.rbegin(); 
    auto it3=mapReqDemo.rbegin();

    string id1 = it1->second->getRequestID();
    string id2 = (id1 > it2->second->getRequestID()) ? id1 :  it2->second->getRequestID();
    string requestID = (id2 > it3->second->getRequestID()) ? id2 :  it3->second->getRequestID();

    int newReqID = stoi(requestID) + 1;
    requestID = to_string(newReqID);

    return requestID;
}


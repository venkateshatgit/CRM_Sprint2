#include <header.h>


/*----------------------------Request---------------------------*/
Request::Request(
    string requestID, 
    string custID, 
    string requestType, 
    string requestDate, 
    string requestDesc, 
    string requestStatus
    ):
    requestID(requestID), 
    custID(custID), 
    requestType(requestType), 
    requestDate(requestDate),
    requestDesc(requestDesc),
    requestStatus(requestStatus)
{
    //cout<<"Request Consrtuctor Created"<<endl;
}

//setter functions

void Request::setRequestDate(string reqDate){
    this->requestDate = reqDate;
}

void Request::setRequestDesc(string reqDesc){
    this->requestDesc = reqDesc;
}

void Request::setRequestStatus(string reqStatus){
    this->requestStatus = reqStatus;
}

//getter functions
string Request::getRequestID(){
    return requestID;
}

string Request::getCustID(){
    return custID;
}

string Request::getrequestType(){
    return requestType;
}

string Request::getRequestDate(){
    return requestDate;
}

string Request::getRequestDesc(){
    return requestDesc;
}

string Request::getRequestStatus(){
    return requestStatus;
}

/*---------------------------------Service-------------------------*/
Service::Service(
    string requestID, 
    string custID, 
    string requestType, 
    string requestDate, 
    string requestDesc, 
    string requestStatus, 
    string amcDate, 
    string amcDur, 
    string purchaseDate, 
    string prodName
    ):
    Request(requestID, custID, requestType, requestDate, requestDesc, requestStatus),
    amcDate(amcDate), 
    amcDur(amcDur), 
    purchaseDate(purchaseDate), 
    prodName(prodName)
{
    //cout<<"Service Constructor Created"<<endl;
}


//Setter functions
void Service::setAmcDate(string amcDate){
    this->amcDate = amcDate;
}

void Service::setAmcDur(string amcDur){
    this->amcDur = amcDur;
}

void Service::setPurchaseDate(string purchaseDate){
    this->purchaseDate = purchaseDate;
}

void Service::setProdName(string prodName){
    this->prodName = prodName;
}

//Getter functions
string Service::getAmcDate(){
    return amcDate;
}

string Service::getAmcDur(){
    return amcDur;
}

string Service::getPurchaseDate(){
    return purchaseDate;
}

string Service::getProdName(){
    return prodName;
}

/*---------------------------------Complaints---------------------------*/
Complaint::Complaint(
    string requestID, 
    string custID, 
    string requestType, 
    string requestDate, 
    string requestDesc, 
    string requestStatus, 
    string category, 
    string subCategory, 
    string description
    ):
    Request(requestID, custID, requestType, requestDate, requestDesc, requestStatus),
    category(category), 
    subCategory(subCategory), 
    description(description)   
{
    //cout<<"Complaint Consrtuctor Created"<<endl;
}

//Setter functions
void Complaint::setCategory(string category){
    this->category = category;
}

void Complaint::setSubCategory(string subCategory){
    this->subCategory = subCategory;
}

void Complaint::setDescription(string description){
    this->description = description;
}


//Getter functions
string Complaint::getCategory(){
    return category;
}

string Complaint::getSubCategory(){
    return subCategory;
}

string Complaint::getDescription(){
    return description;
}

/*--------------------------------Demo------------------------------------*/
Demo::Demo(
    string requestID, 
    string custID, 
    string requestType, 
    string requestDate, 
    string requestDesc, 
    string requestStatus, 
    string demoDate, 
    string demoAddress, 
    string demoTime
    ):
    Request(requestID, custID, requestType, requestDate, requestDesc, requestStatus),
    demoDate(demoDate), 
    demoAddress(demoAddress), 
    demoTime(demoTime)
{
    //cout<<"Demo Constructor created"<< endl;
}

//Setter functions
void Demo:: setDemoDate(string demoDate){
    this->demoDate = demoDate;
}

void Demo:: setDemoAddress(string demoAddress){
    this->demoAddress = demoAddress;
}

void Demo:: setDemoTime(string demoTime){
    this->demoTime = demoTime;
}


//Getter functions
string Demo:: getDemoDate(){
    return demoDate;
}

string Demo:: getDemoAddress(){
    return demoAddress;
}

string Demo:: getDemoTime(){
    return demoTime;
}

/*---------------------------------ReqDatabase---------------------------*/

void ReqDatabase::displayReqDatabase(){
    for(auto it=mapReqService.begin(); it!=mapReqService.end(); ++it){
        cout<<(it->second->getRequestID())<<" "<<(it->second->getCustID())<<" "<<(it->second->getrequestType())<<" "<<(it->second->getRequestDate())
        <<" "<<(it->second->getRequestDesc())<<" || "<<(it->second->getRequestStatus())<<" || "<<(it->second->getAmcDate())
        <<" || "<<(it->second->getAmcDur())<<" || "<<(it->second->getPurchaseDate())<<" || "<<(it->second->getProdName())<<endl;
    }
    for(auto it=mapReqComplaint.begin(); it!=mapReqComplaint.end(); ++it){
        cout<<(it->second->getRequestID())<<" "<<(it->second->getCustID())<<" "<<(it->second->getrequestType())<<" "<<(it->second->getRequestDate())
        <<" "<<(it->second->getRequestDesc())<<" || "<<(it->second->getRequestStatus())<<" || "<<(it->second->getCategory())
        <<" || "<<(it->second->getSubCategory())<<" || "<<(it->second->getDescription())<<endl;
    }
    for(auto it=mapReqDemo.begin(); it!=mapReqDemo.end(); ++it){
        cout<<(it->second->getRequestID())<<" "<<(it->second->getCustID())<<" "<<(it->second->getrequestType())<<" "<<(it->second->getRequestDate())
        <<" "<<(it->second->getRequestDesc())<<" || "<<(it->second->getRequestStatus())<<" || "<<(it->second->getDemoDate())
        <<" || "<<(it->second->getDemoAddress())<<" || "<<(it->second->getDemoTime())<<endl;
    }
}

void ReqDatabase::deleteReqDatabase(){

    for(auto it=mapReqService.begin(); it!=mapReqService.end(); ){
        Service *temp = it->second;

        auto this_it = it++;
        mapReqService.erase(this_it);
        delete temp;

    }

    for(auto it=mapReqComplaint.begin(); it!=mapReqComplaint.end(); ){
        Complaint *temp = it->second;

        auto this_it = it++;
        mapReqComplaint.erase(this_it);
        delete temp;
    }

    for(auto it=mapReqDemo.begin(); it!=mapReqDemo.end(); ){
        Demo *temp = it->second;

        auto this_it = it++;
        mapReqDemo.erase(this_it);
        delete temp;
    }


    
}


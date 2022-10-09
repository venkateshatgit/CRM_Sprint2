#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;
#define serviceStr "SRQ"
#define complaintStr "CML"
#define demoStr "DRQ"
#define SUCCESS 1
#define FAILURE 0

/*-------------------------Customer Class------------------*/
class Customer{
    string customerId, firstName, lastName, address, phoneNumber,customerType;
    public:
        Customer( string id, string fn, string ln, string add, string phn,string cType);
        string getId();
        string getFirstName();
        string getLastName();
        string getAddress();
        string getPhoneNumber();
        string getCustomerType();
        
        void setFirstName(string fname);
        void setLastName(string lname);
        void setAddress(string address);
        void setPhoneNumber(string phoneNumber);
        void setCustomerType(string cType);
        void display();
};


/*-------------------------Request Class------------------*/
class Request{
    protected:
        string custID, requestID, requestType, requestDate, requestDesc, requestStatus;
    public:
        Request(string requestID, string custID, string requestType, string requestDate, string requestDesc, string requestStatus);
        void setRequestDate(string reqDate);
        void setRequestDesc(string reqDesc);
        void setRequestStatus(string reqStatus);
        string getRequestID();
        string getCustID();
        string getrequestType();
        string getRequestDate();
        string getRequestDesc();
        string getRequestStatus();
};


/*-------------------------Service Class------------------*/
class Service: public Request{
        string amcDate, amcDur, purchaseDate, prodName;

    public:
        Service(string requestID, string custID, string requestType, string requestDate, string requestDesc, string requestStatus, string amcDate, string amcDur, string purchaseDate, string prodName);
        void setAmcDate(string amcDate);
        void setAmcDur(string amcDur);
        void setPurchaseDate(string purchaseDate);
        void setProdName(string prodName);
        string getAmcDate();
        string getAmcDur();
        string getPurchaseDate();
        string getProdName();        
};




/*-------------------------complaint Class------------------*/
class Complaint: public Request{
    string category, subCategory, description;
    public:
        Complaint(string custID, string requestID, string requestType, string requestDate, string requestDesc, string requestStatus, string category, string subCategory, string description);
        void setCategory(string category);
        void setSubCategory(string subcategory);
        void setDescription(string description);
        string getCategory();
        string getSubCategory();
        string getDescription();
        
};



/*-------------------------Demo Class------------------*/
class Demo: public Request{
    string demoDate, demoAddress, demoTime;
    public:
        Demo(string custID, string requestID, string requestType, string requestDate, string requestDesc, string requestStatus,string demoDate, string demoAddress, string demoTime);
        void setDemoDate(string demoDate);
        void setDemoAddress(string demoAddress);
        void setDemoTime(string demoTime);
        string getDemoDate();
        string getDemoAddress();
        string getDemoTime();
};



/*-------------------------Request Database Class------------------*/
class ReqDatabase{
    public:
        map<string, Service*> mapReqService;
        map<string, Complaint*> mapReqComplaint;
        map<string, Demo*> mapReqDemo;
        
        void deleteReqDatabase();
        void displayReqDatabase();
};

//int dateValidation(string tempDate);


#endif
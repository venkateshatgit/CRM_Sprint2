#ifndef HEADER_H
#define HEADER_H

#include <bits/stdc++.h>
using namespace std;
#define serviceStr "SRQ"
#define complaintStr "CML"
#define demoStr "DRQ"
#define requtDate "RequestDate"
#define requtDesc "RequestDesc"
#define requtStatus "RequestStatus"
#define requtAMCDate "AmcDate"
#define requtAMCDur "AmcDur"
#define requtPurchaseDate "PurchaseDate"
#define requtProdName "ProdName"
#define requtCat "Category"
#define requtSubCat "SubCategory"
#define requtCmpDesc "CmpDescription"
#define requtDemoDate "DemoDate"
#define requtDemoAddress "DemoAddress"
#define requtDemoTime "DemoTime"
#define SUCCESS 1
#define FAILURE 0

/*-------------------------Customer Class------------------*/
class Customer{
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
    private:
        string customerId, firstName, lastName, address, phoneNumber,customerType;
};


/*-------------------------Request Class------------------*/
class Request{
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
    protected:
        string custID, requestID, requestType, requestDate, requestDesc, requestStatus;
};


/*-------------------------Service Class------------------*/
class Service: public Request{
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
    private:
        string amcDate, amcDur, purchaseDate, prodName;
        
};


/*-------------------------complaint Class------------------*/
class Complaint: public Request{
    public:
        Complaint(string custID, string requestID, string requestType, string requestDate, string requestDesc, string requestStatus, string category, string subCategory, string description);
        void setCategory(string category);
        void setSubCategory(string subcategory);
        void setDescription(string description);
        string getCategory();
        string getSubCategory();
        string getDescription();
    private:
        string category, subCategory, description;
};


/*-------------------------Demo Class------------------*/
class Demo: public Request{
    public:
        Demo(string custID, string requestID, string requestType, string requestDate, string requestDesc, string requestStatus,string demoDate, string demoAddress, string demoTime);
        void setDemoDate(string demoDate);
        void setDemoAddress(string demoAddress);
        void setDemoTime(string demoTime);
        string getDemoDate();
        string getDemoAddress();
        string getDemoTime();
    private:
        string demoDate, demoAddress, demoTime;
};


/*-------------------------Request Database Class------------------*/
class ReqDatabase{
    public:
        void deleteReqDatabase();
        void displayReqDatabase();

        void addToService(Service* s);
        void addToComplaint(Complaint* c);
        void addToDemo(Demo* d);

        void updateService(string id, string type, string str);
        void updateComplaint(string id, string type, string str);
        void updateDemo(string id, string type, string str);

        void eraseMap(string type, string id);
        bool findMap(string type, string id);
        string generateId();
        bool deleteRequest(string id);
        void totalCount();

        void FinalReport_1();
        void FinalReport_2();
        void FinalReport_3(map<string, Customer*> &mapCustomer);
        void FinalReport_4();

        void requestDataWrite(char** argv);
    protected:
        map<string, Service*> mapReqService;
        map<string, Complaint*> mapReqComplaint;
        map<string, Demo*> mapReqDemo;
        
};


#endif
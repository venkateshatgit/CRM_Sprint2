#include <header.h>
#include <functions.h>

//int dateValidation(string tempDate);
int dateValidation(string tempDate)
{
    int x=0;
   
    stringstream str(tempDate);
    vector<string> token;
    string tempStr;
    try
    {
    while(getline(str,tempStr,'/'))
    {
        token.push_back(tempStr);
     
    }
    if(token.size()!=3)
    {
        throw x;
    }
    int dd = stoi(token[0]);
    int mm = stoi(token[1]);
    int yy = stoi(token[2]);

    if(2000 <= yy && yy <= 2022)
    {
         if( (mm==4 && dd>0 && dd <=30) ||( mm==6 && dd>0 && dd <=30)|| (mm==9 && dd>0 && dd <=30)|| (mm==11  && dd>0 && dd <=30))
        {
            return SUCCESS;
        }
        else if( (mm==1 && dd>0 && dd <=31) || (mm==3 && dd>0 && dd <=31) || (mm==5 && dd>0 && dd <=31) || (mm==7 && dd>0 && dd <=31) || (mm==8 && dd>0 && dd <=31) || (mm==10 && dd>0 && dd <=31) || (mm==12 && dd>0 && dd <=31))
        {
            return SUCCESS;
        }
        else if ( mm==2 )
        {
            if(( yy%400==0 || ( yy%100!=0 && yy%4==0 )) && dd>0 && dd<=29)
            {
                return SUCCESS;
            }
            else if( dd>0 && dd<=28 )
            {
                return SUCCESS;
            }
            else{
                return FAILURE;
            }
        }
        else{
            return FAILURE;
        }
    }
    else{
        return FAILURE;
    }
    }
    catch(int x)
    {
        return FAILURE;
    }
}

static int custIdValidation(map<string, Customer*> &mapCustomer, string custID){

    cout<<"Checking Validation: "<<custID<<endl;

    if(mapCustomer.find(custID)!=mapCustomer.end())
        return 1;
    return 0;
}

void addRequest(map<string, Customer*> &mapCustomer, ReqDatabase &reqDb){

    string requestID = reqDb.generateId();
    
    //request variable
    string custID="", requestType="", requestDate="", requestDesc="", requestStatus="";

    //service variables
    string amcDate="", amcDur="", purchaseDate="", prodName="";

    //Demo variables
    string demoDate="", demoAddress="", demoTime="";

    //Complaint variables
    string category="", subCategory="", description="";

    int r=0,r1,r2,r3;
    cout<<"Enter the details for New Request:"<<endl;

    do{

        cout<<"Customer ID: ";
        cin>>custID; cin.ignore();

        r = custIdValidation(mapCustomer, custID);
        if(r==FAILURE)
            cout<<"Please enter valid customer Id"<<endl;

    }while(r==FAILURE);

    cout<<"Request Type(SRQ/CML/DRQ): "; 
    cin>>requestType; cin.ignore();

    do{
    cout<<"Request Date(dd/mm/yyyy): "; 
    cin>>requestDate; cin.ignore();
    r=dateValidation(requestDate);
    if(r==FAILURE)
    {
        cout<<"Please enter valid date."<<endl;
    }
    }while(r==FAILURE);


    cout<<"Request Description: "; 
    getline(cin, requestDesc, '\n');

    cout<<"Request Status(Open/Closed): "; 
    cin>>requestStatus; cin.ignore();

    try{
        if(requestID=="" || custID=="" || requestType=="" || requestDate=="" || requestDesc=="" || requestStatus=="")
            throw requestID;
        
        if(requestType==serviceStr){
            do{
            cout<<"AMC Date(dd/mm/yyyy): "; 
            cin>>amcDate; cin.ignore();
            r1=dateValidation(amcDate);
        if(r1==FAILURE)
        {
        cout<<"Please enter valid date."<<endl;
        }
        }while(r1==FAILURE);

            cout<<"AMC Duration(in Months): "; 
            cin>>amcDur; cin.ignore();
    
            do{
            cout<<"Purchase Date(dd/mm/yyyy): "; 
            cin>>purchaseDate; cin.ignore();
            r2=dateValidation(purchaseDate);
            if(r2==FAILURE)
            {
            cout<<"Please enter valid date."<<endl;
            }
            }while(r2==FAILURE);

            cout<<"Product Name: "; 
            getline(cin, prodName, '\n');

            if(amcDate=="" || amcDur=="" || purchaseDate=="" || prodName=="")
                throw requestID;

            Service *s = new Service(requestID, custID, requestType, requestDate, requestDesc, requestStatus, 
                                amcDate, amcDur, purchaseDate, prodName);
            
            reqDb.addToService(s);
            cout<<"Request ID "<<requestID<<" created Successfully."<<endl;
        }
        else if(requestType==demoStr){
            
            do{
            cout<<"Demo Date(dd/mm/yyyy): "; 
            cin>>demoDate; cin.ignore();
            r3=dateValidation(demoDate);
            if(r3==FAILURE)
            {
                cout<<"Please enter valid date."<<endl;
            }   
            }while(r3==FAILURE);

            cout<<"Demo Address : "; 
            getline(cin, demoAddress, '\n');

            cout<<"Demo Time(HH:MM AM/PM): "; 
            getline(cin, demoTime, '\n');
            if(demoDate=="" || demoAddress=="" || demoTime=="")
                throw requestID;

            Demo *d = new Demo(requestID, custID, requestType, requestDate, requestDesc, requestStatus, 
                                demoDate, demoAddress, demoTime);

            reqDb.addToDemo(d);
            cout<<"Request ID "<<requestID<<" created Successfully."<<endl;
        }   
        else if(requestType==complaintStr){
            cout<<"Category: "; 
            cin>>category; cin.ignore();

            cout<<"Sub-Category: "; 
            cin>>subCategory; cin.ignore();

            cout<<"Description: "; 
            getline(cin, description, '\n');

            if(category=="" || subCategory=="" || description=="")
                throw requestID;

            Complaint *c = new Complaint(requestID, custID, requestType, requestDate, requestDesc, requestStatus, 
                                category, subCategory, description);

            reqDb.addToComplaint(c);
            cout<<"Request ID "<<requestID<<" created Successfully."<<endl;
        }
        else 
            throw requestID;
    }
    catch(string str){
        cout<<"ERROR MESSAGE: Data entered is either invalid data or blank data is entered for Request ID  "<<requestID<<endl;
        cout<<"Request ID" <<requestID<<" is not created, Please add the Request Again !!"<<endl;
    }
}

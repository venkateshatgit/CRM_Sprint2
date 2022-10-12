#include <header.h>

/*---------------------Create Request---------------------*/

void tokenizingRequestFile(string line,  ReqDatabase &reqDb){

    // int cnt=0;
    stringstream check1(line);
    string intermediate;
    string requestID="", custID="", requestType="", requestDate="", requestDesc="", requestStatus="";

    //service variables
    string amcDate="", amcDur="", purchaseDate="", prodName="";

    //Demo variables
    string demoDate="", demoAddress="", demoTime="";

    //Complaint variables
    string category="", subCategory="", description="";
    
    int cnt=0;
    while(getline(check1, intermediate, '|')){

        switch (cnt)
        {
            case 0:
                requestID=intermediate;
                break;
            
            case 1:
                custID=intermediate;
                break;

            case 2:
                requestType=intermediate;
                break;

            case 3:
                requestDate=intermediate;
                break;

            case 4:
                requestDesc=intermediate;
                break;

            case 5:
                requestStatus=intermediate;
                break;
            
            default:
                if(requestType==serviceStr){
                    switch (cnt)
                    {
                        case 6:
                            amcDate=intermediate; 
                            break;

                        case 7:
                            amcDur=intermediate; 
                            break;

                        case 8:
                            purchaseDate=intermediate; 
                            break;

                        case 9:
                            prodName=intermediate; 
                            break;

                        default:
                            break;
                    }
                }

                else if(requestType==demoStr){
                    switch (cnt)
                    {
                        case 6:
                            demoDate=intermediate; 
                            break;

                        case 7:
                            demoAddress=intermediate; 
                            break;

                        case 8:
                            demoTime=intermediate; 
                            break;

                        default:
                            break;
                    }
                }

                else{
                    switch (cnt)
                    {
                        case 6:
                            category=intermediate; 
                            break;

                        case 7:
                            subCategory=intermediate; 
                            break;

                        case 8:
                            description=intermediate; 
                            break;

                        default:
                            break;
                    }
                }
        }
        cnt+=1;
    }

    try{
        if(requestID!="" && custID!="" && requestType!="" && requestDate!="" && requestDesc!="" && requestStatus!=""){

            if(requestType==serviceStr){

                if(amcDate!="" && amcDur!="" && purchaseDate!="" && prodName!=""){
                    Service *s = new Service(requestID, 
                                            custID, 
                                            requestType,
                                            requestDate, 
                                            requestDesc, 
                                            requestStatus, 
                                            amcDate,
                                            amcDur,
                                            purchaseDate,
                                            prodName
                                        );

                    // reqDb.mapReqService[requestID] = s;                     
                    reqDb.addToService(s);
                }
            }
            
            else if(requestType==complaintStr){
                //complaint
                if(category !="" && subCategory !="" && description !=""){
                    Complaint *c = new Complaint(requestID, 
                                            custID, 
                                            requestType,
                                            requestDate, 
                                            requestDesc, 
                                            requestStatus, 
                                            category,
                                            subCategory,
                                            description
                                        );

                    // reqDb.mapReqComplaint[requestID] = c;   
                    reqDb.addToComplaint(c);                  
                }
                else   
                    throw line; 
            }

            else if(requestType==demoStr){
                if(demoDate!="" && demoAddress!="" && demoTime!=""){
                    Demo *d = new Demo(requestID,
                                            custID,
                                            requestType,
                                            requestDate,
                                            requestDesc,
                                            requestStatus,
                                            demoDate,
                                            demoAddress,
                                            demoTime
                                        );
                    
                    // reqDb.mapReqDemo[requestID] = demoTemp;
                    reqDb.addToDemo(d);
                }
                else
                    throw line;
            }

            else    
                throw line;
        }

        else 
            throw line;
    }
    catch(string line){
        cout<<"Request with missing data : "<<line<<endl;
        
        ofstream file;
        file.open("../Data/requInvalid.txt", ios::app);
        file<<line;
        file<<endl;
        file.close();
    }
}


void extractingRequestFile(ReqDatabase &reqDb, char** argv){


    //Exceptional handling for arguement and file opening
    ifstream reqfile;
    reqfile.open(argv[2]);

    //Reading file and storing data in data structure
    string line;
    while(getline(reqfile, line)){
        //tokenizing the line using delimitor '|'
        tokenizingRequestFile(line, reqDb);
    }
    reqfile.close();

    //cout<<"HERE IN EXTRACT REQUEST : "<<argv[2]<<endl;
}
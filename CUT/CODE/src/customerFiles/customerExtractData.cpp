#include <header.h>

void tokenizingFile(string line, map <string, Customer*> &mapCustomer){

    int cnt=0;
    stringstream check1(line);
    string intermediate, 
    customerId="", firstName="", lastName="", address="", phoneNumber="",customerType="";
    while(getline(check1, intermediate, '|')){
       
        switch (cnt)
        {
            case 0:
                customerId=intermediate;
                break;
            
            case 1:
                firstName=intermediate;
                break;

            case 2:
                lastName=intermediate;
                break;

            case 3:
                address=intermediate;
                break;

            case 4:
                phoneNumber=intermediate;
                break;
            case 5 :
                    customerType=intermediate;
                    break;
            
            default:
                break;
        }

        //checking for variables and handling exception for missed data
        if(cnt==5){
            try{

                if(customerId!="" && firstName!="" && lastName!="" && address!="" && phoneNumber!="" && customerType!=""){
                    Customer *cust = new Customer(customerId, firstName, lastName, address, phoneNumber,customerType);
                    mapCustomer[customerId] = cust;
                }
                else
                    throw line;
            }
            catch(string line){
                cout<<"Customer with missing data : "<<line<<endl;
        
                ofstream file;
                file.open("../Data/custInvalid.txt", ios::app);
                file<<line;
                file<<endl;
                file.close();
            }
        }

        cnt+=1;
    }
}


void extractCustomerData(char** argv, map<string, Customer*> &mapCustomer){

    ifstream file_var;
    try{

        file_var.open(argv[1]);
        if(!file_var.is_open())
            throw argv[1];

        string line;
        while(getline(file_var, line)){
            
            //tokenizing the line using delimitor '|'
            tokenizingFile(line, mapCustomer);
        }
        file_var.close();
    }
    catch(char *argv){
        cout<<"ERROR! opening file"<<endl;
        cout<<"Invalid path: "<<argv<<endl;
    }
}
#include<bits/stdc++.h>
#define SUCCESS 1
#define FAILURE 0
#include "testfunction.h"
using namespace std;

int tokenizingFile(string line)
{
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
                    return SUCCESS;
                }
                else
                    throw line;
            }
            catch(string line){
                return FAILURE;
            }
        }

        cnt+=1;
    }
    return FAILURE;
}

int dateValidation(string dateStr)
{
    int x=0;
    stringstream str(dateStr);
    vector<string> token;
    string tempStr;
    try
    {
        while(getline(str,tempStr,'/'))
        {
            token.push_back(tempStr);
        
        }
        if(token.size()==1 || token.size()>3)
        {
            throw x;
        }
        int dd = stoi(token[0]);
        int mm = stoi(token[1]);
        int yy = stoi(token[2]);
        if(yy >= 2000 && yy <=2022)
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

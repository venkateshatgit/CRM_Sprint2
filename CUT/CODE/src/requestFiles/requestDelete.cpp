#include <header.h>

//delete request 
int deleteRequest(ReqDatabase &reqDb){

    string rID;
    cout << "Enter Request ID to delete: ";
    cin >> rID; cin.ignore();

    try{


        if(!reqDb.deleteRequest(rID))
            throw rID;
        
    }
    catch(string id){
        cout << "ERROR MESSAGE! Request with Request ID " << id << " not found." << endl;
        return FAILURE;
    }

    return SUCCESS;
}
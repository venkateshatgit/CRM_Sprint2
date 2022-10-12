#include <header.h>
#include <functions.h>

//int dateValidation(string tempDate);

int updateRequest(ReqDatabase &reqDb){

    string rID;
    cout << "Enter the Request ID to update: ";
    cin >> rID; cin.ignore();

    try{
        if (reqDb.findMap(serviceStr, rID))
        {
            cout << "Request with Request ID " << rID << " found." << endl;
            int opt = 0,r=0,r1=0,r2=0;
            bool flag=true;
            do{
            cout<<"\n---------- Update Request Menu ----------"<<endl;
            cout<<"\n1.Update Request Date\n2.Update Request Description\n3.Update Request Status\n4.Update AMC Date\n5.Update AMC Duration\n6.Update Product Purchased Date\n7.Update Product Name"<<"\n8.Exit"<<endl;
            cout<<"----------------------------------------------------"<<endl;
            cin>>opt; cin.ignore();
            string str;
            switch(opt)
            {
                case 1 :do{
                        cout<<"Enter Request Date (dd/mm/yyyy): ";
                        cin>>str; cin.ignore();   // date validation
                        r=dateValidation(str);
                        if(r==FAILURE)
                         {
                                 cout<<"Please enter valid date."<<endl;
                          }
                         }while(r==FAILURE); 
                        // reqDb.mapReqService[rID]->setRequestDate(str);
                        reqDb.updateService(rID, requtDate, str);
                        cout << "Request Date Updated Succesfully" << endl;
                        break;

                case 2 :cout<<"Enter Request Description: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqService[rID]->setRequestDesc(str);
                        reqDb.updateService(rID, requtDesc, str);
                        cout << "Request Description Updated Succesfully" << endl;
                        break;

                case 3 :cout<<"Enter Request Status(Open/Closed): ";
                        cin>>str; cin.ignore();
                        // reqDb.mapReqService[rID]->setRequestStatus(str);
                        reqDb.updateService(rID, requtStatus, str);
                        cout << "Request Status Updated Succesfully" << endl;
                        break;

                case 4 :do{
                        cout<<"Enter AMC Date (dd/mm/yyyy): ";
                        cin>>str; cin.ignore();   // date validation
                        r1=dateValidation(str);
                         if(r1==FAILURE)
                        {
                                cout<<"Please enter valid date."<<endl;
                        }
                        }while(r1==FAILURE);
                        // reqDb.mapReqService[rID]->setAmcDate(str);
                        reqDb.updateService(rID, requtAMCDate, str);
                        cout << "AMC Date Updated Succesfully" << endl;;
                        break;

                case 5 :cout<<"Enter AMC Duration: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqService[rID]->setAmcDur(str);
                        reqDb.updateService(rID, requtAMCDur, str);
                        cout << "AMC Duration Updated Succesfully" << endl;
                        break;

                case 6 :do{
                        cout<<"Enter Product Purchase Date(dd/mm/yyyy): ";
                        cin>>str; cin.ignore();
                        r2=dateValidation(str);
                        if(r2==FAILURE)
                        {
                                cout<<"Please enter valid date."<<endl;
                        }
                        }while(r2==FAILURE);
                        // reqDb.mapReqService[rID]->setPurchaseDate(str);
                        reqDb.updateService(rID, requtPurchaseDate, str);
                        cout << "Product Purchase Date Updated Succesfully" << endl;
                        break;

                case 7 :cout<<"Enter Product Name: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqService[rID]->setProdName(str);
                        reqDb.updateService(rID, requtProdName, str);
                        cout << "Product Name Updated Succesfully" << endl;
                        break;   
                case 8 : cout<<"--------------------------------------"<<endl;
                        flag=false;
                        return SUCCESS;

                default : cout<<"Enter the correct choice."<<endl; 
            }
            }while(flag);
            return SUCCESS;
        }
        else if (reqDb.findMap(complaintStr, rID))
        {
            cout << "Request with Request ID " << rID << " found." << endl;
            int opt = 0,r=0;
            bool flag=true;
            do{
            cout<<"\n---------- Update Request Menu ----------"<<endl;
            cout<<"\n1.Update Request Date\n2.Update Request Description\n3.Update Request Status\n4.Update Category\n5.Update Sub Category\n6.Update Complaint Description\n7.Exit"<<endl;
            cin>>opt; cin.ignore();
            string str;
            switch(opt)
            {
                case 1 :do{
                        cout<<"Enter Request Date(dd/mm/yyyy) : ";
                        cin>>str; cin.ignore();
                        r=dateValidation(str);
                        if(r==FAILURE)
                         {
                                 cout<<"Please enter valid date."<<endl;
                          }
                         }while(r==FAILURE);     
                        // reqDb.mapReqComplaint[rID]->setRequestDate(str);
                        reqDb.updateComplaint(rID, requtDate, str);
                        cout << "Request Date Updated Succesfully" << endl;
                        break;

                case 2 :cout<<"Enter Request Description: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqComplaint[rID]->setRequestDesc(str);
                        reqDb.updateComplaint(rID, requtDesc, str);
                        cout << "Request Description Updated Succesfully" << endl;
                        break;

                case 3 :cout<<"Enter Request Status (Open/Closed): ";
                        cin>>str; cin.ignore();
                        // reqDb.mapReqComplaint[rID]->setRequestStatus(str);
                        reqDb.updateComplaint(rID, requtStatus, str);
                        cout << "Request Status Updated Succesfully" << endl;
                        break;

                case 4 :cout<<"Enter Complaint Category: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqComplaint[rID]->setCategory(str);
                        reqDb.updateComplaint(rID, requtCat, str);
                        cout << "Complaint Category Updated Succesfully" << endl;;
                        break;

                case 5 :cout<<"Enter Complaint Sub-category: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqComplaint[rID]->setSubCategory(str);
                        reqDb.updateComplaint(rID, requtSubCat, str);
                        cout << "Complaint Sub-category Updated Succesfully" << endl;
                        break;

                case 6 :cout<<"Enter Complaint Description: ";
                        getline(cin, str, '\n');
                        // reqDb.mapReqComplaint[rID]->setDescription(str);
                        reqDb.updateComplaint(rID, requtCmpDesc, str);
                        cout << "Complaint Description Updated Succesfully" << endl;
                        break;  
                case 7 : cout<<"-------------------------------------------"<<endl;
                        flag=false;
                        return SUCCESS;  

                default : cout<<"Enter the correct choice."<<endl; 
            }
            }while(flag);
        }
        else if (reqDb.findMap(demoStr, rID))
        {
            cout << "Request with Request ID " << rID << " found." << endl;
            int opt = 0,r=0;
            bool flag=true;
            do{
            cout<<"\n---------- Update Request Menu ----------"<<endl;
            cout<<"\n1.Update Request Date\n2.Update Request Description\n3.Update Request Status\n4.Update Demo Date\n5.Update Demo Address\n6.Update Demo Time\n7.Exit"<<endl;
            cin>>opt; cin.ignore();
            string str;
            switch(opt)
            {
                case 1 :do{
                        cout<<"Enter Request Date (dd/mm/yyyy): ";
                        cin>>str; cin.ignore(); 
                        r=dateValidation(str);
                        if(r==FAILURE)
                         {
                                 cout<<"Please enter valid date."<<endl;
                          }
                         }while(r==FAILURE);    
                        //reqDb.mapReqDemo[rID]->setRequestDate(str);
                        reqDb.updateDemo(rID, requtDate, str);
                        cout << "Request Date Updated Succesfully" << endl;
                        break;

                case 2 :cout<<"Enter Request Description: ";
                        getline(cin, str, '\n');
                        //reqDb.mapReqDemo[rID]->setRequestDesc(str);
                        reqDb.updateDemo(rID, requtDesc, str);
                        cout << "Request Description Updated Succesfully" << endl;
                        break;

                case 3 :cout<<"Enter Request Status (Open/Closed): ";
                        cin>>str; cin.ignore();
                        //reqDb.mapReqDemo[rID]->setRequestStatus(str);
                        reqDb.updateDemo(rID, requtStatus, str);
                        cout << "Request Status Updated Succesfully" << endl;
                        break;

                case 4 :do{
                        cout<<"Enter Demo Date (dd/mm/yyyy): ";
                        cin>>str; cin.ignore();
                        r=dateValidation(str);
                        if(r==FAILURE)
                         {
                                 cout<<"Please enter valid date."<<endl;
                          }
                         }while(r==FAILURE); 
                        //reqDb.mapReqDemo[rID]->setDemoDate(str);
                        reqDb.updateDemo(rID, requtDemoDate, str);
                        cout << "Demo Date Updated Succesfully" << endl;;
                        break;

                case 5 :cout<<"Enter Demo Address: ";
                        getline(cin, str, '\n');
                        //reqDb.mapReqDemo[rID]->setDemoAddress(str);
                        reqDb.updateDemo(rID, requtDemoAddress, str);
                        cout << "Demo Address Updated Succesfully" << endl;
                        break;

                case 6 :cout<<"Enter Demo Time(Hours:Min AM/PM): ";
                        getline(cin, str, '\n');
                        //reqDb.mapReqDemo[rID]->setDemoTime(str);
                        reqDb.updateDemo(rID, requtDemoTime, str);
                        cout << "Demo Time Updated Succesfully" << endl;
                        break;   
                case 7 : cout<<"-------------------------------------------"<<endl;
                        flag=false;
                        return SUCCESS;

                default : cout<<"Enter the correct choice."<<endl; 
            }
            }while(flag);
        }
        else
            throw rID;
    }
    catch(string id){
        cout << "ERROR MESSAGE! Request with Request ID " << id << " not found." << endl;
        return FAILURE;
    }
    return SUCCESS;
}
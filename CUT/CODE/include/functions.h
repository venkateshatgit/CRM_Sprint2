#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//----------------Customer functions--------
void extractCustomerData(char** argv, map<string, Customer*> &mapCustomer);
void tokenizingFile(string line, map <string, Customer*> &mapCustomer);
void addCustomer(map<string, Customer*> &mapCustomer);
void updateCustomer(map<string, Customer*> &mapCustomer);
void deleteCustomer(map<string, Customer*> &mapCustomer);
void customerDataWrite(map<string, Customer*> &mapCustomer, char* filePath);
void deleteMapCustomer(map<string, Customer*> &mapCustomer);
int customerManagement(map<string, Customer*> &mapCustomer, char* filename);


//----------------Request functions----------
void tokenizingRequestFile(string line, ReqDatabase &reqDb);
void extractingRequestFile(ReqDatabase &reqDb, char** argv);
void addRequest(map<string, Customer*> &mapCustomer, ReqDatabase &reqDb);
int updateRequest(ReqDatabase &reqDb);
int dateValidation(string tempDate);
int deleteRequest(ReqDatabase &reqDb);
void requestManagement(map<string, Customer*> &mapCustomer, ReqDatabase &reqDb);

//----------------Report functions--------------
void FinalReport_1(ReqDatabase &reqDb);
void FinalReport_2(ReqDatabase &reqDb);
void FinalReport_3(ReqDatabase &reqDb, map<string, Customer*> &mapCustomer);
void FinalReport_4(ReqDatabase &reqDb);
int displayReport( map<string, Customer*> &mapCustomer, ReqDatabase &reqDb);

//---------------- Date Validation ----------

int dateValidation(string tempDate);


#endif
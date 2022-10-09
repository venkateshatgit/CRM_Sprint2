
crm: customer.o request.o main.o 
	g++ ../obj/main.o ../obj/customerAdd.o ../obj/customerClass.o ../obj/customerDataWrite.o ../obj/customerDelete.o ../obj/customerDeleteMap.o ../obj/customerExtractData.o ../obj/customerManage.o ../obj/customerUpdate.o ../obj/requestAdd.o ../obj/requestClass.o ../obj/requestDataWrite.o ../obj/requestDelete.o ../obj/requestDisplayReport.o ../obj/requestExtractData.o ../obj/requestFinalReport_1.o ../obj/requestFinalReport_2.o ../obj/requestFinalReport_3.o ../obj/requestFinalReport_4.o ../obj/requestManage.o ../obj/requestTotalCount.o ../obj/requestUpdate.o -o ../bin/crm

customer.o:
	g++ -c ../src/customerFiles/customerAdd.cpp -o ../obj/customerAdd.o	
	g++ -c ../src/customerFiles/customerClass.cpp -o ../obj/customerClass.o
	g++ -c ../src/customerFiles/customerDataWrite.cpp -o ../obj/customerDataWrite.o
	g++ -c ../src/customerFiles/customerDelete.cpp -o ../obj/customerDelete.o
	g++ -c ../src/customerFiles/customerDeleteMap.cpp -o ../obj/customerDeleteMap.o
	g++ -c ../src/customerFiles/customerExtractData.cpp -o ../obj/customerExtractData.o
	g++ -c ../src/customerFiles/customerManage.cpp -o ../obj/customerManage.o
	g++ -c ../src/customerFiles/customerUpdate.cpp -o ../obj/customerUpdate.o
	
request.o:
	g++ -c ../src/requestFiles/requestAdd.cpp -o ../obj/requestAdd.o	
	g++ -c ../src/requestFiles/requestClass.cpp -o ../obj/requestClass.o
	g++ -c ../src/requestFiles/requestDataWrite.cpp -o ../obj/requestDataWrite.o
	g++ -c ../src/requestFiles/requestDelete.cpp -o ../obj/requestDelete.o
	g++ -c ../src/requestFiles/requestDisplayReport.cpp -o ../obj/requestDisplayReport.o
	g++ -c ../src/requestFiles/requestExtractData.cpp -o ../obj/requestExtractData.o
	g++ -c ../src/requestFiles/requestFinalReport_1.cpp -o ../obj/requestFinalReport_1.o
	g++ -c ../src/requestFiles/requestFinalReport_2.cpp -o ../obj/requestFinalReport_2.o
	g++ -c ../src/requestFiles/requestFinalReport_3.cpp -o ../obj/requestFinalReport_3.o
	g++ -c ../src/requestFiles/requestFinalReport_4.cpp -o ../obj/requestFinalReport_4.o
	g++ -c ../src/requestFiles/requestManage.cpp -o ../obj/requestManage.o
	g++ -c ../src/requestFiles/requestTotalCount.cpp -o ../obj/requestTotalCount.o
	g++ -c ../src/requestFiles/requestUpdate.cpp -o ../obj/requestUpdate.o

main.o: 
	g++ -c ../src/main.cpp -o ../obj/main.o

clean:
	rm -rf .././obj/*.o .././bin/*

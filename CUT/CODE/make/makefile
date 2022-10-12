
SRC =../src
SRC1 = ../src/customerFiles
SRC2 = ../src/requestFiles
BIN =../bin
OBJ =../obj
RM = rm *.o
GCC = g++
CFLAGS = -c
LFLAGS = -o
INC=../include
IFLAGS=-I $(INC)




crm: customer.o request.o main.o 
	$(GCC) $(OBJ)/main.o $(OBJ)/customerAdd.o $(OBJ)/customerClass.o $(OBJ)/customerDataWrite.o $(OBJ)/customerDelete.o $(OBJ)/customerDeleteMap.o $(OBJ)/customerExtractData.o $(OBJ)/customerManage.o $(OBJ)/customerUpdate.o $(OBJ)/requestAdd.o $(OBJ)/requestClass.o $(OBJ)/requestDataWrite.o $(OBJ)/requestDelete.o $(OBJ)/requestDisplayReport.o $(OBJ)/requestExtractData.o $(OBJ)/requestFinalReport_1.o $(OBJ)/requestFinalReport_2.o $(OBJ)/requestFinalReport_3.o $(OBJ)/requestFinalReport_4.o $(OBJ)/requestManage.o $(OBJ)/reqDatabase.o $(OBJ)/requestUpdate.o $(LFLAGS) ../bin/crm

customer.o:
	$(GCC) $(CFLAGS) $(SRC1)/customerAdd.cpp $(LFLAGS) $(OBJ)/customerAdd.o	$(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerClass.cpp $(LFLAGS) $(OBJ)/customerClass.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerDataWrite.cpp $(LFLAGS) $(OBJ)/customerDataWrite.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerDelete.cpp $(LFLAGS) $(OBJ)/customerDelete.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerDeleteMap.cpp $(LFLAGS) $(OBJ)/customerDeleteMap.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerExtractData.cpp $(LFLAGS) $(OBJ)/customerExtractData.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerManage.cpp $(LFLAGS) $(OBJ)/customerManage.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC1)/customerUpdate.cpp $(LFLAGS) $(OBJ)/customerUpdate.o $(IFLAGS)
	
request.o:
	$(GCC) $(CFLAGS) $(SRC2)/requestAdd.cpp $(LFLAGS) $(OBJ)/requestAdd.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestClass.cpp $(LFLAGS) $(OBJ)/requestClass.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestDataWrite.cpp $(LFLAGS) $(OBJ)/requestDataWrite.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestDelete.cpp $(LFLAGS) $(OBJ)/requestDelete.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestDisplayReport.cpp $(LFLAGS) $(OBJ)/requestDisplayReport.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestExtractData.cpp $(LFLAGS) $(OBJ)/requestExtractData.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestFinalReport_1.cpp $(LFLAGS) $(OBJ)/requestFinalReport_1.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestFinalReport_2.cpp $(LFLAGS) $(OBJ)/requestFinalReport_2.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestFinalReport_3.cpp $(LFLAGS) $(OBJ)/requestFinalReport_3.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestFinalReport_4.cpp $(LFLAGS) $(OBJ)/requestFinalReport_4.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestManage.cpp $(LFLAGS) $(OBJ)/requestManage.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/reqDatabase.cpp $(LFLAGS) $(OBJ)/reqDatabase.o $(IFLAGS)
	$(GCC) $(CFLAGS) $(SRC2)/requestUpdate.cpp $(LFLAGS) $(OBJ)/requestUpdate.o $(IFLAGS)

main.o: 
	$(GCC) $(CFLAGS) $(SRC)/main.cpp $(LFLAGS) $(OBJ)/main.o $(IFLAGS)

clean:
	rm -rf $(OBJ)/*.o $(BIN)/*

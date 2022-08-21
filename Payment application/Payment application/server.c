#include "Server.h"

ST_accountsDB_t accounts[255] = {
	{2000.0,RUNNING,"2564856474123698"},
	{51313.2,BLOCKED,"6214785236541234"},
	{7851.5,RUNNING,"9874562155476666"},
	{6848.55,RUNNING,"9856412766572214"},
	{97451.56,BLOCKED,"9654775211443365"},
	{2874.9,BLOCKED,"2356821478652324"},
	{978485.0,BLOCKED,"9632547812435547"},
	{1000.0,RUNNING,"96324587132365"},
	{25.5,BLOCKED,"68741236985452"},
	{9851.1,RUNNING,"99558824446663"},
};



EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	printf("hi shehab");
	return APPROVED;
}

EN_serverError_t isValidAccount(ST_CardData_t cardData, ST_accountsDB_t accountRefrence)
{
	return SERVER_OK;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	return SERVER_OK;
}

EN_serverError_t isAmountAvailabe(ST_terminalData_t* termData)
{
	return SERVER_OK;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	return SERVER_OK;
}

EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	return SERVER_OK;
}


int main()

{
	ST_transaction_t* t = malloc(sizeof(t));

	recieveTransactionData(t);

}
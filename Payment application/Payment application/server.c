#include "Server.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>


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

//accounts[1] = { {2000.0,RUNNING,"2564856474123698"} };

ST_transaction_t transaction[255] = {0,0,DECLINED_INSUFFECIENT_FUND,0};

//bool account_found(ST_transaction_t* transData, ST_accountsDB_t arr[]) {
//	for (int i = 1; i < 255; i++)
//	{
//		if (arr[i].PAN==transData->cardHolderData.PAN);
//			return true;
//	}
//	return false;
//};

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	//if (transData->cardHolderData.PAN==accounts[0].PAN)            // first if doesn't work//////////////
	//{
	//	float account_amount 
	//	if(isBelowMaxAmount(transData) || transData->terminalData.transAmount> transData.)
	//}

	return FRAUD_CARD;
}

EN_serverError_t isValidAccount(ST_CardData_t cardData, ST_accountsDB_t accountRefrence)
{

	if (cardData.PAN == accountRefrence.PAN) {         // first if doesn't work//////////////
		printf("found");
	}
	printf("not found");

	return ACCOUNT_NOT_FOUND;
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
	ST_CardData_t* t = malloc(sizeof(t));
	*t->PAN = "2564856474123698";
	/*printf("%s", (const char*)t->cardHolderData.PAN);*/
	//recieveTransactionData(t);
	isValidAccount(*t, accounts[0]);
}
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

int index;      // gets needed account index in DB
int trans = 0;


ST_transaction_t transactions[255] = {0,0,DECLINED_INSUFFECIENT_FUND,0};


//Done
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	if (isValidAccount(transData->cardHolderData,accounts)== SERVER_OK)         
	{

		if (isBelowMaxAmount(transData) == EXCEED_MAX_AMOUNT || transData->terminalData.transAmount > accounts[index].balance) {
			return DECLINED_INSUFFECIENT_FUND;
		}
		else if (isBlockedAccount(accounts) == BLOCKED_ACCOUNT) {
			return DECLINED_STOLEN_CARD;
		}
		else if (saveTransaction(transData)   == SAVING_FAILED)     
		{
			return INTERNAL_SERVER_ERROR;
		}
		else {
			return APPROVED;
		}
	}
	else {
		return FRAUD_CARD;
	}
};



//Done
EN_serverError_t isValidAccount(ST_CardData_t cardData, ST_accountsDB_t* accountRefrence)
{

	for (int i = 0; i < 255; i++)
	{
		if (strcmp(cardData.PAN, accountRefrence[i].PAN) == 0) {      
			index = i;
			printf("found");
			return SERVER_OK;
		}
	}
		printf("not found");

		return ACCOUNT_NOT_FOUND;
	
};


//Done
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence[index].state == BLOCKED) {
		return BLOCKED_ACCOUNT;
	}
	else
	{
		return SERVER_OK;
	}

};


//Done
EN_serverError_t isAmountAvailabe(ST_terminalData_t* termData)
{
	if (termData->transAmount > accounts[index].balance) {
		return LOW_BALANCE;
	}
	else
	{
		return SERVER_OK;
	}
};


//Done
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	// Saving transaction data to transactions DB
	transactions[trans].cardHolderData = transData->cardHolderData;
	transactions[trans].terminalData = transData->terminalData;
	transactions[trans].transState = transData->transState;

	// Giving a sequence number to a transaction
	if (trans == 0)
	{
		transData->transactionSequenceNumber = 1;
	}
	else
	{
		transData->transactionSequenceNumber = (transactions[index - 1].transactionSequenceNumber + 1);
	}
	// Saving sequnce number
	transactions[index].transactionSequenceNumber = transData->transactionSequenceNumber;

	trans++;

	// Checking if the transaction is saved
	if (getTransaction(transData->transactionSequenceNumber, transData) == TRANSACTION_NOT_FOUND)
	{
		return SAVING_FAILED;
	}
	else
	{
		return SERVER_OK;
	}
};


//Done
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	for (int i = 0; i < 255; i++)
	{
		if (transData->transactionSequenceNumber == transactions[i].transactionSequenceNumber) {
			printf("Transaction data is at index %d in the transactions DB.", i);
			return SERVER_OK;
		}
	}
	return TRANSACTION_NOT_FOUND;
}; 

int main()

{
	ST_CardData_t* t = malloc(sizeof(t));

	// isValidAccount function test
	
	//printf("entering valid account\n");
	//strcpy(t->PAN, "2564856474123698");
	//isValidAccount(*t, accounts);
	//printf("entering invalid account\n");
	//strcpy(t->PAN, "4444");
	//isValidAccount(*t, accounts);

}
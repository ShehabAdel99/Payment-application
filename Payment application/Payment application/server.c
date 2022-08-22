#include "Server.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

// Creating a valid initialized accounts DB
ST_accountsDB_t accounts[255] = {
	{2000.0,RUNNING,"2564856474123698"},
	{5313.2,BLOCKED,"6214785236541234"},
	{7851.5,RUNNING,"9874562155476666"},
	{6848.55,RUNNING,"9856412766572214"},
	{9741.56,BLOCKED,"9654775211443365"},
	{2874.9,BLOCKED,"2356821478652324"},
	{9785.0,BLOCKED,"9632547812435547"},
	{1000.0,RUNNING,"96324587132365"},
	{25.5,BLOCKED,"68741236985452"},
	{9851.1,RUNNING,"99558824446663"},
};


// Creating a valid initialized accounts DB
ST_transaction_t transactions[255] = { 0,0,DECLINED_INSUFFECIENT_FUND,0 };


int index;      // gets needed account index in DB
int trans = 0;  // identifies the index of the transaction in transactions DB


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	//// Check Account Validation
	if (isValidAccount(transData,accounts)== SERVER_OK)         
	{

		////Check if it is Blocked
		if (isBlockedAccount(accounts) == BLOCKED_ACCOUNT) {
			return DECLINED_STOLEN_CARD;
		}
		
		//// Check if the amount is available
		if (isBelowMaxAmount(transData) == EXCEED_MAX_AMOUNT || isAmountAvailabe(transData)== LOW_BALANCE) {
			return DECLINED_INSUFFECIENT_FUND;
		}
		//else
		//{
		//                                                    /*just for testing*/
		//	printf("Amount Accepted\n");     
		//}

		////Check if the transaction was saved
		if (saveTransaction(transData)   == SAVING_FAILED)     
		{
			return INTERNAL_SERVER_ERROR;
		}
		else 
		{

			////Updating DB with the new balance
			accounts[index].balance = accounts[index].balance - transData->terminalData.transAmount;
			//printf("Transaction Data was Recieved successfully\n");               //just for testing
			return APPROVED;
		}
	}
	else {
		//printf("Transaction Data was NOT Recieved  ( FRAUD CARD )\n");               //just for testing
		return FRAUD_CARD;
	}
};



EN_serverError_t isValidAccount(ST_CardData_t *cardData, ST_accountsDB_t *accountRefrence)
{

	for (int i = 0; i < 255; i++)
	{

		// Searching for the card PAN in the accounts DB
		if (strcmp(cardData->PAN, accountRefrence[i].PAN) == 0) {  

			index = i;               //Saving the index of the found account from DB to a global variable to be used throw code

			//printf("Valid Account\n");      //just for testing

			return SERVER_OK;
		}
	}
		//printf("ACCOUNT NOT FOUND\n");      //just for testing

		return ACCOUNT_NOT_FOUND;
	
};



EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence[index].state == BLOCKED) {

		//printf("BLOCKED ACCOUNT\n");        //just for testing
		return BLOCKED_ACCOUNT;
	}
	else
	{
		//printf("NOT BLOCKED ACCOUNT\n");      //just for testing
		return SERVER_OK;
	}

};



EN_serverError_t isAmountAvailabe(ST_terminalData_t* termData)
{
	if (termData->transAmount > accounts[index].balance) {
		//printf("LOW BALANCE\n");        //just for testing
		return LOW_BALANCE;
	}
	else
	{
		//printf("Sufficient balance\n");        //just for testing
		return SERVER_OK;
	}
};



EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	//// Saving transaction data to transactions DB
	transactions[trans].cardHolderData = transData->cardHolderData;
	transactions[trans].terminalData = transData->terminalData;
	transactions[trans].transState = transData->transState;

	//// Giving a sequence number to a transaction
	if (trans == 0)
	{
		transData->transactionSequenceNumber = 1;
	}
	else
	{
		transData->transactionSequenceNumber = (transactions[trans - 1].transactionSequenceNumber + 1);
	}
	//// Saving sequnce number
	transactions[trans].transactionSequenceNumber = transData->transactionSequenceNumber;

	trans++; // Move to the next index in Transactions DB

	//// Checking if the transaction is saved
	if (getTransaction(transData->transactionSequenceNumber, transData) == TRANSACTION_NOT_FOUND)
	{
		//printf("SAVING FAILED\n");        //just for testing
		return SAVING_FAILED;
	}
	else
	{
		//printf("SAVING SUCCEEDED\n");        //just for testing
		return SERVER_OK;
	}
};



EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
	for (int i = 0; i < 255; i++)
	{
		if (transData->transactionSequenceNumber == transactions[i].transactionSequenceNumber) {
			printf("Transaction data is at index %d in the transactions DB.\n", i);
			return SERVER_OK;
		}
	}
	//printf("TRANSACTION NOT FOUND\n");          //just for testing
	return TRANSACTION_NOT_FOUND;
}; 

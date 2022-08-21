#include "server.h"

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

ST_accountsDB_t accounts[255];

void filling() {
	accounts[0].balance = 5475;
	printf("%f", accounts[0].balance);

}

int main() {

	filling();
	return 0;
}


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
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

#ifndef server
#define server

//#include "D:\Git\Payment-application\Payment application\Payment application/Card.h"
#include "D:\Git\Payment-application\Payment application\Payment application/Terminal.h"

typedef enum EN_transState
{
    APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, FRAUD_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError
{
    SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE, BLOCKED_ACCOUNT

}EN_serverError_t;

typedef enum EN_accountState
{
    RUNNING, BLOCKED
}EN_accountState_t;

typedef struct ST_transaction
{
    ST_CardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;

}ST_transaction_t;

typedef struct ST_accountsDB
{
    float balance;
    EN_accountState_t state;
    uint8_t PAN[20];


}ST_accountsDB_t;

EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_CardData_t cardData, ST_accountsDB_t *accountRefrence);
EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence);
EN_serverError_t isAmountAvailabe(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);
#endif

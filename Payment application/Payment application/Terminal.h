#ifndef TERMINAL
#define TERMINAL


#include "D:\Git\Payment-application\Payment application\Payment application/Card.h"


typedef enum EN_TerminalError
{

    TERMINAL_OK,WRONG_DATE,EXPIRED_CARD,INVALID_CARD,INVALID_AMOUNT,EXCEED_MAX_AMOUNT,INVALID_MAX_AMOUNT
}EN_TerminalError_t;





typedef struct terminal
{
    float transAmount ;
    float MaxTrasAmount;
    uint8_t transactionDate[11];

}ST_terminalData_t;


EN_TerminalError_t getTransactionDate(ST_terminalData_t *termData);
EN_TerminalError_t isCardExpired (ST_CardData_t *CardData, ST_terminalData_t *termData);
EN_TerminalError_t SetMaxAmount (ST_terminalData_t *termData);
EN_TerminalError_t isBelowMaxAmount (ST_terminalData_t *termData);



#endif
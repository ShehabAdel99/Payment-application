#include "Terminal.h"

EN_TerminalError_t getTransactionDate(ST_terminalData_t *termData)

{
 
    printf("Enter the Transaction Date\n");
    scanf_s("%s",termData ->transactionDate);


    if ((sizeof (termData ->transactionDate)> 11*sizeof(uint8_t))||
    (sizeof (termData ->transactionDate))<10*sizeof(uint8_t)||
    termData->transactionDate ==NULL ||
    termData->transactionDate[2] !='/' ||  //checking for the format
    termData->transactionDate[5] !='/'  || //checking for the format
    ((termData->transactionDate[3] - '0') * 10 + (termData->transactionDate[4]- '0'))> 12||  //checking for a wrong month
    ((termData->transactionDate[0] - '0') * 10 + (termData->transactionDate[1]- '0'))> 31 ||   //checking for a wrong date
      ((termData->transactionDate[6] - '0') * 1000+(termData->transactionDate[7] - '0') * 100 +(termData->transactionDate[8] - '0') * 10 + (termData->transactionDate[9]- '0')) <2000//assuming the user enter only date after 2000

    )

    {
        printf("wrong date\n");
        return WRONG_DATE;
    }


    else 
    {
        printf("k inside f1\n");
        return TERMINAL_OK;
    }

}

 

EN_TerminalError_t isCardExpired (ST_CardData_t *CardData, ST_terminalData_t *termData)
{
        //same year diff month


 if((((( termData->transactionDate[8] - '0') * 10 + (termData->transactionDate[9]- '0'))== ((CardData->CardExpiryDate[3] - '0')*10 +(CardData->CardExpiryDate[4] - '0'))) &&

      (((termData->transactionDate[3] - '0') * 10 + (termData->transactionDate[4]- '0'))>((CardData->CardExpiryDate[0] - '0')*10 +(CardData->CardExpiryDate[1] - '0'))))||

       ((termData->transactionDate[8] - '0') * 10 + (termData->transactionDate[9]- '0'))>((CardData->CardExpiryDate[3] - '0')*10 +(CardData->CardExpiryDate[4] - '0'))

  )
 {
   printf("exp");
   return EXPIRED_CARD; 

 } 

else 
{
    printf("ok");
    return TERMINAL_OK;
}
}
 
EN_TerminalError_t SetMaxAmount (ST_terminalData_t *termData)
{
   
   
    termData -> MaxTrasAmount = 5000.0;
    if ( termData -> MaxTrasAmount <=0) return INVALID_MAX_AMOUNT;
    else return TERMINAL_OK;
}

EN_TerminalError_t isBelowMaxAmount (ST_terminalData_t *termData)
{
    if (termData->transAmount <=  termData -> MaxTrasAmount ) 
    {
        printf("less\n");
        return TERMINAL_OK;
    }
    else 
    {
             printf("more\n");
   
        return EXCEED_MAX_AMOUNT;
    }
}








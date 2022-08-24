#include "Application.h"

int main()
{
    ST_terminalData_t *t=malloc(sizeof(t));
    ST_CardData_t*c = malloc(10*sizeof(c));
    ST_transaction_t* transData =malloc(10*sizeof(transData));


    getCardHolderName(c);
    getExpiryDate(c);
    getCardPAN(c);
    getTransactionDate(t);
  
    printf("Enter the Transaction amount\n");
    scanf("%f", &t->transAmount);

    SetMaxAmount(t);
   
   
    if (isBelowMaxAmount(t) ==EXCEED_MAX_AMOUNT)
    {
        printf("Amount Exceeding Limit");
        
    }


    else{

   if (isCardExpired(c,t)==TERMINAL_OK)
   {

        
    if (isValidAccount(c,accounts)==SERVER_OK && isBlockedAccount(accounts) == SERVER_OK)
    {

           if(isAmountAvailabe(t)==SERVER_OK )
           {    
            recieveTransactionData(transData);
            saveTransaction(transData);

           }
    }



    
}
else {
    printf ("Expired CArd\n");
}
    }
}

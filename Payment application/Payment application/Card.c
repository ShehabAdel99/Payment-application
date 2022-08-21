#include "Card.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>




EN_CardError_t getCardHolderName(ST_CardData_t *cardData)
{ 
    printf("Welcome to our ATM \n");
	printf("Enter Card Holder Name: ");
	scanf("%[^\n]s", cardData->CardHolderName); 
	if (strlen(cardData->CardHolderName)<20||cardData->CardHolderName==NULL)
	{
	    printf("Error..Please enter your full name \n");
	    return WRONG_NAME;
	}
	else 
	{
	    printf("Welcome %s \n ", cardData->CardHolderName); 
	    return CARD_OK;
	}

}
EN_CardError_t getExpiryDate(ST_CardData_t *cardData)
{
  printf("Enter Expiry Date (MM/YY): ");
  scanf("%s", cardData->CardExpiryDate);
  if (strlen(cardData->CardExpiryDate)<5||cardData->CardExpiryDate==NULL|| cardData->CardExpiryDate[2]!='/')
  {
      printf("Error..Please enter your Expire Date in the right format-->(MM/YY)\n");
      return WRONG_EXP_DATE;
  }
  else 
  {
     //
       return CARD_OK;
  }
}
EN_CardError_t getCardPAN(ST_CardData_t *cardData)
{
    printf("Enter Card PAN: ");
	scanf("%s", cardData->PAN);
	if(strlen(cardData->PAN)>19||strlen(cardData->PAN)<16||cardData->PAN==NULL)
	{
	    printf("Error..this's wrong primary account number\n");
	    return WRONG_PAN;
	}
	else
	{
	 printf("Successfull primary account number\n");
	 return CARD_OK;
	}
}

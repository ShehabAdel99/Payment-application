#ifndef CARD
#define CARD

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

typedef struct ST_CardData_t{

uint8_t CardHolderName[25];
uint8_t PAN [20];
uint8_t CardExpiryDate[6];

}ST_CardData_t;

typedef enum EN_CardError
{
    CARD_OK,WRONG_NAME,WRONG_EXP_DATE,WRONG_PAN 
} EN_CardError_t;


#endif 

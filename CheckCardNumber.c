#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    printf("Give me your credit card number: ");
    long long cardNumber = GetLongLong();
    //review: rename to cardNumberLength
    int lengthNumber = floor(log10(cardNumber));// length of card number without 1 digit.
    long long power = pow (10, lengthNumber); //review: rename this one also e.g. currentDivider or so
    
    int sumDigits = 0; //review: rename to digitsSum 
    int firstDigit = 0;
    int secondDigit = 0;
    int i = 0; //review: move this variable inside for loop
    long long curdNumberLeft = 0; //review: cardDigitsLeft (curd -> card) and add comment explaining
    string typeCard = "INVALID"; //review: mb. cardType ?
    
    //check the sum of all digits by Luhn’s algorithm - it's more then nessesary in my task, but let it be.
    
    curdNumberLeft = cardNumber; //restuta is cool, love him - I love him already )))
    for (i = 0; i <= lengthNumber; i += 2)
    {
        firstDigit = curdNumberLeft / power;
        curdNumberLeft = curdNumberLeft - firstDigit * power;
        power = power/10;
        
        if (power >= 1)
        {
            secondDigit = curdNumberLeft / power;
            curdNumberLeft = curdNumberLeft - secondDigit * power;
            
            if (i == 0)
            {
                if (firstDigit == 3 && (secondDigit == 4 || secondDigit == 7))
                    typeCard = "AMEX";
                else if (firstDigit == 5 && secondDigit >=1 && secondDigit <=5)
                    typeCard = "MASTERCARD";
                else if (firstDigit == 4)
                    typeCard = "VISA";
            }
            secondDigit = secondDigit * 2; //review: can be rewritten as secondDigit *= 2;
            power = power / 10;
            
            if (secondDigit > 9)
                //review: explain what is going on here in comments
                secondDigit = secondDigit / 10 + secondDigit - (secondDigit / 10) * 10; //ask Restuta! stupid girl!!!       
        }
        else 
            secondDigit = 0;
            
        sumDigits = sumDigits + firstDigit + secondDigit;
    }
    
    // I need it for checking Luhn’s algorithm only
    //if (sumDigits % 10 > 0)
      // typeCard = "INVALID";

    printf("%s\n", typeCard);
}

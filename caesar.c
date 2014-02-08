#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

//review: it would be nice to have a one line, short comment explaining what this function does
//in this case it could be smth like "encrypts sentence, but it looks like it actually encrypts one character" =)
//so please rename it and add corresponding comment
int encrypt_sentence(int codeChar, int key)//review: codeChar -> charCode
{
    if (codeChar >= 65 && codeChar <= 90)
        return 65 + (codeChar - 65 + key) % 26;  
    else if (codeChar >= 97 && codeChar <= 122)
        return 97 + (codeChar - 97 + key) % 26; 
    else return codeChar;
} 

int main(int argc, string argv[])
{
    
    if (argc != 2 || atoi(argv[1]) < 0)
    {
        printf("Sorry\n"); //=) why not printf("Bye, looser!"); ?
        return 1;
    }
    else 
    {
        int key = atoi(argv[1]);
        string sentence = GetString();
        int n = strlen(sentence);
        for (int i = 0; i < n; i++)
        {
            //translit? really? omg -> facepalm
            //perebrat i zashifrovat! 
            //review: change function name and signature so it would accept char and return char (incapsulatioin bitch)
            sentence[i] = (char)encrypt_sentence((int)sentence[i], key);
        }
        printf("%s\n", sentence);
    }
}

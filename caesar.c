#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int encrypt_sentence(int codeChar, int key)
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
        printf("Sorry\n");
        return 1;
    }
    else 
    {
        int key = atoi(argv[1]);
        string sentence = GetString();
        int n = strlen(sentence);
        for (int i = 0; i < n; i++)
        {
            //perebrat i zashifrovat!
            sentence[i] = (char)encrypt_sentence((int)sentence[i], key);
        }
        printf("%s\n", sentence);
    }
}

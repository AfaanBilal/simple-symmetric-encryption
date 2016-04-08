/*
 *    SIMPLE SYMMETRIC KEY ENCRYPTION
 *    
 *    Author: Afaan Bilal
 *    URL:    https://afaan.ml
 *    
 *    Released under the MIT License
 *    (c) 2015 Afaan Bilal
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_MAX 256
#define KEY_MAX 32

char* encrypt(char*, char*);
char* decrypt(char*, char*);

int main()
{
    char message[MSG_MAX];
    char key[KEY_MAX];
    char *encrypted, *decrypted;
    
    printf("Enter a message (at most %3d characters): ", MSG_MAX);    
    gets(message);
    
    printf("Enter a key     (at most %3d characters): ", KEY_MAX);
    gets(key);
        
    printf("\n\n");
    printf("Message:   %s \n", message);
    printf("Key:       %s \n", key);
    
    encrypted = encrypt(message, key);
    decrypted = decrypt(encrypted, key);
    
    printf("Encrypted: %s\n", encrypted);
    printf("Decrypted: %s\n", decrypted);
    
    getch();
    return 0;
}

char* xor(char* data, char* key, char e)
{
    char* ret;
    int dLen, kLen;
    int i, j;
    
    dLen = strlen(data);
    kLen = strlen(key);
    
    ret = malloc(sizeof(char) * (dLen + 1));
    
    for (i = 0, j = 0; i < dLen; i++, j++)
    {
        if (j == kLen) j = 0;
        if (e == 'e')
        {
            *(ret + i) = (char)( ( (int)*(data + i) ^ (int)*(key + j) ) + (int)'!' );
        }
        else if (e == 'd')
        {
            *(ret + i) = (char)( ( (int)*(data + i) - (int)'!' ) ^ (int)*(key + j) );
        }
    }
    
    *(ret + i) = '\0';
    
    return ret;
}

char* encrypt(char* msg, char* key)
{
    return xor(msg, key, 'e');
}

char* decrypt(char* enc, char* key)
{
    return xor(enc, key, 'd');
}

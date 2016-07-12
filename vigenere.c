/*
 *  Vigenère’s Cipher
 *      - Ronnie Bjørkelund
 *
 *
 *
 * Formula: Ci = (Pi + Kj) % 26
 *
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkArgs(int argc, string argv[]);

string encrypt(string keyword, string plaintext);

int main(int argc, string argv[])
{
    
    if (checkArgs(argc, argv))
        return 1;
    
    
    
    string plaintext = GetString();
    string keyword = argv[1];
    
    printf("%s\n", encrypt(keyword, plaintext));
    
    
    return 0;
}


/*
 * Check if arguments is a single word,
 * exit with error message if not.
 * return 1 if not ok, return 0 if ok
 */
int checkArgs(int argc, string argv[])
{
    if (argc < 2 || argc > 2) {
        
        printf("Error: Caesar expects one single word as argument!\n");
        return 1;
    }
    
    
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        
        if (!isalpha(argv[1][i])) {
            printf("Error: Keyword contains not-alphabetical characters!\n");
            return 1;
        }
        
    }
    
    
    
    return 0;
}

/*
 * This function shifts all characters key spaces.
 *
 */
string encrypt(string keyword, string plaintext) 
{
    
    char c; // encrypted character
    int keywordLen = strlen(keyword);
    int j = 0; // counter for shift array
    int shift[keywordLen];
    
    // make array of shifts
    for (int i = 0; i < keywordLen; i++) {
        if (isupper(keyword[i])) {
            shift[i] = keyword[i] - 65;
        } else if (islower(keyword[i])) {
            shift[i] = keyword[i] - 97;
        } else {
            printf("Error: error is error!\n");
        }
    }
    
  
    
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        
        
        
        if (isalpha(plaintext[i])) {
            
            
            if (isupper(plaintext[i])) {
                c = (((plaintext[i] - 65) + shift[j]) % 26) + 65;
            }
            
            if (islower(plaintext[i])) {
                c = (((plaintext[i] - 97) + shift[j]) % 26) + 97;
            }
            
            plaintext[i] = c;
            
            j = (j + 1) % keywordLen;
        }
        
    }   
    
    return plaintext;
    
}

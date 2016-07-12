/*
 *  Caesar Cipher
 *      - Ronnie Bjørkelund
 *
 *
 *
 * Formula: Ci = (Pi + K) % 26
 *
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int checkArgs(int argc, string argv[]);

string encrypt(int key, string plaintext);

int main(int argc, string argv[])
{
    
    if (checkArgs(argc, argv))
        return 1;
    
    int key = atoi(argv[1]);
    
    string plaintext = GetString();
    
    printf("%s\n", encrypt(key, plaintext));
    
    return 0;
}


/*
 * Check if arguments is a single non-negative integer,
 * exit with error message if not.
 * return 1 if not ok, return 0 if ok
 */
int checkArgs(int argc, string argv[])
{
    if (argc < 2 || argc > 2) {
        
        printf("Error: Caesar expects one non-negative integer as argument!\n");
        return 1;
    }
    
    int argument = atoi(argv[1]);
    
    if (argument < 0) {
        printf("Error: Caesar expects one non-negative integer as argument!\n");
        return 1;
    }
    
    return 0;
}

/*
 * This function shifts all characters key spaces.
 *
 */
string encrypt(int key, string plaintext) 
{
    char c; // encrypted character
    
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                c = (((plaintext[i] - 65) + key) % 26) + 65;
            }
            if (islower(plaintext[i])) {
                c = (((plaintext[i] - 97) + key) % 26) + 97;
            }
            plaintext[i] = c;
        }
    }   
    return plaintext;
}

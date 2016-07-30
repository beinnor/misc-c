/*
* vigcip
* Vignere Cipher tool - (C) Ronnie Bjørkelund 2016
*
* Can read from text files or standard input, then encrypt/decrypt
* with Vigenere Cipher, and output to text file or standard out.
* Totally insecure btw.
*
* Options:
* -i [infile]   Input textfile
* -o [outfile]  Output textfile
* -e            Encrypt
* -d            Decrypt
*
* If run without options, or only either -i or -o,
* standard input and output will be used.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "vigcip.h"

int hasInFile = 0;
int hasOutFile = 0;
int encryptTrue = 0;
int decryptTrue = 0;
char *plaintext;
char *keyword;   // temporary


void assignKeyword(char *optarg)
{
  int keywordLen = strlen(optarg);
  int i;

  

  for (i = 0; i < keywordLen; i++) {
    keyword[i] = optarg[i];
  }
}

int main(int argc, char *argv[])
{

  readOptions(argc, argv);

  if (hasInFile) {
    printf("read from file...\n");
  } else {
    printf("read from stdin...\n");
    readFromStdin(plaintext, sizeof(plaintext));
  }

  if (encryptTrue) {
    printf("encrypt...\n");
    encrypt(keyword, plaintext);
  } else if (decryptTrue) {
    printf("decrypt...\n");
    //decrypt();
  }

  if (hasOutFile) {
    printf("print to file...\n");
  } else {
    printf("print to stdout...\n");
    printf("%s\n", plaintext);
  }


  return 0;
}

void printHelp(void)
{
  printf("Usage:\n");
  printf("  vigcip [options]\n");
  printf("\n");
  printf("Options:\n");
  printf("-i filename : input textfile\n");
  printf("-o filename : output textfile\n");
  printf("-e/-d       : encrypt/decrypt\n");
  printf("-k keyword  : keyword\n");
  printf("-h          : help\n");
  printf("\n");
  printf("If used without options, standard input/output will be used.\n");
}

int readOptions(int argc, char *argv[])
{
  char ch;


  if (argc == 1) {
    printf("No arguments!\n");
    return 0;
  }


  while ((ch = getopt(argc, argv, "i:o:edk:h")) != EOF)
    switch (ch) {
      case 'i':
        printf("Input file: %s\n", optarg);
        hasInFile = 1;
        break;
      case 'o':
        printf("Output file: %s\n", optarg);
        hasOutFile = 1;
        break;
      case 'e':
        printf("Encrypt\n");
        encryptTrue = 1;
        break;
      case 'd':
        printf("Decrypt\n");
        decryptTrue = 1;
        break;
      case 'k':
        printf("Keyword\n");
        assignKeyword(optarg);
      case 'h':
        printHelp();
        return 1;
      default:
        fprintf(stderr, "Try 'vigcip -h' for more information.\n");
        return 1;
    }
    argc -= optind;
    argv += optind;

    return 0;	
}

void readFromStdin(char *text, int length)
{
  printf("Enter your text:\n");
  fgets(text, length, stdin);
}

/*
 * This function shifts all characters key spaces.
 *
 */
int encrypt(char keyword[], char *plaintext)
{

  printf("keywordlen: %zu, plainleng: %zu", strlen(keyword), strlen(plaintext));

    char c; // encrypted character
    int keywordLen = strlen(keyword);
    int i, j = 0; // counter for shift array
    int n;
    int shift[keywordLen];

    // make array of shifts
    for (i = 0; i < keywordLen; i++) {
        if (isupper(keyword[i])) {
            shift[i] = keyword[i] - 65;
        } else if (islower(keyword[i])) {
            shift[i] = keyword[i] - 97;
        } else {
            printf("Error: error is error!\n");
        }
    }



    for (i = 0, n = strlen(plaintext); i < n; i++) {



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

    return 0;

}

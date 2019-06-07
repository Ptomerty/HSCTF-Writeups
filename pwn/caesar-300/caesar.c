#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

void caesar() {
    int i = 0, shift = 0;
    char input[250];
    char s[100], *p;

    printf("Enter text to be encoded: ");
    fgets(input, 250, stdin);


    printf("Enter number of characters to shift: ");
    /* Code from https://stackoverflow.com/a/26583890 */
    while (fgets(s, sizeof(s), stdin)) {
        shift = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer this time: ");
        } else break;
    }

    printf("\nOriginal input:");
    printf(input);

    /* Code from https://stackoverflow.com/a/16374718 */
    while (input[i] != '\0') {
        if (input[i] >= 'A' && input[i]<='Z') {
            char newletter = input[i] - 'A';
            newletter += shift;
            newletter = newletter % 26;
            input[i] = newletter + 'A';
        }
	if (input[i] >= 'a' && input[i]<='z') {
            char newletter = input[i] - 'a';
            newletter += shift;
            newletter = newletter % 26;
            input[i] = newletter + 'a';
        }
        i++;
    }
    printf("Ciphered with a shift of %d: %s", shift, input);
    printf("\nThank you for using the Caesar Cipher Encoder! Be sure to like, comment, and subscribe!\n");
}

void give_flag(char* s) {
    printf("Why, thank you! %s", s);
    char flag[50];
    FILE *flagFile;
    if ((flagFile = fopen("/home/ctfadmin/HSCTF-Problems/caesar/flag","r")) == NULL) {
        printf("Error opening file.");
        return;
    }    
    fscanf(flagFile, "%s", flag);
    printf("Here's a flag: %s\n", flag);
    
}

int main() {
    setbuf(stdout, NULL);
    gid_t gid = getegid();
    setresgid(gid,gid,gid);
    puts("Welcome to the Caesar Cipher Encoder!");
    caesar();
    return 0;
}

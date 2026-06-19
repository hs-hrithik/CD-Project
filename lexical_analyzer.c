#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Keywords list
char keywords[3][10] = {"int", "float", "return"};

// Check keyword
int isKeyword(char word[]) {
    for (int i = 0; i < 3; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char ch, word[20];
    int i = 0;

    printf("Enter code (end input with #):\n");

    while ((ch = getchar()) != '#') {

        // Keyword or Identifier
        if (isalpha(ch)) {
            word[i++] = ch;
            while (isalnum(ch = getchar())) {
                word[i++] = ch;
            }
            word[i] = '\0';
            i = 0;

            if (isKeyword(word))
                printf("Keyword    : %s\n", word);
            else
                printf("Identifier : %s\n", word);
        }

        // Number
        else if (isdigit(ch)) {
            word[i++] = ch;
            while (isdigit(ch = getchar())) {
                word[i++] = ch;
            }
            word[i] = '\0';
            i = 0;

            printf("Number     : %s\n", word);
        }

        // Operators
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '=') {
            printf("Operator   : %c\n", ch);
        }

        // Symbols
        else if (ch == ';' || ch == '(' || ch == ')') {
            printf("Symbol     : %c\n", ch);
        }
    }// pujaaaaaaaaa

    return 0;
}

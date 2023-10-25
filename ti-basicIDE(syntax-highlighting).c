#include <stdio.h>
#include <string.h>

void highlightSyntax(const char *code) {
    const char *keywords[] = {"if", "then", "else", "for", "while", "Input", "Output", "End"};
    const char *operators[] = {"+", "-", "*", "/", "="};

    int i, j;
    int codeLength = strlen(code);
    int inWord = 0;

    for (i = 0; i < codeLength; ++i) {
        if (inWord && (code[i] == ' ' || code[i] == '\t' || code[i] == '\n' || code[i] == '\0')) {
            printf("</span>");
            inWord = 0;
        }

        for (j = 0; j < sizeof(keywords) / sizeof(keywords[0]); ++j) {
            if (strncmp(&code[i], keywords[j], strlen(keywords[j])) == 0) {
                printf("<span style='color: blue;'>%s", keywords[j]);
                i += strlen(keywords[j]) - 1;
                inWord = 1;
                break;
            }
        }

        for (j = 0; j < sizeof(operators) / sizeof(operators[0]); ++j) {
            if (code[i] == operators[j][0]) {
                printf("<span style='color: red;'>%c</span>", code[i]);
                inWord = 1;
                break;
            }
        }

        if (!inWord) {
            printf("%c", code[i]);
        }
    }

    if (inWord) {
        printf("</span>");
    }
}

int main() {
    const char *code = "if x = 5 then\nOutput x\nEnd";

    printf("<pre>");
    highlightSyntax(code);
    printf("</pre>");

    return 0;
}
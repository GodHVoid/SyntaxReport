#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
char *reverse(char s[], int len);
void countUnmatched(char s[], int max, int list[]);
int main(int argc, char *argv[]) {
  int len;               // current line length
  int max;               // max length seen so far
  char line[MAXLINE];    // current input line
  char longest[MAXLINE]; // longest line save

  int NumErrors[5] = {0};

  countUnmatched(line, MAXLINE, NumErrors);
  printf("\nErrors\n");
  printf("Bracket: %d\n", NumErrors[0]);
  printf("Paratency: %d\n", NumErrors[1]);
  printf("Brace: %d\n", NumErrors[2]);
  printf("Single Quote: %d\n", NumErrors[3]);
  printf("Double Qutoe: %d\n", NumErrors[4]);
  return 0;
}
/* Idea: count all unmatched (), {},[],'', and ""
 * how to count error: if the any case is unmatched, count unmatched pair as
 * 1000 Run: total number of unmatched errors as an int array*/
void countUnmatched(char s[], int lim, int NumErrors[]) {

  int c, i;
  // int NumErrors[5] = {0}; // initialize all to zero;
  //
  int balanceBracket = 0;
  int unmatchedBracket = 0;

  int balanceBrace = 0;
  int unmatchedBrace = 0;

  int balancePara = 0;
  int unmatchedPara = 0;

  int balanceSingle = 0;

  int balanceDouble = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
    s[i] = c;

    if (c == '{') {
      balanceBracket++;

    } else if (c == '}') {
      if (balanceBracket > 0) {
        balanceBracket--;
      } else {
        unmatchedBracket++;
      }
    }

    if (c == '[') {
      balanceBrace++;
    } else if (c == ']') {
      if (balanceBrace > 0) {
        balanceBrace--;
      } else {
        unmatchedBrace++;
      }
    }

    if (c == '(') {
      balancePara++;
    } else if (c == ')') {
      if (balancePara > 0) {
        balanceBrace--;
      } else {
        unmatchedPara++;
      }
    }

    if (c == '\'') {
      balanceSingle++;
    }

    if (c == '\"') {
      balanceDouble++;
    }
  }
  // put \0 at the end of \n so when we copy the longest string it will be able
  // to terminate.
  s[i] = '\0';

  if (balanceSingle % 2 != 0) {
    NumErrors[3] = balanceSingle / 2;
  }
  if (balanceDouble % 2 != 0) {
    NumErrors[4] = balanceDouble / 2;
  }
  if (balanceBracket > 0) {
    NumErrors[0] = balanceBracket + unmatchedBracket;
  }

  if (balanceBrace > 0) {
    NumErrors[1] = balanceBrace + unmatchedBrace;
  }

  if (balancePara > 0) {
    NumErrors[2] = balancePara + unmatchedPara;
  }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char passwrd()
{
  char alpha[88] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                    '~', '!', '@', '#', '$', '%', '^', '&', '*', '?', ')', '(', '+', '-', ':', ';', '<', '>', '=', '[', ']', '\\', '_', '|', '}', '{',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  srand(time(0));
  return alpha[rand() % 88];
}

void main()
{
  FILE *btr = NULL;
  int i = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
  char ch, temp = '1';
  char pass[8], pur[60];
  system("cls");
  printf("\t\t========== Welcome To Password Generated Program ==========\n");
  printf("\t Please wait for a while, Password is creating by the password generator...\n");
  while (i < 6)
  {
    ch = passwrd();
    if (temp != ch) // This logic exibhit the repetation of the character.
    {
      if (ch >= 65 && ch <= 90)
      {
        if (c1 < 1 || c5 < 2)
        {
          pass[i] = ch;
          i++;
          c1++;
          c5++;
        }
      }
      else if (ch >= 97 && ch <= 122)
      {
        if (c2 < 1 || c6 < 2)
        {
          pass[i] = ch;
          i++;
          c2++;
          c6++;
        }
      }
      else if (ch >= 33 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch >= 96 || ch >= 123 && ch >= 126)
      {
        if (c3 < 1)
        {
          pass[i] = ch;
          i++;
          c3++;
        }
      }
      else if (ch >= 48 && ch <= 57)
      {
        if (c4 < 1)
        {
          pass[i] = ch;
          i++;
          c4++;
        }
      }
    }
    temp = ch;
  }
  pass[i] = '\0';
  printf("The password is : ");
  puts(pass);
  printf("\nDo you want to use this password for you work?(1 for agree) ");
  scanf("%d", &ch);
  if (ch == 1)
  {
    fflush(stdin);
    printf("Purpose for taking this password(facebook/G-mail/Instagram..) ");
    gets(pur);
    btr = fopen("Password Generator.txt", "a");
    fprintf(btr, "\n\nDate is %s\n", __DATE__);
    fprintf(btr, "Time is %s\n", __TIME__);
    fprintf(btr, "Purpose is %s\n", pur);
    fprintf(btr, "Password is %s", pass);
  }
}
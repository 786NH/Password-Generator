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
  int i = 0, len, *ptr = NULL;
  char ch, temp = '1';
  char pass[8], pur[50];
  system("cls");
  printf("\t\t========== Welcome To Password Generated Program ==========\n");
  printf("\t  Enter the length of the password(4 or 6) : ");
  scanf("%d", &len);
  printf("\t  Please wait for a while, Password is creating by the password generator...\n");
  switch (len)
  {
  case 6:
  {
    ptr = (int *)calloc(len, sizeof(int));
    while (i < 6)
    {
      ch = passwrd();
      if (temp != ch) // This logic exibhit the repetation of the character.
      {
        if (ch >= 65 && ch <= 90)
        {
          if (ptr[0] < 1 || ptr[4] < 2)
          {
            pass[i] = ch;
            i++;
            ptr[0]++;
            ptr[4]++;
          }
        }
        else if (ch >= 97 && ch <= 122)
        {
          if (ptr[1] < 1 || ptr[5] < 2)
          {
            pass[i] = ch;
            i++;
            ptr[1]++;
            ptr[5]++;
          }
        }
        else if (ch >= 33 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch >= 96 || ch >= 123 && ch >= 126)
        {
          if (ptr[2] < 1)
          {
            pass[i] = ch;
            i++;
            ptr[2]++;
          }
        }
        else if (ch >= 48 && ch <= 57)
        {
          if (ptr[3] < 1)
          {
            pass[i] = ch;
            i++;
            ptr[3]++;
          }
        }
      }
      temp = ch;
    }
    free(ptr);
    break;
  }

  case 4:
  {
    ptr = (int *)calloc(len, sizeof(int));
    while (i < 4)
    {
      ch = passwrd();
      if (temp != ch) // This logic exibhit the repetation of the character.
      {
        if (ch >= 65 && ch <= 90)
        {
          if (ptr[0] < 1)
          {
            pass[i] = ch;
            i++;
            ptr[0]++;
          }
        }
        else if (ch >= 97 && ch <= 122)
        {
          if (ptr[1] < 1)
          {
            pass[i] = ch;
            i++;
            ptr[1]++;
          }
        }
        else if (ch >= 33 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch >= 96 || ch >= 123 && ch >= 126)
        {
          if (ptr[2] < 1)
          {
            pass[i] = ch;
            i++;
            ptr[2]++;
          }
        }
        else if (ch >= 48 && ch <= 57)
        {
          if (ptr[3] < 1)
          {
            pass[i] = ch;
            i++;
            ptr[3]++;
          }
        }
      }
      temp = ch;
    }
    free(ptr);
  }
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
    fclose(btr);
  }
}

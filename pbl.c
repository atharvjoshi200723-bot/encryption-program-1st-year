
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt__ceaser__cipher();
int decrypt__ceaser__cipher();

int encrypt__ROT__13();
int decrypt__ROT__13();

int encrypt__vigerene__cipher();
int decrypt__vigerene__cipher();

int encrypt__xor__cipher();
int decrypt__xor__cipher();

int encrypt__atbash__cipher();
int decrypt__atbash__cipher();

int main()
{
    int algo;
    char choice;

    printf("      file encryption and decryption tool.         \n");

    printf("enter what do you want to do ");
    printf("a for encryption ");
    printf("b for decryption\n");
    scanf(" %c", &choice);

    printf("select an algorithm\n");
    printf("1. ceaser cipher\n");
    printf("2. ROT 13\n");
    printf("3. vigerene cipher\n");
    printf("4. xor cipher\n");
    printf("5. atbash cipher\n");

    scanf("%d", &algo);

    if (choice == 'a')
    {
        switch (algo)
        {
            case 1: encrypt__ceaser__cipher(); break;
            case 2: encrypt__ROT__13(); break;
            case 3: encrypt__vigerene__cipher(); break;
            case 4: encrypt__xor__cipher(); break;
            case 5: encrypt__atbash__cipher(); break;
            default: printf("invalid algorithm");
        }
    }
    else if (choice == 'b')
    {
        switch (algo)
        {
            case 1: decrypt__ceaser__cipher(); break;
            case 2: decrypt__ROT__13(); break;
            case 3: decrypt__vigerene__cipher(); break;
            case 4: decrypt__xor__cipher(); break;
            case 5: decrypt__atbash__cipher(); break;
            default: printf("invalid algorithm");
        }
    }
    else
    {
        printf("invalid choice");
    }

    return 0;
}

int encrypt__ceaser__cipher()
{
    char filename[100], ch;

    printf("enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + 3;
            if (ch > 'z')
                ch = ch - 26;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int decrypt__ceaser__cipher()
{
    char filename[100], ch;

    printf("enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 3;
            if (ch < 'a')
                ch = ch + 26;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int encrypt__ROT__13()
{
    char filename[100], ch;

    printf("enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch <= 'm')
                ch = ch + 13;
            else
                ch = ch - 13;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int decrypt__ROT__13()
{
    char filename[100], ch;

    printf("enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            if (ch <= 'm')
                ch = ch + 13;
            else
                ch = ch - 13;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int encrypt__vigerene__cipher()
{
    char filename[100], key[100];
    char ch;
    int i = 0;

    printf("enter file name: ");
    scanf("%s", filename);

    printf("enter key: ");
    scanf("%s", key);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            int shift = key[i] - 'a';
            ch = ch + shift;

            if (ch > 'z')
                ch = ch - 26;

            i++;
            if (key[i] == '\0')
                i = 0;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int decrypt__vigerene__cipher()
{
    char filename[100], key[100];
    char ch;
    int i = 0;

    printf("enter file name: ");
    scanf("%s", filename);

    printf("enter key: ");
    scanf("%s", key);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            int shift = key[i] - 'a';
            ch = ch - shift;

            if (ch < 'a')
                ch = ch + 26;

            i++;
            if (key[i] == '\0')
                i = 0;
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int encrypt__xor__cipher()
{
    char filename[100], ch;
    int key;

    printf("enter file name: ");
    scanf("%s", filename);

    printf("enter key (number): ");
    scanf("%d", &key);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        ch = ch ^ key;
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int decrypt__xor__cipher()
{
    char filename[100], ch;
    int key;

    printf("enter file name: ");
    scanf("%s", filename);

    printf("enter key (number): ");
    scanf("%d", &key);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        ch = ch ^ key;
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int encrypt__atbash__cipher()
{
    char filename[100], ch;

    printf("enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = 'z' - (ch - 'a');
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}

int decrypt__atbash__cipher()
{
    char filename[100], ch;

    printf("enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("file error");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = 'z' - (ch - 'a');
        }
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}
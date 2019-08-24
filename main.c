#include <stdio.h>
#include <process.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#define max 100
#define min 15

/*structure for phonebook*/
struct phonebook
{
    char id[min];
    char fname[min];
    char lname[min];
    char number[min];
    char address[min];
}var[max];
/*sub function*/
/*void search();*/
void color();
void entry();
void menu();

/*main function*/
int main()
{
    color();
    menu();
}
/*function for menu*/
void menu()
{
    int selection;
    printf("                                          [** PHONEBOOK MANAGMENT SYSTEM **]\n\n\n");
    printf("                                               1.CREATE RECORD FILE\n\n");
    printf("                                               2.NEW ENTRY\n\n");
    printf("                                               3.VIEW ENTRY\n\n");
    printf("                                               4.DELETE RECORD FILE\n\n\n ");
    printf("                                             ENTER YOUR SELECTION : (1-3) : ");
    scanf("%d",&selection);
    switch(selection)
    {
    case 1:
        system("cmd /c type nul > phonebook.txt");
        menu();
        break;
    case 2:
        entry();
        break;
    case 3:
        system("cmd /c start notepad phonebook.txt");
        menu();
        break;
    case 4:
        system("cmd /c del /Q phonebook.txt");
        menu();
        break;
    /*case 5:
        search();
        break;*/
    default:
        printf("Invalid Selection");
    }
    getch();
}
/*function for scanf()*/
void entry()
{
    FILE *entry;
    entry = fopen("phonebook.txt","a");
    int input;
    struct phonebook;
    printf("HOW MANY ENTRY DO YOU WANT ? MAX =100: ");
    scanf("%d",&input);
    printf("Example : 01 shahid abdulla 01756852682 mirpur,dhaka\n\n");
    fprintf(entry,"                                                   [** PHONEBOOK MANAGMENT SYSTEM **]\n");
    fprintf(entry,"                                                          [** DATABASE **]\n\n");
    fprintf(entry,"                           [ID]             [F.NAME]            [L.NAME]           [NUMBER]            [ADDRESS]\n\n\n");
    for(int i=1;i<=input;i++)
    {
        scanf("%s%s%s%s%s",var[i].id,var[i].fname,var[i].lname,var[i].number,var[i].address);
    }

    for(int i=1;i<=input;i++)
    {
        fprintf(entry,"%30s%20s%20s%20s%20s\n",var[i].id,var[i].fname,var[i].lname,var[i].number,var[i].address);
    }
    fclose(entry);
    menu();
}
void color()
{
    system("cmd /c color 7C");
}
/*void search()
{
    FILE *entry;
    entry = fopen("phonebook.txt","a");
    printf("%s",*entry);
    fclose(entry);
}*/


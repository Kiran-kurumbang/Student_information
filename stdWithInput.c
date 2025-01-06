#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

void gotoxy(int x, int y);
void menu();
void add();
void view();
void search();
void modify();
void deleterec();

struct student {
    char name[20];
    int stdID;
    char course[20];
    int age;
};

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    gotoxy(15, 8);
    printf("<--:Students Record System:-->\n");
    gotoxy(20, 15);
    printf("Press the any key:- ");
    getch();
    menu();
    return 0;
}

void menu() {
    int choice;
    system("cls");
    gotoxy(10, 3);
    printf("<--:Menu:-->");
    gotoxy(10, 5);
    printf("Enter number to perform the following task:-");
    gotoxy(10, 7);
    printf("1 : Add record.");
    gotoxy(10, 8);
    printf("2 : View record.");
    gotoxy(10, 9);
    printf("3 : Search record.");
    gotoxy(10, 10);
    printf("4 : Modify record.");
    gotoxy(10, 11);
    printf("5 : Delete.");
    gotoxy(10, 12);
    printf("6 : Exit");
    gotoxy(10, 15);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        add();
    } else if (choice == 2) {
        view();
    } else if (choice == 3) {
        search();
    } else if (choice == 4) {
        modify();
    } else if (choice == 5) {
        deleterec();
    } else if (choice == 6) {
        exit(0);
    } else {
        gotoxy(10, 17);
        printf("Invalid Choice.");
    }
}

void add() {
    FILE *fp;
    struct student std;
    char another = 'y';
    system("cls");

    fp = fopen("recordstd.txt", "ab+");
    if (fp == NULL) {
        gotoxy(10, 5);
        printf("Error opening file");
        exit(1);
    }
    
    fflush(stdin);
    while (another == 'y' || another == 'Y') {
        gotoxy(10, 3);
        printf("<--:Add record:-->");
        gotoxy(10, 5);
        printf("Enter details of student.");
        gotoxy(10, 7);
        printf("Enter name: ");
        fgets(std.name, sizeof(std.name), stdin);
        std.name[strcspn(std.name, "\n")] = 0; // Remove newline character if present
        gotoxy(10, 8);
        printf("Enter StudentID: ");
        scanf("%d", &std.stdID);
        fflush(stdin);
        gotoxy(10, 10);
        printf("Enter course: ");
        fgets(std.course, sizeof(std.course), stdin);
        std.course[strcspn(std.course, "\n")] = 0; // Remove newline character if present
        gotoxy(10, 11);
        printf("Enter age: ");
        scanf("%d", &std.age);
        fflush(stdin);
        
        fwrite(&std, sizeof(std), 1, fp);
        
        gotoxy(10, 13);
        printf("Want to add another record? Press 'Y' or 'N': ");
        fflush(stdin);
        another = getch();
        system("cls");
    }
    
    fclose(fp);
    gotoxy(10, 15);
    printf("Press any key to continue.");
    getch();
    menu();
}

void view() {
    FILE *fp;
    int i = 1, j;
    struct student std;
    system("cls");
    gotoxy(10, 3);
    printf("<--:View record:-->");
    gotoxy(10, 5);
    printf("S.No    Name of student     StudentID   Course  Age");
    gotoxy(10, 6);
    printf("-----------------------------------------------------");

    fp = fopen("recordstd.txt", "rb++");
    if (fp == NULL) {
        gotoxy(10, 8);
        printf("Error opening file.");
        exit(1);
    }

    j = 8;
    while (fread(&std, sizeof(std), 1, fp) == 1) {
        gotoxy(10, j);
        printf("%-7d%-22s%-12d%-9s%d",i,std.name,std.stdID,std.course,std.age);
        i++;
        j++;
    }
    
    fclose(fp);
    gotoxy(10, j + 3);
    printf("Press any key to continue.");
    getch();
    menu();
}

void search() {
    FILE *fp;
    struct student std;
    int stdID;
    system("cls");
    gotoxy(10, 3);
    printf("<--Search record:-->");
    gotoxy(10, 5);
    printf("Enter the studentID: ");
    scanf("%d", &stdID);
    
    fp = fopen("recordstd.txt", "rb++");
    if (fp == NULL) {
        gotoxy(10, 6);
        printf("Error opening file.");
        exit(1);
    }

    while (fread(&std, sizeof(std), 1, fp) == 1) {
        if (std.stdID == stdID) {
            gotoxy(10, 8);
            printf("Name: %s", std.name);
            gotoxy(10, 9);
            printf("StudentID: %d", std.stdID);
            gotoxy(10, 10);
            printf("Course: %s", std.course);
            gotoxy(10, 11);
            printf("Age: %d", std.age);
        }
    }

    fclose(fp);
    gotoxy(10, 15);
    printf("Press any key to continue.");
    getch();
    menu();
}

void modify() {
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10, 3);
    printf("<--Modify-->");
    gotoxy(10, 5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    fgets(stname, sizeof(stname), stdin);
    stname[strcspn(stname, "\n")] = 0; // Remove newline character if present

    fp = fopen("recordstd.txt", "rb+");
    if (fp == NULL) {
        gotoxy(10, 6);
        printf("Error opening file.");
        exit(1);
    }
    
    rewind(fp);
    while (fread(&std, sizeof(std), 1, fp) == 1) {
        if (strcmp(stname, std.name) == 0) {
            gotoxy(10, 7);
            printf("Enter name: ");
            fgets(std.name, sizeof(std.name), stdin);
            std.name[strcspn(std.name, "\n")] = 0; // Remove newline character if present
            
            gotoxy(10, 8);
            printf("Enter the ID: ");
            scanf("%d", &std.stdID);
            gotoxy(10, 9);
            printf("Enter course: ");
            fflush(stdin);
            fgets(std.course, sizeof(std.course), stdin);
            std.course[strcspn(std.course, "\n")] = 0; // Remove newline character if present
            
            gotoxy(10, 10);
            printf("Enter age: ");
            scanf("%d", &std.age);
            
            fseek(fp, -sizeof(std), SEEK_CUR);
            fwrite(&std, sizeof(std), 1, fp);
            break;
        }
    }

    fclose(fp);
    gotoxy(10, 15);
    printf("Press any key to continue.");
    getch();
    menu();
}

void deleterec() {
    int stdId;
    FILE *fp, *ft;
    struct student std;
    system("cls");
    gotoxy(10, 3);
    printf("<--Delete record:-->");
    gotoxy(10, 5);
    printf("Enter studentID to delete: ");
    scanf("%d", &stdId);
    
    fp = fopen("recordstd.txt", "rb++");
    if (fp == NULL) {
        gotoxy(10, 6);
        printf("Error opening file.");
        exit(1);
    }
    
    ft = fopen("temp.txt", "wb++");
    if (ft == NULL) {
        gotoxy(10, 6);
        printf("Error opening file.");
        exit(1);
    }

    while (fread(&std, sizeof(std), 1, fp) == 1) {
        if (std.stdID != stdId) {
            fwrite(&std, sizeof(std), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);
    
    remove("recordstd.txt");
    rename("temp.txt", "recordstd.txt");
    
    gotoxy(10, 10);
    printf("Press any key to continue.");
    getch();
    menu();
}

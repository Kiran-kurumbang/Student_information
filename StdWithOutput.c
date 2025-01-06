#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student {
    int stdID;
    char name[20];
    char course[20];
    int age;
} stdr;
void fun(stdr std){ 
    printf("\nStudentID:- %d",std.stdID);
    printf("\nName:- %s",std.name);
    printf("\nCourse:- %s",std.course);
    printf("\nAge:- %d",std.age);
    return;
}
void search(stdr s[],int numStd,int searchID){
    int found =0;//flag to check if std was found
    //loop
    for(int i=0;i<numStd;i++){
        if(s[i].stdID == searchID){
            printf("\n\n===========================================\n\n");
            fun(s[i]); //print std details
            found = 1; //set flag to found
            printf("\n\n===========================================");
            break;
        }
    }
    if(!found){
        printf("\nStudent %d is not found.\n",searchID);
    }
}
void displayMenu(){
    printf("------------------------------------\n\n");
    // stdr kiran;
    // strcpy(kiran.name,"kiran");
    // kiran.stdID=1;
    // kiran.course='A';
    // kiran.age=22;
    int n=8;
    stdr s[]={{202401,"Suzuki","AI",22},
            {202402,"Yamada","AI",18},
            {202403,"Fujiki","WEB",19},
            {202404,"Ishada","WEB",20},
            {202405,"Kiran","ART",20},
            {202406,"Gojo","ART",20},
            {202407,"Toyato","web",21},
            {202408,"Azumz","AI",21}
    };
    
    int numStd=sizeof(s) / sizeof(s[0]);//get num of 
    int choice;
    int searchID;
    while(1){
    //display the menu
    printf("<-------------: STUDENTS RECORD :----------------->\n\n\n");
     printf("\n             Press any key....\n\n\n\n");
     getch();
     printf("***************WELCOME TO NEW STUDENTS*****************\n\n\n");
     printf("               1. View all student\n");
     printf("               2.Search for a student by ID\n\n\n\n");
     printf("Enter your choice:- ");
     scanf("%d",&choice);

     //handle the menu choice
     if(choice == 1){
        //view all std
        for(int i=0;i<n;i++){
            fun(s[i]);
            printf("\n\n------------------------------------\n\n");
        }
     }else if (choice == 2){
        //search
        printf("Enter the studentID:- ");
        scanf("%d",&searchID);
        search(s,numStd,searchID);//call search fun
     }else{
        printf("Invalid ID!!!\n");
     }
    }
}
int main(){
    displayMenu();//call menu
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct student
{
    int id;
    char name[30];
    char dpt[10];
    char section[10];
    char cgpa[10];
    char contact_number[15];
} student;
int main()
{
    int choice;
    do
    {
        printf(" 1. Add Student\n");
        printf(" 2. List of All Students\n");
        printf(" 3. Number of Records\n");
        printf(" 4. Search Student Record\n");
        printf(" 5. Modify Record\n");
        printf(" 0. Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addStudentDetails();
            break;
        case 2:
            printDB();
            break;
        case 3:
            countStudents();
            break;
        case 4:
            findStudent();
            break;
        case 5:
            updateStudent();
            break;
        }
    }
    while(choice!=0);
    return 0;
}
void addStudentDetails()
{
    FILE *fp;
    student *s;
    int num,i;
    printf("\nHow Many Student Want to Add?");
    scanf("%d",&num);
    s = (student*)calloc(num,sizeof(student));
    fp=fopen("StudentDB.txt","w");
    for(i=0; i<num; i++)
    {
        printf("Enter ID: ");
        scanf("%d",&s[i]);
        printf("Enter Name: ");
        fflush(stdin);
        scanf("%[^\n]s",&s[i].name);
        fflush(stdin);
        printf("Enter Department: ");
        gets(s[i].dpt);
        printf("Enter Section: ");
        gets(s[i].section);
        printf("Enter CGPA: ");
//scanf("%f",&s[i].cgpa);
        gets(s[i].cgpa);
        printf("Enter Phone Number: ");
        gets(s[i].contact_number);
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    printf("\nRecord is added Successfully\n");
}
void printDB()
{
    system("cls");
    student s1;
    FILE *fp;
    fp=fopen("StudentDB.txt","r");
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf("\n %-12d%-19s%-14s%-15s%-11s%-16s\n",s1.id,s1.name,s1.dpt,s1.section,s1.cgpa,s1.contact_number);
    }
    fclose(fp);
}
void countStudents()
{
    student s1;
    FILE *fp;
    fp=fopen("StudentDB.txt","r");
    fseek(fp,0,SEEK_END);
    int num = ftell(fp)/sizeof(student);
    printf("\nNumber of Records = %d\n",num);
    fclose(fp);
}
void findStudent()
{
    student s1;
    FILE *fp;
    fp=fopen("StudentDB.txt","r");
    int ID,found=0;
    system("cls");
    printf("Enter ID to search: ");
    scanf("%d",&ID);
//system("cls");
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.id==ID)
        {
            found=1;
            printf(" %-13d%-22s%-12s%-10s%-10s%-10s\n",s1.id,s1.name,s1.dpt,s1.section,s1.cgpa,s1.contact_number);
        }
    }
    if(!found)
    {
        printf("\n Record Not found!\n");
    }
    fclose(fp);
}
void updateStudent()
{
    system("cls");
    student s1;
    FILE *fp,*fp1;
    fp=fopen("StudentDB.txt","r");
    fp1=fopen("temp.txt","w");
    int ID,found=0;
    printf("Enter ID to Modify\n");
    scanf("%d",&ID);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.id==ID)
        {
            found=1;
            printf("enter new name: ");
            fflush(stdin);
            scanf("%[^\n]s",&s1.name);
            fflush(stdin);
            printf("Enter Depertment: ");
            gets(s1.dpt);
            printf("Enter Section: ");
            gets(s1.section);
            printf("Enter CGPA: ");
            gets(s1.cgpa);
            printf("Enter Phone Number: ");
            gets(s1.contact_number);
        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        fp1 = fopen("temp.txt","r");
        fp = fopen("StudentDB.txt","w");
        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
            system("cls");
            printf("\n Record is Modified Successfully.\n");
            fclose(fp);
            fclose(fp1);
        }
    }
    else
    {
        printf("Record is not found!\n");
    }
    fclose(fp);
}


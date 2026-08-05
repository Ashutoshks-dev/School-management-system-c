#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct student{
    char name[50];
    int rollno;
    float cgpa;
    char course[60];


};

struct teachers{
    char name[50];
    char subject[50];
    int id;

};

struct staff{
    char name[50];
    char feild[50];
    int id;

};

void student();
void AddStudent(struct student *s);
void DisplayStudent();
void SearchStudent();
void UpdateStudent();
void DeleteStudent();

void teacher();
void addteacher(struct teachers *s);
void searchteacher();
void Displayteacher();

void staff();
void addstaff();
void displaystaff();


int main(){

    int choice;
    
    printf("===========Main functions========\n");

    printf("1.student\n");
    printf("2.teacher\n");
    printf("3.staff\n");
    printf("4.exit\n");

    printf("Enter a choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Student Menu Selected->\n");
        printf("========================\n");
        student();
        break;

    case 2:
        printf("Teacher Menu selected->\n");
        teacher();
        break;
     
    case 3:
        printf("Staff Menu Selected->\n");
        staff();
        break;
    
    case 4:
        printf("==Thank You For Visiting==");
        break;

    default:
        printf("Invalid Input");
        break;
    }

   
    return 0;
}


void student(void ){
    int choice;

    printf("1.Add Student\n");
    printf("2.Display Student\n");
    printf("3.Search Student\n");
    printf("4.Update Student\n");
    printf("5.Delete Student\n");

    printf("Enter Your Choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:{
        struct student s;
        printf("====Enter Details====\n");
        AddStudent(&s);
        break;
    }
    case 2:
        printf("====STUDENTS====\n");
        DisplayStudent();
        break;

    case 3:
        printf("====Enter Details====\n");
        SearchStudent();
        break;

    case 4:
        printf("====Enter Details====\n");
        UpdateStudent();
        break;

    case 5:
        printf("====Enter Details====\n");
        DeleteStudent();
        break;
    
    default:
        printf("Invalid Input");
        break;
    }

}
void staff(){

    int choice;

    printf("1.Add staff\n");
    printf("2.Display Staff\n");
    

    printf("Enter Your Choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("====Enter Details====\n");
        void addstaff();
        break;

    case 2:
        printf("====Enter Details====\n");
        void displaystaff();
        break;
        
    default:
        printf("Invalid Input");
        break;
    }

}
void AddStudent(struct student *s){
    
    getchar();
    printf("Enter Your Name:");
    fgets(s->name,49,stdin);
    s->name[strcspn(s->name,"\n")]='\0';
    

    printf("Enter Your Roll no:");
    scanf("%d",&s->rollno);

    printf("Enter Your Cgpa:");
    scanf("%f",&s->cgpa);

    printf("Enter Your course:");
    scanf("%s",s->course);

    FILE(*file);
    file = fopen("student.txt","a");

    if (file==NULL)
    {
        printf("File does not exist");
        return;
    }
    

    fprintf(file,"%s  %d  %f  %s \n",s->name,s->rollno,s->cgpa,s->course);
    printf("\n");


    fclose(file);

}
void DisplayStudent(){
    int stud;
    FILE(*file);
    file=fopen("student.txt","r");
    stud=fgetc(file);

    
    if (file==NULL)
    {
        printf("File does not exist");
        return;
    }

    for (int i = 0; stud != EOF; i++)
    {
        printf("%c",stud);
        stud=fgetc(file);
    }
    
    fclose(file);

}
void SearchStudent(){
    int ch;
    int search;
    FILE(*file);
    file=fopen("student.txt","r");
    printf("Enter The Roll no:");
    scanf("%d",&search);

    
    if (file==NULL)
    {
        printf("File does not exist");
        return;
    }

    struct student student;


    while(fscanf(file,"%s %d %f %s",student.name,&student.rollno,&student.cgpa,student.course)==4){

     if (student.rollno == search)
    {
        printf("Name:%s\n",student.name);
        printf("Roll no:%d\n",student.rollno);
        printf("CGPA:%f\n",student.cgpa);
        printf("Coures:%s\n",student.course);
        break;
    }
    }
 fclose(file);
}
void UpdateStudent(){
    int ch;
    int found = 0;
    int search;
    int choice;
    struct student up;
    FILE(*file);
    FILE(*tfile);
    file=fopen("student.txt","r");
    tfile=fopen("temp.txt","w");
    printf("Enter your roll no:");
    scanf("%d",&search);

    
    if (file==NULL || tfile==NULL)
    {
        printf("File does not exist");
        return;
    }

    printf("1.Update Name\n");
    printf("2.Update Roll no\n");
    printf("3.Update CGPA\n");
    printf("4.Update Course\n");

    printf("Enter Your Choice:");
    scanf("%d",&choice);
    
    

    
        

    while (fscanf(file,"%s %d %f %s",up.name,&up.rollno,&up.cgpa,up.course)==4)
    {
        if (search == up.rollno)
        {
           found =1;

           switch (choice)
           {
           case 1:
            printf("New Name:");
            scanf("%s",up.name);
            break;

          case 2:
           printf("New Roll no:");
           scanf("%d",&up.rollno);
           break;

          case 3:
          printf("New Cgpa:");
          scanf("%f",&up.cgpa);
          break;
          
          case 4:
          printf("New Course:");
          scanf("%s",up.course);
          break;
           
           default:
           printf("Invalid Input");
            break;
           }
        }
        
        fprintf(tfile,"%s %d %f %s \n",up.name,up.rollno,up.cgpa,up.course);
    }
    fclose(tfile);
    fclose(file);

    if (found)
    {
        remove("student.txt");
        rename("temp.txt","student.txt"); 
        printf("Updated");
    } else{
        printf("Not found");
    }
    

    
    
    
   

    
}
void DeleteStudent(){

    struct student de;
    FILE(*file);
    FILE(*tfile);
    int roll;
    char verify[10];
    int found =0;
    tfile=fopen("txt.txt","w");
    file=fopen("student.txt","r");

    printf("Enter Roll no :");
    scanf("%d",&roll);

    printf("==Are You Want To Delete (Yes/NO)==\n");
    scanf("%s",verify);



    while (fscanf(file,"%s  %d  %f  %s",de.name,&de.rollno,&de.cgpa,de.course)==4)
    {
        if(de.rollno==roll){
            if (strcmp(verify,"yes")==0 || strcmp(verify,"Yes")==0  || strcmp(verify,"YES")==0 )
            {   found =1;
                continue;
            } if (strcmp(verify,"No")==0 || strcmp(verify,"no")==0  || strcmp(verify,"NO")==0){
                
                fclose(file);
                fclose(tfile);
                return;
            } else{
                printf("Wrong Input");
            }
               
        
            
                
            
        }
            
        
        fprintf(tfile,"%s  %d  %f  %s \n",de.name,de.rollno,de.cgpa,de.course);
    }

    fclose(file);
    fclose(tfile);
    
   
    if (found)
    {
      remove("student.txt");
    rename("txt.txt","student.txt");  
    }else{
    printf("==Student Not Found=="); 
    }
    
    

 
}








void teacher(){
    int choice;

    printf("1.Add Teacher\n");
    printf("2.Display Teacher\n");
    printf("3.Search Teacher\n");

    printf("Enter Your Choice:");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("====Enter Details====\n");
        void addteacher();
        break;

    case 2:
        printf("====Enter Details====\n");
        void displayteacher();
        break;

    case 3:
        printf("====Enter Details====\n");
        void Searchteacher();
        break;

    default:
        printf("Invalid Input");
        break;
    }

    
}

void addteacher(struct teachers *s){
    getchar();
    printf("Enter Your Name:");
    fgets(s->name,49,stdin);
    s->name[strspn(s->name,"\n")]='\0';

}


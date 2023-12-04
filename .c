#include<stdio.h>
#include<conio.h>        //without this also project will run
#include<string.h>
#include<stdlib.h>
struct person   //A structure of type person
{
 //declaration of variables
    char name[51];
    char address[52];
     char father_name[57];
     char mother_name[89];
    long int mble_no;
    char sex[6];
    char mail[79];
    char citision_no[17];

    };
    //declaration of function
    

    
void menu();    /*DISPLAY MAIN MENU*/
void got();
void start();     //It is called on the first time when the script or the code atarts .I have used this to initialize state of our code
void back();      //It is used here for returning
void addrecord(); /*ADDS NEW RECORD */     
void listrecord(); /*FR LISTING THE RECRD*/
void deleterecord();    /*FR DELETING THE RECRD*/
void modifyrecord();  /*FOR MODIFYING THE RECRD*/
int main()
{
    
    system("color 5f");   /*for colouring of the background of screen as we know in c 1f for light blue 2f for green 3f for light blue  4f for red    5f blue  6f yellow*/
start();    //start function called
    return 0;
}
void back()
{
    start();      //start function called
}
void start()    //It is called on the first time when the script or the code atarts .I have used this to initialize state of our code
{
    menu();      //menu function called
}
void menu()   //I have used this because it is a menu driven project
{
    system("cls");   //clearing scren
    
printf("\n\t\t                 **********************TEAM NUMBER 20**********************                  \n\n");

printf("\n\t\t   *********************MADE BY YASH MISHRA AND MEET KUMAR BABARIYA**********************    \n\n");

printf("\n\t\t**********************WELCOME TO MY FIRST PROJECT ON PHONEBOOK APPLICATION**********************\n\n");




printf("\n\n\t\t\t***** MAIN MENU*****\t\t\n\n\n\n");
printf("\t *****1.Add New Record in phonebook***** \n\n\n  ");

printf("\t *****2.List the Records or search records in phonebook *****\n\n\n  ");

printf("\t *****3. Delete the record from phone book ***** \n\n\n ");

printf("\t *****4. Modify the records in phonebook *****\n\n\n");

printf("\t *****5. Exit from Phonebook Application *****\n\n\n");





//switch case

switch(getch())
{
	
	/*FIRST CASE FOR ADDING THE RECORD*/
    case '1':

                addrecord();
    break;
    
    
    /* FOR LISTING THE RECORD*/
   case '2': listrecordorsearchrecord();
    break;
    
    //for deleting the record
    case '3': deleterecord();
    break;
    
    
    
    //for modifying the recrd already saved by the user
    
    case '4': modifyrecord();
    break;


//for coming out of the project
    case '5': exit(0);
    break;
    

    
    
    //if wrong choice is inputted by the user
    default:
                system("cls");
                printf("\n********Enter 1 to 6 only********");
       printf("\n **************ENTER ANY KEY ***********");
	                  getch();

menu();
}
}
//user defined functions
        void addrecord()    //fr adding the recrd
{
        system("cls");     //for clearing the console
        FILE *f;
        struct person p;
        f=fopen("project","ab+");    //opening the project file
        
        
		//inputting users data
        
		printf("\n ********Enter name******** ");
        got(p.name);
        
        printf("\n********Enter the address******** ");
        got(p.address);
        
        printf("\n********Enter father name******** ");
        got(p.father_name);
        
        printf("\n********Enter mother name******** ");
        got(p.mother_name);
 
        printf("\n********Enter phone no.********");
        scanf("%ld",&p.mble_no);
 
        printf("********Enter sex********");
        got(p.sex);
 
        printf("\n********Enter e-mail********");
         got(p.mail);
 
        printf("\n********Enter citizen no********");
        got(p.citision_no);
 
        fwrite(&p,sizeof(p),1,f);

      fflush(stdin);    //It is used here to flush output buffer of the stream .It returns 0 if successful and EOF(end of file) if not successful
 
        printf("\n********record saved********");

fclose(f);  //we have used this fclose() for closing the stream

    printf("\n **************ENTER ANY KEY ***********");

	 getch();
    system("cls");  //for clearing the console
    menu();
}

//user defined function 2 

void listrecordorsearchrecord()
{
    struct person p;
    //declaration of pointers
    FILE *f;
f=fopen("project","rb");     //for opening of the file
if(f==NULL)
{
printf("\n********file opening error in listing ********");


exit(1);   //going out of the program
}
while(fread(&p,sizeof(p),1,f)==1)
{
     printf("\n\n\n ********YOUR RECORD IS********\n\n ");
        printf("\n********Name********=%s\n********Adress********=%s\n********Father name********=%s\n********Mother name********=%s\n********Mobile no********=%ld\n********Sex********=%s\n********E-mail********=%s\n********Citizen no********=%s",p.name,p.address,p.father_name,p.mother_name,p.mble_no,p.sex,p.mail,p.citision_no);

	 getch();
	 system("cls");    //for clearing the console
}
fclose(f);  //for closing the stream
 printf("\n **************ENTER ANY KEY ***********");
 getch();
    system("cls");   //for clearing the console
menu();
}

//user defined function 3
void deleterecord()
{

//declaration of structure

    struct person p;
    //declaration of two pointers
    FILE *f,*ft;
    //declaration of variable and character array
	int flag;
	char name[100];
	f=fopen("project","rb");
    //for the processing coming as contact data is not added yet
	if(f==NULL)
		{

			printf("********CONTACT'S DATA NOT ADDED YET.********");

		}
	else
	{
        //for the case when file cannot be opened
		ft=fopen("temp","wb+");
		if(ft==NULL)

            printf("********file opening error********");
		else

        {
//for if no contact found to delete

		printf("********Enter CONTACT'S NAME:********");
		got(name);

		fflush(stdin);  //we have used here this to flush output after the stream.It will return  0 if it is successfu otherwise it returns eof or feof error
		while(fread(&p,sizeof(p),1,f)==1)
		{
			if(strcmp(p.name,name)!=0)      //to compare the string
				fwrite(&p,sizeof(p),1,ft);    //write function
			if(strcmp(p.name,name)==0)             //to compare the strings
                flag=1;
		}
	fclose(f);  //for closing the file
	fclose(ft);//for closing the file
	
	//if the value f flag variable is false
	
	
	if(flag!=1)
	{
		printf("********NO CONACT'S RECORD TO DELETE.********");
		remove("temp.txt");
	}
		else
		{
            //for removing the record
			remove("project");

			rename("temp.txt","project");
			
			//message sfte recrd is deleted
			
			printf("********RECORD DELETED SUCCESSFULLY.********");

		}
	}
}
 printf("\n **************ENTER ANY KEY ***********");

	 getch();
    system("cls");  //for clearing the console
menu();   //menu function called
}

//user defined function 4
void modifyrecord()
{
    //declaration of variables
    int c;
    //declaration of pointer
    FILE *f;
    int flag=0;
    struct person p,s;
	char  name[50];
	f=fopen("project","rb+");   //opening the file
	if(f==NULL)  //comparing the value of file pointer f
		{

//error message if contact data is not added
			printf("********CONTACT'S DATA NOT ADDED YET.********");
			exit(1);


		}
	else
	{
	    system("cls");  //clearing the sccreen
	    
        //taking input from user to modify the contact name
		
		printf("\n********Enter CONTACT'S NAME TO MODIFY********\n");
            got(name);
            while(fread(&p,sizeof(p),1,f)==1)
            {
                if(strcmp(name,p.name)==0)  //comparing two strings
                {
//taking inputs from user
 

                    printf("\n ********Enter name********");
                    got(s.name);
                    printf("\n********Enter the address********");
                    got(s.address);
                    printf("\n********Enter father name********");
                    got(s.father_name);
                    
					printf("\n********Enter mother name********");
                    got(s.mother_name);
                    
					printf("\n********Enter phone no:********");
                    scanf("%ld",&s.mble_no);
                    
					printf("\n********Enter sex********");
                    got(s.sex);
                    
					printf("\n********Enter e-mail********");
                    got(s.mail);
                    
					printf("\n********Enter citizen no********\n");
                    got(s.citision_no);
                    
					fseek(f,sizeof(p),SEEK_CUR);
                    
					fwrite(&s,sizeof(p),1,f);
                    flag=1;
                    break;



                }
                fflush(stdin);


            }
            
            // checking the value of flag variable s true ornot
            
			if(flag==1)
            {

//if the information is modified

                printf("\n ********your data id modified ********");

            }
            else
            {


//if data is not found

                    printf(" \n ********data is not found********");

            }
            fclose(f);
	}
	 printf("\n **************ENTER ANY KEY ***********");
	 getch();
    system("cls");
	menu();

}
void got(char *name)
{

   int i=0,j;
    char c,ch;
    do
    {
        c=getch();
                if(c!=8&&c!=13)
                {
                    *(name+i)=c;
                        putch(c);
                        i++;
                }
                if(c==8)
                {
                    if(i>0)
                    {
                        i--;
                    }
                   // printf("h");
                    system("cls");
                    for(j=0;j<i;j++)
                    {
                        ch=*(name+j);
                        putch(ch);

                    }

                }
    }while(c!=13);
      *(name+i)='\0';
}

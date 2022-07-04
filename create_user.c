#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include <stdio.h>
#include <libxml/parser.h>

void Main_Menu();
void Get_UserData();
void Create_User();
void BMI_calculator();
void Update();
void View();
void Delete();
void Exit();
void count_nodes();

struct node {
    unsigned char Name[60];
    unsigned int Age;
    unsigned long int PhoneNumber;
    unsigned char Gender[10];
    float Height;
    float Weight;
    unsigned char Password[20];
    unsigned int UID;
    struct node *link;
};
  struct node *head=NULL;

void Main_Menu()
{
    printf("============Main Menu================\n");
    printf("Choose any one of the option\n");
    printf("1.Create User\n");
    printf("2.BMI calculator\n");
    printf("3.Update\n");
    printf("4.View\n");
    printf("5.Delete\n");
    printf("6.View number of data\n");
    printf("7.Exit\n");
    Get_UserData();
}
void Get_UserData()
{
    unsigned int UserChoice;
    scanf("%d",&UserChoice);
    fflush(stdin);
    switch (UserChoice)
    {
        case 1:
            Create_User();
            break;
        case 2:
            BMI_calculator();
            break;
        case 3:
            Update();
            break;
        case 4:
            View();
            break;
        case 5:
            Delete();
            break;
        case 6:
            count_nodes();
            break;
        case 7:
            Exit();
            break;
        default:
            printf("Invalid option Try again");
            Main_Menu();
            break;
    }

}

void Create_User()
{
struct  xml_string{
   unsigned char LUID[10];
   unsigned char LName[20];
   unsigned char LAge[10];
   unsigned char LPhoneNumber[20];
   unsigned char LGender[2];
   unsigned char LHeight[5];
   unsigned char LWeight[5];
   unsigned char LPassword[20];
};
struct xml_string XML_String;
XML_String.LUID;
XML_String.LName;
XML_String.LAge;
XML_String.LPhoneNumber;
XML_String.LGender;
XML_String.LHeight;
XML_String.LWeight;
XML_String.LPassword;

    struct node *user=malloc(sizeof(struct node));
    unsigned char LName[100];
    unsigned int LAge;
    unsigned long int LPhoneNumber;
    unsigned char LGender[10];
    float LHeight;
    float LWeight;
    unsigned char LAPhoneNumber[20];
    unsigned int LUID;
    unsigned char LPassword[20];
    printf("Create_user_called\n");
    printf("Enter the following details:\n");
    
    printf("Enter Your Name:\n");
    scanf("%s",LName);
    strcpy(user->Name,LName);
    if(60<strlen(user->Name))
    {
        printf("Name length exceed Try again\n");
        memset(user->Name,0,sizeof(user->Name));
        Create_User();
    }
    strcpy(XML_String.LName, user->Name);
    printf("Your Name : %s\n",user->Name);
  


    L_Age:  printf("Enter Your Age:\n");
    scanf("%d",&LAge);
    if(LAge>200)
    {
        printf("Invalid Age Try again\n");
        LAge=0;
        goto L_Age;
    }
    user->Age=LAge;
    sprintf(XML_String.LAge,"%d",LAge);

 L_Gender:   printf("Enter Your Gender(M/F):\n");
    scanf("%s",LGender);
    if(!(strcmp(LGender,"M")) || !(strcmp(LGender,"F")))
    {
        strcpy(user->Gender,LGender);
        strcpy(XML_String.LGender,LGender);
    }
    else
    {
        printf("Invalid Input Try again\n");
        memset(LGender,0,sizeof(LGender));
        goto L_Gender;
    }
    

    L_PhoneNumber: printf("Enter Your PhoneNumber:\n");
    scanf("%ld",&LPhoneNumber);
    sprintf(LAPhoneNumber, "%ld", LPhoneNumber);

        if((strlen(LAPhoneNumber))==10)
        {
            user->PhoneNumber=LPhoneNumber;
            sprintf(XML_String.LPhoneNumber,"%ld",LPhoneNumber);
        }
        else
        {
            LPhoneNumber=0;
            printf("Invalid Phone number try again\n");
            memset(LAPhoneNumber,0,sizeof(LAPhoneNumber));
            goto L_PhoneNumber;
        }
    

   L_Height: printf("Enter Your Height in (cms):\n");
    scanf("%f",&LHeight);
    if(LHeight<54 || LHeight>252)
    {
        printf("Invalid Height try again\n");
        LHeight=0;
        goto L_Height;
    }
    user->Height=LHeight;


    sprintf(XML_String.LHeight,"%f",LHeight);
   
    L_Weight:printf("Enter Your Weight in (kg):\n");
    scanf("%f",&LWeight);
    
      if(LWeight<2 || LWeight>636)
    {
        printf("Invalid Weight try again\n");
        LWeight=0;
        goto L_Weight;
    }
    user->Weight=LWeight;
    
    sprintf(XML_String.LWeight,"%f",LWeight);

    L_Password:printf("Enter Your Password:\n");
    scanf("%s",LPassword);
    if(8>(strlen(LPassword)))
    {
        printf("Password length should be greater than 8 and less than 15\n");
        memset(LPassword,0,sizeof(LPassword));
        goto L_Password;
    }
    strcpy(user->Password,LPassword);
    
    strcpy(XML_String.LPassword,LPassword);

    L_rand:   LUID = rand() % 10000 + 1000;
      if(LUID>9999)
      {
        goto L_rand;
      }
      user->UID=LUID;
      sprintf(XML_String.LUID,"%d",LUID);
    
    xml_open();
    add_node(root_element,XML_String.LUID,"user_2",XML_String.LName,XML_String.LAge,XML_String.LGender,XML_String.LPhoneNumber,XML_String.LHeight,XML_String.LWeight,XML_String.LPassword);
    xml_close();
 
    printf("Your Name : %s\n",user->Name);
    printf("Your Age : %d\n",user->Age);
    printf("Your Gender : %s\n",user->Gender);
    printf("Your PhoneNumber : %ld\n",user->PhoneNumber);
    printf("Your Height : %f\n",user->Height);
    printf("Your Weight : %f\n",user->Weight);
    printf("Your Unique ID is  : %d\n",user->UID);
    printf("Your Password is : %s\n",user->Password);
    if(head==NULL)
    {
        head=user;
    }
    else
    {
        user->link=head;
        head=user;
    }
    Main_Menu();

}
void BMI_calculator()
{
    //xml_read();
     struct node *Loop_ptr=NULL;
    unsigned int LUID;
    unsigned char LPassword[20];
    float LHeight;
    float LWeight;
    float BMI;
    printf("BMI_cal_called\n");
    printf("Enter your unique ID : ");
    scanf("%d",&LUID);
    printf("Enter your Password : ");
    scanf("%s",LPassword);
    Loop_ptr=head;
    while(Loop_ptr!=NULL)
    {
        if((Loop_ptr->UID==LUID) && (!(strcmp(Loop_ptr->Password,LPassword))))
        {
            printf("UID and password matched\n");
            LHeight=Loop_ptr->Height;
            LWeight=Loop_ptr->Weight;
         
            printf("Fetched Height %f\n",LHeight);
            LHeight= LHeight*LHeight;
          //  printf("Fetched Height*Height %f\n",LHeight);
            printf("Fetched Weight %f\n",LWeight);
            BMI=(float)((LWeight/LHeight)*10000);
            printf("Your BMI is %f",BMI);
            Loop_ptr=NULL;
            Main_Menu();
        }
        else
        {
            printf("Invalid Username or password try again\n");
            Loop_ptr=Loop_ptr->link;
            Main_Menu();
        }
    }
}
void Update()
{
    printf("Update_user_called\n");
    struct node *Loop_ptr=NULL;
    unsigned char LName[100];
    unsigned int LAge;
    unsigned long int LPhoneNumber;
    unsigned char LGender[10];
    float LHeight;
    float LWeight;
    unsigned char LAPhoneNumber[20];
    unsigned int LUID;
    unsigned char LPassword[20];
    printf("Enter your unique ID : ");
    scanf("%d",&LUID);
    printf("Enter your Password : ");
    scanf("%s",LPassword);
    Loop_ptr=head;
    while(Loop_ptr!=NULL)
    {
        if((Loop_ptr->UID==LUID) && (!(strcmp(Loop_ptr->Password,LPassword))))
        {
            printf("UID and password matched\n");

            L_Name: printf("Enter Your Name to Update:");
            
            scanf("%s",LName);
            
            if(60<strlen(LName))
            {
                printf("Name length exceed Try again\n");
                memset(Loop_ptr->Name,0,sizeof(Loop_ptr->Name));
                goto L_Name;
            }
            strcpy(Loop_ptr->Name,LName);
            
            printf("Your Name : %s\n",Loop_ptr->Name);


            L_Age: printf("Enter Your Age to Update:");
            scanf("%d",&LAge);
            if(LAge>200)
            {
                printf("Invalid Age Try again\n");
                LAge=0;
                goto L_Age;
            }
            
            Loop_ptr->Age=LAge;


            L_Gender:   printf("Enter Your Gender to Update:");
            scanf("%s",LGender);
            if(!(strcmp(LGender,"M")) || !(strcmp(LGender,"F")))
            {
                strcpy(Loop_ptr->Gender,LGender);
            }
            else
            {
                printf("Invalid Input Try again\n");
                memset(LGender,0,sizeof(LGender));
                goto L_Gender;
            }


            L_PhoneNumber: printf("Enter Your PhoneNumber to Update:");
            
            scanf("%ld",&LPhoneNumber);
            
            sprintf(LAPhoneNumber, "%ld", LPhoneNumber);

            if((strlen(LAPhoneNumber))==10)
            {
                Loop_ptr->PhoneNumber=LPhoneNumber;
            }
            else
            {
                LPhoneNumber=0;
                printf("Invalid Phone number try again\n");
                memset(LAPhoneNumber,0,sizeof(LAPhoneNumber));
                goto L_PhoneNumber;
            }


            L_Height: printf("Enter Your Height to Update:");
            scanf("%f",&LHeight);
            if(LHeight<54 || LHeight>252)
            {
                printf("Invalid Height try again\n");
                LHeight=0;
                goto L_Height;
            }
            Loop_ptr->Height=LHeight;

            L_Weight:printf("Enter Your Weight to Update in kg:");
            scanf("%f",&LWeight);

            if(LWeight<2 || LWeight>636)
            {
                printf("Invalid Weight try again\n");
                LWeight=0;
                goto L_Weight;
            }
            Loop_ptr->Weight=LWeight;

            L_Password:printf("Enter Your Password to Update:");
            scanf("%s",LPassword);
            if(8>(strlen(LPassword)))
            {
                printf("Password length should be greater than 8 and less than 15\n");
                memset(LPassword,0,sizeof(LPassword));
                goto L_Password;
            }
            strcpy(Loop_ptr->Password,LPassword);

            if(LWeight<2 || LWeight>636)
            {
                printf("Invalid Weight try again\n");
                LWeight=0;
                goto L_Weight;
            }
            Loop_ptr->Weight=LWeight;
            Loop_ptr=NULL;
            Main_Menu();
        }
        else
        {
            printf("Invalid Username or password try again\n");
            Loop_ptr=Loop_ptr->link;
            Main_Menu();
        }
    }

}
void View()
{
      // xml_read();
    struct node *Loop_ptr=NULL;
    unsigned char LName[100];
    unsigned int LAge;
    unsigned long int LPhoneNumber;
    unsigned char LGender[10];
    float LHeight;
    float LWeight;
    unsigned char LAPhoneNumber[20];
    unsigned int LUID;
    unsigned char LPassword[20];
    printf("View_user_called\n");
    printf("Enter your unique ID : ");
    scanf("%d",&LUID);
    printf("Enter your Password : ");
    scanf("%s",LPassword);
    Loop_ptr=head;
    while(Loop_ptr!=NULL)
    {
        if((Loop_ptr->UID==LUID) && (!(strcmp(Loop_ptr->Password,LPassword))))
        {
            printf("Your Name : %s\n",Loop_ptr->Name);
            printf("Your Age : %d\n",Loop_ptr->Age);
            printf("Your Gender : %s\n",Loop_ptr->Gender);
            printf("Your PhoneNumber : %ld\n",Loop_ptr->PhoneNumber);
            printf("Your Height : %f\n",Loop_ptr->Height);
            printf("Your Weight : %f\n",Loop_ptr->Weight);
            printf("Your Unique ID is  : %d\n",Loop_ptr->UID);
            printf("Your Password is : %s\n",Loop_ptr->Password); 
            Loop_ptr=NULL;
            Main_Menu(); 
        }
        else
        {
            printf("Invalid Username or password try again\n");
         //   Main_Menu();
        }
         Loop_ptr=Loop_ptr->link;

    }
    Main_Menu();
}
void Delete()
{
    struct node *Loop_ptr1=head;
    struct node *Loop_ptr2=head;

    unsigned int LUID;
    unsigned char LPassword[20];
L_Admin:  printf("Enter your unique ID : ");
    scanf("%d",&LUID);
    printf("Enter your Password : ");
    scanf("%s",LPassword);
    if((!(strcmp("qazwsxedc",LPassword))))
    {
        printf("Password Matched\n");
        while(Loop_ptr1!=NULL)
        {
            if(Loop_ptr1->UID==LUID)
            {
                printf("UID Found\n");
                if(Loop_ptr1==Loop_ptr2)
                {
                    head=head->link;
                    free(Loop_ptr1);
                    printf("UID: %d is deleted successfully ",LUID);
                    count_nodes();
                    Main_Menu();
                    count_nodes();
                }
                else
                {
                    Loop_ptr2->link=Loop_ptr1->link;
                    free(Loop_ptr1);
                    printf("UID: %d is deleted successfully\n",LUID);
                    count_nodes();
                    Main_Menu();
                    count_nodes();
                }
            }
 
                Loop_ptr2=Loop_ptr1;
                Loop_ptr1=Loop_ptr1->link;
        //        if(Loop_ptr1==NULL)
         //       {
          //          printf("UID not found try again");
           //         Main_Menu();
            //    }
        

        }    
    }
    else
    {
        printf("Wrong Password Try again\n");
        memset(LPassword,0,sizeof(LPassword));
        LUID=0;
        goto L_Admin;
    }
    
    printf("Delete_user_called\n");

}
void Exit()
{
    exit(0);
}
void count_nodes()
{
    int count=0;
     struct node *ptr=head;
    if(head==NULL)
    {
        printf("Linked list is empty");
    }
    
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("Number of database : %d\n",count);
    Main_Menu();
}


xmlNode * find_node(xmlNode * node, char * name) {
  xmlNode * result;
  
  if (node == NULL) return NULL;
  
  while(node) {
    if((node->type == XML_ELEMENT_NODE) && (strcmp(node->name, name) == 0)) {
      return node;
    }
    if(result = find_node(node->children, name)) return result;
    node = node->next;
  }
  
  return NULL;
}



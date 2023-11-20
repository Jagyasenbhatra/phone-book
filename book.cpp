#include<bits/stdc++.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
struct phonebook
{
    char name[50];
    long long int phoneno;
    char address[50];
    char Email[50];
};
struct login 
{
    char username[10];
    char password[10];
};
void file();
void Login();
void Register();
void group();
void menu();
void Add_new();
void List();
void Update();
void Delete();
void Search();

//main page
int main()
{
  system("color ac");
  system("cls");
  int p1=system("where *password.txt*");
  int p2=system("where *contact_list.txt*");
  if(p1==0&&p2==0)
  {
    Login();
  }
  else 
  {
    file();
    Login();
  }
  system("pause");
  return 0;
}
//file creation page
void file()
{
  system("cls");
  system("type nul>password.txt");
  system("type nul>contact_list.txt");
}
void Login()
{
  struct login p1;
  system("cls");
  FILE *file;
  file=fopen("password.txt","rb+");
  if(file==NULL)
  {
    cout<<"File cannot opned.\n";
  }
  else 
  {
     cout<<"*********************************************************( LOGIN PAGE )************************************************\n";
    char username_1[20];
    char username_2[20];
    char password_1[10];
    char password_2[10];
    cout<<"Username:";
    cin>>username_1;
    cout<<"8 character password:";
    cin>>password_1;
    while(fread(&p1,sizeof(p1),1,file)!=0)
    {
      if(strcmp(p1.username,username_1)==0)
      {
        strcpy(username_2,p1.username);
        strcpy(password_2,p1.password);
        break;
      }
    }
        if(strcmp(username_1,username_2)==0)
        {
          if(strcmp(password_1,password_2)==0)
          {
            cout<<"Login successfully.\n";
            getch();
            group();
          }
          else 
          {
            cout<<"Login failed,incorrect password.\n";
            system("pause");
            Login();
          }
        }
        else 
        {
          cout<<"Invalid username OR Not register yet.\n";
          cout<<"Do you want register ?(y/n)\n";
           switch(getch())
           {
            case 'y':
            Register();
            break;
            case 'Y':
            Register();
            break;
            default:
            Login();
           }
        }
  }
    
}
//REGISTER PAGE
void Register()
{
  struct login p1;
  system("cls");
  FILE *file;
  int flag=0;
  file=fopen("password.txt","ab+");
  if(file==NULL)
  {
    cout<<"File cannot opned.\n";
  }
  else 
  {
     cout<<"*********************************************************( REGISTER PAGE )************************************************\n";
    char ch;
    cout<<"Set Username:";
    cin>>p1.username;
    cout<<"Set 8 character Password:";
    cin>>p1.password;
    fwrite(&p1,sizeof(p1),1,file);
   flag++;
  }
  if(flag==1)
  {
    cout<<"\nSuccessfully register.\n";
    system("pause");
  }
  else 
  {
    cout<<"Not register.\n";
  }
  fclose(file);
  Login();
}
//group page
void group()
{
    system("cls");
    cout<<"  *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n";
    cout<<"                            ( GROUP PROFILE )                          \n";
    cout<<"  *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n";
    // here add your profile details
    system("pause");
    menu();
}
//menu page
void menu()
{
    system("cls");
    cout<<"\n**************************************************************( PHONE BOOK )*********************************************************\n\n";
    cout<<" 1.ADD NEW            2.CONTACT LIST                3.UPDATE               4.DELETE                5.SEARCH                   6.EXIT";
    cout<<"\n\n*************************************************************************************************************************************\n";
    cout<<"\nChose one:\n";
    switch(getch())
    {
        case '1':
        Add_new();
        menu();
        break;
        case '2':
        List();
        menu();
        break;
        case '3':
        Update();
        menu();
        break;
        case '4':
        Delete();
        menu();
        case '5':
        Search();
        menu();
        break;
        case '6':
        exit(0);
        break;
        default:
        cout<<"Invalid Input, choose correct one.\n";
        menu();
    }
}
//ADD NEW
void Add_new()
{
    system("cls");
    struct phonebook s1;
    FILE *file;
    file=fopen("contact_list.txt","ab");
    if(file==NULL)
    {
        cout<<"File cannot opened.\n";
    }
    else
    {
        cout<<"*********************************************************( ADD NEW )************************************************\n";
    char ch='y';
    while(ch=='y'||ch=='Y') 
    {
        cout<<"Enter Name:";
        cin>>s1.name;
        cout<<"Enter Phone No:";
        cin>>s1.phoneno;
        cout<<"Enter address:";
        cin>>s1.address;
        cout<<"Enter Email:";
        cin>>s1.Email;
        fwrite(&s1,sizeof(s1),1,file);
        cout<<"\n\nDo you want to add another record(y/n)\n";
        ch=getch();
    }
   fclose(file);
    }
    
    
}
//LIST
void List()
{
    system("cls");
    struct phonebook s1;
    FILE *file;
    file=fopen("contact_list.txt","rb");
    cout<<"**************************************************************( CONTACT LIST )**********************************************************\n";
   if(file==NULL)
   {
    cout<<"file cannot file\n";
   }
   else
   {
   int flag=0;
   while(fread(&s1,sizeof(s1),1,file)!=0)
   {
    cout<<"Name:"<<s1.name<<endl;
    cout<<"Phone No:"<<s1.phoneno<<endl;
    cout<<"Address:"<<s1.address<<endl;
    cout<<"Email:"<<s1.Email<<endl;
    cout<<endl;
    cout<<"==================================\n\n";
    flag=1;
   }
  if(flag!=1)
  {
    cout<<"Data not added yet.\n";
  }
    fclose(file);
   }
    system("pause");
   
}
//UPDATE
void Update()
{
    system("cls");
    cout<<"*******************************************************************( UPDATE )*********************************************************\n";
    struct phonebook s1;
    char name[50];
    FILE *file,*f;
    int flag=0;
    file=fopen("contact_list.txt","rb+");
    if(file==NULL)
    {
        cout<<"cannot open file\n";
    }
    else
    {
      system("cls");
      cout<<"Enter the name:";
      cin>>name;
      while(fread(&s1,sizeof(s1),1,file)==1)
      {
           if(strcmp(s1.name,name)==0)
           {
            cout<<"Enter name:";
            cin>>s1.name;
            cout<<"Enter phoneno:";
            cin>>s1.phoneno;
            cout<<"Enter address:";
            cin>>s1.address;
            cout<<"Enter Mail:";
            cin>>s1.Email;
            fseek(file,-sizeof(s1),SEEK_CUR);
            fwrite(&s1,sizeof(s1),1,file);
            flag=1;
            break;
           }
           
      }
      if(flag==1)
      {
        cout<<"Record is updated.\n";
      }
      else 
      {
        cout<<"record is not update.\n";
      }
     fclose(file);
    }
    system("pause");
}
//DELETE
void Delete()
{
  /*cout<<"helooooooo.\n";
  system("pause");*/
  system("cls");
	struct phonebook p1;
	char name[100];
	FILE *out,*file;
	int t=system("where temp.txt");
	if(t==0)
	{
		cout<<"file is exist.\n";
    system("cls");
	}
	else 
	{
		system("copy nul>temp.txt");
		cout<<"temp file created.\n";
			system("pause");
	}
	file=fopen("contact_list.txt","rb+");
	out=fopen("temp.txt","ab+");
   cout<<"***********************************************************( DELETE )****************************************************************\n";
	cout<<"\nEnter the name to which you want:\n";
	cin>>name;
	
	while(fread(&p1,sizeof(p1),1,file)!=0)
	{
		if(strcmp(p1.name,name)!=0)
		{
			fwrite(&p1,sizeof(p1),1,out);
		}
	}
	fclose(file);
	fclose(out);
	
	
	remove("contact_list.txt");
	cout<<"contact file is removed.\n";
	system("pause");
	rename("temp.txt","contact_list.txt");
	cout<<"temp rename to contact .\n";
	system("pause");
  
}
//SEARCH page
void Search()
{
    system("cls");
    struct phonebook s1;
    FILE *file;
    file=fopen("contact_list.txt","rb");
    cout<<"***********************************************************( SEARCH )****************************************************************\n";
    if(file==NULL)
    {
        cout<<"cannot open file\n";
    }
    else 
    {
    char name[50];
    int flag;
    cout<<"Enter the name to search:";
    cin>>name;
    while(fread(&s1,sizeof(s1),1,file)!=0)
    {
        if(strcmp(s1.name,name)==0)
        {
            cout<<"Name:"<<s1.name<<endl;
            cout<<"Phone No:"<<s1.phoneno<<endl;
            cout<<"Address:"<<s1.address<<endl; 
            cout<<"Email Id:"<<s1.Email<<endl;
            flag=1;
        }
    }
   fclose(file);
   if(flag==1)
   {
    cout<<"record found.\n";
   }
   else 
   {
    cout<<"record is not found.\n";
   }
    }
    system("pause");
}





  

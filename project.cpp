/* ---------------------------------------PROJECT (BY ABHINAV CHOUDHARY)----------------------------------------------------------*/

//HEADER FILES USED
#include <stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<fstream>
#include <cstdlib>
#include <unistd.h>
//Functions defined
using namespace std; 
void title();          //function for title page
void gotoxy(int,int);  //gotoxy function used to set cursor to a specified position

int x,y,choice,len,xRan,i,sum=0,n,last;  //variables defined
char key[20],c,text[100],option,t;
int main() 
{  
   title();    
 //main program begins....
 label:
 system("cls");
 printf("\nENIGMA MENU...\n1.ENCODE\n2.DECODE\n0.EXIT\nEnter your choice: ");
 scanf("%d",&choice);
 switch(choice)
  { case 1: { ofstream fout;          //opening the file for writing
             fout.open("message.txt",ios::out); 
             printf("\nEnter any key: ");    //inputting the key
             getchar();
             fgets(key,20,stdin);
             len=strlen(key);  //length of the key
             srand(time(NULL));
	         xRan=rand() % len;  //randomly selecting any character from the key
	         c= key[xRan];
	          n=c;   //converting into ASCII
	    while(n>0)
        {
          last = n % 10;          // Obtain Last Digit Of Number
          sum = sum + last;        // Add Obtained Digit to Number
          n = n /10;          // Remove Last Digit From Number
        }
         
     if(sum>=10)
	  { int num=sum;
	       sum=0;
	     while(num>0)
        {
          last = num % 10;          // Obtain Last Digit Of Number
          sum = sum + last;        // Add Obtained Digit to Number
          num = num /10;          // Remove Last Digit From Number
        }
	  }  
       printf("\nEnter the text: ");
        fgets(text,100,stdin);        //inputting the message
        
        len=strlen(text);           //finding the length of the text
        for(i=0;i<len;i++)
        text[i]=text[i]+sum;        //encoding the message using key
        
        printf("\nencoded text is: %s",text);
        fout<<sum<<"\n"<<text<<"\n";
        fout.close();    //closing previously opened file
        printf("\n\nWant to exit? or return to menu(Y:exit,Enter:return to menu): ");
        scanf("%c",&option);
        if(option=='y'||option=='Y')   //exiting
          exit(0);
        else
		  goto label;       //returning to menu if exit is not executed
        break;
    }
    case 2:{
    	 ifstream fin("message.txt",ios::in);    //opening file to read from
        fin.seekg(0);
               fin>>sum;
       i=0;
        while(!fin.eof())               //decoding the message
        { fin>>t;
          text[i]=t-sum;
          i++;
        }
        printf("\ndecoded msg is: %s",text);
        fin.close();            //closing the file
       break;
      }
    case 0: printf("\nEXITING......");   //exiting
	         sleep(1);
			exit(0);
			break;
	default:printf("\nSorry, wrong input");   //default case
	        break;		  
	}
	getch();
	return 0;
}
//function definition
void title()
{gotoxy(60,3);
 sleep(1);
 system("COLOR A");
printf("welcome");
sleep(2);
for(x=1,y=5;y<15;y++)
{ gotoxy(x, y);
system("COLOR C");
printf("E");
}
for(x=1,y=5;x<9;x++)
{ gotoxy(x, y);
  
  system("COLOR A");
  printf("E");
}
for(x=1,y=10;x<9;x++)
{ gotoxy(x, y);
 system("COLOR A");
  printf("E");
 }
 for(x=1,y=15;x<9;x++)
 { gotoxy(x, y);
   system("COLOR A");
   printf("E");
 }
 sleep(1);
 for(x=11,y=15;y>=5;y--)
 { gotoxy(x,y);
   system("COLOR B");
   printf("N");
 }
  for(x=11,y=5;x<=21,y<=15;x++,y++)
 { gotoxy(x,y);
   system("COLOR B");
   printf("N");
 }
  for(x=21,y=15;y>=5;y--)
 { gotoxy(x,y);
   system("COLOR B");
   printf("N");
 }
 sleep(1);
  for(x=23,y=5;x<=32;x++)
 { gotoxy(x,y);
   system("COLOR C");
   printf("I");
 }
  for(x=28,y=5;y<=15;y++)
 { gotoxy(x,y);
   system("COLOR C");
   printf("I");
 }
 for(x=23,y=15;x<=32;x++)
 { gotoxy(x,y);
   system("COLOR C");
   printf("I");
 }
 sleep(1);
 for(x=43,y=5;x>=38;x--)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=38,y=5;x>=31,y<=10;x--,y++)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=32,y=11;x<=38,y<=15;x++,y++)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=37,y=15;x<=43;x++)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=43,y=15;y>10;y--)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=43,y=11;x>=38;x--)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=43,y=11;x<=45;x++)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 for(x=45,y=11;y<=15;y++)
 { gotoxy(x,y);
   system("COLOR D");
   printf("G");
 }
 sleep(1);
 for(x=47,y=15;y>=5;y--)
 { gotoxy(x,y);
   system("COLOR F");
   printf("M");
 }
  for(x=47,y=5;x<=52,y<=10;x++,y++)
 { gotoxy(x,y);
   system("COLOR F");
   printf("M");
 }
  for(x=52,y=10;x<=57,y>=5;x++,y--)
 { gotoxy(x,y);
   system("COLOR F");
   printf("M");
 }
  for(x=57,y=5;y<=15;y++)
 { gotoxy(x,y);
   system("COLOR F");
   printf("M");
 }
 sleep(1);
  for(x=59,y=15;x<=69,y>=5;x++,y--)
 { gotoxy(x,y);
   system("COLOR E");
   printf("A");
 }
  for(x=69,y=5;x<=79,y<=15;x++,y++)
 { gotoxy(x,y);
   system("COLOR E");
   printf("A");
 }
  for(x=64,y=10;x<=74;x++)
 { gotoxy(x,y);
   system("COLOR E");
   printf("A");
 }
 sleep(1);
 gotoxy(1,18);
 system("COLOR 9");
 printf("MINI");
 sleep(1);
 gotoxy(64,18);
 printf("VERSION 1.2.0");
 sleep(1);
 gotoxy(1,20);
 system("COLOR B");
 sleep(1);
 printf("PRESS ANY KEY TO CONTINUE.........................");
 getch(); 
 
}
void gotoxy(int x, int y)               //to set cursor position to a specified point in x-y axis
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
//-----------------------------------------------------END OF PROGRAM-----------------------------------------------------------------------------------------

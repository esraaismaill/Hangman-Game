#include<stdio.h>

#include<stdlib.h>

#include<string.h>

struct word
{

//word size max 100 character

char a[100];

} x[100];

//word x[100];

FILE *fpr, *fpr2;

char c[1], print[100];

int i=0, r, count=0, arr[100], ar=0, life=0;

 void clear ();

void readfile()
{
	int num;
	do
	{
	printf("please enter 1 to start guessing countries or 2 to guess animals:  ");
	scanf("%d",&num);
	clear();
	if(num==1)
	{
   		fpr=fopen("city.txt","r");
    	while (fgets(x[i].a, sizeof(x[i].a), fpr))
   		 {
    	    i++;
      	  count++;
   		 }
   		 	printf("lets start :)\n\n hint: you'll be gussing a country in EGYPT\n\n");
   		 	break;
	}
	else if(num==2)
	{
   		fpr2=fopen("animals.txt","r");
    	while (fgets(x[i].a, sizeof(x[i].a), fpr2))
   		 {
    	    i++;
      	  count++;
   		 }
   		 	printf("lets start :)\n\nyou'll be gussing an animal\n\n");
   		 	break;
	}
	else
	printf("ERROR!\n\n");
}while(num !=1 || num !=2);
	
}

void getr()

{
  do
    {
    r=rand()%10;
} while (r>=count);
    arr[ar]=r;
   
for(int j=0;j<ar;j++)

    {
if (arr[j]==r)
{
getr();
    }
}
}

void clear ()
{
    system("cls");
}

void dash()
{
    char t[1];
    printf("This is the word to be guessed: \n\n");
    for (int j=0;j<strlen(x[r].a)-1;j++)
    {
    printf("_ ");
    }
   printf("\n\nEnter any key to start guessing: ");
   scanf("%s",t);
}

int cong ()
{
    int flag=0;
for(int j=0;j<strlen(print);j++)
    {
    if (print[j]=='_')
    {
    flag=1;
    }
    }
    if (flag==0)
    {
  clear();
    printf("Congratulations :) you Found %s", print);
    ar++;
    return(1);
    }
}

void rchar ();

void check ()
{
    char temp[100];
int flag=0, n;
    strcpy(temp,x[r].a);
    for (int j=0;j<strlen(temp)-1;j++)
{
    if (c[0]==temp[j]||(c[0]-32)==temp[j]||(c[0]+32)==temp[j])
    {
    print[j]=c[0];
    flag=1;
    }
    else if (!((print[j]>='a' && print[j]<='z')||(print[j]>='A' && print[j]<='Z')))
    {
        print[j]='_';
    }
    }
    
    clear();
    printf("This is the word to be guessed: \n\n");
    for(int j=0;j<strlen(print);j++)
    {
    printf("%c ",print[j]);
    }
    n=cong();
    if (n==1 && count!=ar)
    {
    printf("\n\n Next Word:\n");
    for(int j=0;j<strlen(print);j++)
    {
    print[j]=' ';
    }
    getr();
    dash();
    rchar();
}
else if (count==ar)
    {
printf("\n\nEnd of Game");
    }
    char y[1];
    if (count!=ar)
{
    if (flag==0)
    {
   printf("\n\nCharacter Not found: \n");
life++;
if(life==4)
{
clear();
printf("\n\nGAME OVER, you run out of chances, your word is %s\n\n",x[r].a);
printf("please enter any key to exit\n\n");
scanf("%s",y);
}
    if(life!=4)
{
rchar();
}
    }
    else if (flag==1)
    {
    printf("\n\nGood: \n");
    rchar();
    }
}
}

void rchar ()
{
printf("Enter Character: ");
    scanf("%s",c);
    check();
    if (count!=ar)    
    clear();
}

int main ()
{
readfile();
getr();
dash();
clear();
printf("This is the word to be guessed: \n\n");
    for (int j=0;j<strlen(x[r].a)-1;j++)
    {
    printf("_ ");
}
printf("\n\n");
rchar();
fclose(fpr);
return(0);
}

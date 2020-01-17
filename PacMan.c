#include <stdio.h>
#include <windows.h>
#include <string.h>
int move (char map[100][100],int side,int position,int column,int row,int *dots)									//moving as 1 is up, 2 is right, 3 is down, 4 is left
{
	int i=1,j=0,pacman=position;
	while(pacman>column)
	{
		pacman-=column;
		i++;
	}
	j=pacman;
	if (j==0)
	{
		j=column;
		i--;
	}
	if (side==8&&i!=1&&map[i-2][j-1]!='#')
	{
		if (map[i-2][j-1]=='*')
		{
			(*dots)--;
		}
		map[i-2][j-1]='0';
		map[i-1][j-1]='1';
		position-=column;
	}
	if (side==6&&j!=column&&map[i-1][j]!='#')
	{
		if (map[i-1][j]=='*')
			(*dots)--;
		map[i-1][j]='0';
		map[i-1][j-1]='1';
		position++;
	}
	if (side==2&&i!=row&&map[i][j-1]!='#')
	{
		if (map[i][j-1]=='*')
			*dots=*dots-1;
		map[i][j-1]='0';
		map[i-1][j-1]='1';
		position+=column;
	}
	if (side==4&&j!=1&&map[i-1][j-2]!='#')
	{
		if (map[i-1][j-2]=='*')
			*dots=*dots-1;
		map[i-1][j-2]='0';
		map[i-1][j-1]='1';
		position--;
	}
	return position;
}																										//End of moving
void border (char map[100][100],int column,int row)														//making borders & printing map
{
	for (int i=0;i<column+2;i++)
	{
		printf("\033[1;34m");
		putchar(178);
		printf("\033[0m");
	}
	putchar('\n');
	for(int i=0;i<row;i++)
	{
		printf("\033[1;34m");
		putchar(178);
		printf("\033[0m");
		for (int j=0;j<column;j++)
		{
			if (map[i][j]=='1')
				putchar(' ');
			else 
				if (map[i][j]=='0')
				{
					printf("\033[01;33m");
					putchar(2);
					printf("\033[0m");
				}
				else
					if (map[i][j]=='*')
					{
						printf("\033[1;31m");
						putchar(3);
						printf("\033[0m");
					}
					else
					{
						printf("\033[1;34m");
						putchar(178);
						printf("\033[0m");
					}
		}
		printf("\033[1;34m");
		putchar(178);
		printf("\033[0m");
		putchar('\n');
 	}
 	for (int i=0;i<column+2;i++)
	{
		printf("\033[1;34m");
		putchar(178);
		printf("\033[0m");
	}
	putchar('\n');
}																										//End of making borders & printing map
int main ()
{
	repeat:
	printf("  Enter The LEVEL Number For Playing:\n");													//opening the file
	int testcaseNum=0,row=0,column=0,checker=0,checkBlank=0,position=0,sizeOfColumn=0,side=1,dots=0;
	char Adress[100]={'\0'},map[100][100]={'\0'},tmp[1000]={'\0'};
	FILE *test;
	scanf("%d",&testcaseNum);
	if (testcaseNum<10)
		sprintf(Adress,"testcases\\testcase0%d.txt",testcaseNum);
	else
		sprintf(Adress,"testcases\\testcase%d.txt",testcaseNum);
	test=fopen(Adress,"r");
	while(test==NULL)
	{
		system("cls");
		printf("  LEVEL Number %d Is Not Available!\n\n\n  Please Enter Another LEVEL Number:\n",testcaseNum);
		scanf("%d",&testcaseNum);
		Adress[0]='\0';
		if (testcaseNum<10)
			sprintf(Adress,"testcases\\testcase0%d.txt",testcaseNum);
		else
			sprintf(Adress,"testcases\\testcase%d.txt",testcaseNum);
		test=fopen(Adress,"r");
	}																								    //End of opening file
	system("cls");
	while (feof(test)==0)																				//reading file
	{
		fgets(tmp,1001,test);
		for (int i=0;tmp[i]!='\n'&&tmp!='\0'&&row==0;i++)
		{
			if (tmp[i]=='0'||tmp[i]=='1'||tmp[i]=='*'||tmp[i]=='#')	
			{
				sizeOfColumn++;
			}
		}
		column=0;
		checkBlank=0;
		for (checker=0;tmp[checker]!='\n'&&tmp[checker]!='\0';checker++)
		{ 
			if (tmp[checker]=='0'||tmp[checker]=='1'||tmp[checker]=='*'||tmp[checker]=='#')	
			{
				map[row][column++]=tmp[checker];
				checkBlank++;
				if (tmp[checker]=='*')
					dots++;
				if (tmp[checker]=='0')
				{
					position=row*sizeOfColumn+column;
				}
			}
		}
		if (checkBlank)
			row++;
	}																									//End of reading file
	while(dots)
	{
		border(map,column,row);
		printf("\n%d",dots);
		scanf("%d",&side);
		if (side==0) break;
		position=move (map,side,position,column,row,&dots);
		system("cls");
	}
	goto repeat;
}

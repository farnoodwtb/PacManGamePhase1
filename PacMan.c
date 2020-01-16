#include <stdio.h>
#include <windows.h>
#include <string.h>
void border (char map[100][100],int column,int row)														//making borders
{
	for (int i=0;i<column+2;i++)
	putchar(178);
	putchar('\n');
	for(int i=0;i<row;i++)
	{
		putchar(178);
		for (int j=0;j<column;j++)
		{
			if (map[i][j]=='1')
				putchar(' ');
			else 
				if (map[i][j]=='0')
					putchar(2);
				else
					if (map[i][j]=='*')
						putchar(3);
					else
						putchar(178);
		}
		putchar(178);
		putchar('\n');
 	} 
	for (int i=0;i<column+2;i++)
	putchar(178);
	putchar('\n');
}																										//End of making borders
int main ()
{
	repeat:
	printf("  Enter The LEVEL Number For Playing:\n");													//opening the file
	int testcaseNum=0,row=0,column=0,checker=0,checkBlank=0;
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
		column=0;
		checkBlank=0;
		for (checker=0;tmp[checker]!='\n'&&tmp[checker]!='\0';checker++)
		{ 
			if (tmp[checker]=='0'||tmp[checker]=='1'||tmp[checker]=='*'||tmp[checker]=='#')	
			{
				map[row][column++]=tmp[checker];
				checkBlank++;
			}
		}
		if (checkBlank)
			row++;
	}																									//End of reading file
	border(map,column,row);
	sleep(1);
	goto repeat;
}

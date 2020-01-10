#include <stdio.h>
int main ()
{
	printf("  Enter The Testcase Number For Input:\n");													//opening the file
	int testcaseNum=0,row=0,column=0,checker=0;
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
		printf("  Testcase With Number %d Is Not Available!\n\n\n  Please Enter Another Testcase Number:\n",testcaseNum);
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
		for (checker=0;tmp[checker]!='\n'&&tmp[checker]!='\0';checker++)
		{
			if (tmp[checker]=='0'||tmp[checker]=='1'||tmp[checker]=='*'||tmp[checker]=='#')
			map[row][column++]=tmp[checker];
		}
		row++;
	}																									//End of reading file
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			printf("%c  ",map[i][j]);
		printf("\n\n");
	}
}

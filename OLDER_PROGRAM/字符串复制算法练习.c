#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n;
	int i=0;
	int m=0;
	int index=0;
	char *vert;
	char lose[100]={" "};
	printf("������ԭ�ַ����ĳ���:");
	scanf("%d",&n);
	vert= (char*)malloc( n*sizeof(char) );
	if(!vert)
	{
		printf("��������ʧ�ܣ�\n");
		exit(1);
	}
	printf("������ԭ����: \n\n");
//	gets(vert);
	scanf("%s",vert);
	printf("\n\n");	
	printf("��������Ҫ�ӵڼ�λ�ַ���ʼ���Ƹ��ַ���:");
	scanf("%d",&m);	
	for(i=m-1;i<n;i++)
	{
	lose[index]=vert[i];
	index++;
	}
	printf("�㸴�Ƶ��ַ�������:\n\n");
	printf("%s\n\n",lose);
	free(vert);
}
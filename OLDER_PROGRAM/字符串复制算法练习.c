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
	printf("请输入原字符串的长度:");
	scanf("%d",&n);
	vert= (char*)malloc( n*sizeof(char) );
	if(!vert)
	{
		printf("创建数组失败！\n");
		exit(1);
	}
	printf("请输入原数组: \n\n");
//	gets(vert);
	scanf("%s",vert);
	printf("\n\n");	
	printf("请输入你要从第几位字符开始复制该字符串:");
	scanf("%d",&m);	
	for(i=m-1;i<n;i++)
	{
	lose[index]=vert[i];
	index++;
	}
	printf("你复制的字符串如下:\n\n");
	printf("%s\n\n",lose);
	free(vert);
}
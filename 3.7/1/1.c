#include<stdio.h>

int main()
{
	char a[1000];
    int b[10]={0};
    scanf("%s",a);
    for(int i=0;a[i]!='\0';i++)
    {
		int count=a[i]-'0';
		b[count]++;
	}
	for(int j=0;j<10;j++)
	{
		if(b[j]>0)
			printf("%d:%d\n",j,b[j]);
	}
    return 0;
}


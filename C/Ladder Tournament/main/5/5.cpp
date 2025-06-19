#include<bits/stdc++.h>
using namespace std;

int main()
{
	int sum;
	int a[26],b[26];
	char s[1001];
	cin.get(s,1001);
	for(int i=0;i<26;i++)
	{
		cin>>a[i];
		b[i]=0;
	}	
	int j;
	for(j=0;j<1001;j++)
		if(s[j]=='\0') break;
	for(int i=0;i<j;i++)
	{
	    for(char p='a';p<='z';p++)
	    {
			if(s[i]==p)
			{
				b[i]++;
				break;
			}
		}
	}
	for(int i=0;i<26;i++)
	{
		cout<<b[i];
		if(i!=25) cout<<' ';
		sum=sum+a[i]*b[i];
	}
	cout<<endl<<sum;
	return 0;
}
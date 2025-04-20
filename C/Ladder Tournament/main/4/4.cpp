#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m;
	long long x[50];
	x[0]=1;
	for(int i=1;i<50;i++)
	{
		x[i]=x[i-1]*2;
	}
	cin>>n;
	for(int i=49;i>0;i--)
	{
		if(n>x[i])
		{
			m=x[i];
			break;
		}
	}
	cout<<m;
	return 0;
}
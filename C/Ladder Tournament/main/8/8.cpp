#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,k,x[1000],y[1000],max[1000]={0};
	cin>>n>>m>>k;
	int a[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	for(int p=0;p<k;p++)
	{		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]>max[p])
				{
					max[p]=a[i][j];
					x[p]=i;
					y[p]=j;
				}
		for(int i=0;i<n;i++)
			a[i][y[p]]=0;
		for(int i=0;i<m;i++)
			a[x[p]][i]=0;		
	}
	for(int i=0;i<n;i++)
	{
		int f;
		for(f=0;f<k;f++)
		{
			if(y[f]==i) break;
		}
		if(f!=k) break;
		for(int j=0;j<m;j++)
		{
			int l;
			for(l=0;l<k;l++)
			{
				if(x[l]==j) break;
			}
			if(l==k) cout<<a[i][j];
			if(j!=m-1&&l==2) cout<<" ";
		}
		
		if(f==k) cout<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T,s,t;
	cin>>T>>s>>t;
	if(T>=35&&s==1&&t>=33)
		cout<<"Bu Tie\n"<<T;
	else if(T>=35&&s==0&&t>=33)
		cout<<"Shi Nei\n"<<T;
	else if(s==1&&t<33)
		cout<<"Bu Re\n"<<t;
	else if((T<35||t<33)&&s==0)
		cout<<"Shu Shi\n"<<t;
	return 0;
}
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int gcd(int m,int n){
	if(n==0)
		return m;
	else
	  return gcd(n,m%n);
}
void main(){
/*
int num;int root;
int j=1;
vector<int>x2;
cout<<"enter the num"<<endl;
cin>>num;
int *x=new int[num];
for(int i=2;i<=num;i++)
	x[i]=i;
root=floor(sqrt((float(num))));
for(int i=2;i<=root;i++){
	if(x[i]!=0){
	     j=i*i;
	 while(j<=num){
	     x[j]=0;
	     j+=i;
	}
	}
}

j=0;
for(int i=2;i<=num;i++){
	if(x[i]!=0){
		x2.push_back(x[i]);
		cout<<x2[j]<<endl;
		j++;
	}
}
*/
cout<<gcd(60,24)<<endl;
}
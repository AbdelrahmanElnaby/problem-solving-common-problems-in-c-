#include<iostream>
#include<cmath>
using namespace std;

int coinRow(int coins[],int f[],int size){
	f[0]=0;f[1]=coins[1];
	for(int i=2;i<size;i++){
		f[i]=max(f[i-2]+coins[i],f[i-1]);
	}
	return f[size-1];
}

void main(){
	int Coins[7]={0,5,1,2,10,6,2};
	int f[7];
	cout<<coinRow(Coins,f,7)<<endl;
	cout<<"time Complexity is O(n)"<<endl;
	cout<<"space Complexity is O(n)"<<endl;
}
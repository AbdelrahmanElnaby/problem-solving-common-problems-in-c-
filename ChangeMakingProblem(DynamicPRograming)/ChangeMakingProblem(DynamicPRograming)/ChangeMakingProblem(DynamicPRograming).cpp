#include<iostream>
#include<cmath>
using namespace std;
int changrMakingPRoblem(int coins[],int f[],int amount,int size){
	f[0]=0;
	for(int i=1;i<=amount;i++){
		f[i]=i;
		for(int j=0;j<size && coins[j]<=i;j++){
			f[i]=min(f[i-coins[j]],f[i]);
		}
		f[i]++;
	}
	return f[amount];
}

void main(){
	int amount=6;
	int coins[3]={1,3,4};
	int f[6+1];
	cout<<changrMakingPRoblem(coins,f,amount,3)<<endl;
	// (A) amount
	// (N) number of coins
	cout<<"time Complexity is O(AN)"<<endl;
}
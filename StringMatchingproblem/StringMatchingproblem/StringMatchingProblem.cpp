#include<iostream>
#include<string>
using namespace std;

int stringMatching(char n[],char m[],int sn,int sm){

	for(int i=0;i<=sn-sm;i++){
		int j=0;
		while(j<sm){
			if(m[j]==n[i+j])
				j++;
			else break;
		}
		if(j==sm)
			return i;
		j=0;
	}
	return -1;
}

void main(){

	char n[]={'a','b','c','k'};
	char m[]={'a','b','c'};
	cout<<stringMatching(n,m,4,3)<<endl;
	cout<<"time complexity is O(m*(n-m+1))"<<endl;
}
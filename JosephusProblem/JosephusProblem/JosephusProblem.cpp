#include<iostream>
using namespace std;
//find the survivor
int josephusProblem(int n){
	
	if(n==1)
		return 1;
	else if(n%2==0)
		return 2*josephusProblem(n/2)-1;
	else return 2*josephusProblem(n/2)+1;
}

void main(){
	cout<<josephusProblem(6)<<endl;
}
#include<iostream>
using namespace std;
//RussianPeasantMultiplication problem 
int russianPeasant(int n,int m){

		if(n==1)
			return m;
		else if(n%2==0)
			return russianPeasant(n/2,2*m);
		else return russianPeasant(n/2,2*m)+m;
}

void main(){
	
	cout<<russianPeasant(65,65)<<endl;
}
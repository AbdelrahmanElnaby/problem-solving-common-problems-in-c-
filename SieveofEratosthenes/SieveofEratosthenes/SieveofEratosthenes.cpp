#include<iostream>
#include<cmath>
using namespace std;

int *sieveOfEratosthenes(int n){
	int *arr=new int[n+1];

	for(int i=2;i<=n;i++)
		arr[i]=i;
	int end=sqrt(float(n));
	for(int i=2;i<=end;i++){
		if(arr[i]!=0){
			int j=i*i;
			while(j<=n){
				arr[j]=0;
				j+=i;
			}
		}
	}
	return arr;
}

void printSieve(int *arr,int n){

	for(int i=2;i<=n;i++){
		if(arr[i]!=0)
			cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
void main(){
	int n=25;
	int *arr=sieveOfEratosthenes(n);
	printSieve(arr,n);
}
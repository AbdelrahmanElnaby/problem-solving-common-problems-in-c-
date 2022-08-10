#include<iostream>
#include<cmath>
using namespace std;

void knapsakeProblem(int w[],int v[],int F[][6],int r,int c){
	for(int i=0;i<max(r,c);i++){
		if(i<r)
			F[i][0]=0;
		if(i<c)
			F[0][i]=0;
	}
	int vi,wi;
	for(int i=1;i<r;i++){
		wi=w[i-1];
		vi=v[i-1];
		for(int j=1;j<c;j++){
			if(wi <= j)
				F[i][j]=max(F[i-1][j],F[i-1][j-wi]+vi);
			
			else F[i][j]=F[i-1][j];

			cout<<F[i][j]<<"\t";
		}
		cout<<endl;
	}

	//return F[4][5];
}
// using Memory Function method and Dynamic programing

int w[4]={2,1,3,2};
int v[4]={12,10,20,15};
const int r=5,c=6;
int F[r][c];

void initialiation(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			
			if(i==0 || j==0)
				F[i][j]=0;
			else F[i][j]=-1;

			cout<<F[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int knapsakeProblem2(int i,int j){
	if(F[i][j] < 0){
		if(w[i-1]>j)
			F[i][j]=knapsakeProblem2(i-1,j);
		else F[i][j]=max(knapsakeProblem2(i-1,j-w[i-1])+v[i-1],knapsakeProblem2(i-1,j) );

	}

	return F[i][j];
}

void initialiation2(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){

			cout<<F[i][j]<<"\t";
		}
		cout<<endl;
	}
}

// determine the used weights

void weightsUsed(int i,int j){

	if(i!=0 && j!=0){
		if(F[i][j]!=F[i-1][j]){
			weightsUsed(i-1,j-w[i-1]);
			cout<<w[i-1]<<"\t";
		}
		else weightsUsed(i-1,j);
	}
}


void main(){
	int W=5;
	int w[4]={2,1,3,2};
	int v[4]={12,10,20,15};
	int F[5][6];
	knapsakeProblem(w,v,F,5,6);
	cout<<"Max Weigth (5) is "<<F[4][5]<<endl;
	//using Memory Function & Dynamic Programing
	initialiation();
	cout<<"Max Weigth (5) is "<<knapsakeProblem2(4,5)<<endl;
	initialiation2();
	cout<<"weight Used Are "<<endl;
	weightsUsed(4,5);
	cout<<endl;
}
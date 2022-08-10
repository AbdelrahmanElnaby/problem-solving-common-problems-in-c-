#include<iostream>
#include<cmath>
using namespace std;

void initialization(int Coins[][6],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			Coins[i][j]=0;
		}
	}
	Coins[0][4]=1;
	Coins[1][1]=1;
	Coins[1][3]=1;
	Coins[2][3]=Coins[2][5]=1;
	Coins[3][2]=Coins[3][5]=1;
	Coins[4][0]=Coins[4][4]=1;
}
// (r) row  , (c) column
int RobotCoinCollection(int Coins[][6],int F[][6],int r,int c){
	F[0][0]=Coins[0][0];
	for(int i=1;i<c;i++)
		F[0][i]=F[0][i-1]+Coins[0][i];
	
	for(int i=1;i<r;i++){
		F[i][0]=F[i-1][0]+Coins[i][0];
		for(int j=1;j<c;j++){
			F[i][j]=max(F[i][j-1],F[i-1][j])+Coins[i][j];
		}
	}
	return F[4][5];
}

void robotPath(int F[][6],int r,int c){
	if(! ( (r==0 && c==1) || (r==1 && c==0) )){

		
		if(r==0)
			c--;
		else if(c==0)
			r--;
		else if(F[r-1][c] >= F[r][c-1]){

			if(F[r-1][c] == F[r][c-1])
				cout<<"two solutions are ("<<r<<"\t"<<c+1<<")\tOR\t("<< r+1<<"\t"<<c<<")"<<endl;
		
			r--;
		}
		else c--;
		robotPath(F,r,c);
		cout<<r+1<<"\t"<<c+1<<endl;
	}
}

void main(){
	
	int Coins[5][6];
	initialization(Coins,5,6);
	int F[5][6];
	cout<<RobotCoinCollection(Coins,F,5,6)<<endl; 
	cout<<" Time Complexity is O(n*m)  && Space Complexity is O(n*m)"<<endl;
	robotPath(F,4,5);
}
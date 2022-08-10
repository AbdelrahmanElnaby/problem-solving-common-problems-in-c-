#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

// Define Matrix of values
int A[5][5];
void fillMatrix(){
	A[1][2]=10;A[1][3]=15;A[1][4]=20;
	A[2][1]=5;A[2][3]=9;A[2][4]=10;
	A[3][1]=6;A[3][2]=13;A[3][4]=12;
	A[4][1]=8;A[4][2]=8;A[4][3]=9;
}


//make copy of set with modification

vector<int> copyModify(int k,vector<int> S){
	vector<int> copy;
	for(int i=0;i<S.size();i++){
		
		if(S[i]!=k)
			copy.push_back(S[i]);
	}
	return copy;
}



// Travilling Sales Man graph

// (s) start ,, (S) set of cities
int travillingGraph(int s,vector<int> S,vector<pair<int,int>> &cities){
	int x,c;
	if(S.size()>0){
		for(int i=0;i<S.size();i++){
			int k=S[i];
			vector<int> ScM=copyModify(k,S); // (ScM) is the set after copy and modification
			int y=A[s][k]+travillingGraph(k,ScM,cities);
			int cc=cities.size()-1;;
			if(i>0){
				//x=min(x,y);
				if(y < x){
					x=y;
					c=cc;
				}	
			}

			else {
				x=y;
				c=cc;
			}

		}
		cities.push_back(make_pair(c,s));
	}
	else {
		x=A[s][1];
		cities.push_back(make_pair(0,s));	
	}
	//cout<<cities[cities.size()-1].first<<" "<<cities[cities.size()-1].second<<endl;
	return x;
}

void loop(vector<pair<int,int>> cities){
	for(int i=cities.size()-1; i>=0;i=cities[i].first){
		cout<<cities[i].second<<endl;
	}
	//cout<<cities.size()<<endl;
}
void main(){
	fillMatrix();
	vector<int> S;
	S.push_back(2);
	S.push_back(3);
	S.push_back(4);

	vector<pair<int,int> > cities;
	cities.push_back(make_pair(-1,1));
	cout<<travillingGraph(1,S,cities)<<endl;
	loop(cities);
}
#include<iostream>
using namespace std;
binarysem ChopStick[5];
binarysem speak;

void philosopher(int index){
int i,k;
int x;
x=0;
for(i=0;i<k;i++){
    cout << "I am philosopher: " << index << " and i am thinking "<< endl;
    signal(speak);
    if(index % 2 == 0){
        wait(ChopStick[index]);
        wait(ChopStick[(index+1) % 5]);
        }
        else{
        wait(ChopStick[index]);
        wait(ChopStick[(index+1) % 5]);
        }
    x++;
    wait(speak);
    cout <<"I am philosopher: "<< index <<" and i eat: "<< x << "times" << endl;
    signal(speak);
    signal(ChopStick[index]);
    signal(ChopStick[(index+1) % 5]);

main(){
int k;
for(k=0;k<5;k++){
    initialsem(ChopStick[k],1);
    initialsem(speak,1);
    }
cobegin
    {
        philosopher(1); philosopher(2); philosopher(3); philosopher(4); philosopher(5);
    }
}
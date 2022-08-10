#include<iostream>
using namespace std;

class Queue{
	
	private:
		int front,rear,counter,size;
		int *A;
	public:
		Queue(int size){
			this->size=size;
			front=-1;
			rear=-1;
			counter=0;
			A=new int[size];
		}

		void enqueue(int val){
			if(!isFull()){
				rear=++rear%size;
				A[rear]=val;
				counter++;
			}
			else cout<<"Queue is full"<<endl;
		}

		void dequeue(){
			if(!isEmpty()){
			front=++front%size;
			cout<<A[front]<<endl;
			counter--;
			}
			else cout<<"empty Queue"<<endl;
			
		}

		void print(){
			int loop=front;
			for(int i=0;i<counter;i++){
				loop=++loop%size;
				cout<<A[loop]<<endl;
			}
		}

		

		bool isFull(){
			return counter==size;
		}

		bool isEmpty(){
			return counter==0;
		}
}; 

void main(){
	Queue q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.print();
	q.dequeue();
	cout<<"afterdeueue "<<endl;
	q.enqueue(6);
	q.print();
}
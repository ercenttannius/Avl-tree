#include<stdio.h>
#include<stdlib.h>

//heap ada 2 macam : 
//max dan min : Node yang disimpan dalam binary tree besar ke kecil(max) dan Node yang disimpan dalam binary tree kecil ke besar(min)
//mengikuti aturan complete binary tree
const int Maxsize = 100;
	int heap[Maxsize];
	int size = 0;

//swap
void swap(int *parent,int *child){
	int temp = *parent;
	*parent = *child;
	*child = temp;
}



//up Heap
void upHeap(int index){
	if(index == 1){
		return;
	}
	int parent = index/2;
	if(heap[parent] < heap[index]){
		swap(&heap[parent],&heap[index]);
		upHeap(parent);
	}
	
}

//insert
void insert(int value){
	size++;
	heap[size] = value;
	upHeap(size);
}

//down heap




//extract root 


void print(){
	for(int i =0;i<=size;i++){
		printf("heap[%d] : %d\n",i,heap[i]);
	}
}




int main(){
	insert(10);
	insert(15);
	print();
	return 0;
}

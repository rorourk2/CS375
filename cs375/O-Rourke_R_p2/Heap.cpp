#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Heap.h"
using namespace std;
Heap::Heap(){
	size=0;
	int i=0;
	filename= "output.txt";
	handle= new int[200];
	heap= new Contestant[200];
	while(i<200){
		handle[i]=-1;
		i++;
	}
}
Heap::Heap(string f, int n){
	//ofstream out;
	
	size=0;
	filename= f;
	//out.open(filename);
	maxSize=n+1;
	int i=0;
	handle= new int[n+1];
	heap= new Contestant[n+1];
	while(i<n+1){
		handle[i]=-1;
		i++;
	}
}
void Heap::findContestant(int k){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"findContestant <"<<k<<">." <<endl;
	if(handle[k]!=-1){
		out << "Contestant <"<<k<<"> is in the extended heap with score <"<< heap[handle[k]].score <<">." <<endl;
	}else{
		out << "Contestant <"<<k<<"> is not in the extended heap."<< endl;
	}
	out.close();
}
void Heap::insertContestant(int k, int p){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"insertContestant <"<<k<<"> <"<<p<<">." <<endl;
	
	Contestant c;
	//Contestant d;
	/*int i=1;
	int l=2;
	int r=3;
	int small=0;*/
	if(handle[k]!=-1){
		out << "Contestant <"<<k<<"> is already in the extended heap: cannot insert."<< endl;
	}else if(size<maxSize){
		size++;
		handle[k]=size;
		
		c=Contestant(k,p);
		heap[size]=c;
		/*if(c->score<heap[1]->score){
			d=heap[1];
			heap[1]=c;
			c=d;
			handle[k]=1;
		}*/
		if(size!=1){
			BuildMaxHeap();
		}
		//heapify();
		/*while(true){
			l=2*i;
			r=2*i+1;
			if(l<=size && heap[l]->score<c->score){
				small=l;
			}else{
				small =i;
			}
			if(r<=size && heap[r]->score<c->score){
				small=r;
			}
			if(small==i){
				break;
			}else{
				d=heap[small];
				heap[small]=c;
				i=small;
			}
		}*/
		out << "Contestant <"<<k<<"> inserted with initial score <"<< p <<">." <<endl;
	}else{
		out << "Contestant <"<<k<<"> could not be inserted because extended heap is full."<< endl;
	}
	out.close();
}
void Heap::eliminateWeakest(){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"eliminateWeakest"<<endl;
	Contestant c;
	if(size==0){
		cout << "No contestant can be eliminated since the extended heap is empty."<< endl;
	}else{
		c=heap[size];
		out << "Contestant <"<<heap[1].id<<"> with current lowest score <"<< heap[1].score <<"> eliminated."<< endl;
		//delete heap[1]
		handle[heap[1].id]=-1;
		heap[1]=c;
		handle[heap[size].id]=1;
		//delete heap[size];
		//heap[size]=NULL;
		
		size--;
		//if(size!=1){
			//MaxHeapify(1);
			BuildMaxHeap();
		//}
	}
	out.close();
}
void Heap::earnPoints(int k, int p){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"earnPoints <"<<k<<"> <"<<p<<">." <<endl;
	if(handle[k]!=-1){
		//cout<<handle[k]<<endl;
		//cout<<heap[handle[k]].id<<endl;
		heap[handle[k]].addpoints(p);
		MaxHeapify(handle[k]);
		out << "Contestant <"<<k<<">'s score increased by <"<< p <<"> points to <"<< heap[handle[k]].score<<">." <<endl;
	}else{
		out << "Contestant <"<<k<<"> is not in the extended heap."<< endl;
	}
	out.close();
}
void Heap::losePoints(int k, int p){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"losePoints <"<<k<<"> <"<<p<<">." <<endl;
	int i=handle[k];
	Contestant d;
	if(handle[k]!=-1){
		heap[handle[k]].losepoints(p);
		while(i!=1 && heap[i].score<heap[(i-1)/2].score){
			d=heap[(i-1)/2];
			heap[(i-1)/2]=heap[i];
			heap[i]=d;
			handle[heap[i].id]=i;
			handle[heap[(i-1)/2].id]=(i-1)/2;
		}
		out << "Contestant <"<<k<<">'s score decreased by <"<< p <<"> points to <"<< heap[handle[k]].score<<">." <<endl;
	}else{
		out << "Contestant <"<<k<<"> is not in the extended heap."<< endl;
	}
	out.close();
}
void Heap::showContestants(){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"showContestants"<<endl;
	int i=1;
	while(i<=size){
		out << "Contestant <"<<heap[i].id<<"> in extended heap location <"<< i <<"> with score <"<< heap[i].score<<">." <<endl;
		i++;
	}
	out.close();
}
void Heap::showHandles(){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"showHandles"<<endl;
	int i=1;
	while(i<maxSize){
		if(handle[i]!=-1){
			out << "Contestant <"<<i<<"> is stored in extended heap location <"<< handle[i] <<">." <<endl;
		}else{
			out << "There is no Contestant <"<<i<<"> in the extended heap: handle[<"<< i <<">]=-1." <<endl;
		}
		i++;
	}
	out.close();
}
void Heap::showLocation(int k){
	ofstream out;
	out.open(filename,fstream::app);
	out <<"showLocation <"<<k<<">."<<endl;
	if(handle[k]!=-1){
		out << "Contestant <"<<k<<"> stored in extended heap location <"<< handle[k] <<">." <<endl;
	}else{
		out << "There is no Contestant <"<<k<<"> in the extended heap: handle[<"<< k <<">]=-1." << endl;
	}
	out.close();
}
void Heap::BuildMaxHeap(){
	int i=size/2;
	while(i>0){
		MaxHeapify(i);
		i--;
	}
}
void Heap::MaxHeapify(int i){
	Contestant d;
	int l=2*i;
	int r=2*i+1;
	int small=0;
	if(l<=size && heap[l].score<heap[i].score){
		small=l;
	}else{
		small =i;
	}
	if(r<=size && heap[r].score<heap[i].score){
		small=r;
	}
	if(small!=i){
		d=heap[small];
		heap[small]=heap[i];
		heap[i]=d;
		handle[heap[i].id]=i;
		handle[heap[small].id]=small;
		MaxHeapify(small);
	}
	
}
void Heap::crownWinner(){
	//Build-Max-Heap();
	//int i=size;
	while(size>1){
		//delete heap[1];
		handle[heap[1].id]=-1;
		heap[1]=heap[size];
		handle[heap[size].id]=1;
		//heap[size]=NULL;
		size--;
		MaxHeapify(1);
	}
	ofstream out;
	out.open(filename,fstream::app);
	out <<"crownWinner"<<endl;
	out << "Contestant <"<<heap[1].id<<"> wins with score <"<< heap[1].score <<">." <<endl;
	out.close();
}
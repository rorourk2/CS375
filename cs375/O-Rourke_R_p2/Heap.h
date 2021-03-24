#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <time.h>
#include <math.h>
#include <vector>
#include <string>
class Heap{
	private:
		class Contestant{
			public:
				Contestant(){
					id=-1;
					score=-1;
					
				}
				Contestant(int k, int p){
					id=k;
					score=p;
				}
				void addpoints(int p){
					score+=p;
				}
				void losepoints(int p){
					score-=p;
				}
				int id;
				int score;
		};
		Contestant* heap;
		int* handle;
		int size;
		int maxSize;
		//ofstream out;
		std::string filename;
		void MaxHeapify(int i);
		void BuildMaxHeap();
		/*std::vector<Player> vec;
		
		
		void shiftDown(int);
		bool isLeaf(int);
		int getLeft(int);
		void remove();
		void shiftUp(int);
		int getParent(int);*/
	public:
		
		Heap();
		Heap(std::string filename,int n);
		/*Heap(const Heap &copy);
		void clear();
		void addPlayer(Player newPlayer);
		Player getPlayer();
		std::vector<Player> getArray();
		bool empty();
		void printHeap();
		unsigned int size();*/
		void findContestant(int k);
		void insertContestant(int k, int p);
		void eliminateWeakest();
		void earnPoints(int k, int p);
		void losePoints(int k, int p);
		void showContestants();
		void showHandles();
		void showLocation(int k);
		void crownWinner();
};

#endif
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdio>
#include <time.h>
#include <math.h>
#include "Read.h"
#include "Heap.h"
#define DEBUG false

using namespace std;

int main(int argc, char **argv){
	int i=0;
	//int t=0;
	int k=0;
	int p=0;
	string str="";
	//string line="";
	ifstream in;
	in.open(argv[1]);
	Read the= Read(&in);
	the.readFile();
	in.close();
	Heap h(argv[2],stoi(the.getCurrent(), nullptr, 10));
	the.next();
	do{
		//line=the.getCurrent();
		if(the.getCurrent().at(3)=='w' && the.getCurrent().at(4)=='C'){
			h.showContestants();
		}else if(the.getCurrent().at(0)=='e' && the.getCurrent().at(1)=='l'){
			h.eliminateWeakest();
		}else if(the.getCurrent().at(4)=='H'){
			h.showHandles();
		}else if(the.getCurrent().at(0)=='c'){
			h.crownWinner();
		}else if(the.getCurrent().at(0)=='i'){
			i=0;
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			k=stoi(str, nullptr, 10);
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			str="";
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			p=stoi(str, nullptr, 10);
			h.insertContestant(k,p);
			str="";
			k=0;
			p=0;
		}else if(the.getCurrent().at(0)=='f'){
			i=0;
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			k=stoi(str, nullptr, 10);
			str="";
			h.findContestant(k);
			k=0;
		}else if(the.getCurrent().at(0)=='l'){
			i=0;
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			k=stoi(str, nullptr, 10);
			str="";
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			str="";
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			p=stoi(str, nullptr, 10);
			str="";
			h.losePoints(k,p);
			k=0;
			p=0;
		}else if(the.getCurrent().at(0)=='e'){
			i=0;
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			k=stoi(str, nullptr, 10);
			str="";
			while(the.getCurrent().at(i)!='<'){
				i++;
			}
			i++;
			str="";
			while(the.getCurrent().at(i)=='1' || the.getCurrent().at(i)=='2' || the.getCurrent().at(i)=='3' || the.getCurrent().at(i)=='4' || the.getCurrent().at(i)=='5' || the.getCurrent().at(i)=='6' || the.getCurrent().at(i)=='7' || the.getCurrent().at(i)=='8' || the.getCurrent().at(i)=='9' || the.getCurrent().at(i)=='0'){
				str+=the.getCurrent().at(i);
				i++;
			}
			p=stoi(str, nullptr, 10);
			str="";
			h.earnPoints(k,p);
			k=0;
			p=0;
		}
		//t=0;
	}while(the.next());
	/*Heap h("output.txt", 5);
	h.insertContestant(1,0);
	h.insertContestant(2,15);
	h.insertContestant(3,80);
	h.insertContestant(4,20);
	h.showContestants();
	h.findContestant(5);
	h.eliminateWeakest();
	h.losePoints(3,40);
	h.earnPoints(2,10);
	h.showContestants();
	h.showHandles();
	h.crownWinner();*/
}
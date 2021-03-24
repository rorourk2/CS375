#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <time.h>
#include <math.h>
#include "Read.h"
#define DEBUG false

using namespace std;

int main(int argc, char **argv){
	time_t clock;
	time_t clock2;
	double time2=0;
	if(DEBUG)
		cout << "Started" << endl;
	string hoboken= "";
	ifstream prices;
	ofstream out;
	prices.open(argv[2]);
	Read pr = Read(&prices);
	pr.readFile();
	prices.close();
	int dund=0;
	int x=0;
	int yetterson=0;
	int spa=0;
	int wealth=0;
	int num=0;
	int i=0;
	int count=0;
	int good=0;
	int qwelf=0;
	int maxProfit=0;
	int numCards=0;
	int curProfit=0;
	int curCards=0;
	int curCost=0;
	vector<string> names= vector<string>();
	vector<int> price= vector<int>();
	vector<int> cost= vector<int>();
	vector<int> ind= vector<int>();
	vector<int> threw= vector<int>();
	if(DEBUG)
		cout << "2" << endl;
	do{
		x=0;
		if(DEBUG)
		cout << "3" << endl;
		if(yetterson==0){
			if(DEBUG)
				cout << "4" << endl;
			while(x<pr.getCurrent().size()){
				if(DEBUG)
					cout << "5" << endl;
				hoboken+=pr.getCurrent().at(x);
				x++;
			}
			num=stoi(hoboken, nullptr, 10);
			hoboken="";
			
			if(DEBUG)
					cout << "6" << endl;
		} else{
				while(x<pr.getCurrent().size()){
					if(pr.getCurrent().at(x)!=' '){
						if(DEBUG)
							cout << "7" << endl;
						hoboken+=pr.getCurrent().at(x);
				
					}else{
						if(spa==0){
							if(DEBUG)
								cout << "8" << endl;
							names.push_back(hoboken);
							spa=1;
							hoboken="";
						}
					}
					x++;
				}
				if(DEBUG)
					cout << "9" << endl;
				price.push_back(stoi(hoboken, nullptr, 10));
				hoboken="";
		}
		yetterson=1;
		spa=0;
		hoboken="";
		if(DEBUG)
			cout << "10" << endl;
	}
	while(pr.next());
	if(DEBUG)
		cout << "11" << endl;
	yetterson=0;
	hoboken="";
	prices.open(argv[4]);
	Read grandma = Read(&prices);
	grandma.readFile();
	prices.close();
	if(DEBUG)
		cout << "12" << endl;
	out.open("output.txt");
	do{
		x=0;
		spa=0;
		if(DEBUG)
			cout << "13" << endl;
		if(yetterson==0){
			while(x<grandma.getCurrent().size()){
				if(DEBUG)
					cout << "14" << endl;
				if(grandma.getCurrent().at(x)!=' '){
					if(DEBUG)
						cout << "15" << endl;
					hoboken+=grandma.getCurrent().at(x);
				}else{
					if(spa==0){
						if(DEBUG)
							cout << "16" << endl;
						num=stoi(hoboken, nullptr, 10);
						spa=1;
						hoboken="";
					}
				}
				x++;
			}
			if(DEBUG)
				cout << "17" << endl;
			wealth =stoi(hoboken, nullptr, 10);
			hoboken="";
			spa=0;
		} else{
			while(x<grandma.getCurrent().size()){
				if(DEBUG)
					cout << "18" << endl;
				if(grandma.getCurrent().at(x)!=' '){
					hoboken+=grandma.getCurrent().at(x);
					if(DEBUG)
						cout << "19" << endl;
				}else{
					if(spa==0){
						while(i<names.size()){
							if(DEBUG)
								cout << "20" << endl;
							if(hoboken.compare(names.at(i))==0){
								if(DEBUG)
									cout << "21" << endl;
								good=1;
								ind.push_back(price.at(i));
								break;
							}
							i++;
						}
						i=0;
						if(good==0){
							cout<<"invalid card"<<endl;
							exit(-1);
						}
						good=0;
						spa=1;
						hoboken="";
					}
				}
				x++;
				if(DEBUG)
					cout << "22" << endl;
			}
			cost.push_back(stoi(hoboken, nullptr, 10));
			hoboken="";
			spa=0;
			count++;
			threw.push_back(0);
		}
		
		x=0;
		yetterson=1;
		hoboken="";
		if(count==num){
			if(DEBUG)
				cout << "23" << endl;
			time(&clock);
			dund=pow(2,count);
			while(x<dund){
				if(DEBUG)
					cout << "24" << endl;
				for(int z=0; z<count; z++){
					if(threw.at(z)==1){
						if(DEBUG)
							cout << "25" << endl;
						curCost+=cost.at(z);
						curProfit+=ind.at(z);
						curCards+=1;
					}
				}
				if(curCost<=wealth){
					if(DEBUG)
						cout << "26" << endl;
					if(curProfit>=maxProfit){
						if(DEBUG)
							cout << "27" << endl;
						maxProfit=curProfit-curCost;
						numCards=curCards;
					}
				}
				curCost=0;
				curProfit=0;
				curCards=0;
				if(qwelf==0){
					threw.at(0)=1;
					qwelf=1;
					if(DEBUG)
						cout << "28" << endl;
				}else{
					threw.at(0)=0;
					qwelf=0;
					if(DEBUG)
						cout << "29" << endl;
					for(int z=1; z<count; z++){
						if(threw.at(z)==0){
							threw.at(z)=1;
							break;
							if(DEBUG)
								cout << "30" << endl;
						}
						threw.at(z)=0;
						if(DEBUG)
							cout << "31" << endl;
					}
				}
				x++;
			}
			threw.clear();
			ind.clear();
			cost.clear();
			time(&clock2);
			time2= difftime(clock2,clock);
			if(DEBUG)
				cout << "print" << endl;
			out<<num<<" $"<<maxProfit<<" "<<numCards<<" "<<time2<<endl;
			maxProfit=0;
			numCards=0;
			num=0;
			x=0;
			yetterson=0;
			count=0;
			time2=0;
			qwelf=0;
		}
		if(DEBUG)
				cout << "round" << endl;
	}while(grandma.next());
	out.close();
	
};
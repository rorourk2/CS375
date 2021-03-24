#include "Read.h"

using namespace std;

Read::Read(ifstream * file){
	this->file=file;
	this->read=false;
	this->lines=vector<string>();
	this->index=(size_t) 0;
}

bool Read::readFile(){
	if(!this->file->is_open())
		return false;
	this->file->clear();
	this->file->seekg(0, ios_base::beg);
	string str;
	while(getline(*file, str))
		this->lines.push_back(str);
	this->lines.shrink_to_fit();
	this->read=true;
	return true;
}

bool Read::next(){
	if(this->index<this->getSize()-1){
		this->index++;
		return true;
	}
	return false;
}
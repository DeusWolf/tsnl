#include <fstream>
#include <iostream>
#include <stdlib.h>
std::fstream fin;
std::fstream fout;

int main(){
	std::string name, temp;
	std::cin >> name;
	system("mkdir output");
	bool newfile = true;
	fin.open(name.c_str(), std::fstream::in | std::fstream::out);
	
	while(!fin.eof()){
		for(std::string str; std::getline(fin,str);){
			if(str == "<>"){
				newfile = true;
				continue;
			}
			if(newfile){
				name = str;
				std::cout << name << "\n";
				name.erase(0,1);
				name.erase(name.length()-1,1);
				fout.close();
				std::string filename = "output/";
				filename += name;
				fout.open(filename.c_str(), std::fstream::out | std::fstream::app);
				newfile = false;
			}else{
				fout << str << "\n";
			}	
		}
			
	}
	
	fin.close();
	fout.close();
	return 0;
}

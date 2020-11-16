#include <fstream>
#include <iostream>
#include <stdlib.h>

std::fstream fin, fout, flist;

int main(){
	freopen("flielist.txt", "w", stdout);
	system("ls input");
	fclose(stdout);
	fout.open("aee.thing", std::fstream::out | std::fstream::app);
	flist.open("filelist.txt", std::fstream::in);
	
	while(!flist.eof()){
		for(std::string liner; std::getline(flist, liner);){
			fin.open(liner.c_str(), std::fstream::out | std::fstream::app);	
			fin << " \n";
			fin.close();
			fout << "[" << liner << "\n";
			fin.open(liner.c_str(), std::fstream::in);
			for(std::string inputliner; std::getline(fin, inputliner);){
				if(inputliner != " "){
					fout << inputliner << "\n";
				}else{
					break;
				}
			}
			fout << "<>\n";
			fin.close();
		}
	}
	fout.close();
	flist.close();
	return 0;
}

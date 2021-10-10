#include<iostream>
#include<cstdlib>
#include <stdio.h>
#include <stdlib.h>


#include<fstream>
#include<vector>

#include <iostream>
#include <string>
using namespace std;


vector<string> read_dic()
{

	fstream f ("francais.txt");
	vector<string> list_dic(0);
	string s;
	while(!f.eof()){
		getline(f,s);
		list_dic.push_back(s);
	}
	f.close();
	return list_dic;
}
int strlen(string s) {
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
}
bool in_alphabet(char c){
	
	string ch="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0;i<strlen(ch);i++){
		if(c==ch[i])
			return true;
	
	}
	return false;
}
int main(){
	
	vector<string> tab(0);
	tab=read_dic();
	
	
	string ch;
	ch="йкиавзпоЪыфњ";


	for(int j=0;j<tab.size();j++){
		string ch2;
		ch2="";
		for (int i=0;i<strlen(tab[j]);i++){
			
			if(tab[j][i]==ch[0] or tab[j][i]==ch[1] or tab[j][i]==ch[2] ){
				ch2+="e";
			}
			if(tab[j][i]==ch[3] or tab[j][i]==ch[4]){
				ch2+="a";
			}
			if(tab[j][i]==ch[5]){
				ch2+="c";
			}
			if(tab[j][i]==ch[9]){
				ch2+="u";
			}
			if(tab[j][i]==ch[10]){
				ch2+="o";
			}
			if(tab[j][i]==ch[11]){
				ch2+="oe";
			}
			if(tab[j][i]==ch[6] or tab[j][i]==ch[7]){
				ch2+="i";
			}
			if(tab[j][i]==ch[8] ){
				ch2+="";
			}
			if(in_alphabet(tab[j][i])){
				ch2+=tab[j][i];
			}
			
		}
	
		tab[j]=ch2;
		
	}
	ofstream file;
	file.open("francais.txt");
	for(int h=0;h<tab.size();h++){
		file<<tab[h]<<endl;
	}
	

}

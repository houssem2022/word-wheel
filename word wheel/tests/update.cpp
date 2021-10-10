#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<vector>
// 20 caractere le nom

using namespace std;
string to_string(int entier){
	string ch;
	int nb=entier;
	int j;
	while(nb!=0){
		j=nb % 10;
		switch(j){
			case 0:
				{
				ch="0"+ch;
				break;}
			case 1:
				{
				ch="1"+ch;
				break;}
			case 2:
				{
				ch="2"+ch;
				break;}
			case 3:
				{
				ch="3"+ch;
				break;}
			case 4:
				{
				ch="4"+ch;
				break;}
			case 5:
				{
				ch="5"+ch;
				break;}
			case 6:
				{
				ch="6"+ch;
				break;}
			case 7:
				{
				ch="7"+ch;
				break;}
			case 8:
				{
				ch="8"+ch;
				break;}
			case 9:
				{
				ch="9"+ch;
				break;}
		}
		nb=nb/10;
		
	}
	
	return ch;
	
}
int strlen(string s) {
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
}


bool ancien(string nom){
	
	fstream lec_fichier("word_wheel.txt",ios::in);
	vector<string> tab;
	if(lec_fichier.is_open()){
		string line;
		while(getline(lec_fichier,line)){
			tab.push_back(line);
		}
		lec_fichier.close();
	}

	for(int i=0;i<tab.size();i++){
		string ch="";
		for(int j=0;j<strlen(tab[i]);j++){
			char s=tab[i][j];
			
			if(s != tab[0][0]){
				ch+=tab[i][j];
			}else break;
		}
		if(ch==nom){
			return true;
			
		}
	}	
	
}








void update(string nom ,int entier){

fstream lec_fichier("word_wheel.txt",ios::in);
vector<string> tab;
if(lec_fichier.is_open()){
	string line;
	while(getline(lec_fichier,line)){
		tab.push_back(line);
	}
	lec_fichier.close();
}

if(ancien(nom)){



	for(int i=0;i<tab.size();i++){
		string ch="";
		for(int j=0;j<strlen(tab[i]);j++){
			char s=tab[i][j];
			
			if(s != tab[0][0]){
				ch+=tab[i][j];
			}else break;
		}
		if(ch==nom){
			int k=strlen(ch);
			while(k<20){
				ch+=tab[0][0];
				k+=1;
			}
			ch+=to_string(entier);
			tab[i]=ch;
			cout<<"done"<<endl;
			break;
			
		}
	}
	
	
}
if(!ancien(nom)){
	
	string ch;
	ch=nom;
	int k=strlen(nom);
	while(k<20){
		ch+=tab[0][0];
		k+=1;
	}
	ch+=to_string(entier);
	tab.push_back(ch);
	
	cout<<"done"<<endl;
	
}
ofstream file;
file.open("word_wheel.txt");
for(int h=0;h<tab.size();h++){
	file<<tab[h]<<endl;
}
	
}










int main(){
	
	update("mouhammed",500);
	
}

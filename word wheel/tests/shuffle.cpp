// CPP program Illustrating the 
// use of random_shuffle 
#include<iostream>
#include<cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include<time.h>
#include <unistd.h>
#include<fstream>
#include<vector>
#include<map>

using namespace std; 

int strlen(string s) {
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
}

// random generator function 
int randomfunc(int j) 
{ 

    return rand() % j; 
} 
vector<char> shuffle(string s) {
	int m;
	vector<char> vect;
	m=randomfunc(strlen(s))+1;
	vect.push_back(s[m]);
	for(int i=1 ;i<strlen(s);i++){
		int h;
		h=0;
		do{
			int j;
			
			j=randomfunc(strlen(s))+1;
			
			for(int k=0;k<vect.size();k++){
				if(s[j] == vect[k]){
				
					h=1;
					break;	
					
				}
			}
				
			if(h==0){
				vect.push_back(s[j]);
				cout<<s[j]<<" "<<endl;				
			}
		
		}while(h==1);
	}
	return vect;
	
}
void shuffle(int tab[],int N){ 
	int i,j,deja; /* A prevoir ailleurs */ 
	srand((unsigned) time(NULL)); 
	i=0; 
	while (i<N) { 
		tab[i]=rand()%N;
		deja=0;
		for (j=0;j<i;j++) { 
		if (tab[j]==tab[i]) { 
			deja=1; break; 
			} 
		} 
		if (deja==0) 
			i++; 
	}
}
int main() 
{ 
	string ch="houssem";
	int k=strlen(ch);
	int tab[k];
	shuffle(tab,k);
	for(int i=0;i<k;i++){
		cout<<ch[tab[i]]<<" ";
	}
	
    /*vector<char> vect;
   for(int i=0;i<7;i++){

   	cout<<randomfunc(7)<<endl;
   }
    vect=shuffle("houssem");*/
}

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
#include <iostream>
#include <string>








using namespace std;

// des simples fonctions qu'on va l'utiliser dans le reste du travail
//-------------------------------------------------------------------
vector<string> read_dic(string lang)
{
	vector<string> list_dic(0);
	if(lang=="francais"){

		fstream f ("francais.txt");
		cout<<"langue francaise avec succes"<<endl;
		string s;
		while(!f.eof()){
			getline(f,s);
			list_dic.push_back(s);
		}
		f.close();
	}
	else if(lang=="anglais"){

		fstream f ("anglais.txt");
		cout<<"langue anglaise avec succes"<<endl;		
		string s;
		while(!f.eof()){
			getline(f,s);
			list_dic.push_back(s);
		}
		f.close();
	}
	return list_dic;
}
int strlen(string s) {
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
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


//-------------------------------------------------------------------



//CLASS OPENING :
class opening
{

	string language;
	string lvl;
	string name;
public:
	void wecoming()
	{
		cout << "---------------WELCOM IN THIS WORD WHEEL GAME! ---------------\n" <<endl<<endl<< "the creators are:\n" << "Najemeddine Marzouki\n" << "Houssem Sassi\n" << "Meriam Chaieb\n" << "Siwar Jemai" << endl;
		string rep;
		cout << "Do you want to know the rules ? (yes or no)"<<endl;
		cin >> rep;
		if (rep == "yes" and language=="francais"){
			cout<<endl<<"**************************************************************************"<<endl<<endl;
			cout << "REGLES DU JEU\n.Generalites:\n    -Ce  jeux est jouer par un unique joueur\n    -La communication est faite a travers le terminal \n    -Chaque joueur doit commencer par inscrire ses coordonnees (nom et prenom) afin d'acceder au jeu\n    -Le joueur doit choisir le niveau de difficulte dans lequel il va jouer\n    -La duree de la partie du jeux depend de la difficuté deja choisie \n       * Niveau facile:       5 minutes de jeux\n       * Niveau moyen:	      3 minutes de jeux\n       * Niveau difficile:    2 minutes de jeux\n    -Le joueur invite a saisir des mots construit seulement a partir des 9 lettres deja donnees\n    -La partie est renouvlable\n"; 
			cout<<"	 \n.Mots acceptes:\n    -Le joueur est invite a saisir des mots construit seulement a partir des 9 lettres deja données\n    -Le plus petit mot est de longuer  de trois lettres\n    -Le plus long mot est de longueur 9 lettres \n    -Chaque lettre doit etre utiliser une seule fois sauf dans le cas ou la lettre se repete deja dans les 9 lettres deja donnees \n    -Le calcul de score se fait suivant la regle suivante: chaque lettre d'un mot valide vous donne acces à 5 points de plus pour votre score \n";
			cout<<endl<<endl<<"**************************************************************************"<<endl;	
		}else if(rep == "yes" and language=="anglais"){
			
			cout<<endl<<"**************************************************************************"<<endl<<endl;
			cout << ".General:\n   - This game is played by a single player\n    - Communication is made through the terminal\n    - Each player must start by entering their contact details (name and surname) in order to access the game\n    - The player must choose the level of difficulty in which he will play\n    - The duration of the game depends on the difficulty already chosen\n       * Easy level: 5 minutes of games\n       * Medium level: 3 minutes of games\n       * Difficult level: 2 minutes of games\n    - The player invited to enter words constructed only from the 9 letters already given\n    - The game is renewable"; 
			cout<<"	 \n.Words accepted:\n    - The player is invited to enter words constructed only from the 9 letters already given\n    - The smallest word is three letters long\n    - The longest word is 9 letters long\n    - Each letter must be used only once except in the case where the letter is already repeated in the 9 letters already given\n    - The score calculation is done according to the following rule: each letter of a valid word gives you access to 5 more points for your score";
			cout<<endl<<endl<<"**************************************************************************"<<endl;	
			
			
			
			
		}
		string nom;
		cout<<endl<<"donner votre nom d'utilisateur"<<endl;
		cin>>nom;
		name=nom;
	}
	string get_name(){
		return name;
	}
	string Setlanguage()
	{
		while (true)
		{
			string l;
			cout << "please set your language(lowercase):[francais , anglais , arabe] "<<endl;
			cin >> l;
			if ((l == "francais") || (l == "anglais") || (l == "arabe")) {
				language=l;
				return l;
				break;
			}
			else {
				cout << "incorrect language\n";
			}
		}
	};
	string level()
	{
		while (true)
		{
			string l;
			cout << "choose the level(hard,medium,easy): "<<endl;
			cin >> l;
			if ((l == "hard") || (l == "medium") || (l == "easy")) {
				lvl = l;
				return lvl;
				break;
			}
		}
	};

};




//CLASSE HORLOGE  :  
class horloge : public opening{
	int begin_min;
	int begin_hr;
	int begin_sec;
	

	int nb_sec;
	
	int temp_en_seconde(int h, int m,int s ){
		
		return(h*3600+m*60+s );
	}
	public:
		void set_max(int max){	
			nb_sec=max;
		}
		void start(){
			time_t now;
			struct tm nowlocal;
			now=time(NULL);
			nowlocal=*localtime(&now);
			
			begin_hr=nowlocal.tm_hour;
			begin_min=nowlocal.tm_min;
			begin_sec=nowlocal.tm_sec;	
		}
		
		bool depass(){
			
			int temp_ecoule;
			time_t now;
			struct tm nowlocal;
			now=time(NULL);
			nowlocal=*localtime(&now);
			
			temp_ecoule=temp_en_seconde(nowlocal.tm_hour,nowlocal.tm_min,nowlocal.tm_sec)-temp_en_seconde(begin_hr,begin_min,begin_sec) ; 
			return(temp_ecoule>=nb_sec);
		}
		
		void get_time(){
			int temp_ecoule;
			time_t now;
			struct tm nowlocal;
			now=time(NULL);
			nowlocal=*localtime(&now);
			
			temp_ecoule=temp_en_seconde(nowlocal.tm_hour,nowlocal.tm_min,nowlocal.tm_sec)-temp_en_seconde(begin_hr,begin_min,begin_sec) ; 
			cout<<"il vous reste "<<nb_sec-temp_ecoule<<"secondes"<<endl;
		}
		int get_nb_sec(){
			return nb_sec;
		}
	
};









#include "gamesetup.h"
int main(){
	
system("color f4");
string replay;	
do{
	
	opening op;
	string lang;
	string level;
	lang=op.Setlanguage();
	op.wecoming();

	level=op.level();
	
	//remplissage du vector qui contient les mots de la langue choisie
	string c;
	vector<string> list_dic(0);
	list_dic=read_dic(lang);
	
	
	gamesetup game;
	game.generate_word(list_dic);

	horloge hg;
	
	if(level=="hard")
	hg.set_max(60);
	if(level=="medium")
	hg.set_max(120);
	if(level=="easy")
	hg.set_max(180);
	
	hg.start();
	cout<<"you have "<<hg.get_nb_sec()<<" seconds"<<endl<<endl;
	cout<<"donner une mot "<<endl;
	cin>>c;
	
	while(!hg.depass())
	{
		hg.get_time();
		game.verifWord(c);
		cout<<"donner un mot "<<endl;
		cin>>c;	
		
	}
	
	cout<<endl<<endl<<"----------GAME OVER----------"<<endl<<endl;
	game.score();
	game.update(op.get_name());
	game.affiche_suggested_correct_word();
	
	string ch;
	cout<<endl<<"voulez vous s'avoir les solutions(yes or no)"<<endl;
	cin>>ch;
	if (ch=="yes")
	game.affiche_solution();
	
	cout<<"\n\n***********************************\n";
	cout<<"REPLAY ?? (yes or no )\n";
	cin>>replay;
	cout<<"\n***********************************\n\n";	
}while(replay=="yes");
cout<<"\n\n-------------------------------- \n    GAME OVER ";
	
}

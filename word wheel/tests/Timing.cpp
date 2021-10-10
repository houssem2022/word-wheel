#include <iostream>
using namespace std;
#include<stdio.h>
//#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <string.h>
class Horloge /*friend gameSetup*/ {
	public :
		int minute,seconde;
		//string difficulty="hard";
		//string difficulty="hard";
		//string difficulty="hard";
	void debuter(){
			cout<<"are you READY?"<<endl;
			sleep(1.5);
			cout<<" 3"<<endl;
			sleep(1.5);
			cout<<" 2"<<endl;
			sleep(1.5);
			cout<<" 1"<<endl;
			sleep(1.5);
			cout<<"GO!"<<endl;
			sleep(1);
			system ("cls");
			
		}


	int minuterie(/*string difficulty*/){
		
		//dificulté=hard
		/*	if (difficulty=="hard" ){*/
				for (int x=1;x>=0;x--){
							minute=x;

					for (int y=59;y>=10;y--){
						seconde=y;
						sleep(1); 

						cout << minute << "min:" << seconde << "s " <<endl;
						sleep(1);				
						system ("cls"); 
					
					
				}
				for (int y=9;y>=0;y--){
						seconde=y;
						sleep(1);  

						cout << minute << ":0" << seconde << " " <<endl;
					sleep(1);
					system ("cls"); 
			}
			
	/*}
		else if (difficulty=="medium"){
			for (int x=3;x>=0;x--){
					minute=x;

					for (int y=59;y>=0;y--){
						seconde=y;
						sleep(1);

						cout << minute << ":" << seconde << " " <<endl;
						sleep(1);
						system("cls");
					
				}
				for (int y=9;y>=0;y--){
						seconde=y;
						sleep(1); //faire ecouler 1 seconde 
						cout << minute << ":0" << seconde << " " <<endl;
						sleep(1);
						system ("cls"); 
			
			}
			}
		}
		else if (difficulty=="easy"){
			for (int x=5;x>=0;x--){
					minute=x;

					for (int y=59;y>=0;y--){
						seconde=y;
						sleep(1);
						cout << minute << ":" << seconde << " " <<endl;
						sleep(1);
						system("cls");
				}
				for (int y=9;y>=0;y--){
						seconde=y;
						sleep(1);  
						cout << minute << ":0" << seconde << " " <<endl;
						sleep(1);
						system ("cls");
				}
			}
		}*/
		if ((minute==0)&&(seconde==0)){
			cout<<"Game Over"<<endl<<"calcule de votre score"<<endl;
		}
	}
		
}
	
};
int main(){
	Horloge x;
	x.debuter();
	x.minuterie(/*difficulty*/);
	cout<<"hello"<<endl;
}

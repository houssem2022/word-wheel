#include<cstdlib>
#include<iostream>
#include<time.h>
#include <unistd.h>

using namespace std;

class horloge{
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
	
};
int main(){
	horloge	hg;
	hg.set_max(60);
	hg.start();
	sleep(30);
	hg.get_time();
	sleep(30);
	if(hg.depass()){
		cout<<"temp depass?"<<endl;
	}
		
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream> //odczyt danych z pliku
#include <sstream> //odczyt
#include <unistd.h> //sleeep
#include <random> //random

struct Words{
	std::string wordst, wordnd;
	Words(std::string word1, std::string word2) {
		wordst = word1;
		wordnd = word2;
	}
	Words(){}
};


int main(){
	system("clear");
/*	std::cout<<"                 __         __   __  ___                ___                      _          \n";
	std::cout<<"     	    /  \       |  | |  | \  \              /  /                     | |         \n";
	std::cout<<" 		   /	\      |  | |  |  \  \            /  /                      | |         \n";
	std::cout<<" 		  /  /\  \     |  | |  |   \  \    __    /  / ______   ____   ______| |  _____  \n";
	std::cout<<" 		 /  /__\  \    |  | |  |    \  \  /  \  /  / |  __  | |  __| |  ___   | |  ___| \n";
	std::cout<<"            /  ______  \   |  | |  |     \  \/    \/  /  | |  | | | |    | |   |  | |___    \n";
        std::cout<<"           /  /      \  \  |  | |  |      \    /\    /   | |__| | | |    | |___|  |  ___| | \n";
	std::cout<<"          /__/        \__\ |__| |__|       \__/  \__/    |______| |_|    |________| |_____| \n"; */
	std::string insert, nameoffile;
	int option;
	std::cout<<"1.  <<<<Open database>>>>\n";
	std::cout<<"2. <<<<Create database>>>>\n";
	std::cout<<"3.       <<<<Exit>>>>\n";
	std::cout<<"Type option: ";
	std::cin>>option;
	usleep(1000000);
	system("clear");
        std::vector <Words> database;
        std::fstream dane; //obiekt typu fstream
       /* std::cout<<"Insert name of file: ";
        std::cin>>insert;
        nameoffile = insert + ".txt";
        dane.open(nameoffile, std::ios::in); */
//////////////////////////////////////////////////
	switch(option){
	case 3:
		std::cout<<"B\n";
		usleep(500000);
		system("clear");
                std::cout<<"Y\n";   
                usleep(500000);
                system("clear");
                std::cout<<"E\n";   
                usleep(500000);
                system("clear");
                std::cout<<"AllWords by P4steo\n";   
                usleep(1000000);
		system("clear");
		std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n";   
                usleep(1000000);
		system("clear");
		std::cout<<" \n";
		std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n";   
                usleep(1000000);
                system("clear");
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n";   
                usleep(1000000);
                system("clear");
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<" \n";
                std::cout<<"AllWords by P4steo\n";   
                usleep(1000000);
                system("clear");
		return 0;
	case 1 :
	std::cout<<"Insert name of file: ";
        std::cin>>insert;
        nameoffile = insert + ".txt";
        dane.open(nameoffile, std::ios::in);

	if (!dane.good()){
		std::cout<<"File did not open\n";
	}
	if (dane.eof()){
		std::cout<<"File is empty\n";
	}
	std::string line;

	while (std::getline(dane, line))
	 {
		std::string buf;
		std::stringstream ss(line);
		std::string s1, s2;

		ss >> s1;
		ss >> s2;
		database.push_back(Words(s1, s2));
	}

	for (int i=0; i<database.size(); ++i) {
		std::cout<<database[i].wordst<<" "<<database[i].wordnd<<"\n";
	}
	usleep(1000000);
	int optswitch;
	std::cout<<"1. <<<<Learn>>>>\n";
	std::cout<<"2. <<<<Exit>>>>>\n";
	std::cout<<"Type option: ";
	std::cin>>optswitch;
	switch (optswitch) {
	case 2 :
	break;
	break;
	case 1 :
	std::string word;
	std::vector <int> mistakestab; //tablica z indexami błednych odpowiedzi
	int lp=0;
	system("clear");
	for (int j=0; j<database.size(); ++j) {
		std::cout<<database[j].wordnd<<" - ";
		std::cin>>word;
		if (word==database[j].wordst) {
			std::cout<<"Correct!\n";
			usleep(1000000);
			system("clear");
		}
		else {
			std::cout<<"Wrong!\n";
			usleep(1000000);
			///wypisywanie poprawnego słowa!
			system("clear");
			mistakestab.push_back(j); //zapisywanie indexu błedu
		}
	lp++;
	}//for
	while (mistakestab.size()>0) { //jeśli mamy jakies błedy program nas z nich odpyta
		int lp=0;
		for (auto element : mistakestab) {
                std::cout<<database[element].wordnd<<" - ";
                std::cin>>word;
                if (word==database[element].wordst) {
                        std::cout<<"Correct!\n";
                        usleep(1000000);
                        system("clear");
			mistakestab.erase(mistakestab.begin()+(lp)); //jeśli dobrze odpowiedzieliśmy usuwamy index
                }
                else {
                        std::cout<<"Wrong!\n";
                        usleep(1000000);
                        system("clear");
                }
        lp++;
        	}//for
	}//while

	break;
	}//switch w casie
	}//switch

}

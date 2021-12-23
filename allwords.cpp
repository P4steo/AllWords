#include <iostream>
#include <string>
#include <vector>
#include <fstream> //odczyt danych z pliku
#include <sstream>


struct Words{
	std::string wordst, wordnd;
	Words(std::string word1, std::string word2) {
		wordst = word1;
		wordnd = word2;
	}
	Words(){}
};


int main(){
	std::string insert, nameoffile;
	std::vector <Words> database;
	std::fstream dane; //obiekt typu fstream
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

	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream> //odczyt danych z pliku

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
	dane.open(nameoffile);
	if (!dane.good()){
		std::cout<<"File did not open\n";
	}
	if (dane.eof()){
		std::cout<<"File is empty\n";
	}
	std::string line;

	do {
		getline(dane, line);
//		std::cout<<line<<std::endl;
		std::string oneword, twoword, letter;
        int length = line.length();
        for (int i=0; i<=length; i++) { //zapisywanie pierwszego słowa do bazy danych
                std::string letter (line, i, 1);
                if (letter != " " && letter != "\t" &&
                letter != "\n" && letter != "\v" && letter != "\f" && letter != "\r") {
                        oneword += letter;
                }
                else {
                        for (int j=(i+1); j<=length; j++) { //zapisywanie drugiego słowa do bazy danych
				std::string letter (line, j, 1);
                		if (letter != " " && letter != "\t" &&
                		letter != "\n" && letter != "\v" && letter != "\f" && letter != "\r") {
                        		twoword += letter;
				}
			}
                } //else
		database.push_back(Words(oneword, twoword));
		std::cout<<oneword<<" "; //smart
		oneword = "";
		twoword = "";
        } //for


	}
	while (line != "");
//	for (int i=0; i<database.size(); ++i) {
//                std::cout<<database[i].wordst<<" "<<database[i].wordnd;
//        }

	return 0;
}

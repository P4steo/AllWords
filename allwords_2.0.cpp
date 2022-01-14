#include <iostream>
#include <string>
#include <vector>
#include <fstream> //odczyt danych z pliku
#include <sstream> //odczyt
#include <unistd.h> //sleep

struct Words{
	std::string wordst, wordnd;
	Words(std::string word1, std::string word2) {
		wordst = word1;
		wordnd = word2;
	}
	Words(){}
};

void Main_Menu() {
        std::cout<<"---\e[91mAll\e[0m\e[92mWords\e[0m---\n";
        std::cout<<"\e[47m                               \e[0m\n";
        std::cout<<"\e[31;1m  -------MAIN MENU-------\e[0m\n";
        std::cout<<"\e[93m 1.  <Open database> \n";
        std::cout<<" 2. <Create database>\n";
        std::cout<<" 3.       <Exit>\e[0m \n ";
}


int main(){
	std::string insert,nameoffile;
	char option;
	while (true) {
		system("clear");
		Main_Menu();
		std::cout<<"\e[3mType option: \e[0m";
		std::cin>>option;

		int optint = int(option);
		if (optint<49 || optint>51)
			continue;
		else {
			optint-=48;
		}
		option=optint;

		system("clear");

		std::vector <Words> database; //case 1 (open)
		std::vector <Words> newdatabase; //case 2 (create)
		std::fstream dane;

		switch (option){
			case 1: {
				std::cout<<"\e[91mType \"Exit\" to back to Main Menu: \e[0m"<<std::endl;
				std::cout<<"\e[3mInsert name of file, which content You want to use: \e[0m";
				std::cin>>insert;
				if (insert == "Exit"){
					break;
				}
				nameoffile = insert + ".txt";
				dane.open(nameoffile, std::ios::in);

				if (!dane.good()){
					std::cout<<"\e[96mFile did not open\e[0m\n";
					usleep(1000000);
					system("clear");
					std::cout<<"\e[91mType \"Exit\" to back to Main Menu: \e[0m"<<std::endl;
					std::cin>>insert;
					break;
				}
				if (dane.eof())
					std::cout<<"\e[96mFile is empty\e[0m\n";

				std::string line;

				while (std::getline(dane, line)) {
					std::string buf;
					std::stringstream ss(line);
					std::string s1, s2;

					ss >> s1;
					ss >> s2;
					database.push_back(Words(s1, s2));
				}

				usleep(1000000);
				system("clear");
				for (int i=0; i<database.size(); ++i) {
					std::cout<<"\e[31m"<<database[i].wordst<<"\e[0m"<<" - "<<
					"\e[32m"<<database[i].wordnd<<"\e[0m\n";
				}
				usleep(1000000);

				char optswitch;
				std::cout<<"\e[31;1m---MENU---\e[0m\n";
				std::cout<<"\e[93m 1. <Learn>\n";
				std::cout<<" 2. <Back to Main Menu>\e[0m\n";
				std::cout<<"\e[3mType option: \e[0m";
				std::cin>>optswitch;

                		int optswitchint = int(optswitch);
                		while (optswitchint<49 || optswitchint>50) {
                                        std::cout<<"\e[96mError - invalid number\e[0m\n";
                                        std::cout<<"\n";
                                        std::cout<<"\e[3mType a correct option: \e[0m";
                                        std::cin>>optswitch;
					optswitchint = int(optswitch);
				}
                        	optswitchint-=48;


				switch (optswitchint) {
					case 1: {
						std::string word;
						std::vector <int> mistakestab; //tablica blednych odpowiedzi (indexy)
						int lp=0;
						system("clear");

						for (int k=0; k<database.size(); ++k) {
							std::cout<<database[k].wordnd<<" - ";
							std::cin>>word;
							if (word==database[k].wordst) {
								std::cout<<"\e[92mCorrect!\e[0m\n";
								usleep(1000000);
								system("clear");
							}
							else {
								std::cout<<"\e[91mWrong!\e[0m\n";
								usleep(1000000);
								system("clear");
								std::cout<<"\e[32m"<<database[k].wordst<<"\e[0m\n";
								usleep(1000000);
								system("clear");
								mistakestab.push_back(k);
							}
						}

						while (mistakestab.size()>0) {
							int lp=0;
							for (auto element : mistakestab) {
								std::cout<<database[element].wordnd<<" - ";
								std::cin>>word;
								if (word==database[element].wordst) {
									std::cout<<"\e[92mCorrect!\e[0m\n";
									usleep(1000000);
									system("clear");
									mistakestab.erase(mistakestab.begin()+(lp));
								}
								else {
									std::cout<<"\e[91mWrong!\e[0m\n";
									usleep(1000000);
									std::cout<<"\e[33m"<<database[element].wordst<<"\e[0m"<<std::endl;
									usleep(1000000);
									system("clear");
								}
								lp++;
							} //for
						} //while

						std::cout<<"\e[92mAll Words passed\e[0m\n";
						usleep(1000000);
						break;
					} //case 1 w case 1

					case 2: {
						usleep (10000);
						continue;
					} // case 2 w case 1

				} //switch w case 1
			} //case 1
            case 2: {
		int optioncase2;
		std::string wordstcase2, wordndcase2;

                system("clear");
                std::string word1, word2;
                int case2opt;
                std::cout<<"\e[31;1m---MENU---\e[0m\n";
                std::cout<<"\e[93m 1. <New database>\n";
                std::cout<<" 2. <Edit database>\n";
                std::cout<<" 3. <Back to Main Menu>\e[0m\n";
		std::cout<<"\e[3mType option: \e[0m";
		std::cin>>optioncase2;

		switch (optioncase2) {
			case 1: {
				std::string ans;
				int i=0;
				do {
					std::cout<<"\n\e[31mPut english word: \e[0m";
					std::cin>>wordstcase2;
					std::cout<<"\e[32mPut polish word: \e[0m";
					std::cin>>wordndcase2;
					newdatabase.push_back(Words(wordstcase2, wordndcase2));
					std::cout<<"\e[40m                       \e[0m\n";
					std::cout<<"\e[31m"<<newdatabase[i].wordst<<
					"\e[0m"<<" - "<<"\e[32m"<<newdatabase[i].wordnd<<"\e[0m";
					std::cout<<"\n";
					std::cout<<"\e[3mType \"Add\" to add next pair of words: \e[0m";
					std::cin>>ans;
					if (ans == "Add")
						i++;
				}
				while (ans=="Add");
			}//case 1 w case 2
			case 2: {
				//edit database
			}
			case 3: {
				continue;
				system("clear");
			}
		} //switch w case 2
            } //case 2
            case 3: {
                for (int i=0; i<8; i++) {
                    for (int j=0; j<=i; j++) {
                        std::cout<<" \n";
                    }

                    std::cout<<"\e[94mAllWords by P4steo\e[0m\n";
                    usleep(100000);
                    system("clear");
                }
                std::cout<<"\e[93mAllWords by P4steo\e[0m\n";
                usleep(1000000);
                system("clear");
                return 0;
            } //case 3 nawias

        }//switch głowny
    }//while true
}//int main

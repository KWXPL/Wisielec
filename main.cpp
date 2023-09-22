#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

void menu () {
	std::cout << "Wybierz opcje z menu wybierajac odpowiednia liczbe\n";
	std::cout << "1. Nowa gra\n";
	std::cout << "2. Sproboj jeszcze raz\n";
	switch (menuInput()) {
	case 1:
		
		break;
	default:
		break;
	}
}

int menuInput () {
	std::string input;
	while(true) {
		std::cin >> input;
		int number = stoi(input);
		if (number > 0 || number < 3) {
			return number;
		}
		std::cout << "Nieprawidlowy numer. Wprowadź ponownie numer";
	}
}

std::string newWord() {
	std::vector <std::string> *words = readWordsFromFile();
	int randomNumber = rand() % words->size();
	std::string word = words->at(randomNumber);
	return word;
}

std::vector <std::string> *readWordsFromFile() {
	std::string data;
	std::vector <std::string> words;
	std::ifstream input{ "words.txt" };
	while (input >> data) {
		words.push_back(data);
	}
	return &words;
}


int main () {
	menu();
    return 0;
}
//============================================================================
// Name        : Versuch02Teil3.cpp
// Author      : Philip Rexroth
// Version     :
// Copyright   : @2024 Philip Rexroth
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

/**
 *
 * @param WORD
 * @param secret
 * @return
 */
std::string scramble(std::string WORD, char secret[2][26]);
/**
 *
 * @param WORD
 * @param secret
 * @return
 */
std::string unscramble(std::string WORD, char secret[2][26]);
/**
 * @author Philip Rexroth
 * @param cSymbol
 * @param secret
 * @return
 */
int getPositioninArray(char cSymbol, char secret[26]);

/**
 *
 * @return
 */
int main() {

	char secret[2][26]= {{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
						{'d','3','y','+','5','2','?','!','6','q','r','9','-','1','e','u','p','h','z','$','x','*','/','c','j','w'}};
	char secret2electricboogaloo[2][26]= {{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},
											{'w','j','c','/','*','x','$','z','h','p','u','e','1','-','9','r','q','6','!','?','2','5','+','y','3','d'}};


	std::string notsecretWord;
	std::cout << "Pleas Enter IN CAPS a random Word: " << std::endl;
	std::cin >> notsecretWord;

	std::string secretatedWord = scramble(notsecretWord, secret);
	std::string unsecretatedWord = unscramble(secretatedWord, secret2electricboogaloo);

	std::cout << "NOT A SECRETADED WORD!: " << notsecretWord << std::endl;
	std::cout << "Completeley secure Version: " << secretatedWord << std::endl;
	std::cout << "Decrypting....." << std::endl;
	std::cout << "Absolutley definetly the right word: " << unsecretatedWord << std::endl;
	std::cout << "Trust me bro ;)" << std::endl;

	return 0;
}

std::string unscramble(std::string WORD, char secret[2][26]){

	std::string aha (WORD.length(), ' ');

	for (int i=0; i<=WORD.length(); i++){
		int pos =getPositioninArray(WORD[i], secret[1]);
		 aha[i] = secret[0][pos];
	}
	return aha;
}

std::string scramble(std::string WORD, char secret[2][26]){

	std::string psst (WORD.length(), ' ');

	for (int i=0; i<=WORD.length(); i++){
		int pos =getPositioninArray(WORD[i], secret[0]);
		 psst[i] = secret[1][pos];
	}

	return psst;
}


int getPositioninArray(char cSymbol, char secret[26]){

	for (int i=0; i<26; i++){
		if (cSymbol == secret[i]) {
			return i;
		}
	}

	return 0;
}

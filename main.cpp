#include <iostream>
#include "algo_cpp.h"

int main( int argc, char** argv )
{
	char str[5] = { 'A', 'B', 'C', 'D', 'E' };
	char key[3] = { '1', '2', '3' };

	for( int i = 0; i < 5; i++ ) std::cout << str[i];
	std::cout << std::endl;
	AlgoCpp::CaesarEncryptDecrypt( str, str + 5, 5 );
	for( int i = 0; i < 5; i++ ) std::cout << str[i];
	std::cout << std::endl;
	AlgoCpp::CaesarEncryptDecrypt( str, str + 5, -5 );
	for( int i = 0; i < 5; i++ ) std::cout << str[i];
	std::cout << std::endl;

	AlgoCpp::XorEncryptDecryt( key, 3, str, 5 );
	for( int i = 0; i < 5; i++ ) std::cout << str[i];
	std::cout << std::endl;
	AlgoCpp::XorEncryptDecryt( key, 3, str, 5 );
	for( int i = 0; i < 5; i++ ) std::cout << str[i];
	std::cout << std::endl;

	std::getchar();
	return 0;
}

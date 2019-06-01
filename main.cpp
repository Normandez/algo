#include <iostream>
#include "algo_cpp.h"

int main( int argc, char** argv )
{
	std::string input = "AAAAABBCCCDFFFA";
	std::string res = AlgoCpp::RLE_Encode(input);
	std::string res_input = AlgoCpp::RLE_Decode(res);

	std::cout << res.c_str() << std::endl;
	std::cout << res_input.c_str() << std::endl;

	std::getchar();
	return 0;
}

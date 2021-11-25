#include <iostream>

#include "algo.h"

int main(int argc, char** argv)
{
    size_t N;
    std::cout << "1..N sequence. Enter N = ";
    std::cin >> N;

    int* sorted_input_seq = new int[N];
    for (size_t it = 0; it < N; ++it)
        sorted_input_seq[it] = (int)(it + 1);

    std::string permutations = "";
    AlgoCpp::GetPermutations(permutations, sorted_input_seq, N);

    std::cout << std::endl;
    std::cout << "Generated permutations:\n" << permutations.c_str() << std::endl;

    delete[] sorted_input_seq;

    std::getchar();

    return 0;
}


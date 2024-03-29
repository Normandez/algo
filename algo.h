#ifndef ALGO_H
#define ALGO_H

#include <cmath>
#include <functional>
#include <string>
#include <vector>

namespace AlgoCpp
{
template<class T>
void ReverseArray(T* l, T *r)
{
    while (l < r)
    {
        T tmp = *l;
        *l = *r;
        *r = tmp;

        ++l;
        --r;
    }
}
template<class T>
void ReverseArrayRecurse(T* l, T* r)
{
    if (l >= r)
        return;

    T tmp = *l;
    *l = *r;
    *r = tmp;

    ReverseArrayRecurse<T>(l + 1, r - 1);
}

// In ASCII upper case latin alphas start at num 65, lower case at num 97
void CaesarEncryptDecrypt(char* start, char* end, int diff)
{
    for (char* i = start; i < end; ++i)
    {
        if (isupper(*i))
            *i = char(int((*i + diff - 65)%26 + 65));
        else
            *i = char(int((*i + diff - 97)%26 + 97));
    }
}

void XorEncryptDecryt(char* key, size_t key_length, char* data, size_t data_length)
{
    for (size_t it = 0; it < data_length; ++it)
        data[it] = data[it] ^ key[it % key_length];
}

// O(e^n)
unsigned long FibonacciSequenceRecurse(unsigned n)
{
    if (n <= 1)
        return n;

    return FibonacciSequenceRecurse(n - 1) + FibonacciSequenceRecurse(n - 2);
}

// O(n)
unsigned long FibonacciSequenceDynarray(unsigned n)
{
    if (n <= 1)
        return n;

    unsigned long* arr = new unsigned long[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for (unsigned i = 2; i <= n; ++i)
        arr[i] = arr[i - 1] + arr[i - 2];

    unsigned long res = arr[n];
    delete[] arr;

    return res;
}

// O(n) memory optimized
unsigned long FibonacciSequenceVars(unsigned n)
{
    unsigned long a = 0, b = 1, c;
    if (n <= 1)
        return n;

    for (unsigned i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// O(1) - using formula
unsigned long FibonacciSequenceFormula(unsigned n)
{
    double phi = (1 + std::sqrt(5))/2;
    return std::round(std::pow(phi, n)/std::sqrt(5));
}

unsigned long FactorialRecurse(unsigned n)
{
    return (n == 0 || n == 1) ? 1 : n * FactorialRecurse(n - 1);
}

unsigned long FactorialIterate(unsigned n)
{
    unsigned long res = 1;
    for (unsigned i = 2; i <= n; ++i)
        res *= i;

    return res;
}

// Encode format [N]V, where N - number of duplicates, V - duplicated value
// N is empty when duplicates count is 0
// Works correctly only with strings which not contains digits
std::string RLE_Encode(const std::string& input)
{
    std::string res = "";

    int repeat_count = 1;
    for (size_t it = 1; it <= input.length(); ++it)
    {
        if (it != input.length() && input[it - 1] == input[it])
            repeat_count++;
        else if (repeat_count != 1)
        {
            res += std::to_string(repeat_count) + input[it - 1];
            repeat_count = 1;
        }
        else
            res += input[it - 1];
    }

    return res;
}
std::string RLE_Decode(const std::string& input)
{
    std::string res = "";

    std::string repeat_count_str = "";
    for (size_t it = 0; it < input.length(); ++it)
    {
        if (isdigit(input[it]))
            repeat_count_str += input[it];
        else
        {
            if (!repeat_count_str.empty())
            {
                for (int repeat_cnt_int = std::stoi(repeat_count_str); repeat_cnt_int != 0; --repeat_cnt_int)
                    res += input[it];

                repeat_count_str.clear();
            }
            else
                res += input[it];
        }
    }

    return res;
}

// Generates permutations.
// Input params:
//		OUT '_permutations' - string with result permutations, every starts from new line
//		IN 'input_seq' - input sorted sequence on which permutations generates
//		IN 'input_seq_size' - size of sorted input sequence
//		IN 'iter' - permutation count (starts from 0-permutation)
void GetPermutations(std::string& _permutations, int* input_seq, size_t input_seq_size, size_t iter = 0)
{
    if (iter == input_seq_size)
    {
        for (size_t it = 0; it < input_seq_size; ++it)
            _permutations.append(std::to_string(input_seq[it]) + " ");

        _permutations.append("\n");
    }
    else
    {
        for (size_t it = iter; it < input_seq_size; ++it)
        {
            if (input_seq[it] == input_seq[it + 1])
                continue;

            std::swap(input_seq[iter], input_seq[it]);
            GetPermutations(_permutations, input_seq, input_seq_size, iter + 1);
            std::swap(input_seq[iter], input_seq[it]);
        }
    }
}

// Calculates Catalan number via recurrent expression
// 'n' - number of needed Catalan sequence value (value returns)
int CatalanNumber(int n)
{
    std::vector<int> result = {1, 1};

    for (int count = 2; count < n + 1; ++count)
    {
        result.push_back(0);
        for (int root = 1; root < count + 1; ++root)
            result.back() += result[root - 1] * result[count - root];
    }

    return result[n];
}

// Binary Search Tree (BST) traversal
// The node must have Node::root, Node::left and Node::right pointers
template<class Node>
void BSTTraversal(Node* root, std::function<void(Node*)> f = nullptr)
{
    if (!root)
        return;

    if (f)
        f(root);

    BSTTraversal<Node>(root->left, f);
    BSTTraversal<Node>(root->right, f);
}

// Look-and-say sequence generator
// Returns empty vector if 'seed' is not a digit or empty or 'gen' is 0
// By default, generates Conway's sequence
std::vector<std::string> LookAndSaySequence(const std::string& seed = "1", size_t gen = 5)
{
    std::vector<std::string> sequence;
    sequence.reserve(gen);

    if (!seed.size() or !gen)
        return sequence;

    for (const auto& d : seed)
    {
        if (isdigit(d) == 0)
            return sequence;
    }

    sequence.push_back(seed);

    std::string prev = seed;
    std::string next = "";
    for (int i = 1; i < gen; ++i)
    {
        int j = 0;
        int k = 0;

        while (j < prev.size())
        {
            while (k < prev.size() and prev[j] == prev[k]) ++k;
            next += std::to_string(k - j) + prev[j];
            j = k;
        }

        sequence.push_back(next);
        prev = next;
        next = "";
    }

    return sequence;
}
}

#endif // ALGO_H


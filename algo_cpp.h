#ifndef ALGO_CPP_H
#define ALGO_CPP_H

#include <string>

namespace AlgoCpp
{

	template<class T>
	void ReverseArray( T* l, T *r )
	{
		while( l < r )
		{
			T tmp = *l;
			*l = *r;
			*r = tmp;

			l++;
			r--;
		}
	}
	template<class T>
	void ReverseArrayRecurse( T* l, T* r )
	{
		if( l >= r ) return;

		T tmp = *l;
		*l = *r;
		*r = tmp;

		ReverseArrayRecurse<T>( l + 1, r - 1 );
	}

	// In ASCII upper case latin alphas starts on 65 num, lower case - on 97
	void CaesarEncryptDecrypt( char* start, char* end, int diff )
	{
		for( char* i = start; i < end; i++ )
		{
			if( isupper(*i) )
			{
				*i = char( int( (*i + diff - 65)%26 + 65 ) );
			}
			else
			{
				*i = char( int( (*i + diff - 97)%26 + 97 ) );
			}
		}
	}

	void XorEncryptDecryt( char* key, size_t key_length, char* data, size_t data_length )
	{
		for( size_t it = 0; it < data_length; it++ )
		{
			data[it] = data[it] ^ key[it % key_length];
		}
	}

	// O(e^n)
	unsigned long FibonacciSequenceRecurse( unsigned n )
	{
		if( n <= 1 ) return n;
		return FibonacciSequenceRecurse( n - 1 ) + FibonacciSequenceRecurse( n - 2 );
	}

	// O(n)
	unsigned long FibonacciSequenceDynarray( unsigned n )
	{
		if( n <= 1 ) return n;

		unsigned long* arr = new unsigned long[n + 1];
		arr[0] = 0;
		arr[1] = 1;
		for( unsigned i = 2; i <= n; i++ )
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		unsigned long res = arr[n];
		delete[] arr;

		return res;
	}

	// O(n) memory optimized
	unsigned long FibonacciSequenceVars( unsigned n )
	{
		unsigned long a = 0, b = 1, c;
		if( n <= 1 ) return n;
		for( unsigned i = 2; i <= n; i++ )
		{
			c = a + b;
			a = b;
			b = c;
		}
		return b;
	}

	// O(1) - using formula
	unsigned long FibonacciSequenceFormula( unsigned n )
	{
		double phi = ( 1 + sqrt(5) ) / 2;
		return round( pow( phi, n ) / sqrt(5) );
	}

	unsigned long FactorialRecurse( unsigned n )
	{
		return ( n == 0 || n == 1 ) ? 1 : n * FactorialRecurse( n - 1 );
	}

	unsigned long FactorialIterate( unsigned n )
	{
		unsigned long res = 1;
		for( unsigned i = 2; i <= n; i++ ) res *= i;
		return res;
	}

	// Encode format [N]V, where N - number of duplicates, V - duplicated value
	// N is empty when duplicates count is 0
	// Works correctly only with strings which not contains digits
	std::string RLE_Encode( const std::string& input )
	{
		std::string res = "";

		int repeat_count = 1;
		for( size_t it = 1; it <= input.length(); it++ )
		{
			if( it != input.length() && input[it - 1] == input[it] )
			{
				repeat_count++;
			}
			else if( repeat_count != 1 )
			{
				res += std::to_string(repeat_count) + input[it - 1];
				repeat_count = 1;
			}
			else
			{
				res += input[it - 1];
			}
		}

		return res;
	}
	std::string RLE_Decode( const std::string& input )
	{
		std::string res = "";

		std::string repeat_count_str = "";
		for( size_t it = 0; it < input.length(); it++ )
		{
			if( isdigit(input[it]) )
			{
				repeat_count_str += input[it];
			}
			else
			{
				if( !repeat_count_str.empty() )
				{
					for( int repeat_cnt_int = std::stoi( repeat_count_str ); repeat_cnt_int != 0; repeat_cnt_int-- ) res += input[it];
					repeat_count_str.clear();
				}
				else
				{
					res += input[it];
				}
			}
		}

		return res;
	}

	// Generates simple permutations.
	// Input params:
	//		OUT '_permutations' - string with result permutations, every starts from new line
	//		IN 'input_seq' - input sorted sequence on which permutations generates
	//		IN 'input_seq_size' - size of sorted input sequence
	//		IN 'iter' - permutation count (starts from 0-permutation)
	void GetPermutationsNoRepeats( std::string& _permutations, int* input_seq, size_t input_seq_size, size_t iter = 0 )
	{
		if( iter == input_seq_size )
		{
			for ( size_t it = 0; it < input_seq_size; it++ ) _permutations.append( std::to_string(input_seq[it]) + " " );
			_permutations.append("\n");
		}
		else
		{
			for ( size_t it = iter; it < input_seq_size; it++ )
			{
				std::swap( input_seq[iter], input_seq[it] );
				GetPermutationsNoRepeats( _permutations, input_seq, input_seq_size, iter + 1 );
				std::swap( input_seq[iter], input_seq[it] );
			}
		}
	}

}

#endif // ALGO_CPP_H

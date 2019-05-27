#ifndef ALGO_CPP_H
#define ALGO_CPP_H

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
	void CaesarEncrypt( char* start, char* end, int diff )
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

}

#endif // ALGO_CPP_H

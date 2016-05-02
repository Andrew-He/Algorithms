#include <utility>
#include <iostream>
#include <stack>
#include <cassert>

using namespace std;



/* implements two ways of tracking min element in stack */
namespace solution_two_stacks     // add extra min stack 
{
	class min_stack 
	{
	private:
		stack<int> min; 
		stack<int> s; 
	public:
		void push(int n)
		{
			if ( min.empty() || n <= min.top() )
				min.push(n); 
			s.push(n); 
		}
		void pop()
		{
			if ( s.empty() ) return; 
			if ( min.top() == s.top())
				min.pop(); 
			s.pop(); 
		}
		int top()
		{
			return s.top(); 
		}
		int get_min()
		{
			return min.top(); 
		}
	};
}
class utility
{
public:
	template <typename T1, typename T2>     
	static pair<T1, T2> make_pair(T1 t1, T2 t2)   // T1 is elements, T2 is the currrent min element when T1 is pushed 
	{
		pair<T1,T2> p; 
		p.first = t1; 
		p.second = t2; 
		return p; 
	}
};

namespace solution_one_stack
{
	class min_stack{
		private:
			stack<pair<int,int>>s; 
		public:
			void push(int n)
			{
				if ( s.empty() ) s.push( utility::make_pair<int,int>(n, n));
				else 
				{
					if ( n < s.top().second ) s.push(utility::make_pair<int,int>(n, n)); 
					else s.push( utility::make_pair<int,int>(n, s.top().second)); 
				} 
			}
			void pop()
			{
				s.pop(); 
			}

			int top()
			{
				return s.top().first; 
			}
			int get_min()
			{
				return s.top().second; 
			}

	};
}

template <class TEST_CLASS>
void testcase()
{
	TEST_CLASS ms; 
	ms.push(2); 
	ms.push(1); 
	assert( ms.get_min() == 1 ); 
	ms.push(3);
	ms.push(0); 
	assert( ms.get_min() == 0 ); 
	ms.pop(); 
	assert( ms.get_min() == 1 ); 
}

int main()
{
	testcase<solution_one_stack::min_stack>(); 
 	testcase<solution_two_stacks::min_stack>(); 

	return 0; 
}
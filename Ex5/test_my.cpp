 /**
 * A demo program for itertools.
 *
 * @author Erel Segal-Halevi
 * @since  2019-05
 */


#include <iostream>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;


int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {



//		Constant Range,Chain,Zip,Product,Powerset


		range a11{1, 1};	range a044{0, 44};range Saz{'a', 'z'};range Saa{'a', 'a'};range Smq{'m' , 'q'};
		
		chain CR14R03{range{1, 4}, range{0, 3}}; chain CRACRDG{range{'a', 'c'}, range{'d', 'g'}};chain CACSTEST{range{'a', 'c'}, string{"test"}};
		
		zip ZCR14RAD{range{1, 4}, range{'a', 'd'}}; 	zip ZCACSAB{range{'a', 'c'}, string{"ab"}};

		product PR14RAD{range{1, 4}, range{'a', 'd'}}; product PCACSAB{range{'a', 'c'}, string{"hello"}};
	



	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST RANGE 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////


//	Simple tests or we only advance the figure is we check if it is equal.
	
		testcase.setname("TEST RANGE ");
	
		int number = 0;
			for (int i : range(0, 9))
			{
				testcase.CHECK_EQUAL(i, number);
				number++;
			}
		number =10;
			for (int i : range(10, 44))
			{
				testcase.CHECK_EQUAL(i, number);
				number++;
			}
		 number = -8;
			for (int i : range(-8, 10))
			{
				testcase.CHECK_EQUAL(i,number);
				number++;
			}

	char chartemp='a';
			for (char i : range('a', 'd'))
			{
				testcase.CHECK_EQUAL(i, chartemp);
			chartemp++;
			}


			chartemp='e';
			for (char i : range('e', 'z'))
			{
				testcase.CHECK_EQUAL(i, chartemp);
			chartemp++;
			}
			for (int i : range(0, 0))
				testcase.CHECK_EQUAL(i, 0);


			for (int i : a11)
				testcase.CHECK_OUTPUT(i,"1");









/*From there we will find tests that we walk in the following way.
We find a table that is in fact the data that must be received each time.
And simply, it remains more than check the outgoing data with what we expect to return
*/




	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST CHAIN 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	


testcase.setname("TEST CHAIN ");

number=0;
int tab[]={1,2,3,5,6,7};
for (int i: chain(range(1,4), range(5,8)))
	{
		testcase.CHECK_EQUAL(i, tab[number]);
		number++;
	}


number=0;
int tab2[]={0,1,2,3,9,10};
for (int i: chain(range(0,4), range(9,11)))
	{
		testcase.CHECK_EQUAL(i, tab2[number]);
		number++;
	}

number=0;
int temp=0;
char tab3[]={'h','e','l','l','o'};
char tab4[]={'a','b','c'}	;

for (auto i: chain(range('a','d'), string("hello")))
	{
		if(number<3)
		{
		testcase.CHECK_EQUAL(i, tab4[number]);
		number++;
		}
	else{
		testcase.CHECK_EQUAL(i, tab3[temp]);
		temp++;
	}
	}


	
number=0;
temp=0;
char tab5[]={'d','e','f'};
char tab6[]={'a','b','c'}	;

for (auto i: chain(range('a','d'), range('d','g')))
	{
		if(number<3)
		{
		testcase.CHECK_EQUAL(i, tab6[number]);
		number++;
		}
	else{
		testcase.CHECK_EQUAL(i, tab5[temp]);
		temp++;
	}
	}




	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST ZIP 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
		testcase.setname("TEST ZIP ");
number=0;

string tab9[]={"1,h","2,e","3,l","4,l","5,o"};
for (auto pair: zip(range(1,6), string("hello")))
{
		testcase.CHECK_OUTPUT(pair,tab9[number]);
		number++;

}

number=0;
		string tab10[]={"6,q","7,w","8,e","9,r","10,t"};
for (auto pair: zip(range(6,11), string("qwert")))
{
		testcase.CHECK_OUTPUT(pair,tab10[number]);
		number++;

}

number=0;
		string tab11[]={"6,0","7,1","8,2","9,3","10,4"};
for (auto pair: zip(range(6,11), range(0,5)))
{
		testcase.CHECK_OUTPUT(pair,tab11[number]);
		number++;

}

number=0;
		string tab16[]={"6,a","7,b","8,c","9,d","10,e"};
for (auto pair: zip(range(6,11), range('a','f')))
{
		testcase.CHECK_OUTPUT(pair,tab16[number]);
		number++;

}

number=0;
		string tab12[]={"0,a","1,b","2,c","3,d","4,e","5,f"};
for (auto pair: zip(range(0,6), range('a','g')))
{
		testcase.CHECK_OUTPUT(pair,tab12[number]);
		number++;

}




	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST PRODUCT 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	testcase.setname(" TEST PRODUCT");
	number=0;
		string tab13[]={"0,a","0,b","1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
for (auto pair: product(range(0,5), string("ab")))
{
		testcase.CHECK_OUTPUT(pair,tab13[number]);
		number++;

}

	number=0;
		string tab14[]={"0,5","0,6","1,5","1,6","2,5","2,6","3,5","3,6","4,5","4,6"};
for (auto pair: product(range(0,5), range(5,7)))
{
		testcase.CHECK_OUTPUT(pair,tab14[number]);
		number++;

}


	number=0;
		string tab17[]={"0,a","0,b","1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
for (auto pair: product(range(0,5), range('a','c')))
{
		testcase.CHECK_OUTPUT(pair,tab17[number]);
		number++;

}

	//////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////// TEST PowerSet 	/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	testcase.setname(" TEST PowerSet");
	number=0;
		string tab18[]={"{}","{1}","{2}","{1,2}","{3}","{1,3}","{2,3}","{1,2,3}"};
for (auto pair: powerset(range(1,4))){
		testcase.CHECK_OUTPUT(pair,tab18[number]);
		number++;

}

	number=0;
		string tab20[]={"{}","{a}","{b}","{a,b}","{x}","{a,x}","{b,x}","{a,b,x}","{y}","{a,y}","{b,y}","{a,b,y}","{x,y}","{a,x,y}","{b,x,y}","{a,b,x,y}"};
for (auto subset: powerset(chain(range('a','c'),range('x','z'))))
{		testcase.CHECK_OUTPUT(subset,tab20[number]);
		number++;

}

	number=0;
	string tab21[]={"{}","{a}","{b}","{a,b}","{c}","{a,c}","{b,c}","{a,b,c}"};
for (auto subset: powerset(string("abc")))
{		testcase.CHECK_OUTPUT(subset,tab21[number]);
		number++;

}


    testcase.print(cout, /*show_grade=*/false);
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

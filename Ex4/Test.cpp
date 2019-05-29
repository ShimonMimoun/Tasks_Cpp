
/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;
		
		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}
		
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////// MY TEST //////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	
		testcase.setname("Test CalculateBull_and_pgia Succes")
				.CHECK_OUTPUT(calculateBullAndPgia("123456789","123456789"),"9,0")	//9 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1231","1113"), "1,2")      //1 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1112","2111"), "2,2")      //2 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6900","9060"), "1,3")      //1 bull,3 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1010","1010"),"4,0") 		//4 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("222","222"),"3,0")					//3 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("17","17"),"2,0")						//2 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("11111","11111"),"5,0")			//5 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3319","1111"), "1,0")      //1 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2020","2200"), "2,2")      //2 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6661","1116"), "0,2")      //0 bull,2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("33333","33333"),"5,0")			//5 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9920","2922"), "2,0")      //2 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("3","3"),"1,0")								//1 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1011","1010"),"3,0")				//3 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("123","301"),"0,2")						//0 bull,2 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("71","17"),"0,2")							//0 bull,2 pgia		
	.CHECK_OUTPUT(calculateBullAndPgia("2341324","9876348"),"1,1")			//1 bull,1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("5","3"),"0,0")							//0 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"),"0,4")				//0 bull,4 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("123456789","195864732"),"2,7")	//2 bull,7 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("123456","123456"),"6,0")			//6 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1231","1113"), "1,2")      //1 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8060","4448"), "0,1")      //0 bull,1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9999","2292"), "1,0")      //1 bull,0 pgia
		;

testcase.setname("Test CalculateBull_and_pgia With error lenght ")

.CHECK_OUTPUT(calculateBullAndPgia("123456789","12345678"),"8,0")	//8 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1231","111"), "1,1")      //1 bull,1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1112","21111"), "2,2")      //2 bull,2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("620","9060"), "0,2")      //0 bull,2 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("105","1010"),"2,0") 		//2 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("2242","222"),"2,1")					//2 bull,1 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("137","17"),"1,1")						//1 bull,1 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("66","1116"), "0,0")      //0 bull,0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("3333","33333"),"4,0")			//4 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("920","22"), "1,0")      //1 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("38","3"),"1,0")								//1 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("111","1010"),"2,0")				//2 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("123","31"),"0,2")						//0 bull,2 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("71","1"),"0,1")							//0 bull,1 pgia		
	.CHECK_OUTPUT(calculateBullAndPgia("2341324","98763"),"1,0")			//1 bull,0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("58","3"),"0,0")							//0 bull,0 pgia
	.CHECK_OUTPUT(calculateBullAndPgia("1234","421"),"1,2")				//1 bull,2 pgia
;


		ConstantChooser c4236{"4236"}, c3123{"3123"}, c993{"9993"}, c12343{"12343"};
		ConstantGuesser g12343{"12343"}, g3123{"3123"}, g9965{"9965"};

		testcase.setname("Test Play Constant");		
			testcase.CHECK_EQUAL(play(c3123, g3123, 4, 100), 1);      // guesser wins in one turn.
		testcase.CHECK_EQUAL(play(c4236, g9965, 4, 100), 101);    // guesser loses by running out of turns 
		testcase.CHECK_EQUAL(play(c3123, g1234, 4, 100), 101);   // guesser loses technically by making an illegal guess (too long).
		testcase.CHECK_EQUAL(play(c993, g12343, 4, 100), 101) ;    // chooser loses technically by choosing an illegal number (too long).
		testcase.CHECK_EQUAL(play(c3123, g3123, 4, 100), 1) ;     // guesser wins in one turn.
		testcase.CHECK_EQUAL(play(c4236, g12343, 4, 100), 101);    // guesser loses by running out of turns 
		testcase.CHECK_EQUAL(play(c993, g3123, 4, 100), 101);   // guesser loses technically by making an illegal guess (too long).
		testcase.CHECK_EQUAL(play(c12343, g3123, 4, 100), 0);     // chooser loses technically by choosing an illegal number (too long).
		
		;

		testcase.setname("Test Play With Random ");
		RandomChooser rchooser;
		SmartGuesser schooser;
		testcase.CHECK_EQUAL(play(rchooser, schooser, 4, 100)<=100, true);   
		testcase.CHECK_EQUAL(play(rchooser, schooser, 3, 100)<=100, true);     		  		 
		testcase.CHECK_EQUAL(play(rchooser, schooser, 2, 100)<=100, true); 
		testcase.CHECK_EQUAL(play(rchooser, schooser, 1, 100)<=100, true); 

		  
testcase.setname("Play Test");

		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(rchooser, schooser, 3, 100)<=100, true);  // schooser  win at most 10 rounds
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(rchooser, schooser, 2, 100)<=100, true);  // schooser  win  at most 10 turns
		}
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(rchooser, schooser, 1, 100)<=100, true);  // schooser win  at most 10 turns
		}

// 		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}	
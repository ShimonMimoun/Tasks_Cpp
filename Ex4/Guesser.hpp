#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std; 
using std::string;

namespace bullpgia {


class Guesser{

public:

  unsigned  int length;
  int countBull;
  int countPgia;


	virtual string guess() = 0;
        virtual void startNewGame(uint length) {};
        virtual void learn(string results) {};
};



}

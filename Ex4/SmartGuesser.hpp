#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector> 
#include <bits/stdc++.h> 


/**
 * ConstantChooser is a chooser that always chooses the same string. 
 */

 namespace bullpgia {
    
class SmartGuesser: public bullpgia::Guesser{
    private:
      string str;
      int myplace;
      int value[10] = {0};
      vector<string> ans;
      string combi;
      string reply;
      int count;
public:
          SmartGuesser();
          string guess() override;
          void startNewGame(uint length) override;
          void FindTheNum();
          string Getstrlength(string s, int legnth);
          void learn(string results) override;
          void permute(string s1, string s2);
          vector<string> getpremu(string s);
};
}
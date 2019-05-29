#include "SmartGuesser.hpp"
#include <string>
 

using std::string;
           bullpgia::SmartGuesser::SmartGuesser(){
        
           }
           

string bullpgia::SmartGuesser::guess() { 
    if(myplace <= 10){
    helping();
    }
    if (myplace == 10){
        for (size_t i = 0; i <= 9; i++) {
            if(value[i] !=0){
                int temp =value[i]; 
                for (size_t j = 1; j <= temp; j++) {
                reply =reply+to_string(i)+"";
                }
                
            }
        }
        combi = reply;
        }
        if(myplace >=10){
        if(!combi.empty()){
        ans = getpremu(combi);
        }
        str = ans[count];
        count=(count+1);

        }
     return this->str; 


    }



void bullpgia::SmartGuesser::helping (){
        if (((this->countPgia != 0) || (this->countBull != 0))  && (myplace <= 9)){
            if(countPgia == 1){
                this->value[myplace]++;
                this->myplace++;
            } else{
            for (size_t i = 1; i <= countPgia; i++){
                this->value[myplace]++;
                }
                this->myplace++;
            }
                string ans="";
                for (size_t i = 0; i < this->length; i++){
                ans=ans+to_string(this->myplace)+"";
                this->str = ans;
                }

    }else{
        this->myplace++;
        string ans="";
        for (size_t i = 0; i < this->length; i++)
        {
        ans=ans+to_string(this->myplace)+"";
        this->str = ans;
        }

    }
}
void bullpgia::SmartGuesser::permute(string str, string out) { 
    if (str.size() == 0) 
    { 
        ans.push_back(out);  
        return; 
    } 

    for (int i = 0; i < str.size(); i++) 
    { 
        permute(str.substr(1), out + str[0]); 
  
        rotate(str.begin(), str.begin() + 1, str.end()); 
    } 
}

vector<string> bullpgia::SmartGuesser::getpremu(string s)
{
      permute(s,"");
      return ans;
}

void bullpgia::SmartGuesser::learn(string results)
{    
          string delimiter = ",";
          string pgia = results.substr(0, results.find(delimiter)); 
          string bull = results.substr(results.find(delimiter)+1); 

          this->countPgia = stoi(pgia);
          this->countBull = stoi(bull);
}

string bullpgia::SmartGuesser::Getstrlength(string s, int length){

    string s1 = "0";
    for (size_t i = 0; i < length; i++)
    {
    s=s+to_string(0)+"";
    }
    return s;

}



void bullpgia::SmartGuesser::startNewGame(uint length) {
            this->length = length;
            this->str = Getstrlength("",length);
            this->myplace = -1;
            this->countBull = 0;
            this->countPgia = 0;
            combi = "";
            reply = "";
            count = 0;
            ans.clear();
        for (size_t i = 0; i < 10; i++)
        {
           value[i] = 0;
        }
        

};


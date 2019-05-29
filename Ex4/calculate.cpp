#include "calculate.hpp"

using std::string, std::to_string ,std::fill ;

using namespace bullpgia;


string bullpgia::calculateBullAndPgia(string choice, string guess) {

   int length_choice = choice.length();
   char *arr_temp = new  char[length_choice];
   for (int q=0;q<length_choice;q++)
   {
       arr_temp[q]=0;
   }

    int count_bull = 0; 
    int count_pgia = 0; 

    for (int k = 0; k < length_choice; k++)
    {
        if (guess[k] == choice[k])   
        {
             arr_temp[k] = 'b';   continue ;

        }
        
    
    }

    for (int a = 0; a < 10; a++) 
    {
        for (int i = 0; i < length_choice ; i++) 
        {
            if ((guess[i] == 48 + a) && (arr_temp[i] !='b' )) 
            {
                for (int j = 0; j < length_choice; j++)
                {
                    if ( (choice[j] == guess[i]) && (i != j))
                    {
                        if (arr_temp[j] == 0)
                        {   
                            arr_temp[j] = 'p'; 
                            break;
     }}}}}}


////////////////////////////////////////////////////////////////////////////
    /////////////////////////// COUNT PGIA AND BULL /////////////////////
///////////////////////////////////////////////////////////////////////////

    for (size_t i = 0; i < length_choice; ++i)
    {
        count_pgia = count_pgia+ (arr_temp[i] == 'p');
        count_bull = count_bull+ (arr_temp[i] == 'b');  
    }
     delete[] arr_temp;
    // std::cout << to_string(count_bull) + "," + to_string(count_pgia) << std::endl;
    return to_string(count_bull) + "," + to_string(count_pgia);
}
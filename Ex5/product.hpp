#pragma once

#include <utility>
#include <assert.h>
#include <iostream>

//NameSpace for a Tasks
namespace itertools {

    bool temp = false;
    template <typename T1, typename T2> 
    class product {
    
    private: // private variables and functions
        T1 iterable_A;
        T2 iterable_B;

    public:
        product(T1 start, T2 end) :  iterable_A(start), iterable_B(end) {
              temp = false;
              if(!(end.begin() != end.end())) 
              temp = true;
            }
        
        
   auto begin() const {
              return iterator<decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin());
             }
            auto end() const {
              return iterator<decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end());
             }
    template <typename C1, typename C2>
        class iterator {

        private:
            C1 iter_A; // iterator A
            C2 iter_B; // iterator B
            C2 save_position_B;
              bool sauv_index;

        public:
            iterator(C1 itA , C2 itB): iter_A(itA) , iter_B(itB) , save_position_B(iter_B),sauv_index(false) {}

         
              iterator& operator++() {
              if(!sauv_index)
              ++iter_B;
              return *this;
              }

             auto operator*() const
              {
               return pair<decltype(*iter_A),decltype(*iter_B)> (*iter_A,*iter_B);
              }

      
              bool operator!= (iterator const & other)
              {
                if ((iter_A != other.iter_A) && !(iter_B != other.iter_B)){
                    sauv_index = true;
                  }
                if(sauv_index){
                  iter_B = save_position_B;
                  ++iter_A;
                  sauv_index = false;
                }
                return (iter_A != other.iter_A && !temp);
              }


         
        }; // END OF CLASS ITERATOR


    };

}
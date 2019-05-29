#pragma once

#include <iterator>
#include<iostream>

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T1, typename T2> 
    class chain {
    
    private: // private variables and functions
        T1 iterable_A;
        T2 iterable_B;

    public:
        chain(T1 start, T2 end) :  iterable_A(start), iterable_B(end) {}
        
    auto begin()const{ 
        return  iterator<decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin()); }  // iteratable object

    auto end() const{
        return iterator<decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end()); }  // iteratable object  
 
    template <typename C1, typename C2>
        class iterator {

        private:
            C1 iter_A; // iterator A
            C2 iter_B; // iterator B
         bool checkKind;

        public:
            iterator(C1 itA , C2 itB): iter_A(itA) , iter_B(itB), checkKind(true)  {}

           iterator<C1,C2>& operator++() {
                if(checkKind){
                    ++iter_A;
                }else {
                    ++iter_B;
                }
                return *this;
            }


            decltype(*iter_A) operator*() const {

                if(checkKind){
                    return *iter_A;
                }else {
                    return *iter_B;
                }
            }

            bool operator!=(iterator<C1,C2>  it){
                if(checkKind && !(iter_A != it.iter_A)){
                    checkKind = false;
                }
                if(checkKind){
                    return iter_A != it.iter_A;
                }else{
                    return iter_B != it.iter_B;
                }
            }

         
        }; // END OF CLASS ITERATOR

	};

}
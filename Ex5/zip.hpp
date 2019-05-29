#include <iostream>
#include <utility>

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T1, typename T2> 
    class zip {
    
    private: // private variables and functions
        T1 iterable_A;
        T2 iterable_B;

    public:
        zip(T1 start, T2 end) :  iterable_A(start), iterable_B(end) {}
        
   auto begin() const{
          return iterator <decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin());
        }
        auto end() const{
          return iterator <decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end());
         }
    template <typename C1, typename C2>
        class iterator {

        private:
            C1 iter_A; // iterator A
            C2 iter_B; // iterator B

        public:
            iterator(C1 itA , C2 itB): iter_A(itA) , iter_B(itB)  {}

           iterator<C1,C2>& operator++() {
               ++iter_A;
               ++iter_B;
               return *this;
 
            }


            auto operator*() const
          {
           return pair< decltype(*iter_A),decltype(*iter_B)> (*iter_A,*iter_B);
          }


            bool operator!= (const iterator& other)
          {
            return (iter_A != other.iter_A) && (iter_B != other.iter_B);
           }


         
        }; // END OF CLASS ITERATOR


    };
    template <typename T,typename E>
    std::ostream &operator<<(std::ostream &os, const std::pair<T,E> &c){
    os << c.first << ',' << c.second;

    return os;
}


}
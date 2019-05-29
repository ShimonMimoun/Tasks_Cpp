#include <iostream>
#include <vector>
#include <cmath>



namespace itertools {

    


template <typename Iter>
class powerset {

private:
Iter Iter_a;

public:
powerset(Iter value) : Iter_a(value) {}

auto begin() const {    return iterator<decltype(Iter_a.begin())> (Iter_a.begin(), Iter_a.end());
}
auto end() const {       return iterator<decltype(Iter_a.begin())>(Iter_a.end(), Iter_a.end());
}




template <typename T>
class iterator {


private:

vector<vector<T>> mix(const vector<T> &other){
        vector<vector<T>> mix_combin;
        vector<T> data_temp;
        mix_combin.push_back(data_temp);

        for (int i = 0; i < other.size(); i++) {
 vector<vector<T>> Temp_mix = mix_combin;

                for (int j = 0; j < Temp_mix.size(); j++) {  Temp_mix[j].push_back(other[i]); }
                for (int j = 0; j < Temp_mix.size(); j++) {  mix_combin.push_back(Temp_mix[j]); }
        }
        return mix_combin;
}

int length_iter(const T A,const T B){
        T data = A;
        int temp = 0;
        while(data != B) {  temp++;  ++data;    }
        return pow(2,temp);
}

vector<T> Swap(const T a,const T b){
        
        vector<T> temp;
        T run = a;
        while(run != b) {
                temp.push_back(run);
                ++run; }
        return temp;
}



public:

vector<vector<T>>   data;
T iterable_a;
T iterable_b;
int size;
int value_index;



iterator(T itA, T itB) : iterable_a(itA), iterable_b(itB), size(length_iter(itA,itB)),value_index(0){}

bool operator!= (const iterator & temp){
        return (value_index != size);
}

auto operator++() {      ++value_index;     return *this;}


auto operator*(){
        vector<T> A  = Swap(iterable_a,iterable_b);
        data = mix(A);
        
        vector<typename remove_const<typename remove_reference<decltype(*iterable_b)>::type>::type> temp; 
       
        for(auto i : data[value_index]) { temp.push_back(*i);  }
        return temp;
}




};



};



template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &Value)
{
        os << "{";

        auto temp = Value.begin();
        if(temp != Value.end())  {
                os << *temp;
                ++temp; }
        while (temp != Value.end()) {
                os << ',' << *temp;
                ++temp;}

        os << "}";
        return os;
}

};

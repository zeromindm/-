#ifndef SET_H
#define SET_H

#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
class Set {
private:
    std::vector<T> elements;

public:
    Set();
    Set(const std::vector<T>& values);
    Set(size_t count, const T& min_val, const T& max_val);
    
  
    size_t size() const;
    bool empty() const;
    
   
    T operator[](size_t index) const;
    
  
    void insert(const T& value);
    void remove(const T& value);
    
 
    bool contains(const T& value) const;
    
  
    void clear();
    std::vector<T> to_vector() const;
};

#include "Set.tpp"

#endif 
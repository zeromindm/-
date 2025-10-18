#ifndef SET_H
#define SET_H

#include <iostream>
#include <stdexcept>

template<typename T>
class Set {
private:
    T* elements;
    size_t capacity;
    size_t count;
    
    static constexpr size_t INITIAL_CAPACITY = 10;
    static constexpr double GROWTH_FACTOR = 2.0;
    
    void resize(size_t new_capacity);
    size_t find_index(const T& value) const;

public:
   
    Set();
    explicit Set(const T* values, size_t size);
    Set(const Set& other);
    Set(Set&& other) noexcept;
    ~Set();
    
    
    Set& operator=(const Set& other);
    Set& operator=(Set&& other) noexcept;
    
   
    size_t size() const;
    bool empty() const;
    
   
    T operator[](size_t index) const;
    
   
    void insert(const T& value);
    void remove(const T& value);
    void clear();
    
    
    bool contains(const T& value) const;
    
    
    T* to_array() const;
};

#include "Set.tpp"

#endif 
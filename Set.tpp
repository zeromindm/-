#ifndef SET_TPP
#define SET_TPP

#include <algorithm>
#include <cstring>

template<typename T>
Set<T>::Set() : elements(nullptr), capacity(0), count(0) {
    resize(INITIAL_CAPACITY);
}

template<typename T>
Set<T>::Set(const T* values, size_t size) : elements(nullptr), capacity(0), count(0) {
    resize(size > INITIAL_CAPACITY ? size * 2 : INITIAL_CAPACITY);
    for (size_t i = 0; i < size; ++i) {
        insert(values[i]);
    }
}

template<typename T>
Set<T>::Set(const Set& other) : elements(nullptr), capacity(0), count(0) {
    resize(other.capacity);
    count = other.count;
    for (size_t i = 0; i < count; ++i) {
        elements[i] = other.elements[i];
    }
}

template<typename T>
Set<T>::Set(Set&& other) noexcept 
    : elements(other.elements), capacity(other.capacity), count(other.count) {
    other.elements = nullptr;
    other.capacity = 0;
    other.count = 0;
}

template<typename T>
Set<T>::~Set() {
    delete[] elements;
}

template<typename T>
Set<T>& Set<T>::operator=(const Set& other) {
    if (this != &other) {
        delete[] elements;
        capacity = 0;
        count = 0;
        resize(other.capacity);
        count = other.count;
        for (size_t i = 0; i < count; ++i) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator=(Set&& other) noexcept {
    if (this != &other) {
        delete[] elements;
        elements = other.elements;
        capacity = other.capacity;
        count = other.count;
        other.elements = nullptr;
        other.capacity = 0;
        other.count = 0;
    }
    return *this;
}

template<typename T>
void Set<T>::resize(size_t new_capacity) {
    if (new_capacity <= capacity) return;
    
    T* new_elements = new T[new_capacity];
    for (size_t i = 0; i < count; ++i) {
        new_elements[i] = elements[i];
    }
    
    delete[] elements;
    elements = new_elements;
    capacity = new_capacity;
}

template<typename T>
size_t Set<T>::find_index(const T& value) const {
    for (size_t i = 0; i < count; ++i) {
        if (elements[i] == value) {
            return i;
        }
    }
    return count;
}

template<typename T>
size_t Set<T>::size() const {
    return count;
}

template<typename T>
bool Set<T>::empty() const {
    return count == 0;
}

template<typename T>
T Set<T>::operator[](size_t index) const {
    if (index >= count) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

template<typename T>
void Set<T>::insert(const T& value) {
    if (contains(value)) return;
    
    if (count >= capacity) {
        resize(static_cast<size_t>(capacity * GROWTH_FACTOR));
    }
    
    elements[count] = value;
    ++count;
}

template<typename T>
void Set<T>::remove(const T& value) {
    size_t index = find_index(value);
    if (index < count) {
        for (size_t i = index; i < count - 1; ++i) {
            elements[i] = elements[i + 1];
        }
        --count;
    }
}

template<typename T>
bool Set<T>::contains(const T& value) const {
    return find_index(value) < count;
}

template<typename T>
void Set<T>::clear() {
    count = 0;
}

template<typename T>
T* Set<T>::to_array() const {
    T* result = new T[count];
    for (size_t i = 0; i < count; ++i) {
        result[i] = elements[i];
    }
    return result;
}

#endif
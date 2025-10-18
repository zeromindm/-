#ifndef SET_TPP
#define SET_TPP

#include <random>

template<typename T>
Set<T>::Set() {}

template<typename T>
Set<T>::Set(const std::vector<T>& values) {
    for (const auto& value : values) {
        insert(value);
    }
}

template<typename T>
Set<T>::Set(size_t count, const T& min_val, const T& max_val) {

}

template<typename T>
size_t Set<T>::size() const {
    return elements.size();
}

template<typename T>
bool Set<T>::empty() const {
    return elements.empty();
}

template<typename T>
T Set<T>::operator[](size_t index) const {
    if (index >= elements.size()) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

template<typename T>
void Set<T>::insert(const T& value) {
    if (!contains(value)) {
        elements.push_back(value);
    }
}

template<typename T>
void Set<T>::remove(const T& value) {
    auto it = std::find(elements.begin(), elements.end(), value);
    if (it != elements.end()) {
        elements.erase(it);
    }
}

template<typename T>
bool Set<T>::contains(const T& value) const {
    return std::find(elements.begin(), elements.end(), value) != elements.end();
}

template<typename T>
void Set<T>::clear() {
    elements.clear();
}

template<typename T>
std::vector<T> Set<T>::to_vector() const {
    return elements;
}

#endif 
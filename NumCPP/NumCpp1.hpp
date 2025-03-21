#ifndef NUMCPP_HPP
#define NUMCPP_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

namespace NCPP 
{

    template <typename T>
    class NumCpp 
    {

        private:
            std::vector<T> data;
            std::vector<size_t> shape;
            size_t size;
            size_t ndim;
    
            size_t index(const std::vector<size_t>& indices) const;
    
        public:
            NumCpp(const std::vector<size_t>& sizes);
            T& operator[](const std::vector<size_t>& indices);
            const T& operator[](const std::vector<size_t>& indices) const;
            void print() const;

            #include "NumCpp2.cpp"

            NumCpp<T> operator=(const NumCpp<T>& m);
            NumCpp<T> operator+(const NumCpp<T>& m) const;
            NumCpp<T> operator-(const NumCpp<T>& m) const;
            NumCpp<T> operator*(const NumCpp<T>& m) const;
            NumCpp<T> operator/(const NumCpp<T>& m) const;

            static NumCpp<T> full(const std::vector<size_t>& sizes, const T& value);
            static NumCpp<T> zeros(const std::vector<size_t>& sizes);
            static NumCpp<T> ones(const std::vector<size_t>& sizes);
            static NumCpp<T> linspace(const T& start, const T& stop, size_t num);
            static NumCpp<T> arrange(const std::vector<T>& sizes);
            static NumCpp<T> eye(size_t dim);
            
    };

} 

#endif
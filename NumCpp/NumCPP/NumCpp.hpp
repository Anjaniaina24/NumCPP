#ifndef NUMCPP_HPP
#define NUMCPP_HPP

#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <functional>
#include <set>

namespace NumCPP 
{

    template <typename T>
    class NumCpp
    {

        private:
            std::vector<T> data;
            std::vector<size_t> shape;
            size_t ndim;
            size_t size;

            void calculateShapeAndSize();
            size_t index(const std::vector<size_t>& indices) const;
            void setShape(const std::vector<size_t>& sizes);

        public:
            /// Constructeurs
            NumCpp(T a);
            NumCpp(std::initializer_list<T> init);
            NumCpp(std::initializer_list<NumCpp<T>> init);
            NumCpp(const std::vector<size_t>& taille);

            T& operator[](const std::vector<size_t>& indices);
            const T& operator[](const std::vector<size_t>& indices) const;
            std::vector<T> getData() const;
            std::vector<size_t> getShape() const;
            size_t getNdim() const;
            size_t getSize() const;
            void print();

            /// Array
            static NumCpp<T> array(T a);
            static NumCpp<T> array(std::initializer_list<T> init);
            static NumCpp<T> array(std::initializer_list<NumCpp<T>> init);

            /// Opérateur
            NumCpp<T> operator=(const NumCpp<T>& m);
            NumCpp<T> operator+(const NumCpp<T>& m) const;
            NumCpp<T> operator-(const NumCpp<T>& m) const;
            NumCpp<T> operator*(const NumCpp<T>& m) const;
            NumCpp<T> operator/(const NumCpp<T>& m) const;
            NumCpp<T> operator%(const NumCpp<T>& m) const;

            NumCpp<T> operator+(const T& m) const;
            NumCpp<T> operator-(const T& m) const;
            NumCpp<T> operator*(const T& m) const;
            NumCpp<T> operator/(const T& m) const;
            NumCpp<T> operator%(const T& m) const;

            NumCpp<bool> operator==(const NumCpp<T>& other) const;
            NumCpp<bool> operator!=(const NumCpp<T>& other) const;
            NumCpp<bool> operator<(const NumCpp<T>& other) const;
            NumCpp<bool> operator<=(const NumCpp<T>& other) const;
            NumCpp<bool> operator>(const NumCpp<T>& other) const;
            NumCpp<bool> operator>=(const NumCpp<T>& other) const;

            NumCpp<bool> operator==(const T& scalar) const;
            NumCpp<bool> operator!=(const T& scalar) const;
            NumCpp<bool> operator<(const T& scalar) const;
            NumCpp<bool> operator<=(const T& scalar) const;
            NumCpp<bool> operator>(const T& scalar) const;
            NumCpp<bool> operator>=(const T& scalar) const;

            /// Tableau
            static NumCpp<T> zeros(const std::vector<size_t>& taille);
            static NumCpp<T> ones(const std::vector<size_t>& taille);
            static NumCpp<T> full(const std::vector<size_t>& taille, T value);
            static NumCpp<T> empty(const std::vector<size_t>& taille);
            static NumCpp<T> random(const std::vector<size_t>& sizes, int start=0, int stop=1000);
            NumCpp<T> reshape(const std::vector<size_t>& sizes);
            NumCpp<T> resize(const std::vector<size_t>& sizes);
            NumCpp<T> slice(const size_t& start, size_t stop = 0, const size_t& step = 1);
            static NumCpp<T> where(const NumCpp<bool>& condition, const NumCpp<T>& x, const NumCpp<T>& y);
            NumCpp<T> cumsum() const;
            NumCpp<T> cumprod() const;

            /// Tableau 1D
            static NumCpp<T> linspace(const T& start, const T& stop, size_t num);
            static NumCpp<T> arange(const std::vector<T>& sizes);
            std::vector<T> flatten();
            NumCpp<T> unique() const;

            /// Tableau 2D
            static NumCpp<T> eye(size_t row, size_t col = 0);
            static NumCpp<T> diag(const std::vector<T>& elem);
            static NumCpp<T> vander(const std::vector<T>& elem, size_t col);

            /// Calcul
            T sum();
            T prod();
            T min();
            T max();
            T mean();
            T var();
            T std();
            size_t argmin() const;
            size_t argmax() const;

            /// Manipulation
            NumCpp<T> sort();
            NumCpp<T> transpose();

            /// Math
            NumCpp<T> apply(std::function<T(T)> func) const;
            NumCpp<T> exp();
            NumCpp<T> log();
            NumCpp<T> sqrt();
            NumCpp<T> sin();
            NumCpp<T> cos();
            NumCpp<T> tan();
            NumCpp<T> asin();
            NumCpp<T> acos();
            NumCpp<T> atan();
            NumCpp<T> sinh();
            NumCpp<T> cosh();
            NumCpp<T> tanh();
            NumCpp<T> fabs();
            NumCpp<T> ceil();
            NumCpp<T> floor();

        };

} 

#include "Array.tpp"
#include "NumCpp.tpp"
#include "Tableau.tpp"
#include "Tableau1D.tpp"
#include "Tableau2D.tpp"
#include "Operator.tpp"
#include "Math.tpp"
#include "Calcul.tpp"
#include "Manipulation.tpp"

#endif

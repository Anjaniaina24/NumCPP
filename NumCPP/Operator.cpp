#include "NumCpp1.hpp"

namespace NCPP
{

    template <typename T>
    NumCpp<T> NumCpp<T>::operator=(const NumCpp<T>& m)
    {
        data.clear();
        data.resize(m.size);
        size = m.size;
        shape = m.shape;
        ndim = m.ndim;
        data = m.data;
        return *this;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator+(const NumCpp<T>& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] + m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator-(const NumCpp<T>& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] - m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator*(const NumCpp<T>& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] * m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator/(const NumCpp<T>& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] / m.data[i];
        return result;
    }


template class NumCpp<double>;
template class NumCpp<int>;

}
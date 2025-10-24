
namespace NumCPP
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
        if (shape == m.shape) 
        {
            throw std::invalid_argument("Shapes are not equal for operator+");
        }
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] + m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator-(const NumCpp<T>& m) const
    {
        if (shape == m.shape) 
        {
            throw std::invalid_argument("Shapes are not equal for operator-");
        }
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] - m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator*(const NumCpp<T>& m) const
    {
        if (shape == m.shape) 
        {
            throw std::invalid_argument("Shapes are not equal for operator*");
        }
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] * m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator/(const NumCpp<T>& m) const
    {
        if (shape == m.shape) 
        {
            throw std::invalid_argument("Shapes are not equal for operator/");
        }
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] / m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator%(const NumCpp<T>& m) const
    {
        if (shape == m.shape) 
        {
            throw std::invalid_argument("Shapes are not equal for operator%");
        }
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] % m.data[i];
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator+(const T& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] + m;
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator-(const T& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] - m;
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator*(const T& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] * m;
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator/(const T& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] / m;
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::operator%(const T& m) const
    {
        NumCpp<T> result(shape);
        for(size_t i = 0; i < size; i++)
            result.data[i] = data[i] % m;
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator==(const NumCpp<T>& other) const {
        if (shape != other.shape) {
            throw std::invalid_argument("Shape mismatch in operator==");
        }
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] == other.data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator!=(const NumCpp<T>& other) const {
        if (shape != other.shape) {
            throw std::invalid_argument("Shape mismatch in operator!=");
        }
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] != other.data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator<(const NumCpp<T>& other) const {
        if (shape != other.shape) {
            throw std::invalid_argument("Shape mismatch in operator<");
        }
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] < other.data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator<=(const NumCpp<T>& other) const {
        if (shape != other.shape) {
            throw std::invalid_argument("Shape mismatch in operator<=");
        }
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] <= other.data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator>(const NumCpp<T>& other) const {
        if (shape != other.shape) {
            throw std::invalid_argument("Shape mismatch in operator>");
        }
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] > other.data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator>=(const NumCpp<T>& other) const {
        if (shape != other.shape) {
            throw std::invalid_argument("Shape mismatch in operator>=");
        }
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] >= other.data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator==(const T& scalar) const {
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] == scalar);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator!=(const T& scalar) const {
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] != scalar);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator<(const T& scalar) const {
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] < scalar);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator<=(const T& scalar) const {
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] <= scalar);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator>(const T& scalar) const {
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] > scalar);
        }
        return result;
    }

    template <typename T>
    NumCpp<bool> NumCpp<T>::operator>=(const T& scalar) const {
        NumCpp<bool> result(shape);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = (data[i] >= scalar);
        }
        return result;
    }

}
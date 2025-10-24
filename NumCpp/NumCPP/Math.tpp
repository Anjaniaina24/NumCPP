
namespace NumCPP 
{

    template <typename T>
    NumCpp<T> NumCpp<T>::apply(std::function<T(T)> func) const 
    {
        NumCpp<T> result(shape);
        for (size_t i = 0; i < size; i++) 
        {
            result.data[i] = func(data[i]);
        }
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::exp() 
    {
        return apply(std::exp);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::log() 
    {
        return apply(std::log);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::sqrt() 
    {
        return apply(std::sqrt);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::sin() 
    {
        return apply(std::sin);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::cos() 
    {
        return apply(std::cos);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::tan() 
    {
        return apply(std::tan);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::asin() 
    {
        return apply(std::asin);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::acos() 
    {
        return apply(std::acos);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::atan() 
    {
        return apply(std::atan);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::sinh() 
    {
        return apply(std::sinh);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::cosh() 
    {
        return apply(std::cosh);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::tanh() 
    {
        return apply(std::tanh);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::fabs() 
    {
        return apply(std::fabs);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::ceil() 
    {
        return apply(std::ceil);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::floor() 
    {
        return apply(std::floor);
    }

} 
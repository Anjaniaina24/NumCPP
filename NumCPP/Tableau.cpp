#include "NumCpp1.hpp"

namespace NCPP
{

    template <typename T>
    NumCpp<T> NumCpp<T>::full(const std::vector<size_t>& sizes, const T& value) 
    {
        NumCpp<T> arr(sizes);
        std::fill(arr.data.begin(), arr.data.end(), value);
        return arr;
    }
             
    template <typename T>       
    NumCpp<T> NumCpp<T>::zeros(const std::vector<size_t>& sizes) 
    {
        return NumCpp<T>::full(sizes, T(0));
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::ones(const std::vector<size_t>& sizes) 
    {
        return NumCpp<T>::full(sizes, T(1));
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::linspace(const T& start, const T& stop, size_t num) 
    {
        if (num == 0) {
            throw std::invalid_argument("num must be greater than 0.");
        }
        NumCpp<T> arr({num});
        T step = (stop - start) / (num - 1);
        for (size_t i = 0; i < num; ++i) {
            arr.data[i] = start + i * step;
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::arrange(const std::vector<T>& sizes) 
    {
        T dim(0);
        switch(sizes.size())
        {
            case 1:
                dim = sizes[0];
                break;
            case 2:
                dim = sizes[1] - sizes[0];
                break;
            case 3:
                dim = ceil((sizes[1] - sizes[0]) / sizes[2]);
                break;
        }
        NumCpp<T> arr({(size_t)dim});
        switch(sizes.size())
        {
            case 1:
                for(int i = 0; i < sizes[0]; i++)
                    arr.data[i] = i;
                break;
            case 2:
                for(int i = sizes[0], a = 0; i < sizes[1]; i++, a++)
                    arr.data[a] = i;
                break;
            case 3:
                for(int i = sizes[0], a = 0; i < sizes[1]; a++, i+=sizes[2])
                    arr.data[a] = i;
                break;
        }
        return arr;
    }
    
    template <typename T>
    NumCpp<T> NumCpp<T>::eye(size_t dim)
    {
        NumCpp<T> arr({dim, dim});
        for(size_t i = 0; i < arr.size; i++)
        {
            if(i % (dim + 1) == 0)
                arr.data[i] = 1;
            else    
                arr.data[i] = 0;
        }
        return arr;
    }

template class NumCpp<double>;
template class NumCpp<int>;

}
#include "NumCpp1.hpp"

namespace NCPP
{

template <typename T>
NumCpp<T>::NumCpp(const std::vector<size_t>& sizes) 
{
    dimensions = sizes;
    totalSize = 1;
    for (size_t size : dimensions) {
        totalSize *= size;
    }
    data.resize(totalSize);
}

template <typename T>
size_t NumCpp<T>::index(const std::vector<size_t>& indices) const 
{
    if (indices.size() != dimensions.size()) {
        throw std::invalid_argument("Incorrect number of indices.");
    }
    size_t flatIndex = 0;
    size_t stride = totalSize;
    for (size_t dim = 0; dim < dimensions.size(); ++dim) {
        stride /= dimensions[dim];
        if (indices[dim] >= dimensions[dim]) {
            throw std::out_of_range("Index out of bounds.");
        }
        flatIndex += indices[dim] * stride;
    }
    return flatIndex;
}

template <typename T>
T& NumCpp<T>::operator[](const std::vector<size_t>& indices) 
{
    return data[index(indices)];
}

template <typename T>
const T& NumCpp<T>::operator[](const std::vector<size_t>& indices) const 
{
    return data[index(indices)];
}

template <typename T>
void NumCpp<T>::print() const 
{
    std::cout << "Dimensions : [";
    for (size_t i = 0; i < dimensions.size(); ++i) 
    {  
        std::cout << dimensions[i];
        if (i < dimensions.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
    
    std::cout << "Tableau : \n";
    for (size_t i = 0; i < dimensions.size(); ++i)
        std::cout << "[";
    for (size_t i = 0; i < data.size(); ++i) 
    {
        std::cout << data[i];
                if (i < data.size() - 1)
                    std::cout << ", ";
    }
    for (size_t i = 0; i < dimensions.size(); ++i)
        std::cout << "]";
    std::cout << "\n\n";
}

template class NumCpp<double>;

}

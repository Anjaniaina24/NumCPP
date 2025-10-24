
namespace NumCPP 
{

    template <typename T>
    void NumCpp<T>::calculateShapeAndSize()
    {
        ndim = shape.size();
        size = 1;
        for (const auto& dim : shape)
            size *= dim;
    }

    template <typename T>
    size_t NumCpp<T>::index(const std::vector<size_t>& indices) const 
    {
        if(indices.size() != ndim) 
        {
            throw std::invalid_argument("Incorrect number of indices.");
        }
        size_t flatIndex = 0;
        size_t stride = size;
        for(size_t dim = 0; dim < ndim; ++dim) 
        {
            stride /= shape[dim];
            if (indices[dim] >= shape[dim]) 
            {
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
    std::vector<T> NumCpp<T>::getData() const 
    { 
        return data; 
    }

    template <typename T>
    size_t NumCpp<T>::getNdim() const 
    { 
        return ndim; 
    }

    template <typename T>
    size_t NumCpp<T>::getSize() const  
    { 
        return size; 
    }

    template <typename T>
    std::vector<size_t> NumCpp<T>::getShape() const 
    { 
        return shape; 
    }

    template <typename T>
    void NumCpp<T>::setShape(const std::vector<size_t>& sizes)
    {
        shape = sizes;
        calculateShapeAndSize();
        data.resize(size);
    }

    template <typename T>
    void NumCpp<T>::print()
    {
        std::cout << "Tableau [";
        for (size_t i = 0; i < ndim; ++i)
        {
            std::cout << shape[i];
            if (i != ndim - 1)
                std::cout << ", ";
        }
        std::cout << "] : " << std::endl;

        for (size_t i = 0; i < ndim; ++i)
                std::cout << "[";
            for (size_t i = 0; i < size; ++i) 
            {
                std::cout << data[i];
                size_t div(1);
                for (size_t j = 0; j < ndim; ++j) 
                {
                    div *= shape[ndim-1-j];
                    if((i % div == div-1) && i != 0 && i != size - 1)
                    {
                        std::cout << "]";
                    }
                }
                if (i < size - 1)
                {
                    std::cout << ", ";
                }
                div = 1;
                for (size_t j = 0; j < ndim; ++j) 
                {
                    div *= shape[ndim-1-j];
                    if((i % div == div-1) && i != 0 && i != size - 1)
                    {
                        std::cout << "[";
                    }
                }
            }
            for (size_t i = 0; i < ndim; ++i)
                std::cout << "]";
        std::cout << std::endl << std::endl;
    }

} 

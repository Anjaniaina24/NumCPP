
namespace NumCPP 
{

    template <typename T>
    NumCpp<T> NumCpp<T>::full(const std::vector<size_t>& taille, T value)
    {
        NumCpp<T> result(taille);
        std::fill(result.data.begin(), result.data.end(), value);
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::zeros(const std::vector<size_t>& taille)
    {
        return NumCpp<T>::full(taille, T(0));
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::ones(const std::vector<size_t>& taille)
    {
        return NumCpp<T>::full(taille, T(1));
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::empty(const std::vector<size_t>& taille)
    {
        return NumCpp<T>(taille);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::random(const std::vector<size_t>& sizes, int start, int stop)
    {
        NumCpp<T> arr(sizes);
        for(size_t i = 0; i < arr.size; i++)
        {
            arr.data[i] = (rand() % stop-start)+start;
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::reshape(const std::vector<size_t>& sizes)
    {
        size_t n_size = 1;
        for(auto i: sizes)
        {
            n_size *= i;
        }
        if(n_size != size) 
        {
            throw std::invalid_argument("Reshape impossible : la taille totale ne correspond pas.");
        }
        NumCpp<T> arr(sizes);
        arr = *this;
        arr.setShape(sizes);
        return arr;
    }
   
    template <typename T>
    NumCpp<T> NumCpp<T>::resize(const std::vector<size_t>& sizes)
    {
        size_t n_size = 1;
        size_t m_size = size;
        for(auto i: sizes)
        {
            n_size *= i;
        }
        NumCpp<T> arr(sizes);
        arr = *this;
        arr.setShape(sizes);
        if(n_size > m_size)
        {
            NumCpp<T> temp = *this;
            setShape(sizes);
            for(size_t i = m_size; i < n_size; i++)
            {
                data[i] = data[i%m_size];
            }
            arr = *this;
            *this = temp;
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::slice(const size_t& start, size_t stop, const size_t& step)
    {
        NumCpp<T> arr(shape);
        if(ndim == 1)
        {
            stop = (stop == 0) ? ndim : stop;
            arr = arr.resize({(stop-start)/step});
            int j = 0;
            for(size_t i = start; i < stop; i+=step)
            {
                arr.data[j] = data[i];
                j++;
            }
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::where(const NumCpp<bool>& condition, const NumCpp<T>& x, const NumCpp<T>& y)
    {
        if (condition.getShape() != x.getShape() || x.getShape() != y.getShape())
        {
            throw std::invalid_argument("Shape mismatch in NumCpp::where()");
        }
        NumCpp<T> result(x.getShape());
        for (size_t i = 0; i < x.getSize(); ++i)
        {
            result.data[i] = condition.data[i] ? x.data[i] : y.data[i];
        }
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::cumsum() const {
        NumCpp<T> result = *this;
        if (size == 0) 
        return result;
        for (size_t i = 1; i < size; ++i) 
        {
            result.data[i] = result.data[i - 1] + data[i];
        }
        return result;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::cumprod() const {
        NumCpp<T> result = *this; 
        if (size == 0) 
            return result;
        for (size_t i = 1; i < size; ++i) 
        {
            result.data[i] = result.data[i - 1] * data[i];
        }
        return result;
    }

} 

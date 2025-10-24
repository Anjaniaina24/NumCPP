
namespace NumCPP 
{

    template <typename T>
    NumCpp<T> NumCpp<T>::linspace(const T& start, const T& stop, size_t num) 
    {
        if (num == 0) 
        {
            throw std::invalid_argument("num must be greater than 0.");
        }
        NumCpp<T> arr(std::vector<size_t>({num}));
        T step = (stop - start) / (num - 1);
        for (size_t i = 0; i < num; ++i) {
            arr.data[i] = start + i * step;
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::arange(const std::vector<T>& sizes) 
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
                dim = std::ceil((sizes[1] - sizes[0]) / sizes[2]);
                break;
        }
        NumCpp<T> arr(std::vector<size_t>({(size_t)dim}));
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
    std::vector<T> NumCpp<T>::flatten()
    {
        return data;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::unique() const
    {
        std::set<T> unique_set(data.begin(), data.end());
        std::vector<T> unique_vec(unique_set.begin(), unique_set.end());
        return NumCpp<T>(unique_vec);
    }

} 

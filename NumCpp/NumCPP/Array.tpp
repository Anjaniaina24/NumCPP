
namespace NumCPP 
{

    template <typename T>
    NumCpp<T>::NumCpp(T a)
    {
        data.push_back(a);
        shape = {1};
        calculateShapeAndSize();
    }

    template <typename T>
    NumCpp<T>::NumCpp(std::initializer_list<T> init)
    {
        data.insert(data.end(), init.begin(), init.end());
        shape = {init.size()};
        calculateShapeAndSize();
    }

    template <typename T>
    NumCpp<T>::NumCpp(std::initializer_list<NumCpp<T>> init)
    {
        for (const auto& e : init)
            data.insert(data.end(), e.data.begin(), e.data.end());

        shape.push_back(init.size());

        if (!init.begin()->shape.empty())
            shape.insert(shape.end(), init.begin()->shape.begin(), init.begin()->shape.end());

        calculateShapeAndSize();
    }

    template <typename T>
    NumCpp<T>::NumCpp(const std::vector<size_t>& taille)
    {
        shape = taille;
        calculateShapeAndSize();
        data.resize(size); 
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::array(T a)
    {
        return NumCpp<T>(a);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::array(std::initializer_list<T> init)
    {
        return NumCpp<T>(init);
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::array(std::initializer_list<NumCpp<T>> init)
    {
        return NumCpp<T>(init);
    }

} 
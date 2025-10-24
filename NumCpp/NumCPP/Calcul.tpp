
namespace NumCPP
{

    template <typename T>
    T NumCpp<T>::sum()
    {
        return accumulate(std::cbegin(data), std::cend(data), T(0));
    }

    template <typename T>
    T NumCpp<T>::prod()
    {
        return accumulate(std::cbegin(data), std::cend(data), T(1), std::multiplies<int> {});
    }

    template <typename T>
    T NumCpp<T>::min()
    {
        return *std::min_element(data.begin(), data.end());
    }

    template <typename T>
    T NumCpp<T>::max()
    {
        return *std::max_element(data.begin(), data.end());
    }

    template <typename T>
    T NumCpp<T>::mean()
    {
        return float(sum()) / size;
    }

    template <typename T>
    T NumCpp<T>::var()
    {
        T m = mean();
        T variance = T(0);
        for (const auto& val : data)
        {
            variance += (val - m) * (val - m);
        }
        return variance / static_cast<T>(size);
    }

    template <typename T>
    T NumCpp<T>::std()
    {
        return std::sqrt(var());
    }

    template <typename T>
    size_t NumCpp<T>::argmin() const
    {
        if (data.empty())
            throw std::runtime_error("argmin() called on empty array");

        auto min_iter = std::min_element(data.begin(), data.end());
        return static_cast<size_t>(std::distance(data.begin(), min_iter));
    }

    template <typename T>
    size_t NumCpp<T>::argmax() const
    {
        if (data.empty())
            throw std::runtime_error("argmax() called on empty array");

        auto max_iter = std::max_element(data.begin(), data.end());
        return static_cast<size_t>(std::distance(data.begin(), max_iter));
    }

}
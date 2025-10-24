
namespace NumCPP
{

    template <typename T>
    NumCpp<T> NumCpp<T>::sort()
    {
        NumCpp<T> arr = *this;
        std::sort(std::begin(arr.data), std::end(arr.data));
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::transpose()
    {
        if (ndim != 2) {
            throw std::invalid_argument("Transpose is only implemented for 2D arrays.");
        }
        size_t rows = shape[0];
        size_t cols = shape[1];
        std::vector<size_t> newShape = {cols, rows};
        NumCpp<T> result(newShape);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[{j, i}] = (*this)[{i, j}];
            }
        }
        return result;
    }

}
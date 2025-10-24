
namespace NumCPP 
{

    template <typename T>
    NumCpp<T> NumCpp<T>::eye(size_t row, size_t col)
    {
        col = (col == 0) ? row : col;
        NumCpp<T> arr(std::vector<size_t>({row, col}));
        for(size_t i = 0; i < arr.size; i += col + 1)
        {
            arr.data[i] = 1;
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::diag(const std::vector<T>& elem)
    {
        size_t dim = elem.size();
        NumCpp<T> arr(std::vector<size_t>({dim, dim}));
        for(size_t i = 0, j = 0; i < arr.size; i += dim + 1, j++)
        {
            arr.data[i] = elem[j];
        }
        return arr;
    }

    template <typename T>
    NumCpp<T> NumCpp<T>::vander(const std::vector<T>& elem, size_t col)
    {
        size_t row = elem.size();
        NumCpp<T> arr(std::vector<size_t>({row, col}));
        for(size_t i = 0; i < row; i++)
        {
            for(size_t j = 0; j < col; j++)
            {
                arr[{i, j}] = pow(elem[i], col-1-j);
            }
        }
        return arr;
    }

} 

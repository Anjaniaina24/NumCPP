template <typename U>
void flatten(const U& input, std::vector<T>& output) 
{
    if constexpr (std::is_same_v<U, std::vector<T>>) 
    {
        output.insert(output.end(), input.begin(), input.end());
    } else 
    {
        for (const auto& element : input) 
        {
            flatten(element, output);
        }
    }
}
    
template <typename U>
static std::vector<size_t> getshape(const U& input) 
{
    std::vector<size_t> dims;
    getshapeRecursively(input, dims);
    return dims;
}
    
template <typename U>
static void getshapeRecursively(const U& input, std::vector<size_t>& dims) 
{
    
    if constexpr (std::is_same_v<U, std::vector<T>>) 
    {
        dims.push_back(input.size());  
    } else 
    {
        dims.push_back(input.size());  
        getshapeRecursively(input[0], dims);
    }
}
    
template <typename U>
static NumCpp<T> array(const U& input) 
{
    NumCpp<T> arr(getshape(input));
    std::vector<T> flattenedData;
    arr.flatten(input, flattenedData);
    arr.data = flattenedData;
    return arr;
}
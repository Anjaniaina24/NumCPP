#ifndef NUMCPP_HPP
#define NUMCPP_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

namespace NCPP 
{

    template <typename T>
    class NumCpp 
    {

        private:
            std::vector<T> data;
            std::vector<size_t> dimensions;
            size_t totalSize;
    
            size_t index(const std::vector<size_t>& indices) const;
    
        public:
            NumCpp(const std::vector<size_t>& sizes);
            T& operator[](const std::vector<size_t>& indices);
            const T& operator[](const std::vector<size_t>& indices) const;
            void print() const;

            template <typename U>
            void flatten(const U& input, std::vector<T>& output) {
                if constexpr (std::is_same_v<U, std::vector<T>>) {
                    output.insert(output.end(), input.begin(), input.end());
                } else {
                    for (const auto& element : input) {
                        flatten(element, output);
                    }
                }
            }
    
            template <typename U>
            static std::vector<size_t> getDimensions(const U& input) {
                std::vector<size_t> dims;
                getDimensionsRecursively(input, dims);
                return dims;
            }
    
            template <typename U>
            static void getDimensionsRecursively(const U& input, std::vector<size_t>& dims) {
                if constexpr (std::is_same_v<U, std::vector<T>>) {
                    dims.push_back(input.size());  
                } else {
                    dims.push_back(input.size());  
                    getDimensionsRecursively(input[0], dims);
                }
            }
    
            template <typename U>
            static NumCpp<T> array(const U& input) {
                NumCpp<T> arr({});
                arr.dimensions = getDimensions(input);
    
                std::vector<T> flattenedData;
                arr.flatten(input, flattenedData);
                arr.data = flattenedData; 
                return arr;
            }
    
    };

}

#endif

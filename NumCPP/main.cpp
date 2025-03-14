#include "NumCpp1.hpp"

using namespace NCPP;

int main() 
{

    std::vector<double> array1D = {1.0, 2.0, 3.0, 4.0, 5.0};
    NumCpp<double> arrayFlattened1D = NumCpp<double>::array(array1D);
    std::cout << "Tableau 1D aplati et dimensions :\n";
    arrayFlattened1D.print();

    std::vector<std::vector<double>> array2D = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    NumCpp<double> arrayFlattened2D = NumCpp<double>::array(array2D);
    std::cout << "Tableau 2D aplati et dimensions :\n";
    arrayFlattened2D.print();

    std::vector<std::vector<std::vector<double>>> array3D = {
        {
            {1.0, 2.0}, {3.0, 4.0}
        },
        {
            {5.0, 6.0}, {7.0, 8.0}
        },
        {
            {9.0, 10.0}, {11.0, 12.0}
        }
    };
    NumCpp<double> arrayFlattened3D = NumCpp<double>::array(array3D);
    std::cout << "Tableau 3D aplati et dimensions :\n";
    arrayFlattened3D.print();

    std::vector<std::vector<std::vector<std::vector<double>>>> array4D = {
        {
            {
                {1.0, 2.0}, {3.0, 4.0}
            },
            {
                {5.0, 6.0}, {7.0, 8.0}
            }
        },
        {
            {
                {9.0, 10.0}, {11.0, 12.0}
            },
            {
                {13.0, 14.0}, {15.0, 16.0}
            }
        }
    };
    NumCpp<double> arrayFlattened4D = NumCpp<double>::array(array4D);
    std::cout << "Tableau 4D aplati et dimensions :\n";
    arrayFlattened4D.print();

    return 0;
}

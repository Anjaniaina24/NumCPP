#include "NumCpp1.hpp"

using namespace NCPP;

int main() 
{

    // Exemple 1 : Tableau 1D
    std::vector<double> array1D = {1.0, 2.0, 3.0, 4.0, 5.0};
    NumCpp<double> arrayFlattened1D = NumCpp<double>::array(array1D);
    std::cout << "Tableau 1D aplati et shape :\n";
    arrayFlattened1D.print();

    // Exemple 2 : Tableau 2D (vector de vector)
    std::vector<std::vector<double>> array2D = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    NumCpp<double> arrayFlattened2D = NumCpp<double>::array(array2D);
    std::cout << "Tableau 2D aplati et shape :\n";
    arrayFlattened2D.print();

    // Exemple 3 : Tableau 3D (vector de vector de vector)
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
    std::cout << "Tableau 3D aplati et shape :\n";
    arrayFlattened3D.print();

    // Exemple 4 : Tableau 4D (vector de vector de vector de vector)
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
    std::cout << "Tableau 4D aplati et shape :\n";
    arrayFlattened4D.print();

    // Exemple de zeros
    NumCpp<double> arrZeros = NumCpp<double>::zeros({3, 3});
    std::cout << "Tableau de zéros 3x3 :\n";
    arrZeros.print();

    // Exemple de ones
    NumCpp<double> arrOnes = NumCpp<double>::ones({2, 4});
    std::cout << "Tableau de uns 2x4 :\n";
    arrOnes.print();

    // Exemple de full
    NumCpp<double> arrFull = NumCpp<double>::full({2, 3}, 7.5);
    std::cout << "Tableau rempli de 7.5 2x3 :\n";
    arrFull.print();

    // Exemple de linspace
    NumCpp<double> arrLinspace = NumCpp<double>::linspace(0.0, 1.0, 5);
    std::cout << "Tableau linspace de 5 éléments entre 0 et 1 :\n";
    arrLinspace.print();

    // Exemple de arrange
    NumCpp<double> arrArrange1 = NumCpp<double>::arrange({4});
    std::cout << "Tableau arrange :\n";
    arrArrange1.print();

    // Exemple de arrange
    NumCpp<double> arrArrange2 = NumCpp<double>::arrange({3, 9});
    std::cout << "Tableau arrange :\n";
    arrArrange2.print();

    // Exemple de arrange
    NumCpp<double> arrArrange3 = NumCpp<double>::arrange({3, 8, 2});
    std::cout << "Tableau arrange :\n";
    arrArrange3.print();

    // Exemple de eye
    NumCpp<double> arreye = NumCpp<double>::eye(3);
    std::cout << "Tableau eye :\n";
    arreye.print();

    return 0;
}

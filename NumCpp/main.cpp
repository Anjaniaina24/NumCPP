#include "NumCPP/NumCpp.hpp"

using namespace NumCPP;

int main()
{

    auto scalar = NumCpp<int>::array(42);
    scalar.print();

    auto oneD = NumCpp<int>::array({10, 20, 30});
    oneD.print();

    auto twoD = NumCpp<int>::array({{1, 2}, {3, 4}});
    twoD.print();

    auto threeD = NumCpp<int>::array({{{1, 2}, {3, 4}},{{1, 2}, {3, 4}}});
    threeD.print();

    auto z = NumCpp<int>::zeros({2, 2});
    z.print();

    auto o = NumCpp<int>::ones({2, 3});
    o.print();

    auto f = NumCpp<int>::full({2, 2}, 7);
    f.print();

    auto e = NumCpp<int>::empty({3, 3});
    e.print();

    auto arreye = NumCpp<int>::eye(3, 5);
    arreye.print();

    auto arrdiag = NumCpp<double>::diag({1, 2, 3, 4});
    arrdiag.print();

    auto arrvander = NumCpp<double>::vander({1, 2, 3, 4}, 5);
    arrvander.print();

    auto arrLinspace = NumCpp<double>::linspace(0.0, 1.0, 5);
    arrLinspace.print();

    auto arrarange1 = NumCpp<double>::arange({4});
    arrarange1.print();

    auto arrarange2 = NumCpp<double>::arange({3, 9});
    arrarange2.print();

    auto arrarange3 = NumCpp<double>::arange({3, 8, 2});
    arrarange3.print();

    return 0;
}

#include <iostream>
#include <callable_range_accrual.h>

int main() {
    std::cout << "hello, this is a test main !";

    CallableRangeAccrual cra(
        ql::Date(14, ql::July, 2016),
        ql::Date(14, ql::July, 2018),
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        3,
        6,
        ql::Rate(0.052),
        ql::Rate(0.04),
        ql::Rate(0.03)
    );
    return EXIT_SUCCESS;
}

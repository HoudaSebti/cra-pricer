#include <iostream>

#include <callable_range_accrual.h>
#include <models.h>
#include <utilities.h>


int main() {
    std::cout << "hello, this is a test main !";

    CallableRangeAccrual<ql::Rate> cra(
        ql::Date(14, ql::June, 2016),
        ql::Date(14, ql::June, 2018),
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        3,
        6,
        ql::Rate(0.052),
        ql::Rate(0.04),
        ql::Rate(0.03)
    );
    
    generateZeroCurveTermStructure(
        ql::Date(14, ql::June, 2016),
        ql::Date(14, ql::June, 2018),
        ql::Rate(.04),
        ql::Rate(.08),
        ql::DayCounter(ql::Actual360())
    );

    return EXIT_SUCCESS;
}

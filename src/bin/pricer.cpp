#include <iostream>
#include <callable_range_accrual.h>

int main() {
    std::cout << "hello, this is a test main !";
    ql::Date startDate(14, ql::July, 2016);
    ql::Date endDate(14, ql::July, 2018);


    CallableRangeAccrual cra(
        ql::Rate(0.052),
        ql::Rate(0.04),
        ql::Rate(0.03)
    );
    std::cout << "created the CRA variable";
    return(EXIT_SUCCESS);
}

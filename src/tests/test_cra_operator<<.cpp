#include<callable_range_accrual.h>
#include<iostream>

#include<catch.hpp>

TEST_CASE("operator << for callable range accruals", "operator << for cra"){

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

    std::ostringstream testStream;
    testStream << cra;

    std::ostringstream expectedStream;
    expectedStream << 
        "Callable range accrual contract info:\n" <<

        "start date: "             << ql::Date(14, ql::July, 2016) << '\n' <<
        "end date: "               << ql::Date(14, ql::July, 2018) << '\n' <<

        "payoff: "                 << ql::Rate(0.052) << '\n' <<
        "max rate of the range : " << ql::Rate(0.04) << '\n' <<
        "min rate of the range : " << ql::Rate(0.03) << '\n' <<

        "fixed increment: "    << 3 * 30 << "days" << '\n' <<
        "variable increment: " << 6 * 30 << "days";

    REQUIRE(
        testStream.str().compare(expectedStream.str()) == 0
    );
}
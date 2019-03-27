#include<iostream>

#include<catch2/catch.hpp>

#include<callable_range_accrual.h>
#include <callable_range_accrual_impl.ipp>
#include <dummy_model.h>


TEST_CASE("cra constructor for open start and end dates"){

    CallableRangeAccrual<ql::Rate> cra(
        ql::Date(14, ql::June, 2016),
        ql::Date(14, ql::June, 2018),
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        3,
        6,
        6,
        ql::Rate(0.052),
        ql::Rate(0.03),
        1000000.0,
        ql::Rate(0.04),
        ql::Rate(0.03)
    );

    std::ostringstream testStream;
    testStream << cra;

    std::ostringstream expectedStream;
    expectedStream <<         
        "Callable range accrual contract info:" << std::endl <<

        "start date: "             << ql::Date(14, ql::June, 2016) << std::endl <<
        "end date: "               << ql::Date(14, ql::June, 2018) << std::endl <<

        "max range of the range : " << ql::Rate(0.04)  << std::endl <<
        "min range of the range : " << ql::Rate(0.03)  << std::endl <<

        "payoff: "                 << ql::Rate(0.052) << std::endl <<
        "fixed rate: "             << ql::Rate(0.03)  << std::endl <<
        "cra.fixedLegTenor[1]= "   << ql::Date(14, ql::September, 2016) << std::endl <<
        "cra.varLegTenor  [1]= "   << ql::Date(14, ql::December, 2016 ) << std::endl <<

        "size of fixed tenor: "    << 9 << std::endl <<
        "size of variable tenor: " << 5;

        

    REQUIRE(
         testStream.str().compare(expectedStream.str()) == 0
    );
}

 TEST_CASE("cra constructor for closed start date"){

    REQUIRE_THROWS(
        CallableRangeAccrual<ql::Rate>(
            ql::Date(17, ql::January, 2016),
            ql::Date(17, ql::January, 2018),
            ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
            3,
            6,
            6,
            ql::Rate(0.052),
            ql::Rate(0.03),
            1000000.0,
            ql::Rate(0.04),
            ql::Rate(0.03)
        )
    );
 }

 TEST_CASE("cra fixed coupon test for fixedLegTenor[1] > endDate"){
    
    CallableRangeAccrual<ql::Rate> cra(
        ql::Date(19, ql::December, 2016),
        ql::Date(17, ql::December, 2018),
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        3,
        6,
        6,
        ql::Rate(0.052),
        ql::Rate(0.03),
        1000000.0,
        ql::Rate(0.04),
        ql::Rate(0.03)
    );

    auto fixedCoupon = cra.computeFixedLeg(
        ql::Date(17, ql::December, 2016),
        ql::Date(17, ql::February, 2017),
        5.75 / 100.0
    );

    REQUIRE(
        fixedCoupon == 0.0
    );
 }

TEST_CASE("cra fixed coupon test for fixedLegTenor[1] < endDate"){
    
    CallableRangeAccrual<ql::Rate> cra(
        ql::Date(19, ql::December, 2016),
        ql::Date(17, ql::December, 2018),
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        3,
        6,
        6,
        ql::Rate(0.052),
        ql::Rate(0.03),
        1000000.0,
        ql::Rate(0.04),
        ql::Rate(0.03)
    );

    std::cout << cra;

    auto fixedCoupon = cra.computeFixedLeg(
        ql::Date(19, ql::December, 2016),
        ql::Date(17, ql::April, 2017),
        5.75 / 100.0
    );

    auto expectedValue = 
        .03 *
        1000000.0 *
        ql::daysBetween(ql::Date(19, ql::December, 2016), ql::Date(17, ql::March, 2017)) / 365.0 *
        exp(5.75 / 100.0 * ql::daysBetween(ql::Date(17, ql::March, 2017), ql::Date(17, ql::April, 2017)) / 365.0);

    REQUIRE(
        fixedCoupon == expectedValue
    );
 }

TEST_CASE("variable leg test"){
    CallableRangeAccrual<ql::Rate> cra(
        ql::Date(19, ql::December, 2016),
        ql::Date(17, ql::December, 2018),
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        1,
        1,
        1,
        ql::Rate(0.052),
        ql::Rate(0.03),
        1000000.0,
        ql::Rate(0.04),
        ql::Rate(0.03)
    );
    DummyModel dummyModel = DummyModel();
    
    auto path(
        dummyModel.generatePath(
            ql::Date(19, ql::December, 2016),
            ql::Date(25, ql::January, 2017),
            ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex))
        )
    );
    auto variableCoupon = cra.computeVariableLeg(
        path,
        ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex)),
        ql::Date(19, ql::December, 2016),
        ql::Date(20, ql::January, 2017),
        5.75 / 100.0
    );

    REQUIRE(
        variableCoupon == 0.0
    );
}
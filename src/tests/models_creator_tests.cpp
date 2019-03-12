#include<rate_models.h>
#include<dummy_model.h>
#include<black_scholes.h>
#include<iostream>

#include<catch2/catch.hpp>


TEST_CASE("daysBetween(startDate, endDate) modulus 365 is less than liborDaysToMaturity (3 months)"){

    ql::Size size(
        getProcessSize(
            ql::Date(14, ql::January, 2018),
            ql::Date(14, ql::February, 2019),
            365 / 4
        )
    );
    REQUIRE(
         size == 4
    );
}

TEST_CASE("daysBetween(startDate, endDate) modulus 365 is greater than liborDaysToMaturity (3 months)"){
    ql::Size size(
        getProcessSize(
            ql::Date(14, ql::January, 2018),
            ql::Date(14, ql::April, 2019),
            365 / 4
        )
    );
    REQUIRE(
         size == 5
    );
}

TEST_CASE("creating a dummy model"){
    DummyModel dummyModel();
    
}
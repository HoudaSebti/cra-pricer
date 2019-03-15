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

TEST_CASE("Black Scholes simulation for t = 0"){
    BlackScholes blackScholesModel(100.0, .15, .2);
    auto S0(blackScholesModel.simulateValue(0));
    REQUIRE(
        S0 == 100.0
    );
}

TEST_CASE("Black Scholes simulation for sigma = 0"){
    BlackScholes blackScholesModel(100.0, .15, .0);
    
    for(int t = 0; t < 100; ++t)
    {
        auto S_t(blackScholesModel.simulateValue(t));
        REQUIRE(
            S_t == 100.0 * exp(.15 * t)
        );
    }
        
    
}
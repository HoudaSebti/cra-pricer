#include<rate_models.h>
#include<dummy_model.h>
#include<black_scholes.h>

#include <math.h>
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
            S_t == 100.0 * exp(.15 * t / 365.0)
        );
    } 
}

TEST_CASE(" Black scholes expectancy check"){
    BlackScholes blackScholesModel(100.0, .15, .2);
    double sumLogS_2 = 0.0;
    int nbSimulations = 1000000;
    for(int n = 0; n < nbSimulations; ++n)
        sumLogS_2 += log(blackScholesModel.simulateValue(2) / 100.0);
    
    auto error = sumLogS_2 / nbSimulations - (.15 - pow(.2 , 2) / 2) * (2 / 365.0);
    auto stdDeviation = .2 / sqrt(nbSimulations);
    REQUIRE(
        abs(error) <= 3 * stdDeviation
    );
    
}

TEST_CASE("generate path with dummy model"){
    DummyModel dummyModel = DummyModel();
    
    auto path(
        dummyModel.generatePath(
            ql::Date(14, ql::January, 2018),
            ql::Date(14, ql::February, 2019),
            ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex))
        )
    );
    for(int i = 0; i < path.getSize(); ++i){
        REQUIRE(path.getElement(i) == 0.0);
    }
}

TEST_CASE("generate path with black scholes model"){
    BlackScholes bsModel(100.0, .15, .2);
    
    auto path(
        bsModel.generatePath(
            ql::Date(14, ql::January, 2017),
            ql::Date(14, ql::February, 2019),
            ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex))
        )
    );
    
}

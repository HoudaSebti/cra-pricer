
#include <path.h>
#include <path_impl.ipp>
#include<black_scholes.h>

#include<catch2/catch.hpp>


TEST_CASE("testing saveTo csv file method"){
    BlackScholes bsModel(100.0, .15, .2);
    
    auto path(
        bsModel.generatePath(
            ql::Date(14, ql::January, 2017),
            ql::Date(14, ql::February, 2019),
            ql::Germany(ql::Germany::Market(ql::Germany::Market::Eurex))
        )
    );
    std::vector<Path<double>> paths{{path}};
    saveToCsv("~/Workspace/Projects/houda/cra_pricer.csv", paths);
    
}

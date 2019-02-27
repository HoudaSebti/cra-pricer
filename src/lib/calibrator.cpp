#include<calibrator.h>

#include <ql/legacy/libormarketmodels/lfmprocess.hpp>
#include <ql/legacy/libormarketmodels/liborforwardmodel.hpp>
#include <ql/indexes/ibor/euribor.hpp>
#include <ql/time/daycounters/actual360.hpp>


ql::StochasticProcess & generateProcess(
    ModelName const& modelName,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
){
    switch(modelName){
        case LiborMarketModel_Euribor6M:{
             ql::LiborForwardModelProcess process(
                getProcessSize(
                        startDate,
                        endDate,
                        365 / 2
                    ),
                boost::shared_ptr<ql::Euribor6M>(
                    new ql::Euribor6M(
                        ql::Handle<ql::YieldTermStructure>(termStructure)
                   ) 
                )
            );
            return process;
        }

        case LiborMarketModel_Euribor1Y:{
             std::runtime_error("process generator for LiborMarketModel_Euribor1Y not supported yet !");
        }
    
        case HestonModel:{
            std::runtime_error("process generator for HEstonModel not supported yet !");
        }
            
            
    // boost::shared_ptr<LmCorrelationModel> corrModel(
    //                             new LmExponentialCorrelationModel(size, 0.5));

    // boost::shared_ptr<LmVolatilityModel> volaModel(
    //     new LmLinearExponentialVolatilityModel(process->fixingTimes(),
    //                                            0.291, 1.483, 0.116, 0.00001));



    //         break;
    }

}

ql::Size getProcessSize(
    ql::Date const& startDate,
    ql::Date const& endDate,
    int const& liborDaysToMaturity
){
    return static_cast<int>(daysBetween(startDate, endDate)) / liborDaysToMaturity;
}


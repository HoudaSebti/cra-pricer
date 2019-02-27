#include<calibrator.h>

#include <ql/indexes/ibor/euribor.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/legacy/libormarketmodels/lmlinexpvolmodel.hpp>
#include <ql/legacy/libormarketmodels/lmlinexpcorrmodel.hpp>


ql::CalibratedModel generateModel(
    ModelName const& modelName,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
){
    switch(modelName){
        case LiborMarketModel_Euribor6M:
            return generateLmmModel(
                generateLMMProcess(
                    ql::Period(6, ql::Months),
                    termStructure,
                    startDate,
                    endDate,
                    calendar
                )
            );
        case LiborMarketModel_Euribor1Y:
             return generateLmmModel(
                generateLMMProcess(
                    ql::Period(1, ql::Years),
                    termStructure,
                    startDate,
                    endDate,
                    calendar
                )
            );
        case HestonModel:
            std::runtime_error("process generator for HEstonModel not supported yet !");   
    }
}

ql::LiborForwardModelProcess generateLMMProcess(
    ql::Period const& lmmMaturity,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
){
    ql::LiborForwardModelProcess process(
                getProcessSize(
                        startDate,
                        endDate,
                        static_cast<int>(days(lmmMaturity))
                    ),
                boost::shared_ptr<ql::Euribor>(
                    new ql::Euribor(
                        lmmMaturity,
                        ql::Handle<ql::YieldTermStructure>(termStructure)
                    ) 
                )
            );
            return process;
}

ql::LiborForwardModel generateLmmModel(
    ql::LiborForwardModelProcess process
){
    return(
                ql::LiborForwardModel(
                    boost::shared_ptr<ql::LiborForwardModelProcess>(& process),
                    boost::shared_ptr<ql::LmLinearExponentialVolatilityModel>(
                        new ql::LmLinearExponentialVolatilityModel(
                            process.fixingTimes(),
                            .5,
                            .6,
                            .1,
                            .1
                        )
                    ),
                    boost::shared_ptr<ql::LmLinearExponentialCorrelationModel>(
                        new ql::LmLinearExponentialCorrelationModel(
                            process.size(),
                            .5,
                            .8
                        )
                    )    
                )
            );
}

ql::Size getProcessSize(
    ql::Date const& startDate,
    ql::Date const& endDate,
    int const& liborDaysToMaturity
){
    return static_cast<int>(daysBetween(startDate, endDate)) / liborDaysToMaturity;
}

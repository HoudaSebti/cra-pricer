#pragma<once>

#include<definitions.h>

#include <ql/handle.hpp>
#include <ql/legacy/libormarketmodels/lfmprocess.hpp>
#include <ql/legacy/libormarketmodels/liborforwardmodel.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>

// supported rate model names
enum RateModelName{
    LiborMarketModel_Euribor6M,
    LiborMarketModel_Euribor1Y,
    HestonModel
};

ql::CalibratedModel generateRateModel(
    RateModelName const& modelName,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
);

ql::LiborForwardModelProcess generateLMMProcess(
    ql::Period const& lmmMaturity,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
);

ql::LiborForwardModel generateLmmModel(
    ql::LiborForwardModelProcess & process,
    ql::Real a = .5,
    ql::Real b = .6,
    ql::Real c =.1,
    ql::Real d =.1   
);

ql::Size getProcessSize(
    ql::Date const& startDate,
    ql::Date const& endDate,
    int const& liborDaysToMaturity 
);


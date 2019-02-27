#pragma<once>

#include<definitions.h>

#include <ql/stochasticprocess.hpp>
#include <ql/handle.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>


// supported model names
enum ModelName {
    LiborMarketModel_Euribor6M,
    LiborMarketModel_Euribor1Y,
    HestonModel
};

ql::StochasticProcess & generateProcess(
    ModelName const& modelName,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
);

ql::Size getProcessSize(
    ql::Date const& startDate,
    ql::Date const& endDate,
    int const& liborDaysToMaturity  
);

void calibrate(ql::CalibratedModel model, std::vector<std::istream> const& data);
//void calibrateOtherModel(...)

#pragma once

#include<definitions.h>
#include<black_scholes.h>

template <typename Underlying_type>
std::vector<Underlying_type> generatePath(
    Model model,
    ql::Date startDate,
    ql::Date endDate,
    ql::Calendar calendar
){
    if(typeid(model) == typeid(BlackScholes)){
        std::vector<Underlying_type> path;
        path.reserve(calendar.businessDaysBetween(startDate, endDate) + 1);
        ql::Date date(startDate);
        int daysFromStartDate = 0;
        while(date <= endDate){
            path.push_back(model.simulateValue(daysFromStartDate));
            date = calendar.advance(date, 1, ql::Days, ql::BusinessDayConvention::Preceding);
            daysFromStartDate++;
        }
        return path;
    }
    else if (typeid(model) == typeid(RateModels))
    {
        std::error("path generator does not support the rate models yet");
    }
    else
        std::error("path generator does not support the class of your model");
}
template <typename Underlying_type>
class Path{
    public:
        double computeCashFlow(
            ql::Date startDate,
            ql::Date endDate,
            ql::Rate payoff,
            Underlying_type rangeMax,
            Underlying_type rangeMin
        );
    private:
        double computeFixedLeg(ql::Rate fixedRate, double fixedIncrementInYears);
    
};


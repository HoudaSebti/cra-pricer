#pragma once

#include <definitions.h>
#include <vector>

class CallableRangeAccrual
{
    public:
        CallableRangeAccrual();
        CallableRangeAccrual(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar,
            int fixedIncrement,
            int varIncrement,
            ql::Rate const& payoff_,
            ql::Rate const& maxRate_,
            ql::Rate const& minRate_
        );
        ~CallableRangeAccrual();

        double computeFixedLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);
        double computeVarLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);

        double computeActualizedCashFlow(ql::Date const &date);
        double computeExerciseValue(ql::Date const &date);
        double computeHoldValue(ql::Date const &date);

        double computeLSPrice();

    private:

        std::vector<ql::Date> generateTenor(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar,
            int increment
        );

        //contract specifications: rates
        ql::Rate payoff;
        ql::Rate maxRate;
        ql::Rate minRate;

        //tenor dates
        std::vector<ql::Date> fixedLegTenor;
        std::vector<ql::Date> varLegTenor;
};

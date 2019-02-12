#pragma once

#include <definitions.h>
#include <vector>


class CallableRangeAccrual
{
    public:
        CallableRangeAccrual(ql::Rate const &payoff_, ql::Rate const& maxRate_, ql::Rate const &minRate_);
        ~CallableRangeAccrual();
        std::vector<ql::Date> generateTenor(ql::Date startDate, ql::Date endDate, ql::Calendar const &cal, ql::Size const &increment);

        double computeFixedLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);
        double computeVarLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);

        double computeActualizedCashFlow(ql::Date const &date);
        double computeExerciseValue(ql::Date const &date);
        double computeHoldValue(ql::Date const &date);

        double computeLSPrice();

    private:
    
        //contract specifications: rates
        ql::Rate payoff;
        ql::Rate maxRate;
        ql::Rate minRate;

        //contract specifications: increments
        ql::Size fixedLegIncrement;
        ql::Size variableLegIncrement;

        //values according to which the call decision is taken
        std::vector<double> exerciseValues;
        std::vector<double> holdValues;

        //tenor dates
        std::vector<ql::Date> fixedLegTenor;
        std::vector<ql::Date> varLegTenor;

        //coupons
        std::vector<double> fixedLegCoupons;
        std::vector<double> varLegCoupons;

};

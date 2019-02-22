#pragma once

#include <definitions.h>
#include <vector>


std::vector<ql::Date> generateTenor(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int const& increment
);

void checkLimitDates(
    ql::Date const& date,
    bool const& isStartDate,
    ql::Calendar const& calendar
);

bool checkUpdate(
    ql::Date const& lhsDate,
    ql::Date & rhsDate, 
    ql::Calendar calendar,
    int const& increment
);


class CallableRangeAccrual{
    public:
        
        CallableRangeAccrual();
        CallableRangeAccrual(CallableRangeAccrual const& other);
        CallableRangeAccrual(CallableRangeAccrual && other);
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

        friend std::ostream& operator<<(std::ostream& oStream, CallableRangeAccrual const& cra);

        // double computeFixedLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);
        // double computeVarLegCoupons(ql::Date const &fromDate, ql::Date const &toDate);

        // double computeActualizedCashFlow(ql::Date const &date);
        // double computeExerciseValue(ql::Date const &date);
        // double computeHoldValue(ql::Date const &date);

        // double computeLSPrice();
    private:
        //contract specifications: rates
        ql::Rate payoff;
        ql::Rate maxRate;
        ql::Rate minRate;

        // tenor dates
        std::vector<ql::Date> fixedLegTenor;
        std::vector<ql::Date> varLegTenor;
};


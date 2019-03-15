#pragma once

#include <definitions.h>


bool checkUpdate(
    ql::Date const& lhsDate,
    ql::Date & rhsDate, 
    ql::Calendar calendar,
    int const& increment
){
    rhsDate = calendar.advance(rhsDate, increment, ql::Months, ql::BusinessDayConvention::Preceding);
    if(lhsDate > rhsDate)
        return true;
    else
        return false;
    
}

std::vector<ql::Date> generateTenor(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int const& increment
){
    
    std::vector<ql::Date> tenor = {{startDate}};
    tenor.reserve(daysBetween(startDate, endDate) / (increment * 30) + 2);

    auto date(tenor.back());
    while (checkUpdate(endDate, date, calendar, increment))
        tenor.push_back(date);
    
    tenor.push_back(endDate);       
    return tenor;
}

void checkLimitDates(
    ql::Date const& date,
    bool const& isStartDate,
    ql::Calendar const& calendar
){
    
    if(! calendar.isBusinessDay(date))
    {
        std::stringstream errorStream;
        errorStream << "inserted "  << (isStartDate ? "start" : "end") << " date is not a business day!";
        throw std::invalid_argument(errorStream.str());
    }
}

template <typename Underlying_type>
class CallableRangeAccrual{
    public:
        
        CallableRangeAccrual<Underlying_type>();
        CallableRangeAccrual<Underlying_type>(CallableRangeAccrual const& other);
        CallableRangeAccrual<Underlying_type>(CallableRangeAccrual && other);
        CallableRangeAccrual<Underlying_type>(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar,
            int fixedIncrement,
            int varIncrement,
            int callIncrement,
            ql::Rate const& payoff_,
            ql::Rate const& fixedRate_,
            Underlying_type const& rangeMax_,
            Underlying_type const& rangeMin_
        );
            
        ~CallableRangeAccrual<Underlying_type>();

        template <typename TT>
        friend std::ostream& operator<<(std::ostream& oStream, CallableRangeAccrual<TT> const& cra);

        //contract specifications
        ql::Rate payoff;
        ql::Rate fixedRate;
        Underlying_type rangeMax;
        Underlying_type rangeMin;

        // tenor dates
        std::vector<ql::Date> fixedLegTenor;
        std::vector<ql::Date> varLegTenor;
        std::vector<ql::Date> callTenor;
};

#include <callable_range_accrual_impl.ipp>

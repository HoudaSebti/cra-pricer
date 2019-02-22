#include <stdexcept>

#include <callable_range_accrual.h>


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
CallableRangeAccrual::CallableRangeAccrual(){}
CallableRangeAccrual::CallableRangeAccrual(CallableRangeAccrual const& other)
    : payoff (other.payoff),
      maxRate(other.maxRate),
      minRate(other.minRate),
      fixedLegTenor(other.fixedLegTenor),
      varLegTenor(other.varLegTenor)
{}
CallableRangeAccrual::CallableRangeAccrual(CallableRangeAccrual && other)
    : payoff(std::move(other.payoff)),
      maxRate(std::move(other.maxRate)),
      minRate(std::move(other.minRate)),
      fixedLegTenor(std::move(other.fixedLegTenor)),
      varLegTenor(std::move(other.varLegTenor))
{}
CallableRangeAccrual::CallableRangeAccrual(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int fixedIncrement,
    int varIncrement,
    ql::Rate const& payoff_,
    ql::Rate const& maxRate_,
    ql::Rate const& minRate_
)
    : payoff(payoff_),
      maxRate(maxRate_),
      minRate(minRate_)
{
    /*
        Must check before initializing!
    */
    checkLimitDates(startDate, true, calendar);
    checkLimitDates(endDate  , false, calendar);
    
    fixedLegTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        fixedIncrement
    );
    varLegTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        varIncrement
    );
}
      
CallableRangeAccrual::~CallableRangeAccrual(){}


std::ostream &operator<<(std::ostream &oStream, CallableRangeAccrual const& cra){
    oStream << 
    "Callable range accrual contract info:" << std::endl <<

    "start date: "             << cra.fixedLegTenor.front() << std::endl <<
    "end date: "               << cra.fixedLegTenor.back()  << std::endl <<

    "max rate of the range : " << cra.maxRate << std::endl <<
    "min rate of the range : " << cra.minRate << std::endl <<
    "payoff: "                 << cra.payoff  << std::endl <<

    "cra.fixedLegTenor[1]= "   << cra.fixedLegTenor[1] << std::endl <<
    "cra.varLegTenor  [1]= "   << cra.varLegTenor  [1] << std::endl <<

    "size of fixed tenor: "    << cra.fixedLegTenor.size() << std::endl <<
    "size of variable tenor: " << cra.varLegTenor.size();
    
  
    return oStream;
}


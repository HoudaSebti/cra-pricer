#include <stdexcept>

#include <callable_range_accrual.h>


std::vector<ql::Date> generateTenor(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int increment
){
    
    std::vector<ql::Date> tenor = {{startDate}};
    tenor.reserve(daysBetween(startDate, endDate) / (increment * 30) + 2);
    auto date = calendar.advance(tenor.back(), increment, ql::Months, ql::BusinessDayConvention::Preceding);

    while(endDate - date > increment * 30)
    {
        tenor.push_back(date);
        date = calendar.advance(tenor.back(), increment, ql::Months, ql::BusinessDayConvention::Preceding);
    }
    
    tenor.push_back(endDate);       
    return tenor;
}

void doSanityChecks(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
){
    if(! calendar.isBusinessDay(startDate))
        throw std::invalid_argument("inserted start date is not a business day!");
    if(! calendar.isBusinessDay(endDate))
        throw std::invalid_argument("inserted end date is not a business day!");
}


CallableRangeAccrual::CallableRangeAccrual(){}
CallableRangeAccrual::CallableRangeAccrual(CallableRangeAccrual const& other)
    : payoff (other.payoff),
      maxRate(other.maxRate),
      minRate(other.minRate),
      fixedLegTenor(other.fixedLegTenor),
      varLegTenor  (other.varLegTenor)
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
    try 
        :   payoff(payoff_),
            maxRate(maxRate_),
            minRate(minRate_),
            fixedLegTenor(
                generateTenor(
                    startDate,
                    endDate,
                    calendar,
                    fixedIncrement
                )
           ),
            varLegTenor(
                generateTenor(
                    startDate,
                    endDate,
                    calendar,
                    varIncrement
                )
            )
    {
        doSanityChecks(startDate, endDate, calendar);
    }
    catch(std::invalid_argument const& e){

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


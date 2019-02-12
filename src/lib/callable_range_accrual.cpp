#include <callable_range_accrual.h>

CallableRangeAccrual::CallableRangeAccrual(
    ql::Rate const &payoff_,
    ql::Rate const &maxRate_,
    ql::Rate const &minRate_
)
    :payoff(payoff_),
    maxRate(maxRate_),
    minRate(minRate_)
      
{
}

CallableRangeAccrual::~CallableRangeAccrual()
{}



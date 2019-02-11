#include<definitions.h>
#include<vector>
class CallableRangeAccrual
{
    private:
        //values according to which the call decision is taken
        std::vector<double> exerciseValues;
        std::vector<double> holdValues;

        //contract specifications: dates
        ql::Date startDate;
        ql::Date maturity;

        //contract specifications: rates
        double payoff;
        double maxRate;
        double minRate;

        //contract specifications: increments
        ql::Size fixedLegIncrement;
        ql::Size varLegIncrement;

        //tenor dates
        TenorDates fixedLegTenor;
        TenorDates varLegTenor;

        //coupons
        std::vector<double> fixedLegCoupons;
        std::vector<double> varLegCoupons;

    public:
        TenorDates generateTenor(ql::Calendar const& cal, ql::Size const& increment);

        double computeFixedLegCoupons(ql::Date const& fromDate, ql::Date const& toDate);
        double computeVarLegCoupons  (ql::Date const& fromDate, ql::Date const& toDate);

        double computeActualizedCashFlow(ql::Date const& date);
        double computeExerciseValue     (ql::Date const& date);
        double computeHoldValue         (ql::Date const& date);
        
        double computeLSPrice();

};

#include<rate_models.h>

#include <ql/indexes/ibor/euribor.hpp>
#include <ql/time/daycounters/actual360.hpp>
#include <ql/legacy/libormarketmodels/lmlinexpvolmodel.hpp>
#include <ql/legacy/libormarketmodels/lmlinexpcorrmodel.hpp>



// No need for this function
ql::LiborForwardModelProcess generateLMMProcess(
    ql::Period const& lmmMaturity,
    boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
){
    ql::LiborForwardModelProcess process(
                getProcessSize(
                        startDate,
                        endDate,
                        static_cast<int>(days(lmmMaturity))
                    ),
                boost::shared_ptr<ql::Euribor>(
                    new ql::Euribor(
                        lmmMaturity,
                        ql::Handle<ql::YieldTermStructure>(termStructure)
                    ) 
                )
            );
    return process;
}

ql::LiborForwardModel generateLmmModel(
    ql::LiborForwardModelProcess & process,
    ql::Real a,
    ql::Real b,
    ql::Real c,
    ql::Real d
){
    return ql::LiborForwardModel(
        boost::shared_ptr<ql::LiborForwardModelProcess>(& process),
        boost::shared_ptr<ql::LmLinearExponentialVolatilityModel>(
            new ql::LmLinearExponentialVolatilityModel(
                process.fixingTimes(),
                a,
                b,
                c,
                d
            )
        ),
        boost::shared_ptr<ql::LmLinearExponentialCorrelationModel>(
            new ql::LmLinearExponentialCorrelationModel(
                process.size(),
                .5,
                .8
            )
        )    
    );
}

ql::Size getProcessSize(
    ql::Date const& startDate,
    ql::Date const& endDate,
    int const& liborDaysToMaturity
){
    return static_cast<int>(daysBetween(startDate, endDate)) / liborDaysToMaturity;
}

class Rate_models : public Models_creator{
    public:
        Rate_models(RateModelName const& modelName,
            boost::shared_ptr<ql::YieldTermStructure> const& termStructure,
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar){
            switch(modelName){
                case LiborMarketModel_Euribor6M:{
                    auto process = generateLMMProcess(
                        ql::Period(6, ql::Months),
                        termStructure,
                        startDate,
                        endDate,
                        calendar
                    );
                    return generateLmmModel(process);
                }
                case LiborMarketModel_Euribor1Y:{
                    auto process = generateLMMProcess(
                        ql::Period(1, ql::Months),
                        termStructure,
                        startDate,
                        endDate,
                        calendar
                    );
                    return generateLmmModel(process);
                }
                case HestonModel:
                    std::runtime_error("process generator for HEstonModel not supported yet !");   
            }
        ~Rate_models();
    private:
        virtual ql::Rate computeValue(ql::Date date){

            return ql::Rate(.05);
        }
        virtual void calibrate(std::vector<std::istream> const& data){

        }

        
};



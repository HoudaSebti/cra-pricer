#pragma once
#pragma once

#include<definitions.h>
#include<models.h>

class BlackScholes : Models<double>{
    double computeValue(ql::Date date) const override{
        return 0.0;
    }
    void calibrate(std::vector<std::istream> const& data) override{
    }

    public:
        BlackScholes(double S0_, double mu_, double sigma_, double W0_);
        ~BlackScholes();

    private:
        double S0;
        double mu;
        double sigma;
        double W0;   
};
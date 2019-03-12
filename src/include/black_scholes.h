#pragma once
#pragma once

#include<definitions.h>
#include<models.h>

double simulateWienerProcess(double W0, int daysFromStart);
class BlackScholes : Models<double>{

    public:
        BlackScholes(double S0_, double mu_, double sigma_);
        ~BlackScholes();
        double simulateValue(int daysFromStart) const override;
        void calibrate(std::vector<std::istream> const& data) override;
    private:
        double S0;
        double mu;
        double sigma; 
};
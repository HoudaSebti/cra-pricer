#pragma once

#include <definitions.h>
#include <models.h>

class DummyModel : Models<double>{
    public:
        DummyModel();
        ~DummyModel();
    private:
        double simulateValue(int daysFromStartDate) const override;
        void calibrate(std::vector<std::istream> const& data) override;
};
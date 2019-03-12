#include <black_scholes.h>
#include <random>
#include <cmath>


double simulateWienerProcess(double W0, int daysFromStart){ 
    std::random_device rd{};
    std::mt19937 gen{rd()};
    
    return std::normal_distribution<>{0, sqrt(daysFromStart)}(gen) / 365.0;
}
BlackScholes::BlackScholes(double S0_, double mu_, double sigma_)
    :S0(S0_),
    mu(mu_),
    sigma(sigma_)
{}
BlackScholes::~BlackScholes(){};
double BlackScholes::simulateValue(int daysFromStart) const {
    auto wienerValue = simulateWienerProcess(0.0, daysFromStart);
    return(S0 * exp((mu - pow(sigma,2)) * daysFromStart + sigma * wienerValue));
}
void BlackScholes::calibrate(std::vector<std::istream> const& data){

}

#pragma<once>

#include<definitions.h>

template <typename Underlying_type>
class Path{
    public:
        Path();
        ~Path();

    private:
        std::vector<Underlying_type> rates;
}
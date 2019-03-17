#pragma once


template <typename Underlying_type>
Path<Underlying_type>::Path(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar){
        elements.reserve(calendar.businessDaysBetween(startDate, endDate));
}

template<typename Underlying_type>
Path<Underlying_type>::Path(Path const& other):
    elements(other.elements)
{}

template<typename Underlying_type>
Path<Underlying_type>::Path(Path && other):
    elements(std::move(other.elements))
{}

template <typename Underlying_type>
Path<Underlying_type>::~Path(){};

template <typename Underlying_type>
std::vector<double> Path<Underlying_type>::computeCashFlow(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Rate const& riskFreeRate,
    ql::Rate const& fixedRate,
    ql::Rate const& payout,
    Underlying_type const& rangeMax,
    Underlying_type const& rangeMin
){
    std::vector<double> cashFlows;
    return cashFlows;
}

template <typename Underlying_type>
void Path<Underlying_type>::addElement(Underlying_type const& element){
    elements.push_back(element);
}

template <typename Underlying_type>
Underlying_type Path<Underlying_type>::getElement(int const& position){
    return elements[position];
}

template <typename Underlying_type>
int Path<Underlying_type>::getSize(){
    return elements.size();
}

template <typename Underlying_type>
std::basic_ofstream<char, std::char_traits<char>> Path<Underlying_type>::saveToCsv(std::string pathName) const{
    std::basic_ofstream<char, std::char_traits<char>> outFile(pathName);
    outFile << elements[0];
    for(int j = 1; j < elements.size(); ++j)
        outFile <<  "," << elements[j];
    outFile << std::endl;
    outFile.close();
    
    return outFile;
}

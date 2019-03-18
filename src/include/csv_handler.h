#include "definitions.h"

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include <fstream>
#include <string>
#include <vector>

class CSV_Handler
{
public:
    CSV_Handler(boost::filesystem::path const& _filepath);
    CSV_Handler(std::string const& _filename);
    ~CSV_Handler();
    
    std::vector< std::vector<double> > read();

    template<class Iterable>
    void write(std::vector< Iterable > const& data)
    {
        std::fstream file(filepath.string(), std::ios::out);

        for(auto const& line : data)
        {
            if(!line.empty())
            {
                file << *std::begin(line);
                std::for_each(
                    std::next(std::begin(line)),
                    std::end(line),
                    [&file](double const entry)
                    {
                        file << ", " << entry;
                    }
                );    
            }
            file << std::endl;
        }
        file.close();
    }
    
private:
    boost::filesystem::path filepath;
};

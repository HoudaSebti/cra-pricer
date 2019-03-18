#include <csv_handler.h>

#include <line.h>

#include <boost/algorithm/string.hpp>

#include <algorithm>
#include <iterator>
#include <sstream>


CSV_Handler::CSV_Handler(boost::filesystem::path const& _filepath)
    : filepath(_filepath)
{}
CSV_Handler::CSV_Handler(std::string const& _filename)
    : filepath(boost::filesystem::path(_filename))
{}
CSV_Handler::~CSV_Handler()
{}

std::vector< std::vector<double> > CSV_Handler::read()
{
    std::fstream file;
    
    if(boost::filesystem::is_regular_file(filepath))
        file.open(filepath.string(), std::ios::in);
    else
    {
        boost::system::error_code ec(boost::system::errc::no_such_file_or_directory, boost::system::system_category());
        throw boost::filesystem::filesystem_error(filepath.string(), ec);
    }

    std::vector<std::string> lines;
    lines.reserve(10);
    
    readlines(file, std::back_inserter(lines));
    
    lines.erase(
        std::remove_if(
            std::begin(lines),
            std::end(lines),
            [](const std::string & line)
            {
                return line.empty();
            }
        ),
        std::end(lines)
    );

    std::vector< std::vector<double> > data(lines.size());
    std::transform(
        std::begin(lines),
        std::end(lines),
        std::begin(data),
        [](std::string const& line)
        {
            std::vector<std::string> entries;
            boost::split(entries, line, boost::is_any_of(","));
            std::vector<double> result(entries.size());
            std::transform(
                std::begin(entries),
                std::end(entries),
                std::begin(result),
                [](std::string const& entry)
                {
                    return std::stod(entry);
                }
            );
            return result;
        }
    );
        
    file.close();
    return data;
}

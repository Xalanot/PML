#include <string>
#include <vector>

#include <pml/printcommon.h>

class CSVWriter
{
public:
    CSVWriter()
    : seperator(std::string(", "))
    {}
    
    void setHeaderNames(std::vector<std::string>&& headerVector)
    {
        headerNames = std::move(headerVector);
    }
    
    void printHeader()
    {
        std::cout << headerNames[0];
        for (size_t i = 1; i < headerNames.size(); ++i)
        {
            std:: cout << seperator << headerNames[i];
        }
        std::cout << std::endl;
    }
    
    template <typename First, typename... Args>
    void printContent(First const& first, Args const&... args)
    {
        if (!checkSizes(first, args...))
        {
            std::cout << "Contents differ in sizes" << std::endl;
            return;
        }
        
        for (size_t i = 0; i < first.size(); ++i)
        {
            printCSVLine(seperator, first[i], args[i]...);
        }
    }
private:
    std::string seperator;
    std::vector<std::string> headerNames;
};
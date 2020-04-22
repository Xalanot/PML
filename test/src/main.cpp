#include <iostream>
#include <thread>

#include <pml/csvwriter.h>
#include <pml/measurement.h>


int main()
{
    CSVWriter writer;
    std::vector<std::string> headerNames = {"Time", "Size"};
    writer.setHeaderNames(std::move(headerNames));
    writer.printHeader();
    std::vector vec{1, 2, 3};
    std::vector vec2{"My", "Name", "Is"};
    writer.printContent(vec, vec2);
    return 0;
}
template<typename... Args>
bool checkSizes(Args const&... args)
{
    return (... == args.size());
}

template<typename T>
concept Printable = requires (T t) {std::cout << t;};

template<Printable First, Printable... Args>
void printCSVLine(std::string const& seperator, First const& first, Args const&... args)
{
    auto print_with_seperator = [](const std::string& seperator, const auto& arg) -> const auto& {
        std::cout << seperator;
        return arg;
    };
    
    std::cout << first;
    (std::cout << ... << print_with_seperator(seperator, args)) << std::endl;
}
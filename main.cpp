#include <array>
#include <string>
#include <iostream>
#include <optional>

#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

struct foo
{
    std::optional<int> _f = 3;
    foo() = default;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(foo, _f);

struct bar
{
    int _b = 0;
    bar() = default;
};
struct baz
{
    std::optional<bar> _bar = std::nullopt;
    baz() = default;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bar, _b);
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(baz, _bar);

int main()
{
    try{
        nlohmann::json j = nlohmann::json::parse(R"({"_b": 37})");
        bar b;
        j.get_to(b);
        std::cout << "b._b: " << b._b << std::endl;
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Un-comment the code below to break the build.

    try {
        baz bz;
        nlohmann::json j2 = nlohmann::json::parse(R"({"_bar": {"_b": 1}})");
        j2.get_to(bz);
        std::cout << "bz._bar->_f: " << (bz._bar ? std::to_string(bz._bar->_b) : "null") << std::endl;
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        foo f;
        nlohmann::json j3 = nlohmann::json::parse(R"({"_f": 1})");
        j3.get_to(f);
        std::cout << "f._f: " << (f._f ? std::to_string(f._f.value()) : "null") << std::endl;
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
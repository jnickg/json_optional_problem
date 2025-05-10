# Overview

This repo demonstrates a simple issue with the new support for `std::optional`

## Reproduction steps:

1. Configure and build with cmake which uses [CPM](https://github.com/cpm-cmake/CPM.cmake) to fetch and build nlohmann::json. I did not test if this was the cause because it seems very unlikely.
2. Build the project and observe it compiles. Run test program to see deserialization working normally
3. Un-comment the code in `main` and attempt to compile; observe that it does not due to template instantiation issues (copied below for posterity)

```
json.hpp(1825, 17): candidate template ignored: requirement 'detail::has_from_json<nlohmann::basic_json<std::map, std::vector, std::basic_string<char, std::char_traits<char>, std::allocator<char>>, bool, long, unsigned long, double, std::allocator, nlohmann::adl_serializer, std::vector<unsigned char, std::allocator<unsigned char>>, void>, std::optional<int>, void>::value' was not satisfied [with ValueType = std::optional<int>]
json.hpp(1838, 17): candidate template ignored: requirement 'detail::is_basic_json<std::optional<int>>::value' was not satisfied [with ValueType = std::optional<int>]
json.hpp(1849, 11): candidate template ignored: could not match 'T[N]' against 'std::optional<int>'
```


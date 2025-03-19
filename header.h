#include <iostream>
#include <vector>
#include <string>
#include <random>




/*#if __has_include(<optional>)
#include <optional>
#define has_optional 1
template<class T>
using optional_t = std::optional<T>;
#else if __has_include(<experimental/optional>)
#include <experimental/optional>
#define has_optional -1
template<class T>
using optional_t = std::experimental::optional<T>;
#else
#define has_optional 0
template<class V>
class optional_t
{
    V v{};
    bool has{};

public:
    optional_t() = default;
    optional_t(V&& v) : v(v), has{true} {}
    V value_or(V&& alt) const&
    {
        return has ? v : alt;
    }
    // etc.
};
#endif */
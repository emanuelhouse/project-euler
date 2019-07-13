#include <cmath>


namespace math {

template <class Integer>
Integer isqrt(Integer n) {
    return static_cast<Integer>(std::sqrt(n));
}

} // namespace math

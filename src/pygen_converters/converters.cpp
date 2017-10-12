
#include <complex>
#include <pygen/converters.h>

// Explicit instantion
namespace pygen {
extern template void convert<int>(Converters converter, bool isListConvertible = true);
extern template void convert<float>(Converters converter, bool isListConvertible = true);
extern template void convert<double>(Converters converter, bool isListConvertible = true);
extern template void convert<std::complex<float> >(Converters converter, bool isListConvertible = true);
extern template void convert<std::complex<double> >(Converters converter, bool isListConvertible = true);
} // namespace pygen
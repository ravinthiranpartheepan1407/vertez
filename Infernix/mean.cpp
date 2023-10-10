// Name: vertezml
// Version: 0.0.3
// Summary: Vertez: Statify and Infer
// Home-page:
// Author: Ravinthiran Partheepan

#include <vector>

double mean(const std::vector<double> &numbers)
{
    double sum = 0.0;
    for (const auto &num : numbers)
    {
        sum += num;
    }
    return sum / numbers.size();
}
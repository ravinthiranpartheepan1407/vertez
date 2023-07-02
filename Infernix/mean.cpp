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
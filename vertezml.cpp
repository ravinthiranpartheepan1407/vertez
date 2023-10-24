#include "C:/Users/ravin/vertez/Infernix/mean.cpp"
#include "C:/Users/ravin/vertez/Infernix/euclidean.cpp"
#include "C:/Users/ravin/vertez/Infernix/chebyshev.cpp"
#include "C:/Users/ravin/vertez/Infernix/correlation.cpp"
#include "C:/Users/ravin/vertez/Infernix/cosimilarity.cpp"
#include "C:/Users/ravin/vertez/Infernix/covariance.cpp"
#include "C:/Users/ravin/vertez/Infernix/entropy.cpp"
#include "C:/Users/ravin/vertez/Infernix/gini.cpp"
#include "C:/Users/ravin/vertez/Infernix/hamming.cpp"
#include "C:/Users/ravin/vertez/Infernix/kmeans.cpp"
#include "C:/Users/ravin/vertez/Infernix/lineareg.cpp"
#include "C:/Users/ravin/vertez/Infernix/logtransform.cpp"
#include "C:/Users/ravin/vertez/Infernix/mae.cpp"
#include "C:/Users/ravin/vertez/Infernix/manhattan.cpp"
#include "C:/Users/ravin/vertez/Infernix/max.cpp"
#include "C:/Users/ravin/vertez/Infernix/median.cpp"
#include "C:/Users/ravin/vertez/Infernix/min.cpp"
#include "C:/Users/ravin/vertez/Infernix/minkowski.cpp"
#include "C:/Users/ravin/vertez/Infernix/minmax.cpp"
#include "C:/Users/ravin/vertez/Infernix/mode.cpp"
#include "C:/Users/ravin/vertez/Infernix/mse.cpp"
#include "C:/Users/ravin/vertez/Infernix/range.cpp"
#include "C:/Users/ravin/vertez/Infernix/rmse.cpp"
#include "C:/Users/ravin/vertez/Infernix/rsquare.cpp"
#include "C:/Users/ravin/vertez/Infernix/samplecovar.cpp"
#include "C:/Users/ravin/vertez/Infernix/samplevar.cpp"
#include "C:/Users/ravin/vertez/Infernix/softmax.cpp"
#include "C:/Users/ravin/vertez/Infernix/stdev.cpp"
#include "C:/Users/ravin/vertez/Infernix/variance.cpp"
#include "C:/Users/ravin/vertez/Infernix/zscore.cpp"
#include "C:/Users/ravin/vertez/Infernix/kurtosis.cpp"
#include "C:/Users/ravin/vertez/Infernix/mape.cpp"
#include "C:/Users/ravin/vertez/Infernix/rmsle.cpp"
#include "C:/Users/ravin/vertez/Infernix/sigmoid.cpp"
#include "C:/Users/ravin/vertez/Infernix/tanh.cpp"
#include "C:/Users/ravin/vertez/Infernix/vrange.cpp"
#include "C:/Users/ravin/vertez/Infernix/anova.cpp"
#include "C:/Users/ravin/vertez/Infernix/gradientdescentslope.cpp"
#include "C:/Users/ravin/vertez/Infernix/gradientdescentinter.cpp"
#include "C:/Users/ravin/vertez/Infernix/rmspropslope.cpp"
#include "C:/Users/ravin/vertez/Infernix/rmspropinter.cpp"
#include "C:/Users/ravin/vertez/Infernix/softplus.cpp"
#include <C:/Users/ravin/AppData/Local/Programs/Python/Python311/Lib/site-packages/pybind11-2.11.1/pybind11/include/pybind11/pybind11.h>
#include <C:/Users/ravin/AppData/Local/Programs/Python/Python311/Lib/site-packages/pybind11-2.11.1/pybind11/include/pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(vertezml, m)
{
    m.def("mean", &mean, "Mean of a list of numbers");
    m.def("euclidean", &euclidean, "Euclidean Distance");
    m.def("chebyshev", &chebyshev, "Chebyshev Distance");
    m.def("correlation", &correlation, "correlation");
    m.def("cosimilarity", &cosimilarity, "cosimilarity");
    m.def("covariance", &covariance, "covariance");
    m.def("entropy", &entropy, "entropy");
    m.def("gini", &gini, "gini");
    m.def("hamming", &hamming, "hamming");
    m.def("kmeans", &kmeans, "kmeans");
    m.def("lineareg", &lineareg, "lineareg");
    m.def("logtransform", &logtransform, "logtransform");
    m.def("mae", &mae, "mae");
    m.def("manhattan", &manhattan, "manhattan");
    m.def("max", &max, "max");
    m.def("median", &median, "median");
    m.def("min", &min, "min");
    m.def("minkowski", &minkowski, "minkowski");
    m.def("minmax", &minmax, "minmax");
    m.def("mode", &mode, "mode");
    m.def("mse", &mse, "mse");
    m.def("range", &range, "range");
    m.def("rmse", &rmse, "rmse");
    m.def("rsquare", &rsquare, "rsquare");
    m.def("samplecovar", &samplecovar, "samplecovar");
    m.def("samplevar", &samplevar, "samplevar");
    m.def("softmax", &softmax, "softmax");
    m.def("stdev", &stdev, "stdev");
    m.def("variance", &variance, "variance");
    m.def("zscore", &zscore, "zscore");
    m.def("kurtosis", &kurtosis, "Kurtosis");
    m.def("mape", &mape, "MAPE");
    m.def("rmsle", &rmsle, "RMSLE");
    m.def("sigmoid", &sigmoid, "Sigmoid");
    m.def("tanh", &tanh, "TanH");
    m.def("vrange", &vrange, "VRange");
    m.def("anova", &anova, "anova");
    m.def("gradientdescentslope", &gradientdescentslope, "gradientdescentslope");
    m.def("gradientdescentinter", &gradientdescentinter, "gradientdescentinter");
    m.def("rmspropslope", &rmspropslope, "rmspropslope");
    m.def("rmspropinter", &rmspropinter, "rmspropinter");
    m.def("softplus", &softplus, "softplus");
}
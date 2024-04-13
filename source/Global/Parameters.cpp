#include "Parameters.h"

namespace tuc
{
namespace ParameterData
{

Params::Params()
{
    initSliderParams();
    initButtonParams();
}

void Params::initSliderParams()
{
    using skew = SliderParameterData::SkewType;
    using type = SliderParameterData::NumericType;

    _sliderParams.push_back({viator_core::Parameters::outputID, viator_core::Parameters::outputName, -20.0f, 20.0f, 0.0f, skew::kNoSkew, 1000.0, type::kInt});
}

void Params::initButtonParams()
{
}

}
}

#pragma once
#include "Globals.h"

namespace viator_core
{
    namespace ParameterData
    {

        // Param data
        struct SliderParameterData
        {
            enum SkewType
            {
                kSkew,
                kNoSkew
            };

            enum NumericType
            {
                kInt,
                kFloat
            };

        public:
            juce::String paramID;
            juce::String paramName;
            float min;
            float max;
            float initial;
            SkewType isSkew;
            float center;
            NumericType isInt;
        };

        struct ButtonParameterData
        {
        public:
            juce::String paramID;
            juce::String paramName;
            bool initial;
        };

        class Params
        {
        public:
            Params();

            // Get a ref to the param data
            std::vector<viator_core::ParameterData::SliderParameterData> &getSliderParams() { return _sliderParams; };
            std::vector<viator_core::ParameterData::ButtonParameterData> &getButtonParams() { return _buttonParams; };

        private:
            // Adds params to the vector
            void initSliderParams();
            void initButtonParams();

        private:
            // Vector holding param data
            std::vector<viator_core::ParameterData::SliderParameterData> _sliderParams;
            std::vector<viator_core::ParameterData::ButtonParameterData> _buttonParams;
        };
    }
}

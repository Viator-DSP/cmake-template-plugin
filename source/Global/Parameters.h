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
            juce::String paramID;
            juce::String paramName;
            bool initial;
        };

        struct MenuParameterData
        {
            juce::String paramID;
            juce::String paramName;
            juce::StringArray choices;
            int initial;
        };

        class Params
        {
        public:
            Params();

            // Get a ref to the param data
            std::vector<viator_core::ParameterData::SliderParameterData> &get_slider_params() { return slider_params; }
            std::vector<viator_core::ParameterData::ButtonParameterData> &get_button_params() { return button_params; }
            std::vector<viator_core::ParameterData::MenuParameterData> &get_menu_params() { return menu_params; }

        private:
            // Adds params to the vector
            void init_slider_params();
            void init_button_params();
            void init_menu_params();

        private:
            // Vector holding param data
            std::vector<viator_core::ParameterData::SliderParameterData> slider_params;
            std::vector<viator_core::ParameterData::ButtonParameterData> button_params;
            std::vector<viator_core::ParameterData::MenuParameterData> menu_params;
        };
    }
}

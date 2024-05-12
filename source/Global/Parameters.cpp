#include "Parameters.h"

namespace viator_core
{
    namespace ParameterData
    {

        Params::Params()
        {
            init_slider_params();
            init_button_params();
            init_menu_params();
        }

        void Params::init_slider_params()
        {
            using skew = SliderParameterData::SkewType;
            using type = SliderParameterData::NumericType;

            slider_params.push_back
            ({
                 viator_core::Parameters::inputID,
                 viator_core::Parameters::inputName,
                 -20.0f, 20.0f, 0.0f, skew::kNoSkew,
                 1000.0, type::kInt
             });

            slider_params.push_back
            ({
                viator_core::Parameters::outputID,
                viator_core::Parameters::outputName,
                -20.0f, 20.0f, 0.0f, skew::kNoSkew,
                1000.0, type::kInt
            });

            slider_params.push_back
            ({
                     viator_core::Parameters::cutoffID,
                     viator_core::Parameters::cutoffName,
                     20.0f, 20000.0f, 1000.0f, skew::kSkew,
                     1000.0, type::kFloat
             });

            slider_params.push_back
            ({
                     viator_core::Parameters::bwID,
                     viator_core::Parameters::bwName,
                     0.01f, 0.99f, 0.3f, skew::kNoSkew,
                     0.5, type::kFloat
             });

            slider_params.push_back
            ({
                     viator_core::Parameters::gainID,
                     viator_core::Parameters::gainName,
                     -20.0f, 20.0f, 0.0f, skew::kNoSkew,
                     0.0, type::kFloat
             });
        }

        void Params::init_button_params()
        {
        }

        void Params::init_menu_params()
        {
            juce::StringArray hq_choices = {"Off", "2X", "4X", "8X"};
            menu_params.push_back
            ({
                 viator_core::Parameters::hqID,
                 viator_core::Parameters::hqName,
                 hq_choices, 0
            });

            juce::StringArray stereo_choices = {"Stereo", "Mono", "Mid", "Sides"};
            menu_params.push_back
            ({
                 viator_core::Parameters::stereoID,
                 viator_core::Parameters::stereoName,
                 stereo_choices, 0
            });

            juce::StringArray type_choices = {"LP", "HP", "BS", "LS", "HS"};
            menu_params.push_back
            ({
                     viator_core::Parameters::typeID,
                     viator_core::Parameters::typeID,
                     type_choices, 0
             });
        }
    }
}

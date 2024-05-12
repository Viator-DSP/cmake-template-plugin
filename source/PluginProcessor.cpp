#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PluginProcessor::PluginProcessor()
    : AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                         .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
                         .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
                         ),
      _treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
{
    for (int i = 0; i < _parameterMap.get_slider_params().size(); i++)
    {
        _treeState.addParameterListener(_parameterMap.get_slider_params()[i].paramID, this);
    }

    for (int i = 0; i < _parameterMap.get_button_params().size(); i++)
    {
        _treeState.addParameterListener(_parameterMap.get_button_params()[i].paramID, this);
    }

    for (int i = 0; i < _parameterMap.get_menu_params().size(); i++)
    {
        _treeState.addParameterListener(_parameterMap.get_menu_params()[i].paramID, this);
    }
}

PluginProcessor::~PluginProcessor()
{
    for (int i = 0; i < _parameterMap.get_slider_params().size(); i++)
    {
        _treeState.removeParameterListener(_parameterMap.get_slider_params()[i].paramID, this);
    }

    for (int i = 0; i < _parameterMap.get_button_params().size(); i++)
    {
        _treeState.removeParameterListener(_parameterMap.get_button_params()[i].paramID, this);
    }

    for (int i = 0; i < _parameterMap.get_menu_params().size(); i++)
    {
        _treeState.removeParameterListener(_parameterMap.get_menu_params()[i].paramID, this);
    }
}

//==============================================================================
const juce::String PluginProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PluginProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool PluginProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool PluginProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
    return true;
#else
    return false;
#endif
}

double PluginProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PluginProcessor::getNumPrograms()
{
    return 1; // NB: some hosts don't cope very well if you tell them there are 0 programs,
              // so this should be at least 1, even if you're not really implementing programs.
}

int PluginProcessor::getCurrentProgram()
{
    return 0;
}

void PluginProcessor::setCurrentProgram(int index)
{
    juce::ignoreUnused(index);
}

const juce::String PluginProcessor::getProgramName(int index)
{
    juce::ignoreUnused(index);
    return {};
}

void PluginProcessor::changeProgramName(int index, const juce::String &newName)
{
    juce::ignoreUnused(index, newName);
}

juce::AudioProcessorValueTreeState::ParameterLayout PluginProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

    // sliders
    for (int i = 0; i < _parameterMap.get_slider_params().size(); i++)
    {
        auto param = _parameterMap.get_slider_params()[i];

        if (param.isInt == viator_core::ParameterData::SliderParameterData::NumericType::kInt || param.isSkew == viator_core::ParameterData::SliderParameterData::SkewType::kSkew)
        {
            auto range = juce::NormalisableRange<float>(param.min, param.max);

            if (param.isSkew == viator_core::ParameterData::SliderParameterData::SkewType::kSkew)
            {
                range.setSkewForCentre(param.center);
            }

            params.push_back(std::make_unique<juce::AudioProcessorValueTreeState::Parameter>(juce::ParameterID{param.paramID, 1}, param.paramName, param.paramName, range, param.initial, valueToTextFunction, textToValueFunction));
        }

        else
        {
            params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID{param.paramID, 1}, param.paramName, param.min, param.max, param.initial));
        }
    }

    // buttons
    for (int i = 0; i < _parameterMap.get_button_params().size(); i++)
    {
        auto param = _parameterMap.get_button_params()[i];
        params.push_back(std::make_unique<juce::AudioParameterBool>(juce::ParameterID{param.paramID, 1}, param.paramName, _parameterMap.get_button_params()[i].initial));
    }

    // menus
    for (int i = 0; i < _parameterMap.get_menu_params().size(); i++)
    {
        auto param = _parameterMap.get_menu_params()[i];
        params.push_back(std::make_unique<juce::AudioParameterChoice>(
                        juce::ParameterID{param.paramID, 1},
                        param.paramName,
                        _parameterMap.get_menu_params()[i].choices,
                        _parameterMap.get_menu_params()[i].initial));
    }

    return {params.begin(), params.end()};
}

void PluginProcessor::parameterChanged(const juce::String &parameterID, float newValue)
{
}

void PluginProcessor::updateParameters()
{
    auto cutoff = _treeState.getRawParameterValue(viator_core::Parameters::cutoffID)->load();
    auto q = _treeState.getRawParameterValue(viator_core::Parameters::bwID)->load();
    auto gain = _treeState.getRawParameterValue(viator_core::Parameters::gainID)->load();
    test_filter.set_parameters(cutoff, q, gain);

    auto type = _treeState.getRawParameterValue(viator_core::Parameters::typeID)->load();

    using param = viator::SVFilter<float>::ParameterId;
    switch (static_cast<int>(type))
    {
        case 0: test_filter.setParameter(param::kType,
                                         viator::SVFilter<float>::FilterType::kLowPass); break;
        case 1: test_filter.setParameter(param::kType,
                                         viator::SVFilter<float>::FilterType::kHighPass); break;
        case 2: test_filter.setParameter(param::kType,
                                         viator::SVFilter<float>::FilterType::kBandShelf); break;
        case 3: test_filter.setParameter(param::kType,
                                         viator::SVFilter<float>::FilterType::kLowShelf); break;
        case 4: test_filter.setParameter(param::kType,
                                         viator::SVFilter<float>::FilterType::kHighShelf); break;
    }
}

//==============================================================================
void PluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(sampleRate, samplesPerBlock);
    process_spec.sampleRate = sampleRate;
    process_spec.numChannels = static_cast<unsigned int>(getTotalNumOutputChannels());
    process_spec.maximumBlockSize = static_cast<unsigned int>(samplesPerBlock);

    test_filter.prepare(static_cast<float>(sampleRate),
                        static_cast<int>(process_spec.numChannels));
    using param = viator::SVFilter<float>::ParameterId;
    test_filter.setParameter(param::kQType, viator::SVFilter<float>::QType::kParametric);
}

void PluginProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool PluginProcessor::isBusesLayoutSupported(const BusesLayout &layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused(layouts);
    return true;
#else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

        // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
#endif

    return true;
#endif
}

void PluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                   juce::MidiBuffer &midiMessages)
{
    juce::ignoreUnused(midiMessages);
    updateParameters();

    float* pointers[buffer.getNumSamples()];
    for (int i = 0; i < buffer.getNumChannels(); ++i)
    {
        pointers[i] = buffer.getWritePointer(i);
    }

    test_filter.process_buffer(pointers,
                               buffer.getNumChannels(),
                               buffer.getNumSamples());
}

//==============================================================================
bool PluginProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor *PluginProcessor::createEditor()
{ // Use generic gui for editor for now
    //return new PluginEditor(*this);
    return new juce::GenericAudioProcessorEditor(*this);
}

//==============================================================================
void PluginProcessor::getStateInformation(juce::MemoryBlock &destData)
{
    _treeState.state.appendChild(getVariableTree(), nullptr);
    juce::MemoryOutputStream stream(destData, false);
    _treeState.state.writeToStream (stream);
}

void PluginProcessor::setStateInformation(const void *data, int sizeInBytes)
{
    auto tree = juce::ValueTree::readFromData (data, size_t(sizeInBytes));
    variableTree = tree.getChildWithName("Variables");

    if (tree.isValid())
    {
        _treeState.state = tree;
    }
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}

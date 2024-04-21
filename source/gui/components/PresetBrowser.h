#pragma once
#ifndef PresetBrowser_h
#define PresetBrowser_h
#include "../../Global/Parameters.h"
#include "../widgets/TextButton.h"
#include "../widgets/Menu.h"
#include "../lookandfeel/Colors.h"
#include <juce_gui_extra/juce_gui_extra.h>

class PluginProcessor;

namespace viator_core
{

class PresetBrowser  : public juce::Component, public juce::ActionBroadcaster
{
public:
    PresetBrowser(PluginProcessor&);
    ~PresetBrowser() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    viator_core::Menu& getMenu(){return _presetMenu;};

    // presets
    void savePreset();
    void importPreset();
    void loadPreset(const juce::String& filePath);
    void populateMenu();
    void setPresetFolderLocation();
    void populateFactoryMenu();
    void prepareFactoryMenu();
    void createPresetFolder();
    void populateSubMenu(std::vector<juce::File>& presets, const juce::StringArray& fileNames, juce::PopupMenu& menu, int offset);
    void recallMenuState();
    void checkIfPresetIsDirty();
    
    bool getDoesPresetFolderExist()
    {
        auto folderPath = juce::File::getSpecialLocation(juce::File::SpecialLocationType::userApplicationDataDirectory);
        auto path = folderPath.getFullPathName();
        auto pluginName = _projectName;
        path.append("/", juce::CharPointer_UTF8::getBytesRequiredFor(path.getCharPointer()));
        path.append(pluginName, juce::CharPointer_UTF8::getBytesRequiredFor(pluginName.getCharPointer()));
        juce::File _folder(path);
        return _folder.isDirectory();
    };

    enum class Direction
    {
        kLeft,
        kRight
    };
    
    enum class PresetType
    {
        kMix,
        kDrums,
        kKick,
        kSnare,
        kToms,
        kCymbals,
        kVocal,
        kGeetar,
        kBass
    };
    
    void addFactoryFiles(const void* wav, size_t wavSize, const juce::String& fileName, PresetType presetType);
    
private:
    PluginProcessor& audioProcessor;

    std::vector<viator_core::ParameterData::SliderParameterData> _sliderParams;
    std::vector<viator_core::ParameterData::ButtonParameterData> _btnParams;
    juce::String _projectName;

    // buttons
    juce::OwnedArray<viator_core::TextButton> _buttons;
    juce::StringArray _buttonNameTexts =
    {
      "<", ">"
    };

    viator_core::Menu _presetMenu;
    juce::Array<juce::File> _xmlFiles;
    juce::StringArray _xmlFilePaths;

private:

    // buttons
    void initButtons();
    int getButtonIndex(const juce::String& name);
    void navigateMenuOnButtonClick(Direction newDirection);

    // presets
    void initMenu();
    void saveMenuState();
    void resetState();
    void makeMenuSelection();
    void saveParamsToFile(const juce::File& fileToSave);
    void countNumberXMLElements(juce::XmlElement* element);
    void writeParamsToXML(juce::XmlElement* element);
    void showPresetErrorMessage();
    int getXMLByName(juce::String name);
    int numXMLParameters = 0;
    std::unique_ptr<juce::FileChooser> _myChooser;
    juce::File _folderPath;
    juce::File _exportFile;
    int previousMenuID;
    
    std::vector<juce::File> _drumPresets;
    juce::StringArray _drumFileNames;
    std::vector<juce::File> _kickPresets;
    juce::StringArray _kickFileNames;
    std::vector<juce::File> _snarePresets;
    juce::StringArray _snareFileNames;
    std::vector<juce::File> _tomsPresets;
    juce::StringArray _tomsFileNames;
    std::vector<juce::File> _cymbalsPresets;
    juce::StringArray _cymbalsFileNames;
    std::vector<juce::File> _vocalPresets;
    juce::StringArray _vocalFileNames;
    std::vector<juce::File> _geetarPresets;
    juce::StringArray _geetarFileNames;
    std::vector<juce::File> _bassPresets;
    juce::StringArray _bassFileNames;
    std::vector<juce::File> _mixPresets;
    juce::StringArray _mixFileNames;
    
private:

    const int _numButtons = 2;
    int numParams = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetBrowser)
};
}

#endif

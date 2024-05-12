#ifndef filter_h
#define filter_h

#include <vector>
#include "utils.h"

namespace viator
{
template <typename SampleType>
class SVFilter
{
public:
    
    SVFilter();
    
    void prepare(float sample_rate, int num_channels);

    void process_buffer(float** buffer, int channels, int samples_per_channel)
    {
        if (buffer == nullptr)
            return;

        for (int channel = 0; channel < channels; channel++)
        {
            for (int sample = 0; sample < samples_per_channel; sample++)
            {
                float input = buffer[channel][sample];
                buffer[channel][sample] = process_sample(input, channel);
            }
        }
    }
    
    SampleType process_sample(SampleType input, int ch) noexcept
    {
        const auto z1 = mZ1[ch];
        const auto z2 = mZ2[ch];
        
        const float x = input;
            
        const double HP = (x - mRCoeff2 * z1 - mGCoeff * z1 - z2) * mInversion;
        const double BP = HP * mGCoeff + z1;
        const double LP = BP * mGCoeff + z2;
        const double UBP = mRCoeff2 * BP;
        const double BShelf = x + UBP * mGain;
        const double LS = x + mGain * LP;
        const double HS = x + mGain * HP;
            
        // unit delay (state variable)
        mZ1[ch] = mGCoeff * HP + BP;
        mZ2[ch] = mGCoeff * BP + LP;

        switch (mType)
        {
            case kHighPass: return HP; break;
            case kLowPass: return LP; break;
            case kBandShelf: return BShelf; break;
            case kLowShelf: return LS; break;
            case kHighShelf: return HS; break;
        }
    }

    enum class ParameterId
    {
        kType,
        kQType,
        kSampleRate,
        kBypass
    };
        
    enum FilterType
    {
        kLowShelf,
        kHighPass,
        kBandShelf,
        kLowPass,
        kHighShelf
    };
    
    enum QType
    {
        kParametric,
        kProportional,
    };
    
    void setParameter(ParameterId parameter, SampleType parameterValue);
    void set_parameters(float cutoff, float band_width, float gain)
    {
        // cutoff
        mCutoff = cutoff;
        preWarp();

        // band_width
        mQ = band_width;

        switch (mQType)
        {
            case kParametric: mRCoeff = 1.0 - mQ; break;
            case kProportional:

                if (mType == kBandShelf)
                {
                    mRCoeff = 1.0 - getPeakQ(mRawGain); break;
                }

                else
                {
                    mRCoeff = 1.0 - getShelfQ(mRawGain); break;
                }
        }

        mRCoeff2 = mRCoeff * 2.0;
        mInversion = 1.0 / (1.0 + mRCoeff2 * mGCoeff + mGCoeff * mGCoeff);

        // gain
        setGain(gain);
    }

private:
    
    float mCurrentSampleRate, mQ, mCutoff, mGain{0.0}, mRawGain, twoPi { 3.14159265358979323f };
    bool mGlobalBypass;

     /** Variables for the Z filter equations */
    double mGCoeff, mRCoeff, mRCoeff2, mK, mInversion;
    
    FilterType mType;
    
    QType mQType;
    
     /** state variables (z^-1) */
    std::vector<double> mZ1{}, mZ2{};
    
    void setGain(SampleType value);
    
    SampleType getShelfQ(SampleType value) const;
    SampleType getPeakQ(SampleType value) const;
    
    double sampleRate2X {0.0};
    double halfSampleDuration {0.0};
    
    double wd {0.0};
    double wa {0.0};
    
    void preWarp();
    void setSampleRates();
};
}

#endif /* filter_h */

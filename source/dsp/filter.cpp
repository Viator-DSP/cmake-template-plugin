#include "filter.h"
template <typename SampleType>
viator::SVFilter<SampleType>::SVFilter()
: mCurrentSampleRate (44100.0f), mQ (0.1f), mCutoff (1000.0f), mRawGain (0.0f)
, mGlobalBypass (false)
, mGCoeff (0.0), mRCoeff (0.0), mRCoeff2 (0.0), mK (1.0), mInversion (0.0)
, mType (FilterType::kLowPass), mQType (QType::kParametric)
{
    preWarp();
    setGain(0.0);
}

template <typename SampleType>
void viator::SVFilter<SampleType>::prepare(const float sample_rate, const int num_channels)
{
    mCurrentSampleRate = sample_rate;
    setSampleRates();
    
    mZ1.assign(num_channels, 0.0);
    mZ2.assign(num_channels, 0.0);
}

template <typename SampleType>
void viator::SVFilter<SampleType>::setParameter(ParameterId parameter, SampleType parameterValue)
{
    switch (parameter)
    {
        // Filter Type
        case ParameterId::kType:
        {
            mType = (FilterType)parameterValue;

            if (mType == kLowShelf || mType == kHighShelf)
            {
                mQ *= 0.8;
            }

            break;
        }
            
        // Filter Q Type
        case ParameterId::kQType:
        {
            mQType = (QType)parameterValue;
            break;
        }
        case ParameterId::kSampleRate:
        {
            mCurrentSampleRate = parameterValue;
            setSampleRates();
            break;
        }
            
        // Filter Bypass
        case ParameterId::kBypass: mGlobalBypass = static_cast<bool>(parameterValue); break;
    }
}

template <typename SampleType>
void viator::SVFilter<SampleType>::setGain(SampleType value)
{
    mGain = pow(10, value * 0.05) - 1.f;
    mRawGain = value;
}

template <typename SampleType>
SampleType viator::SVFilter<SampleType>::getShelfQ(SampleType value) const
{
    return viator::dsp::Decibels::db_to_gain(std::abs(value)) * 0.25f - 0.24f;
}

template <typename SampleType>
SampleType viator::SVFilter<SampleType>::getPeakQ(SampleType value) const
{
    return viator::dsp::Decibels::db_to_gain(std::abs(value)) * 0.1f;
}

template <typename SampleType>
void viator::SVFilter<SampleType>::preWarp()
{
    // prewarp the cutoff (for bilinear-transform filters)
    wd = mCutoff * 6.28f;
    wa = sampleRate2X * std::tan(wd * halfSampleDuration);
            
    //Calculate g (gain element of integrator)
    mGCoeff = wa * halfSampleDuration;
            
    mRCoeff2 = mRCoeff * 2.0;
            
    mInversion = 1.0 / (1.0 + mRCoeff2 * mGCoeff + mGCoeff * mGCoeff);
}

template <typename SampleType>
void viator::SVFilter<SampleType>::setSampleRates()
{
    sampleRate2X = mCurrentSampleRate * 2.0;
    halfSampleDuration = 1.0 / mCurrentSampleRate / 2.0;
}

template class viator::SVFilter<float>;
template class viator::SVFilter<double>;


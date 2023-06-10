/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"




//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    auto juce__slider  = new juce::Slider() ;
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible (juce__slider);
    juce__slider->setRange (0, 1, 0.005 );
    juce__slider->setBounds (32, 240 - (240 / 2), 300, 240);
    

    juce__slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    juce__slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    
    juce__slider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffc842c1));
    juce__slider->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colours::black);

    juce__slider->setColour (juce::Slider::textBoxTextColourId, juce::Colours::black);
    juce__slider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colours::white);
    juce__slider->setTextValueSuffix(" Shhh");
    juce__slider->addListener(this);


    setSize (370, 400);
}
void NewProjectAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.setGain(slider->getValue());
}


NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

//void NewProjectAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
//{
//    //[UsersliderValueChanged_Pre]
//    //[/UsersliderValueChanged_Pre]
//
//    if (sliderThatWasMoved == juce__slider)
//    {
//        //[UserSliderCode_juce__slider] -- add your slider handling code here..
//        //[/UserSliderCode_juce__slider]
//    }
//
//    //[UsersliderValueChanged_Post]
//    //[/UsersliderValueChanged_Post]
//}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
    
    g.fillAll (juce::Colours::white);

        {
//            int x = 132, y = 172, width = 100, height = 100;
            //[UserPaintCustomArguments] Customize the painting arguments here..
            //[/UserPaintCustomArguments]
        }

        {
            int x = 44, y = 36, width = 284, height = 30;
            juce::String text (TRANS("PROVERBIAL SILENCE"));
            juce::Colour fillColour = juce::Colour (0xff8a00aa);
            //[UserPaintCustomArguments] Customize the painting arguments here..
            //[/UserPaintCustomArguments]
            g.setColour (fillColour);
            g.setFont (juce::Font ("Gill Sans", 33.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
            g.drawText (text, x, y, width, height,
                        juce::Justification::centred, true);
        }
    {
            float x = 140.0f, y = 188.0f, width = 20.0f, height = 20.0f;
            juce::Colour fillColour = juce::Colour (0xffa52a8b);
            //[UserPaintCustomArguments] Customize the painting arguments here..
            //[/UserPaintCustomArguments]
            g.setColour (fillColour);
            g.fillEllipse (x, y, width, height);
        }

        {
            float x = 204.0f, y = 188.0f, width = 20.0f, height = 20.0f;
            juce::Colour fillColour = juce::Colour (0xffa52a8b);
            //[UserPaintCustomArguments] Customize the painting arguments here..
            //[/UserPaintCustomArguments]
            g.setColour (fillColour);
            g.fillEllipse (x, y, width, height);
        }

        {
            int x = 84, y = 236, width = 200, height = 30;
            juce::String text (TRANS("X"));
            juce::Colour fillColour = juce::Colour (0xffbd16a0);
            //[UserPaintCustomArguments] Customize the painting arguments here..
            //[/UserPaintCustomArguments]
            g.setColour (fillColour);
            g.setFont (juce::Font ("Gill Sans", 50.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
            g.drawText (text, x, y, width, height,
                        juce::Justification::centred, true);
        }
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
}

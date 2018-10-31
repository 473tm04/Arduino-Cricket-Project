# Arduino-Cricket-Project
Uses an Arduino to turn on LEDs when action potential is detected by electrodes in cricket's leg. For use in demonstration at the 2018 Brain Discovery Fair at University of Kansas Medical Center.

![Goal of Demonstration](/docs/goal.PNG "Goal of Demo")

## Contents ##

1. [Markdown ReadMe File](#markdown-practice)
2. [Arduino Sketch](#arduino-sketch)
3. [Demo Overview](#overview)



## Markdown Practice ##

* @tej:
  * I've added some markdown (.md) syntax to the **ReadMe** file. It's good practice to include a ReadMe with any repo you post. Try to format it in a way that any stranger would be able to get a general gist of what is going on with the project and could pick it up and start contributing. That way, once you have 100 repositories and you don't remember your first repository, it will be easier to go back to it and remember what you did. 
  * I like to use [typora](https://typora.io/), which is an editor that will automatically let you see how the markdown syntax will look once the _README.md_ is posted to a particular GitHub directory. GitHub automatically looks for that file and then puts its content below all the files in the repository, so it is kind of a shorthand way to make a decent-looking website describing what your code does. I also use it to take notes and stuff for other things.



## Arduino Sketch ##

### contents ###

* [Cricket](#cricket)
  * [void setup()](#setup)
  * [void loop()](#loop)
  * [int setSpikeThreshold()](#setspikethreshold)
  * [void detectSpikes(int threshold)](#detectSpikes)



---

### cricket ###

_Detailed description of Arduino sketch and significance of what it does, what is hoped to accomplish with the demo, what things someone might learn by doing this._

### setup ###

_Description of what happens during setup(). Why did you put things here instead of at the top (outside of the setup code)._

### loop ###

_This contains only 2 functions currently; keep this part as simple as possible and try and stick to only having one "theme" that each sub-function does. Briefly describe what goes on here._

### setSpikeThreshold ###

_Description of how the spike threshold is set. How would the potentiometer be used? As a hint, the analog input will be quantized into discrete levels using a 10-bit analog-to-digital converter. That means the continuous voltage values obtained from the potentiometer used to set the threshold will have to be converted into threshold values in some way. There are built-in Arduino functions that do this, I think one of them is used maybe in the Potentiometer example on the Arduino website. You should be able to describe what is quantization and why is it necessary to do that._

### detectSpikes ###

_How is spike detection done? Why did you choose to only get monopolar thresholds (what does that mean)? What do you expect would happen if the threshold is too low, or too high? Can you think of a way that you could automatically set the threshold levels without having to manually adjust it? How will you know if the threshold is too low or too high? How do you know if the things you are detecting with the LED light flashes are actually spikes?_



## Overview ##

In this experiment, spikes in the extracellular electrical field from an invertebrate (cricket) will be filtered and amplified using a SpikerBox ([BackyardBrains](https://backyardbrains.com/)), which will relay the processed signal to a microcontroller (Arduino UNO), where the signal will be used to control an LED output. 

![Acquisition and Detection](/docs/detection.PNG "Acquisition and Detection")

_@tej: Why do we need the SpikerBox? Why not go straight into the Arduino?_

The output of the SpikerBox is split so that the filtered and amplified signal from the box is passed to an audio amplifier, where additional filtering may be applied. Correct filtering, grounding, and recording lead placement should lead the amplifier to produce a noise similar to rain falling.

![Audio output](/docs/audio_out.PNG "Audio output")

Finally, online thresholding using an empirically determined scaling of the potentiometer voltage will be used in conjunction with a fixed de-bounce period to identify the presence of spikes. Each time a spike is detected, the LED will flash for an artificially longer duration so that it is apparent to the observer, although in reality the spike may be 1.2 milliseconds or shorter. 

![LED output](/docs/led_out.PNG "LED output")
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <font_Arial.h>
#include <font_ArialBold.h>
#include <ILI9341_t3.h>

/*
 * DEFINE PINS
 */

#define PIN_ON_OFF      0   // digital
#define PIN_VOLUME_IN   24  // analog
#define PIN_VOLUME_OUT  25  // analog
#define PIN_WETNESS     26  // analog
#define PIN_COLOR       27  // analog
#define PIN_            17  // analog

/*
#define PIN_DTIME_SW    33  // digital
#define PIN_DTIME_CLK   14  // analog
#define PIN_DTIME_DT    16  // analog
#define PIN_FEED_SW     28  // dital
#define PIN_FEED_CLK    39  // analog
#define PIN_FEED_DT     38  // analog

#define PIN_TFT_CS      10
#define PIN_TFT_DC      9
#define PIN_TFT_MOSI    11
#define PIN_TFT_SCLK    13
#define PIN_TFT_RST     -1
#define PIN_TFT_MISO    12

ILI9341_t3 tft = ILI9341_t3(PIN_TFT_CS, PIN_TFT_DC, PIN_TFT_RST, PIN_TFT_MOSI, PIN_TFT_SCLK, PIN_TFT_MISO);
*/

/*
 * TEENSY AUDIO: DEFINE NODES & CONNECTIONS
 */

// either or
AudioInputI2S            audioInput;      // stereo input (line)
//AudioInputUSB            audioInput;      // stereo input (usb)

// nodes
AudioEffectDelay         delayL;          // L delay
AudioEffectDelay         delayR;          // R delay
AudioMixer4              mixerWetnessL;   // L delay mixer (dry / delay)
AudioMixer4              mixerWetnessR;   // R delay mixer (dry / delay)
AudioMixer4              mixerFeedbackL;  // L delay mixer (feedback)
AudioMixer4              mixerFeedbackR;  // R delay mixer (feedback)
AudioOutputI2S           audioOutput;     // stereo output (line)
AudioControlSGTL5000     sgtl5000;        // audio shield controls

// L & R input
AudioConnection          patchCord1(audioInput, 0, mixerFeedbackL, 0);
AudioConnection          patchCord2(audioInput, 1, mixerFeedbackR, 0);

AudioConnection          patchCord3(audioInput, 0, mixerWetnessL, 0);
AudioConnection          patchCord4(audioInput, 1, mixerWetnessR, 0);

// L delay line
AudioConnection          patchCord5(mixerFeedbackL, delayL);
AudioConnection          patchCord6(delayL, 0, mixerFeedbackL, 2);
AudioConnection          patchCord7(mixerFeedbackL, 0, mixerWetnessL, 2);

// R delay line
AudioConnection          patchCord8(mixerFeedbackR, delayR);
AudioConnection          patchCord9(delayR, 0, mixerFeedbackR, 2);
AudioConnection          patchCord10(mixerFeedbackR, 0, mixerWetnessR, 2);

// L & R output
AudioConnection          patchCord11(mixerWetnessL, 0, audioOutput, 0);
AudioConnection          patchCord12(mixerWetnessR, 0, audioOutput, 1);

/*
 * INITIALIZE CONTROL VARIABLES
 */

float volumeIn        = 1.0;
float volumeOut       = 1.0;
float wetness         = 0.5;
float color           = 0.5;
float modulation      = 0.0;

int delayTimeChannel  = 0;            // 0 = left, 1 = left
int delayTime[]       = {500, 500};   // in ms
int feedbackChannel   = 0;            // 0 = left, 1 = left
float feedback[]      = {0.8, 0.8};

int delayTimeState;
int delayTimeLastState;
int feedbackState;
int feedbackLastState;

/*
 * SETUP
 */

void setup() {
  // allocate memory for audio
  AudioMemory(1024);

  // initialize audio shield
  sgtl5000.enable();
  //sgtl5000.adcHighPassFilterDisable();

  // start serial output
  //Serial.begin(9600);

  // initialize display
  /*
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);

  tft.print("Hello");

  // initialize state variables for stepped rotary encoders
  delayTimeLastState = digitalRead(PIN_DTIME_DT);
  feedbackLastState = digitalRead(PIN_FEED_DT);

  // update all parameters
  updateParameters();
  */
}

/*
 * LOOP
 */

void loop() {
  // update all parameters
  //updateParameters();
  /*
  Serial.print("IN: ");
  Serial.print(volumeIn);
  Serial.print(", OUT: ");
  Serial.println(volumeOut);
  */
}

/*
 * DECLARE CUSTOM FUNCTIONS
 */

/*
void updateParameters() {
  // volume in
  volumeIn = analogRead(PIN_VOLUME_IN) / 1024.0;
  mixerFeedbackL.gain(0, (0.5*volumeIn));
  mixerFeedbackR.gain(0, (0.5*volumeIn));

  // volume out
  volumeOut = analogRead(PIN_VOLUME_OUT) / 1024.0;
  sgtl5000.volume(volumeOut);

  // wetness
  wetness = analogRead(PIN_WETNESS) / 1024.0;
  mixerWetnessL.gain(0, (1-wetness));   // dry
  mixerWetnessL.gain(2, wetness);       // wet
  mixerWetnessR.gain(0, (1-wetness));   // dry
  mixerWetnessR.gain(2, wetness);       // wet

  // delay time
  delayTimeState = digitalRead(PIN_DTIME_DT);
  if (delayTimeState != delayTimeLastState) {
    if (digitalRead(PIN_DTIME_CLK) != delayTimeState) {
      switch (delayTimeChannel) {
        default: delayTime[0] += 10; delayTime[1] += 10; break;
        case 0: delayTime[0] += 10; break;
        case 1: delayTime[1] += 10; break;
      }
    } else {
      switch (delayTimeChannel) {
        default: delayTime[0] -= 10; delayTime[1] -= 10; break;
        case 0: delayTime[0] -= 10; break;
        case 1: delayTime[1] -= 10; break;
      }
    }
    delayL.delay(0, delayTime[0]);
    delayR.delay(0, delayTime[1]);
  } 
  delayTimeLastState = delayTimeState;

  // feedback
  feedbackState = digitalRead(PIN_FEED_DT);
  if (feedbackState != feedbackLastState) {
    if (digitalRead(PIN_FEED_CLK) != feedbackState) {
      switch (feedbackChannel) {
        default: feedback[0] += 0.02; feedback[1] += 0.02; break;
        case 0: feedback[0] += 0.02; break;
        case 1: feedback[1] += 0.02; break;
      }
    } else {
      switch (delayTimeChannel) {
        default: feedback[0] -= 0.02; feedback[1] -= 0.02; break;
        case 0: feedback[0] -= 0.02; break;
        case 1: feedback[1] -= 0.02; break;
      }
    }
    mixerFeedbackL.gain(2, (0.5*feedback[0]));
    mixerFeedbackR.gain(2, (0.5*feedback[1]));
  } 
  feedbackLastState = feedbackState;
  
  // color

  // modulation
  
}
*/

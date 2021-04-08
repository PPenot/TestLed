#include <NeoPixelBus.h>
#include <arduino.h>
#include <SPI.h>
#include <Wire.h>


// manually configure these params:
const uint16_t strip01_PixelCount = 10;
const uint8_t strip01_PixelPin = 16;

const uint16_t totalPixelCount = strip01_PixelCount;
NeoPixelBus<NeoGrbFeature, NeoEsp32Rmt0Ws2812xMethod> strip01(strip01_PixelCount, strip01_PixelPin);
NeoBuffer<NeoBufferMethod<NeoGrbFeature>> strip00(totalPixelCount,1,NULL);


#define colormid 55
#define colorfull 255

// four element pixels, RGBW
//NeoPixelBus<NeoRgbwFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

RgbColor redfmid(colormid, 0, 0);
RgbColor greenmid(0, colormid, 0);
RgbColor bluemid(0, 0, colormid);
RgbColor whitemid(colormid);

RgbColor redffull(colorfull, 0, 0);
RgbColor greenfull(0, colorfull, 0);
RgbColor bluefull(0, 0, colorfull);
RgbColor whitefull(colorfull);

RgbColor black(0);


void setup()
{

    Serial.begin(115200);
    while (!Serial) {
    }
    Serial.println("Initializing...");
    strip01.Begin();
    // reset them to off:
    strip01.Show();
    // set the entire buffer to black color to set off for all pixels:
    strip00.ClearTo(black);


    for(int i=0; i<10; i++){

        strip01.SetPixelColor(i, whitemid);
    }

    strip01.SetPixelColor(9, whitefull);
    strip01.SetPixelColor(8, bluefull);
    strip01.SetPixelColor(7, greenfull);
    strip01.SetPixelColor(6, redffull);
    strip01.SetPixelColor(5, black);
    strip01.SetPixelColor(4, black);
    strip01.SetPixelColor(3, whitemid);
    strip01.SetPixelColor(2, bluemid);
    strip01.SetPixelColor(1, greenmid);
    strip01.SetPixelColor(0, redfmid);

    strip01.Show();
}


void loop()
{

    //Serial.println("begin loop..");

    // set the colors for some test pixels on each strip:

    //strip01.SetPixelColor(1, red);
    //strip01.SetPixelColor(3, green);
    //strip01.SetPixelColor(5, blue);
    //strip01.SetPixelColor(7, white);

    //strip02.SetPixelColor(17, red);
    //strip02.SetPixelColor(15, green);
    //strip02.SetPixelColor(13, blue);
    //strip02.SetPixelColor(11, white);

// assign color to the buffer object LEDs instead: (notice the x/y coordiinate, just use 0 since we're using a "single row" bitmap)



}

#include <Arduino.h>
#include <esp_log.h>
#include "xy6020.h"

/* Default pin where XY6020 hardware is connected on a ESP32 */
#define RXD2 16
#define TXD2 17

XY6020Library XY6020;
static const char *const TAG = "xy6020";

void configureXY6020(void)
{
    XY6020.setLock(0);                             /* No lock */
    XY6020.setProtect(0);                          /* set protection */
    XY6020.setDefaultOutputVoltage(0);
    XY6020.setSerialTimeout(50);

    XY6020.setMaxCurrent(2100);

    XY6020.setLowVoltageProtection(8000);          /* 8000 mV or 8.00V */
    XY6020.setOverVoltageProtection(20000);        /* 00000 mV or 20.00V */
    XY6020.setOverCurrentProtection(1000);         /* Max. 1 Amp (mA*/
    XY6020.setOverPowerProtection(50);             /* Max. 50 W output  */

    XY6020.setMaximumOutputTime_h(0);
    XY6020.setMaximumOutputTime_m(0);
    
    XY6020.setMaximumOutput_AH(999999999);
    XY6020.setMaximumOutput_WH(999999999);

    XY6020.setCurrent(1000);                       /* 1Amp*/
    XY6020.setVoltage(12000);                      /* 12V */

    XY6020.setOnOff(1);                            /* turn on output */
}


void setup() {

  Serial.begin(115200);                             /* used for ESP32 debug information communication */
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);    /* used for XY6020 communication*/

  ESP_LOGI(TAG, "Setting up xy6020...");

  configureXY6020();

}

void loop() {

  /* This need to called in order to update the data from the XY6020 device */
  XY6020.updatestats();

  ESP_LOGI("Voltage: ", XY6020.get_vout());
  ESP_LOGI("Current: ", XY6020.get_Current());
  ESP_LOGI("Power: ", XY6020.get_Power());

  delay(1000);    /* make sure there is a little delay */
}


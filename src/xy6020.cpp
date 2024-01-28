// Include necessary libraries
#include <Arduino.h>
#include "xy6020.h"

// Function to get default output voltage
uint16_t XY6020Library::getDefaultOutputVoltage(void)
{
  return this->defaultOutputVoltage;
}

// Function to set default output voltage
void XY6020Library::setDefaultOutputVoltage(uint16_t voltage)
{
  this->defaultOutputVoltage = voltage;
}

// Function to get default output current
uint16_t XY6020Library::getDefaultOutputCurrent(void)
{
  return this->defaultOutputCurrent;
}

// Function to set default output current
void XY6020Library::setDefaultOutputCurrent(uint16_t current)
{
  this->defaultOutputVoltage = current;  // Typo: Should be defaultOutputCurrent
}

// Function to set serial timeout
void XY6020Library::setSerialTimeout(uint16_t timeout_ms)
{
  this->serialTimeout = timeout_ms;
}

// Function to get stats count
uint8_t XY6020Library::getStats(void)
{
  return this->stats_count;
}

// Function to set voltage
void XY6020Library::setVoltage(uint16_t voltage_mv)
{
  if (voltage_mv > MAX_VOLTAGE) {
    voltage_mv = MAX_VOLTAGE;
  }

  send_data(XY6020_WRITE_REGISTER, XY6020_V_SET, voltage_mv / 10);
}

// Function to get current
uint16_t XY6020Library::getCurrent(void)
{
  return iset;
}

// Function to set current
void XY6020Library::setCurrent(uint16_t current_ma)
{
  if (current_ma > getMaxCurrent()) {
    current_ma = getMaxCurrent();
  }

  send_data(XY6020_WRITE_REGISTER, XY6020_I_SET, current_ma);
}

// Function to set maximum current
void XY6020Library::setMaxCurrent(uint16_t max_current)
{
  if (max_current > ABS_MAX_AMP)
  {
    max_current = ABS_MAX_AMP;
  }

  maxCurrent = max_current;
}

// Function to get maximum current
uint16_t XY6020Library::getMaxCurrent(void)
{
  return maxCurrent;
}

// Function to get iset
uint16_t XY6020Library::getiset(void)
{
  return iset;
}

// Function to get vset
uint16_t XY6020Library::getvset(void)
{
  return vset;
}

// Function to get data length error
uint8_t XY6020Library::getDataLengthError(void)
{
  return datalength_error;
}

// Function to get vout
uint16_t XY6020Library::getvout(void)
{
  return vout;
}

// Function to get iout
uint16_t XY6020Library::getiout(void)
{
  return iout;
}

// Function to get power
uint16_t XY6020Library::getPower(void)
{
  return power;
}

// Function to get uin
uint16_t XY6020Library::getuin(void)
{
  return uin;
}

// Function to get out_h
uint16_t XY6020Library::getout_h(void)
{
  return out_h;
}

// Function to get out_m
uint16_t XY6020Library::getout_m(void)
{
  return out_m;
}

// Function to get out_s
uint16_t XY6020Library::getout_s(void)
{
  return out_s;
}

// Function to set t_in
void XY6020Library::sett_in(uint16_t tin)
{
  t_in = tin;
}

// Function to get t_in
uint16_t XY6020Library::gett_in(void)
{
  return t_in;
}

// Function to set t_ex
void XY6020Library::sett_ex(uint16_t tex)
{
  t_ex = tex;
}

// Function to get t_ex
uint16_t XY6020Library::gett_ex(void)
{
  return t_ex;
}

// Function to get ah
uint32_t XY6020Library::getah(void)
{
  return (ah_high << 16) | (ah_low);
}

// Function to get wh
uint32_t XY6020Library::getwh(void)
{
  uint32_t tempwh = (wh_high << 16) | (wh_low);

  tempwh = tempwh / 1000000;

  return tempwh;
}

// Function to get lock
uint16_t XY6020Library::getLock(void)
{
  return lock;
}

// Function to set lock
void XY6020Library::setLock(uint16_t _lock)
{
  lock = _lock;
  setregister(XY6020_WRITE_REGISTER, XY6020_LOCK, _lock);
}

// Function to get protect
uint16_t XY6020Library::getProtect(void)
{
  return protect;
}

// Function to set protect
void XY6020Library::setProtect(uint16_t _protect)
{
  protect = _protect;
  setregister(XY6020_WRITE_REGISTER, XY6020_PROTECT, _protect);
}

// Function to get cvcc
uint16_t XY6020Library::getcvcc(void)
{
  return cvcc;
}

// Function to get OnOff
uint16_t XY6020Library::getOnOff(void)
{
  return onoff;
}

// Function to set OnOff
void XY6020Library::setOnOff(uint16_t _onoff)
{
  onoff = _onoff;
  setregister(XY6020_WRITE_REGISTER, XY6020_ONOFF, _onoff);
}

// Function to set Low Voltage Protection
void XY6020Library::setLowVoltageProtection(uint16_t _lpv)
{
  lvp = _lpv / 10;
  setregister(XY6020_WRITE_REGISTER, XY6020_S_LVP, lvp);
}

// Function to get Low Voltage Protection
uint16_t XY6020Library::getLowVoltageProtection(void)
{
  return lvp;
}

// Function to set Over Voltage Protection
void XY6020Library::setOverVoltageProtection(uint16_t _opv)
{
  ovp = _opv / 10;
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OVP, ovp);
}

// Function to get Over Voltage Protection
uint16_t XY6020Library::getOverVoltageProtection(void)
{
  return ovp;
}

// Function to set Over Current Protection
void XY6020Library::setOverCurrentProtection(uint16_t _ocp)
{
  ocp = _ocp;
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OCP, ocp);
}

// Function to get Over Current Protection
uint16_t XY6020Library::getOverCurrentProtection(void)
{
  return ocp;
}

// Function to set Over Power Protection
void XY6020Library::setOverPowerProtection(uint16_t _opp)
{
  opp = _opp;
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OPP, opp);
}

// Function to get Over Power Protection
uint16_t XY6020Library::getOverPowerProtection(void)
{
  return opp;
}

// Function to set Maximum Output Time in hours
void XY6020Library::setMaximumOutputTime_h(uint16_t _ohp_h)
{
  ohp_h = _ohp_h;
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OHP_H, ohp_h);
}

// Function to get Maximum Output Time in hours
uint16_t XY6020Library::getMaximumOutputTime_h(void)
{
  return ohp_h;
}

// Function to set Maximum Output Time in minutes
void XY6020Library::setMaximumOutputTime_m(uint16_t _ohp_m)
{
  ohp_m = _ohp_m;
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OHP_M, ohp_m);
}

// Function to get Maximum Output Time in minutes
uint16_t XY6020Library::getMaximumOutputTime_m(void)
{
  return ohp_m;
}

// Function to set Maximum Output AH
void XY6020Library::setMaximumOutput_AH(uint32_t _oah)
{
  oah = _oah;

  setregister(XY6020_WRITE_REGISTER, XY6020_S_OAH_L,  (0xffff & oah));
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OAH_H,  (oah >> 16) & 0xffff);
}

// Function to get Maximum Output AH
uint32_t XY6020Library::getMaximumOutput_AH(void)
{
  return oah;
}

// Function to set Maximum Output WH
void XY6020Library::setMaximumOutput_WH(uint32_t _owh)
{
  owh = _owh;

  setregister(XY6020_WRITE_REGISTER, XY6020_S_OWH_L, (0xffff & owh));
  setregister(XY6020_WRITE_REGISTER, XY6020_S_OWH_H, (owh >> 16) & 0xffff);
}

// Function to get Maximum Output WH
uint32_t XY6020Library::getMaximumOutput_WH(void)
{
  return owh;
}

// Function to get f_c
uint16_t XY6020Library::getf_c(void)
{
  return f_c;
}

// Function to get b_led
uint16_t XY6020Library::getb_led(void)
{
  return b_led;
}

// Function to get Sleep
uint16_t XY6020Library::getSleep(void)
{
  return sleep;
}

// Function to get Model
uint16_t XY6020Library::getModel(void)
{
  return model;
}

// Function to get Version
uint16_t XY6020Library::getVersion(void)
{
  return version;
}

// Function to get stats count
uint32_t XY6020Library::getstats_count(void)
{
  return stats_count;
}

// Function to get data length
uint32_t XY6020Library::getdatalength(void)
{
  return datalength;
}

// Function to calculate CRC value
uint16_t XY6020Library::calculate_crc(const uint8_t* data, size_t length)
{
  uint16_t crc_register = 0xFFFF;

  for (size_t i = 0; i < length; i++) {
    crc_register ^= data[i];

    for (int j = 0; j < 8; j++) {
      if (crc_register & 0x0001) {
        crc_register = (crc_register >> 1) ^ 0xA001;
      } else {
        crc_register >>= 1;
      }
    }
  }

  crc_register = ((crc_register & 0xFF) << 8) | ((crc_register >> 8) & 0xFF);

  // Uncomment the line below to print the CRC value
  // printf("CRC: %04X\n", crc_register);

  return crc_register & 0xFFFF;
}

// Function to send data to the device
size_t XY6020Library::send_data(uint8_t function_code, uint16_t register_start_address, uint16_t num_register_addresses)
{
  // Create data packet
  uint8_t data[64];
  size_t data_length = 0;

  // Populate data packet
  data[data_length++] = SLAVE_ADDRESS;
  data[data_length++] = function_code;
  data[data_length++] = (register_start_address >> 8) & 0xFF;
  data[data_length++] = register_start_address & 0xFF;
  data[data_length++] = (num_register_addresses >> 8) & 0xFF;
  data[data_length++] = num_register_addresses & 0xFF;

  // Calculate CRC
  uint16_t crc = calculate_crc(data, data_length);

  // Add CRC to data packet
  data[data_length++] = (crc >> 8) & 0xFF;
  data[data_length++] = crc & 0xFF;

  // Send the data packet
  Serial2.write(data, data_length);

  // Clear input data buffer
  for (size_t i = 0; i < 64; i++) { in_data[i] = 0; }

  // Read the response data
  size_t in_data_length = Serial2.readBytes(in_data, 45);

  return in_data_length;
}

// Function to set register on the device
void XY6020Library::setregister(uint8_t function_code, uint16_t register_start_address, uint16_t num_register_addresses)
{
  // Create data packet
  uint8_t data[64];
  size_t data_length = 0;

  // Populate data packet
  data[data_length++] = SLAVE_ADDRESS;
  data[data_length++] = function_code;
  data[data_length++] = (register_start_address >> 8) & 0xFF;
  data[data_length++] = register_start_address & 0xFF;
  data[data_length++] = (num_register_addresses >> 8) & 0xFF;
  data[data_length++] = num_register_addresses & 0xFF;

  // Calculate CRC
  uint16_t crc = calculate_crc(data, data_length);

  // Add CRC to data packet
  data[data_length++] = (crc >> 8) & 0xFF;
  data[data_length++] = crc & 0xFF;

  // Send the data packet
  Serial2.write(data, data_length);

  // Read the response data
  size_t in_data_length = Serial2.readBytes(in_data, 10);
}

// Function to update device statistics
void XY6020Library::updatestats() 
{
    size_t _datalength = 0;

    //    datalength = 0;
    datalength_error = 0;

    _datalength = send_data(XY6020_READ_REGISTER, XY6020_V_SET, 30);
    if (_datalength > 20)
    {
        vset = ((in_data[3] << 8) | in_data[4]);
        iset = ((in_data[5] << 8) | in_data[6]);
        vout = ((in_data[7] << 8) | in_data[8]);
        iout = ((in_data[9] << 8) | in_data[10]);
        power =((in_data[11] << 8) | in_data[12]);
        uin =  ((in_data[13] << 8) | in_data[14]);
        ah_low = ((in_data[15] << 8) | in_data[16]);
        ah_high = ((in_data[17] << 8) | in_data[18]);
        wh_low = ((in_data[19] << 8) | in_data[20]);
        wh_high = ((in_data[21] << 8) | in_data[22]);
        out_h = ((in_data[23] << 8) | in_data[24]);
        out_m = ((in_data[25] << 8) | in_data[26]);
        out_s = ((in_data[27] << 8) | in_data[28]);

        t_in = ((in_data[29] << 8) | in_data[30]);
        t_ex = ((in_data[31] << 8) | in_data[32]);
        
    }
    else
    {
        datalength_error = _datalength;
    }

    datalength += _datalength;

    _datalength = send_data(XY6020_READ_REGISTER, XY6020_LOCK, 30);
    if (_datalength > 20)
    {
        lock = ((in_data[3] << 8) | in_data[4]);
        protect = ((in_data[5] << 8) | in_data[6]);
        cvcc = ((in_data[7] << 8) | in_data[8]);
        onoff = ((in_data[9] << 8) | in_data[10]);
        
        f_c = ((in_data[11] << 8) | in_data[12]);
        b_led = ((in_data[13] << 8) | in_data[14]);
        sleep = ((in_data[15] << 8) | in_data[16]);
        
        model = ((in_data[17] << 8) | in_data[18]);
        version = ((in_data[19] << 8) | in_data[20]);
        slaveadd = ((in_data[21] << 8) | in_data[22]);
        baudrate = ((in_data[23] << 8) | in_data[24]);

        stats_count++;
    }
    else
    {
        datalength_error = _datalength;
    }

    datalength += _datalength;
}


uint16_t XY6020Library::getuin(uint8_t function_code, const char* desc) 
{
    send_data(XY6020_READ_REGISTER, function_code, 0x02);

    // Read and process the data response
    // ...

    uint16_t result = 0; // Placeholder value, replace with actual result

    // Print the result
    // ...

    return result;
}

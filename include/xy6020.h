
#define ABS_MAX_AMP         20000
#define DEFAULT_VOLTAGE     12000
#define MAX_VOLTAGE         54000


enum xy6020_command : uint8_t {
    XY6020_READ_REGISTER = 0x03,
    XY6020_WRITE_REGISTER = 0x06,
    XY6020_WRITE_MULTIPLE_REGISTERS = 0x10,
    SLAVE_ADDRESS = 0x01
  };
 
enum XY6020_register {
    XY6020_V_SET = 0x0000,         // Voltage Setting
    XY6020_I_SET = 0x0001,         // Current Setting
    XY6020_VOUT = 0x0002,          // Output voltage display value
    XY6020_IOUT = 0x0003,          // Output current display value
    XY6020_POWER = 0x0004,         // Output power display value
    XY6020_UIN = 0x0005,           // Input voltage display value
    XY6020_AH_LOW = 0x0006,        // Output AH low 16 bits
    XY6020_AH_HIGH = 0x0007,       // Output AH high 16 bits
    XY6020_WH_LOW = 0x0008,        // Output WH low 16 bits
    XY6020_WH_HIGH = 0x0009,       // Output WH high 16 bits
    XY6020_OUT_H = 0x000A,         // Open time - hours
    XY6020_OUT_M = 0x000B,         // Start time - minutes
    XY6020_OUT_S = 0x000C,         // Open time - seconds
    XY6020_T_IN = 0x000D,          // Internal temperature value
    XY6020_T_EX = 0x000E,          // External temperature value
    XY6020_LOCK = 0x000F,          // Key lock
    XY6020_PROTECT = 0x0010,       // Protection status
    XY6020_CVCC = 0x0011,          // Constant voltage and constant current state
    XY6020_ONOFF = 0x0012,         // Output On/Off
    XY6020_F_C = 0x0013,           // Temperature F/C
    XY6020_B_LED = 0x0014,         // Backlight brightness level
    XY6020_SLEEP = 0x0015,         // Off screen time
    XY6020_MODEL = 0x0016,         // Product number
    XY6020_VERSION = 0x0017,       // Firmware version
    XY6020_SLAVE_ADD = 0x0018,     // Slave address
    XY6020_BAUDRATE_L = 0x0019,    // Baud rate
    XY6020_T_IN_OFFSET = 0x001A,   // Internal temperature correction
    XY6020_T_EX_OFFSET = 0x001B,   // External temperature correction
    XY6020_BUZZER = 0x001C,        // Buzzer switch
    XY6020_EXTRACT_M = 0x001D,     // Quickly call out data sets
    XY6020_DEVICE = 0x001E,        // Device status
    XY6020_MASTER = 0x0030,        // Host type
    XY6020_WIFI_CONFIG = 0x0031,   // WIFI-CONFIG
    XY6020_WIFI_STATUS = 0x0032,   // WIFI State
    XY6020_IPV4_H = 0x0033,        // First 2 bytes of the IP address
    XY6020_IPV4_L = 0x0034,        // Last 2 bytes of the IP address
    XY6020_V_SET_SET = 0x0050,     // Set voltage
    XY6020_I_SET_SET = 0x0051,     // Set current
    XY6020_S_LVP = 0x0052,         // Low voltage protection value
    XY6020_S_OVP = 0x0053,         // Overvoltage protection value
    XY6020_S_OCP = 0x0054,         // Overcurrent protection value
    XY6020_S_OPP = 0x0055,         // Over power protection value
    XY6020_S_OHP_H = 0x0056,       // Maximum output time - hour
    XY6020_S_OHP_M = 0x0057,       // Maximum output duration - minutes
    XY6020_S_OAH_L = 0x0058,       // Maximum output AH low 16 bits
    XY6020_S_OAH_H = 0x0059,       // Maximum output AH high 16 bits
    XY6020_S_OWH_L = 0x005A,       // Maximum output WH low 16 bits
    XY6020_S_OWH_H = 0x005B,       // Maximum output WH high 16 bits
    XY6020_S_OTP = 0x005C,         // Over temperature protection value
    XY6020_S_INI = 0x005D          // Power-on output switch
}; 

class XY6020Library {
 public:
    uint16_t calculate_crc(const uint8_t* data, size_t length);
    uint16_t getuin(uint8_t function_code, const char* desc);
    void setVoltage(uint16_t voltage_mv);
    void setCurrent(uint16_t current_ma);
    void powerswitch(uint8_t power_state);
    size_t send_data(uint8_t function_code, uint16_t register_start_address, uint16_t num_register_addresses);

    void setregister(uint8_t function_code, uint16_t register_start_address, uint16_t num_register_addresses);

    void updatestats(void);

    void getRegisters(uint8_t register_begin, uint8_t* data);

    void setSerialTimeout(uint16_t timeout_ms);
    uint16_t getSerialTimeout(void);

    uint8_t getStats(void);

    void setDefaultOutputVoltage(uint16_t voltage);
    uint16_t getDefaultOutputVoltage(void);

    void setDefaultOutputCurrent(uint16_t current);
    uint16_t getDefaultOutputCurrent(void);

    uint8_t getPowerState(void);

    void setMaxCurrent(uint16_t max_current);
    uint16_t getMaxCurrent(void);

    uint8_t getDataLengthError(void);

    uint16_t getCurrent(void);
    uint16_t getiset(void);
    uint16_t getvset(void);
    uint16_t getvout(void);
    uint16_t getiout(void);
    uint16_t getPower(void);
    uint16_t getuin(void);

    uint16_t getout_h(void);
    uint16_t getout_m(void);
    uint16_t getout_s(void);
    uint16_t gett_in(void);
    void sett_in(uint16_t tex);

    uint16_t gett_ex(void);
    void sett_ex(uint16_t tex);

    uint32_t getah(void);
    uint32_t getwh(void);


    void setLock(uint16_t _lock);
    uint16_t getLock(void);
    void setProtect(uint16_t _protect);
    uint16_t getProtect(void);

    uint16_t getcvcc(void);

    void setOnOff(uint16_t _lock);
    uint16_t getOnOff(void);

    uint16_t getf_c(void);
    uint16_t getb_led(void);
    uint16_t getModel(void);
    uint16_t getVersion(void);

    uint16_t getSleep(void);


    uint32_t getstats_count(void);

    void setLowVoltageProtection(uint16_t _lvp);
    uint16_t getLowVoltageProtection(void); 
    
    void setOverVoltageProtection(uint16_t _opv);
    uint16_t getOverVoltageProtection(void); 

    void setOverCurrentProtection(uint16_t _ocp);
    uint16_t getOverCurrentProtection(void); 

    void setOverPowerProtection(uint16_t _opp);
    uint16_t getOverPowerProtection(void);    
    
    void setMaximumOutputTime_h(uint16_t _ohp_h);
    uint16_t getMaximumOutputTime_h(void);    

    void setMaximumOutputTime_m(uint16_t _ohp_m);
    uint16_t getMaximumOutputTime_m(void);    

    void setMaximumOutput_AH(uint32_t _oah);
    uint32_t getMaximumOutput_AH(void);    

    void setMaximumOutput_WH(uint32_t _owh);
    uint32_t getMaximumOutput_WH(void);  

    uint32_t getdatalength(void);

 private:

    uint8_t in_data[128];
    uint32_t datalength;
    uint32_t datalength_error = 0;

    uint32_t stats_count;

//    uint32_t datalength;

    uint16_t vset = 0;      /* mV */
    uint16_t iset = 0;      /* mA */
    uint16_t vout = 0;      /* mV */
    uint16_t iout = 0;      /* mA */
    uint16_t power = 0;     /* W */
    uint16_t uin = 0;       /* mV */
    uint16_t ah_low;
    uint16_t ah_high;
    uint16_t wh_low;
    uint16_t wh_high;
    uint16_t out_h;
    uint16_t out_m;
    uint16_t out_s;
    uint16_t t_in;
    uint16_t t_ex;

    uint16_t lock;
    uint16_t protect;
    uint16_t cvcc;
    uint16_t onoff;
    uint16_t f_c;
    uint16_t b_led;
    uint16_t sleep;
    uint16_t model;
    uint16_t version;
    uint16_t slaveadd;
    uint16_t baudrate;

    uint16_t lvp;           //Low Voltage Protection Value Default 4.8V
    uint16_t ovp;           //Over Voltage Protection Value

    uint16_t ocp;           //Over Current Protection Value
    uint16_t opp;           //Over Power Protection Value

    uint16_t ohp_h;         //Maximum Output Time Hours
    uint16_t ohp_m;         //Maximum Output Time Minutes

    uint32_t oah;         //Maximum Output Ah 32 Bit
    uint32_t owh;         //Maximum Output Wh 32 Bit



    uint16_t defaultOutputVoltage;
    uint16_t defaultOutputCurrent;
    uint32_t serialTimeout = 100;       //in ms
    uint8_t powerState = 0;

    uint16_t maxCurrent = ABS_MAX_AMP;          // 20000 mA

 protected:

};


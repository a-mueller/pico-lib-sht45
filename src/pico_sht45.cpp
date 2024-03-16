#include "pico_sht45.hpp"

static uint8_t sht45_cmd_measure = SHT45_CMD_MEASURE_HPM;
static uint8_t sht45_i2c_address = SHT45_I2C_ADDRESS;

/*
  This is basically a straight copy from the datasheet pseudo code
  Apart from having the result as an int (10.33 would be 1033)
*/
int pico_sht45_read(i2c_inst_t *i2c, sht45_result_t *result) {
    i2c_write_blocking(i2c, sht45_i2c_address, &sht45_cmd_measure, 1, false);
    sleep_ms(100);
    uint8_t data[6];
    int ret = i2c_read_blocking(i2c, sht45_i2c_address, data, sizeof(data), false);
    if (ret >= 0) {
      int t_ticks = data[0] * 256 + data[1];
      int rh_ticks = data[3] * 256 + data[4];
      result -> temp = 17500 * t_ticks/65535 - 4500;
      int rh_pRH = 12500 * rh_ticks/65535 - 600;
      if (rh_pRH > 10000) {
        rh_pRH = 10000;
      }
      if (rh_pRH < 0) {
        rh_pRH = 0;
      }
      result -> hum = rh_pRH;
    }
    return ret;
}

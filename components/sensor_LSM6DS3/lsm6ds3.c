#include "driver/i2c_master.h"
#include "lsm6ds3.h" 

esp_err_t lsm6ds3_init(i2c_master_dev_handle_t dev_handle){
  uint8_t who_am_i = 0;
  uint8_t reg_addr = LSM6DS3_REG_WHO_AM_I;


  // write-read transaction on the i2c bus.
  esp_err_t err = i2c_master_transmit_receive(dev_handle, &reg_addr, 1, &who_am_i, 1, -1);

  if (err != ESP_OK || who_am_i != LSM6DS3_WHO_AM_I_VAL){
    return ESP_FAIL;
  }

  uint8_t write_buf[2] = {LSM6DS3_REG_CTRL1_XL, 0x40};







}



#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"
#include "lsm6ds3.h"

// no esp
#define I2C_MASTER_SCL_IO 9
#define I2C_MASTER_SDA_IO 8
#define I2C_MASTER_FREQ_HZ 100000 // 100 kHZ


void app_main(void){
  // 1. configuracao fisica do barramento i2c
  i2c_master_bus_config_t i2c_mst_config = {
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .i2c_port = I2C_NUM_0,
    .scl_io_num = I2C_MASTER_SCL_IO,
    .sda_io_num = I2C_MASTER_SDA_IO,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = true, 
  };
  
  i2c_master_bus_handle_t bus_handle;
  ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));
  
  i2c_device_config_t dev_config = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = LSM6DS3_I2C_ADD_0,
    .scl_speed_hz = I2C_MASTER_FREQ_HZ,
  };

  i2c_master_dev_handle_t sensor_handle;
  ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_config, &sensor_handle));

  // 3. Inicialização lógica da HAL do sensor
  if (lsm6ds3_init(sensor_handle) != ESP_OK) {
      printf("FALHA: Sensor LSM6DS3 não respondeu!\n");
      return;
  }
  printf("LSM6DS3 Inicializado com Sucesso!\n");

  if(lsm6ds3_init(sensor_handle) != ESP_OK){
    printf("FALHA: Sensor LSM6DS3 não encontrado ou falha na configuração!");
    return;
  }
  printf("LSM6DS3 Inicializado com Sucesso!\n");

  int16_t acc_x, acc_y, acc_z;
  while(1){
    if(lsm6ds3_read_accel_raw(sensor_handle, &acc_x, &acc_y, &acc_z)== ESP_OK){
      printf("ACCEL: X: %d | Y: %d | Z: %d\n", acc_x, acc_y, acc_z);
    } else {
      printf("ERRO: Falha na leitura I2C\n");
    }

    vTaskDelay(pdMS_TO_TICKS(100));
  }
}


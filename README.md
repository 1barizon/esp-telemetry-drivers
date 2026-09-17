echo # esp-telemetry-drivers
# esp-telemetry-drivers

telemetry-hal-esp32/
├── components/                 # Raiz de todas as bibliotecas
│   │
│   ├── bus_hal/                # Camada 1: Abstração de Barramento (I2C, SPI, UART)
│   │   ├── include/
│   │   │   ├── bus_i2c.h       # Assinaturas das funções (init, read_bytes, write_bytes)
│   │   │   └── bus_spi.h
│   │   ├── bus_i2c.c           # Implementação real chamando drivers do ESP-IDF
│   │   ├── bus_spi.c
│   │   └── CMakeLists.txt      # Define este diretório como um componente do IDF
│   │
│   ├── sensor_mpu6050/         # Camada 2: Driver do Sensor Específico
│   │   ├── include/
│   │   │   └── mpu6050.h       # Estruturas de dados, registradores e protótipos
│   │   ├── mpu6050.c           # Lógica do sensor (cálculos, configuração)
│   │   └── CMakeLists.txt      # Requisita a dependência do componente "bus_hal"
│   │
│   └── sensor_bme280/          # Outro sensor isolado
│       ├── include/
│       │   └── bme280.h
│       ├── bme280.c
│       └── CMakeLists.txt
│
├── examples/                   # Códigos de teste para a equipe validar cada sensor
│   ├── test_mpu6050/
│   │   ├── main/main.c
│   │   └── platformio.ini      # Ambiente de compilação isolado para teste
│   └── test_bme280/
│
├── platformio.ini              # (Opcional) PIO root para compilar testes massivos
├── .gitignore
└── README.md


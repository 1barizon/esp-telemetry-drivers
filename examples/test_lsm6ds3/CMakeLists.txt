cmake_minimum_required(VERSION 3.16.0)

# Diz ao compilador para procurar componentes duas pastas acima
set(EXTRA_COMPONENT_DIRS "../../components")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(test_lsm6ds3)

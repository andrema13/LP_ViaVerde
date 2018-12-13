cmake_minimum_required(VERSION 3.12)
project(ViaVerde C)

set(CMAKE_C_STANDARD 99)

add_executable(ViaVerde Utils.c main.c Cliente.c Portico.c Veiculo.c Utilizador.c Viagem.c API_Leitura.c API_Utils.c Headers.h )
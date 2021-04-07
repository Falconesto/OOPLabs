cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp Transport.h Transport.cpp FlyingTransport.h FlyingTransport.cpp GroundTransport.h GroundTransport.cpp BactrianCamel.h BactrianCamel.cpp SpeedCamel.h SpeedCamel.cpp
        Centaur.h Centaur.cpp AllTerrainBoots.h AllTerrainBoots.cpp MagicCarpet.h MagicCarpet.cpp Mortar.h Mortar.cpp Broom.h Broom.cpp Race.h Race.cpp AirRace.cpp AirRace.h GroundRace.cpp GroundRace.h MixedRace.cpp MixedRace.h)
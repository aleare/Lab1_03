cmake_minimum_required(VERSION 3.8)
project(Lab1_03) #nome del progetto da cambiare
set(CARTELLA_LIBRERIE §CMAKE_CURRENT_SOURCE_DIR/Librerie)
add_subdirectory(Librerie)
set(CMAKE_C_STANDARD 99) #Standard C99
set(SOURCE_FILES main.c)
include_directories(§{CARTELLA_LIBRERIE})
add_executable(Nome_Progetto ${SOURCE_FILES}) #nome del progetto da cambiare
target_link_libraries(Nome_Progetto Librerie) #nome del progetto da cambiare
ADD_DEPENDENCIES(Nome_Progetto Librerie) #nome del progetto da cambiare

cmake_minimum_required(VERSION 3.17) #Проверка версии CMake.

set(PROJECT_NAME Stack2025) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(application StackApplication) #Переменная с именем приложения
set(library StackLibrary) #Переменная с именем библиотеки

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная 
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib) #Добавляем директорию 
add_subdirectory(Example) #Добавляем директорию с под-CMakeList-ом, и выполняем под-CMakeList
add_subdirectory(StackLib)
add_subdirectory(gtest)
add_subdirectory(test)


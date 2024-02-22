cmake_minimum_required(VERSION 3.26)
project(POCU_Study_Space)

set(CMAKE_CXX_STANDARD 14)

# 모든 .c와 .h 파일을 재귀적으로 찾습니다.
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_SOURCE_DIR}/*.h")

# build-debug 용 생성 폴더 내 cpp 및 헤더 제외하기 위한 리스트 생성
set(EXCLUDE_DIR "D:/c++_workspace/POCU_Study_Space/cmake-build-debug/")

# 제외할 폴더의 파일들을 목록에서 제거합니다.
foreach(ITEM ${PROJECT_SOURCES})
 string(FIND "${ITEM}" "${EXCLUDE_DIR}" POSITION)
 if(NOT ${POSITION} EQUAL -1)
  list(REMOVE_ITEM PROJECT_SOURCES "${ITEM}")
 endif()
endforeach()

foreach(ITEM ${PROJECT_HEADERS})
 string(FIND "${ITEM}" "${EXCLUDE_DIR}" POSITION)
 if(NOT ${POSITION} EQUAL -1)
  list(REMOVE_ITEM PROJECT_HEADERS "${ITEM}")
 endif()
endforeach()

# 찾은 소스 파일과 헤더 파일로 실행 파일을 생성합니다.
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

function(add_include_directories_recursively target start_dir exclude_dirs)
 # 시작 디렉토리에서 모든 하위 디렉토리를 찾습니다.
 file(GLOB_RECURSE all_files RELATIVE ${start_dir} ${start_dir}/*)
 set(dir_list "")
 foreach(file_path ${all_files})
  get_filename_component(dir_path ${file_path} PATH)
  set(dir_list ${dir_list} ${dir_path})
 endforeach()
 # 중복된 경로를 제거합니다.
 list(REMOVE_DUPLICATES dir_list)

 # 제외할 디렉토리를 필터링합니다.
 foreach(exclude_dir ${exclude_dir})
  foreach(dir ${dir_list})
   string(FIND ${dir} ${exclude_dir} found_pos)
   if(NOT ${found_pos} EQUAL -1)
    list(REMOVE_ITEM dir_list ${dir})
   endif()
  endforeach()
 endforeach()

 # 남은 디렉토리를 대상의 포함 경로에 추가합니다.
 foreach(dir ${dir_list})
  target_include_directories(${target} PRIVATE ${start_dir}/${dir})
 endforeach()
endfunction()

# 특정 폴더를 제외하고 모든 폴더를 포함 경로에 추가합니다.
add_include_directories_recursively(${PROJECT_NAME} ${CMAKE_SOURCE_DIR} "build")
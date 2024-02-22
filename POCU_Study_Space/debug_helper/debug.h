//
// Created by redmk on 2024-02-22.
//

#ifndef POCU_STUDY_SPACE_DEBUG_H
#define POCU_STUDY_SPACE_DEBUG_H
#include "stdio.h"
#include "errno.h"
#include "string.h"


#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)
        
#endif //POCU_STUDY_SPACE_DEBUG_H

#pragma once

#define CREATE_RESPONSE_TYPE 6
typedef struct CreateResponseStruct {
        char ** filenames;
        int * fileSizes;
        int numFiles;
} CreateResponseStruct;


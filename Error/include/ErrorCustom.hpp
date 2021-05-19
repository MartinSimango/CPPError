#pragma once


typedef struct CreateResponseStruct {
        char ** filenames;
        int * fileSizes;
        int numFiles;
} CreateResponseStruct;

#define CREATE_RESPONSE_TYPE 6

#pragma once

// ADD CUSTOM TYPES HERE
enum StructTypes {
        CREATE_RESPONSE_STRUCT_TYPE  
};

typedef struct CreateResponseStruct {
        char ** filenames;
        int * fileSizes;
        int numFiles;
} CreateResponseStruct;


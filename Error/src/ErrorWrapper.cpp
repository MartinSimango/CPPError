
#include <cpperror/ErrorWrapper.h>
#include <cpperror/Error.hpp>
#include <stdio.h>
#include <cpperror/ErrorCustom.h>

ErrorBase* AsError(void* err) { 
    return reinterpret_cast<ErrorBase*>(err); 
}

void DestroyError(void *err) {
    AsError(err)->~ErrorBase();
}

char * GetErrorMessage(void *err) {
    return AsError(err)->getErrorMessage();
}

int GetFuncReturnType(void *err){
    return AsError(err)->getFunctionReturnType();
}

int GetFuncReturnValue_Int(void *err){
    return *AsError(err)->getFunctionReturnValue<int>();
}

bool GetFuncReturnValue_Bool(void *err) {
    return *AsError(err)->getFunctionReturnValue<bool>();
}

char * GetFuncReturnValue_String(void *err) {
    return *AsError(err)->getFunctionReturnValue<char *>();
}

double GetFuncReturnValue_Double(void *err) {
    return *AsError(err)->getFunctionReturnValue<double>();
}

void* GetFuncReturnValue_Struct(void * err, enum StructTypes structTypeId) {
    switch (structTypeId)
    {
    case CREATE_RESPONSE_STRUCT_TYPE:
       return AsError(err)->getFunctionReturnValue<CreateResponseStruct>();
    }
    return (void *) (NULL);
}







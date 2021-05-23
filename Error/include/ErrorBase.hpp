#pragma once
#include <stdio.h>
#include <ErrorConstants.h>
#include <memory>

class ErrorBase {

    protected:
    char * errorMessage;
    std::shared_ptr<void> retVal;
    int funcReturnType;
 
    virtual void setFunctionReturnType() = 0;

    public:

    ErrorBase(){
        errorMessage = NULL;
        funcReturnType = UNKNOWN_TYPE;
    }

    virtual ~ErrorBase(){ }
    
    virtual char * getErrorMessage() const {
        return errorMessage;
    }
   
    template<typename RetVal> RetVal* getFunctionReturnValue(){
        return reinterpret_cast<RetVal *>(retVal.get());
    }

    virtual int getFunctionReturnType() {
        return funcReturnType;
    }

};

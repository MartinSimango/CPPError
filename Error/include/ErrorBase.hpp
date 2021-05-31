#pragma once
#include <stdio.h>
#include <cpperror/ErrorConstants.h>
#include <memory>
#include <iostream>

class ErrorBase { 

    protected:
    std::string *errorMessage;
    std::shared_ptr<void> retVal;
    int funcReturnType;
 
    virtual void setFunctionReturnType() {
        funcReturnType = UNKNOWN_TYPE;
    }

    public:

    ErrorBase(){
        setFunctionReturnType();
        errorMessage = NULL;

    }

    virtual ~ErrorBase(){ 
                std::cout << "ERROR BASE DES" <<std::endl;

        delete errorMessage;
        errorMessage =  NULL;
    }
    
    virtual std::string* getErrorMessage() const {
        return errorMessage;
    }
   
    template<typename RetVal> RetVal* getFunctionReturnValue(){
        return reinterpret_cast<RetVal *>(retVal.get());
    }

    virtual int getFunctionReturnType() {
        return funcReturnType;
    }

};

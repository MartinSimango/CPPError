#pragma once

#include <type_traits>
#include <string.h>
#include <iostream>
#include <cpperror/Delegate.hpp>
#include <cpperror/ErrorBase.hpp>
#include <cpperror/ErrorException.hpp>


namespace error {
    //TODO add support for const functions

    //Assumes clas Object method that is being called throws Exceptions dervied from the Exception class
    template<typename RetVal, typename Object, typename... Args>
    class Error: public Delegate<RetVal, Args...>, public ErrorBase {

        private:

            using MemberFunctionPtrType = typename MemberFunctionPtr<RetVal, Object, Args...>::Type; 
            using FunctionPtrType = typename FunctionPtr<RetVal, Args...>::Type;
            Object * object;
            MemberFunctionPtrType memberFunctionPtr;
            FunctionPtrType* functionPtr;
        
            void setFunctionReturnType() override {
                if (std::is_same<RetVal, int>::value) {
                    funcReturnType = INT_TYPE;
                }

                else if (std::is_same<RetVal, bool>::value) {
                    funcReturnType = BOOL_TYPE;
                }

                else if (std::is_same<RetVal, char *>::value || std::is_same<RetVal, const char *>::value || std::is_same<RetVal, std::string>::value) {
                    funcReturnType = STRING_TYPE;
                }

                else if (std::is_same<RetVal, double>::value) {
                    funcReturnType = DOUBLE_TYPE;
                }
                else {
                    funcReturnType = UNKNOWN_TYPE;
                }
            }


        public:

        explicit Error (MemberFunctionPtrType delegateFunc, Object * obj) : ErrorBase(), memberFunctionPtr(delegateFunc), object(obj) {
            setFunctionReturnType();
        }


        ~Error() { }
    

        virtual void Execute(Args... args) override
        {       
            std::shared_ptr<void> tempVal = retVal; //ensures that if exception is thrown retVal retains it's default value

            try {
                retVal = std::make_shared<RetVal>((object->*memberFunctionPtr)(std::forward<Args>(args)...));
            }
            catch(ErrorException * e){
                delete this->errorMessage;
                errorMessage = NULL;
                this->errorMessage = new std::string(e->getErrorMessage());
             
                delete e;
            }
            

        }

        
        RetVal getFunctionReturnValue(){ //overrides default implementation in ErrorBase
            // todo throw exception is null
            return *reinterpret_cast<RetVal*>(retVal.get());
        }
        

    };

}
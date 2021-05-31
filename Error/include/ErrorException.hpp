#pragma once
#include <iostream>
#include <exception>
#include <cpperror/ErrorConstants.h>


namespace error
{

    class ErrorException : public std::exception {
        
        public:
            ErrorException() : std::exception(){}
            
            virtual std::string getErrorMessage() = 0;
        
    };

}
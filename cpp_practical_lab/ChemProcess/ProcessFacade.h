//
// Created by Alexander Novinskiy on 31/10/2016.
//

#ifndef CHEMPROCESS_PROCESSFACADE_H
#define CHEMPROCESS_PROCESSFACADE_H

#include "ChProcess.h"

class ProcessFacade {
private:
    ChProcess *chProcess;
public:
    void setChProcess(ChProcess*);
    ChProcess* getChProcess(void);
    void releaseChProcess();
    virtual void runProcess()=0;
};

class ProcessFacadeDefault : public ProcessFacade{
public:
    ProcessFacadeDefault(int);
    void runProcess();
    void setDropsNumber(int);
    int getDropsNumber();
private:
    int dropsNumber;
};


#endif //CHEMPROCESS_PROCESSFACADE_H

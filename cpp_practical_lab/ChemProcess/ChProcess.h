class ChProcess{
public:
    virtual void run(void)=0;
};

class ChProcessInc : public ChProcess{
public:
    void run(void);
};
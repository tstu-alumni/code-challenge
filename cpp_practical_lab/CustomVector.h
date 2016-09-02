//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_CUSTOMVECTOR_H
#define PRACTICE_CUSTOMVECTOR_H

class CustomVector {
public:

    CustomVector(int);

    double& operator[](int);

    int size(void);

    ~CustomVector(void);
private:
    double* elem; // pointer to the elements
    int sz; // the number of elements
};


#endif //PRACTICE_CUSTOMVECTOR_H

//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_CUSTOMVECTOR_H
#define PRACTICE_CUSTOMVECTOR_H
/*
 * CustomVector class dedicated to replace the STL vector container can be (best) implemented via a two-directional
 * list of objects.
 * Operator [] will iterate through the list until it finds the demanded element.
 * Method .append(...) will link a new element with the end of th list.
 * To increase the speed of object retrieval an intermediate pointer to the middle of the vector can be used. I.e. the
 * following algorithm will do:
 *  if INDEX >= MAX/2 then
 *      startfrom(MIDDLE_POSITION)
 *  else
 *      startfrom(ZERO_POSITION)
 * Where startfrom is a routine iterating forward from the given record in a list.
 * Note:
 *  Obviously, vector elements can not be allocated subsequently due to dynamic nature of a vector container.
 *  Therefore, the bigger the size of a vector is, the greater the access time to a particular element will be.
 *  Intermediate indexes can be used to increase an access time. Dynamic allocation of nested vectors (this term needs
 *  explanation) can make the use of intermediate indexes vector size agnostic.
 */
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

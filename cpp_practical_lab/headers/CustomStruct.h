//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_CUSTOMSTRUCT_H
#define PRACTICE_CUSTOMSTRUCT_H

/*
 * This struct is made to check if structs can act like classes.
 */

/*
 * CustomStruct: attempts to replaces a class
 * Methods:
 *  CustomStruct(void): initializes CustomStruct structure by increasing a static field by 1 and assigning id field.
 *  int getId(void): returns id filed.
 */
typedef struct CustomStruct CustomStruct;
struct CustomStruct{
    CustomStruct(void);
    int getId(void);
    static int TotalAmount;
private:
    int id;
};

#endif //PRACTICE_CUSTOMSTRUCT_H

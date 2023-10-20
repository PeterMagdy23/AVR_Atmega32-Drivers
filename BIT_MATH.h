/*****************************************************************************/
/*                          Author: Peter Magdy                              */
/*                            Date: Oct 20, 2023                             */
/*                         version: 1.0v                                     */
/*                     Description: STD_TYPES lib                            */
/*****************************************************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(var,BitNumber)             var|=   1<<BitNumber
#define CLR_BIT(var,BitNumber)             var&=(~(1<<BitNumber))
#define TOGGL_BIT(var,BitNumber)           var^=   1<<BitNumber
#define GET_BIT(var,BitNumber)             var>>BitNumber&1
#define SET_BYTE(var,val)                  var = val
#define CONC_BYTE(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0 //set the byte by one function
// CONC_BYTE(OUTPUT,INPUT,INPUT,..,..,..,..,..)
#define MASK_BYTE(var,MASK_val)                  var &= MASK_val

#endif /* BIT_MATH_H_ */

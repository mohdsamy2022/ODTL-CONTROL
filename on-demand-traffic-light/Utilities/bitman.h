/*
 * bitman.h
 *
 * Created: 09/12/2022 04:39:51 م
 *  Author: DELL
 */ 


#ifndef BITMAN_H_
#define BITMAN_H_

#define CLEAR_BIT(REG,NUM) REG&=~(1<<NUM)
#define SET_BIT(REG,NUM) REG|=(1<<NUM)
#define TOGGLE_BIT(REG,NUM) REG^=(1<<NUM)
#define READ_BIT(REG,NUM) ((REG&(1<<NUM))>>NUM)



#endif /* BITMAN_H_ */
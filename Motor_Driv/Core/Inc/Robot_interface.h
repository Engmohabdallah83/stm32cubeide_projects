/*
 * Robot_interface.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Mohamed Aboelhassan
 */

#ifndef INC_ROBOT_INTERFACE_H_
#define INC_ROBOT_INTERFACE_H_

#include "Motor_Interface.h"


class Robot_Abstract
{
public:
	virtual void MoveFWD()=0;
	virtual void MoveBWD()=0;
	virtual void TurnLeft()=0;
	virtual void TurnRight()=0;
	virtual void Rob_Stop()= 0;

};

class RC_Robot : public Robot_Abstract
{
public:
	RC_Robot(Motor* LW_Cfg, Motor* RW_Cfg);

	void MoveFWD()  override;
	void MoveBWD()  override;
	void TurnLeft() override;
	void TurnRight()override;
	void Rob_Stop() override;


private:
	Motor* mL_Wheel;
	Motor* mR_Wheel;
};



#endif /* INC_ROBOT_INTERFACE_H_ */

#!/usr/bin/env python

import rospy

from std_msgs.msg import Float64
from std_msgs.msg import String

from golubev_anton_13345_2.srv import *

class Calculator:

    def __init__(self):
        # Make service
        s = rospy.Service('calculator', GetCalculate, self.calculate_value)

        rospy.spin()

    def calculate_value(self, req):
        res = 0
        error_status = False
        if req.operation == "+":
            res = req.a + req.b
        elif req.operation == "-":
            res = req.a - req.b
        elif req.operation == "*":
            res = req.a * req.b
        elif (req.operation == "/") and (req.b != 0):
            res = req.a / req.b
        else:
            rospy.loginfo("nonexistent operatin or division by zero")
            error_status = True
        return GetCalculateResponse(res, error_status)



if __name__ == '__main__':
    rospy.init_node('calculator_server')
    try:
        calculator = Calculator()
    except rospy.ROSInterruptException:
        pass

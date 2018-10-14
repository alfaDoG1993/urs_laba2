#!/usr/bin/env python

import sys
import rospy
from golubev_anton_13345_2.srv import *


class Calculator:

    def __init__(self, a, b, operation):

        self.a = a
        self.b = b
        self.operation = operation
        self.init_service()


    def init_service(self):
        rospy.wait_for_service('calculator')
        try:
           calculate = rospy.ServiceProxy('calculator', GetCalculate)
           result = calculate(self.a, self.b, self.operation)
           if result.error_status:
               rospy.loginfo("nonexistent operatin or division by zero")
           else:
               print("{} {} {} = {}".format(self.a,
                                            self.operation,
                                            self.b,
                                            result.result))
        except rospy.ServiceException:
           print ("Service call failed")


if __name__ == "__main__":

    if len(sys.argv) == 4:
        a         = int(sys.argv[1])
        operation = sys.argv[2]
        b         = int(sys.argv[3])
    else:
        print "pls, enter [a sign b]"
        sys.exit(1)

    rospy.init_node('calculator_cleint')
    try:
        calculator = Calculator(a, b, operation)
    except rospy.ROSInterruptException:
        pass

#!/usr/bin/env python

import rospy
from andrey_maslow_13345_2_lab2.srv import *
import random

def call_determinate():
    rospy.init_node('get_determinate_client')
    rospy.wait_for_service("get_determinate")

    add_two_ints = rospy.ServiceProxy("get_determinate", GetDeterminant)

    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        mat = [random.uniform(-10.0, 10.0) for _ in range(9)]
        det = add_two_ints(mat)
        rospy.loginfo("response :" + str(det.determinant))

        rate.sleep()

    return

if __name__ == "__main__":
    call_determinate()
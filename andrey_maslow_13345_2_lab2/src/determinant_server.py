#!/usr/bin/env python

import rospy
from andrey_maslow_13345_2_lab2.srv import *
import numpy as np
#from GetDeterminant.srv import *

def handle_add_two_ints(req):
    mat = req.matrix
    rospy.loginfo('get_determinate_server request ' + str(mat))
    mat = np.array([mat[:3], mat[3:6], mat[6:9]], dtype="float32")
    return GetDeterminantResponse(np.linalg.det(mat))

def add_two_ints_server():
    rospy.init_node('get_determinate_server')
    serv = rospy.Service('get_determinate', GetDeterminant, handle_add_two_ints)
    rospy.loginfo('get_determinate_server is ready')
    rospy.spin()

if __name__ == "__main__":
    add_two_ints_server()
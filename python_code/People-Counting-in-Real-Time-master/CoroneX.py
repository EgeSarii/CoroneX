import sys
import os
os.system ("sudo service motion start")
sys.argv.extend(['--prototxt', 'mobilenet_ssd/MobileNetSSD_deploy.prototxt', '--model', 'mobilenet_ssd/MobileNetSSD_deploy.caffemodel', '--input', 'videos/example_01.mp4'])

import Run


Run.run()
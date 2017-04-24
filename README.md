forked from: https://github.com/hrastnik/FaceSwap

to install on OSX

1. install openFrameworks (http://openframeworks.cc/)
2. download ofxDLib and add folder to openFrameworks/addons (https://github.com/roymacdonald/ofxDLib)
3. open openFrameworks/projectGenerator-osx/projectGenerator
4. add ofxDlib and ofxCv to project
5. generate project
6. delete src/ofApp.cpp and src/ofApp.h
7. add contents of this repo to src/
8. move haarcascade_frontalface_default.xml and shape_predictor_68_face_landmarks.dat to bin/data
9. move 1.bmp into bin/data/images
10. build project, press escape to toggle using still image
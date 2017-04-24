#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "FaceDetectorAndTracker.h"
#include "FaceSwapper.h"

using namespace std;

int main()
{
    cout << "OpenCV version : " << CV_VERSION << endl;
    
    try
    {
        //cv::setWindowProperty("window", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
        
        //cv::namedWindow("Name", CV_WINDOW_NORMAL);
        //cv::setWindowProperty("Name", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
        
        const size_t num_faces = 2;
        FaceDetectorAndTracker detector("data/haarcascade_frontalface_default.xml", 0, num_faces);
        FaceSwapper face_swapper("data/shape_predictor_68_face_landmarks.dat");
        
        double fps = 0;

        while (true)
        {
            auto time_start = cv::getTickCount();
            
            // Grab a frame
            cv::Mat frame;
            
            detector >> frame;
            
            auto cv_faces = detector.faces();
            if (cv_faces.size() == num_faces)
            {
                face_swapper.swapFaces(frame, cv_faces[0], cv_faces[1]);
            }
            
            auto time_end = cv::getTickCount();
            auto time_per_frame = (time_end - time_start) / cv::getTickFrequency();
            
            fps = (15 * fps + (1 / time_per_frame)) / 16;
            
            //printf("Total time: %3.5f | FPS: %3.2f\n", time_per_frame, fps);
            
            // Display it all on the screen
            cv::imshow("Face Swap", frame);
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}


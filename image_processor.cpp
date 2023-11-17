#include <opencv2/opencv.hpp>

int main() {
    // Open the default camera (usually 0 or -1)
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cout << "Error opening camera" << std::endl;
        return -1;
    }

    cv::Mat frame, grayFrame;

    cv::namedWindow("Original", cv::WINDOW_NORMAL);
    cv::namedWindow("Grayscale", cv::WINDOW_NORMAL);

    while (true) {
        // Capture frame-by-frame
        cap >> frame;

        if (frame.empty()) {
            std::cout << "End of video stream" << std::endl;
            break;
        }

        // Convert frame to grayscale
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // Display the original and grayscale frames
        cv::imshow("Original", frame);
        cv::imshow("Grayscale", grayFrame);

        // Break the loop if 'q' is pressed
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }

    // Release the camera and close windows
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
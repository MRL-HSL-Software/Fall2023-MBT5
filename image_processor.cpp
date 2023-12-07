#include <opencv2/opencv.hpp>

using namespace std;

class FrameProcessor {
private:
    cv::VideoCapture capture;

public:
    FrameProcessor(int cameraID) {
        capture.open(cameraID); 
        if (!capture.isOpened()) {
            cout << "Failed to open the camera" << endl;
            exit(EXIT_FAILURE);
        }
    }

    void capture_and_show(string original_fram_name, string gray_frame_name) {
        cv::Mat frame, grayscaleFrame;

        while (true) {
            capture >> frame;

            if (frame.empty()) {
                cout << "Captured frame is empty" << endl;
                break;
            }

            cv::imshow(original_fram_name, frame);
            cv::cvtColor(frame, grayscaleFrame, cv::COLOR_BGR2GRAY);
            cv::imshow(gray_frame_name, grayscaleFrame);

            if (cv::waitKey(1) == 'q') {
                break;
            }
        }

        capture.release();
        cv::destroyAllWindows();
    }
};

int main() {
    FrameProcessor processor(0);
    processor.capture_and_show("Hello", "World");
    return 0;
}

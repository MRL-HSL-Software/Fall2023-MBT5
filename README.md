# Fall2023-MBT5 : MRL Beginners Task 5
### Subject : Build OpenCV and Webcam Operations
Task Description: Build the Open Source Computer Vision (OpenCV) C++ library from its source code. Develop a program that accesses a webcam and captures video frames. Additionally, write code to display the webcam feed in both grayscale and RGB format.
### Task Submission :
* Clean Code
* How Computers See Images ?
* Getting Started with OpenCV
* Open Camera Device with OpenCV
* Showing in both RGB and Grayscale
* Object Oriented Programming (OOP)
* Must Know How to Check Video Devices in Linux
* Fork This Repository and Commit Your Codes on It
* :warning: <ins>**Do Not**</ins> Use this command :
    ```bash
    sudo apt install libopencv-dev
    ```
## Solution explanation
This task requires opencv library which is not a built-in lib. in order to install it, I clone its repository to my system. after completion of this process, I have all codes of opencv but its not reasonable for using as a external lib in any project.
The repository contains a CMakeLists.txt file which helps us to create the build instructions using `cmake` command. by using this command requried files for building the source code gets generated.
After generating them, `make` command can be used for building the binary result. this step may take some times depending on the system processor.
After all these steps, we are ready to use opencv in out projects. in this codes there is a class for handling this task. in object initiation, the camera gets open and when the capturing methods gets called, frames get capture and all of them converter to grayscale in order to display both original and grayscale version of the video simultaniously.
on order to check all video devices in linus, we can use this command
```bash
ls /dev/ | grep video
```
this command returns all video devices with their IDs

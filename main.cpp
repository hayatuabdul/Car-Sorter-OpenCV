//Hayatu Abdullahi - 10614230

//James Rogers Jan 2021 (c) Plymouth University
#include <iostream>

#include<opencv2/opencv.hpp>
#include<opencv2/opencv_modules.hpp>

using namespace std;
using namespace cv;

int main(){

    //Path of image folder
    string PathToFolder = "C:/AINT308Lib/Data/Task1 Images/";

    //Loop through the 30 car images
    for(int n=0; n<30; ++n){


        //Each image is named 0.png, 1.png, 2.png, etc. So generate the image file path based on n and the folder path
        string PathToImage = PathToFolder+to_string(n)+".png";

        //Load car image at the file paths location
        Mat Car=imread(PathToImage);

        //Your code goes here. The example code below shows you how to read the red, green, and blue colour values of the
        //pixel at position (0,0). Modify this section to check not just one pixel, but all of them in the 640x480 image
        //(using for-loops), and using the RGB values classifiy if a given pixel looks red, green, blue, or other. For
        //example, if the blue value is 30, green is 10, and red is 255, there is a lot more red in the pixel than the
        //other two colours so it will look red. Now count all the red, green, and blue pixels in your image, and classify
        //what colour the car is. for example if you count 30000 blue pixels, 100 green pixels, and 2000 red pixels, the
        //car is probably blue as the image contains a lot more blue than the other colours.

        //==============example code, feel free to delete=============

        double bluesum = 0;    //Counts blue color every pixel
        double greensum = 0;   //Counts green color every pixel
        double redsum = 0;     //Counts red color every pixel
        int x;
        int y;
        Vec3b PixelValue;
        Vec3b PixelValue1;


        // Loop that goes through each pixel
        for(y=0; y<Car.size().height; y++){
         for(x=0; x<Car.size().width; x++){
             //Pixel level code here
             // Get pixel values for a certain axis
             PixelValue = Car.at<Vec3b>(y,x);
             bluesum = bluesum + PixelValue[0];
             greensum = greensum + PixelValue[1];
             redsum = redsum + PixelValue[2];


         }
        }



              // Prints out which car is what color using the pixel colour sum
              if(bluesum > greensum && bluesum > redsum){
                   cout<<"\nThe car is Blue\n"<<endl;
              }

              if(greensum > bluesum && greensum > redsum){
                   cout<<"\nThe car is Green\n"<<endl;
              }

              if(redsum > greensum && redsum > bluesum){
                   cout<<"\nThe car is Red\n"<<endl;
              }

//           cout<<"\nThe blue value is " <<(int)bluesum<<endl;
//           cout<<"\nThe green value is "<<(int)greensum<<endl;
//           cout<<"\nThe red value is "  <<(int)redsum<<endl;

//           cout<<"\nBlue Counter is "  <<(int)Bluecounter<<endl;
//           cout<<"\nGreen Counter is " <<(int)Greencounter<<endl;
//           cout<<"\nRed Counter is "   <<(int)Redcounter<<endl;

        //============================================================

        //display the car image untill x is pressed
        while(waitKey(10)!='x'){
            imshow("Car", Car);
        }

    }


}























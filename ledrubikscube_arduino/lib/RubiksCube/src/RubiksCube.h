/*
    RubiksCube.h - Library for Led Rubik's Cube
    Created by Bram Langmans 18/02/2020
*/
#ifndef RubiksCube_h
#define RubiksCube_h

#include <Arduino.h>

class RubiksCube {
    public:
        RubiksCube();
        void printCube();
        void moveCube(int move);        
        void showLEDS();
    private: 
        int row1_r;
        int row1_g;
        int row1_b;
        int row2_r;
        int row2_g;
        int row2_b;
        int row3_r;
        int row3_g;
        int row3_b;

        int col3_g;   
        int col2_g;    
        int col1_g;   
        int col3_p;    
        int col2_p;    
        int col1_p;    
        int col3_r;     
        int col2_r;    
        int col1_r;    
        int col1_b;    
        int col2_b;   
        int col3_b;    
        int col1_c;    
        int col2_c;    
        int col3_c;    
        int col3_y;   
        int col1_y;   
        int col2_y;

        void turnPurpleLeftUp();
        void turnPurpleLeftDown();
        void turnPurpleRightUp();
        void turnPurpleRightDown();
        void turnPurpleAboveLeft();
        void turnPurpleAboveRight();
        void turnPurpleBelowLeft();
        void turnPurpleBelowRight();
        void turnPurpleClockwise();
        void turnPurpleCounterClockwise();
        void turnYellowClockWise();
        void turnYellowCounterClockwise();
        void showColumn(byte column, byte cel1, byte cel2, byte cel3);     
};

#endif
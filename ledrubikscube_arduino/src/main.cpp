/*
    main.cpp - Main program Led Rubik's Cube
    Created by Bram Langmans 18/02/2020
*/
#include <Arduino.h>
#include <RubiksCube.h>

int choice = 0; 
boolean on = true;
RubiksCube cube;

void setup() {
    Serial.begin(1000000);
}

void loop() {   
    if (Serial.available()) {         
        choice = Serial.read();
        if(choice == 108){
            cube.moveCube(0);
        }else if (choice == 76){
            cube.moveCube(1);
        }else if (choice == 82){
            cube.moveCube(2);
        }else if (choice == 114){
            cube.moveCube(3);
        }else if (choice == 68){
            cube.moveCube(4);
        }else if (choice == 100){
            cube.moveCube(5);
        }else if (choice == 117){
            cube.moveCube(6);
        }else if (choice == 85){
            cube.moveCube(7);
        }else if (choice == 70){
            cube.moveCube(8);
        }else if (choice == 102){
            cube.moveCube(9);
        }else if (choice == 66){
            cube.moveCube(10);
        }else if (choice == 98){
            cube.moveCube(11);
        }  
    }
}


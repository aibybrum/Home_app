/*
    RubiksCube.cpp - Library for Led Rubik's Cube
    Created by Bram Langmans 18/02/2020
*/
#include <Arduino.h>
#include <RubiksCube.h>

byte red[3][3] = {{B100, B100, B100}, {B100, B100, B100}, {B100, B100, B100}};
byte green[3][3] = {{B010, B010, B010}, {B010, B010, B010}, {B010, B010, B010}};
byte blue[3][3] = {{B001, B001, B001}, {B001, B001, B001}, {B001, B001, B001}};
byte yellow[3][3] = {{B110, B110, B110}, {B110, B110, B110}, {B110, B110, B110}};
byte purple[3][3] = {{B101, B101, B101}, {B101, B101, B101}, {B101, B101, B101}};
byte cyan[3][3] = {{B011, B011, B011}, {B011, B011, B011}, {B011, B011, B011}};

RubiksCube::RubiksCube(){
    this->row1_r = 11;
    this->row1_g = 12;
    this->row1_b = 13;
    this->row2_r = 9;
    this->row2_g = 10;
    this->row2_b = 8;
    this->row3_r = 7;
    this->row3_g = 6;
    this->row3_b = 5;

    this->col3_g = 20;   
    this->col2_g = 21;    
    this->col1_g = 22;   
    this->col3_p = 24;    
    this->col2_p = 26;    
    this->col1_p = 28;    
    this->col3_r = 30;     
    this->col2_r = 32;    
    this->col1_r = 34;    
    this->col1_b = 38;    
    this->col2_b = 40;   
    this->col3_b = 42;    
    this->col1_c = 44;    
    this->col2_c = 46;    
    this->col3_c = 48;    
    this->col3_y = 36;   
    this->col1_y = 50;   
    this->col2_y = 52;

    pinMode(this->row1_r, OUTPUT);
    pinMode(this->row1_g, OUTPUT);
    pinMode(this->row1_b, OUTPUT);
    pinMode(this->row2_r, OUTPUT);
    pinMode(this->row2_g, OUTPUT);
    pinMode(this->row2_b, OUTPUT);
    pinMode(this->row3_r, OUTPUT);
    pinMode(this->row3_g, OUTPUT);
    pinMode(this->row3_b, OUTPUT);

    pinMode(this->col3_g, OUTPUT);
    pinMode(this->col2_g, OUTPUT);
    pinMode(this->col1_g, OUTPUT);
    pinMode(this->col3_p, OUTPUT);
    pinMode(this->col2_p, OUTPUT);
    pinMode(this->col1_p, OUTPUT);
    pinMode(this->col3_r, OUTPUT);
    pinMode(this->col2_r, OUTPUT);
    pinMode(this->col1_r, OUTPUT);
    pinMode(this->col3_b, OUTPUT);
    pinMode(this->col2_b, OUTPUT);
    pinMode(this->col1_b, OUTPUT); 
    pinMode(this->col1_c, OUTPUT); 
    pinMode(this->col2_c, OUTPUT); 
    pinMode(this->col3_c, OUTPUT); 
    pinMode(this->col1_y, OUTPUT); 
    pinMode(this->col2_y, OUTPUT); 
    pinMode(this->col3_y, OUTPUT); 

    digitalWrite(this->row1_r, LOW);
    digitalWrite(this->row1_g, LOW);
    digitalWrite(this->row1_b, LOW);
    digitalWrite(this->row2_r, LOW);
    digitalWrite(this->row2_g, LOW);
    digitalWrite(this->row2_b, LOW);
    digitalWrite(this->row3_r, LOW);
    digitalWrite(this->row3_g, LOW);
    digitalWrite(this->row3_b, LOW);

    digitalWrite(this->col3_g, LOW);
    digitalWrite(this->col2_g, LOW);
    digitalWrite(this->col1_g, LOW);
    digitalWrite(this->col3_p, LOW);
    digitalWrite(this->col2_p, LOW);
    digitalWrite(this->col1_p, LOW);
    digitalWrite(this->col3_r, LOW);
    digitalWrite(this->col2_r, LOW);
    digitalWrite(this->col1_r, LOW);
    digitalWrite(this->col3_b, LOW);
    digitalWrite(this->col2_b, LOW);
    digitalWrite(this->col1_b, LOW); 
    digitalWrite(this->col1_c, LOW); 
    digitalWrite(this->col2_c, LOW); 
    digitalWrite(this->col3_c, LOW); 
    digitalWrite(this->col1_y, LOW); 
    digitalWrite(this->col2_y, LOW); 
    digitalWrite(this->col3_y, LOW); 
}

void RubiksCube::turnPurpleLeftUp() {
    byte temp[3] = {purple[0][0], purple[1][0], purple[2][0]};
    purple[0][0] = blue[0][0];
    purple[1][0] = blue[1][0];
    purple[2][0] = blue[2][0];
    blue[0][0] = yellow[2][2];
    blue[1][0] = yellow[1][2];
    blue[2][0] = yellow[0][2];
    yellow[2][2] = green[0][0];
    yellow[1][2] = green[1][0];
    yellow[0][2] = green[2][0];
    green[0][0] = temp[0];
    green[1][0] = temp[1];
    green[2][0] = temp[2];
    temp[0] = red[0][0];
    temp[1] = red[0][1];
    red[0][0] = red[0][2];
    red[0][1] = red[1][2];
    red[0][2] = red[2][2];
    red[1][2] = red[2][1];
    red[2][2] = red[2][0];
    red[2][1] = red[1][0];
    red[2][0] = temp[0];
    red[1][0] = temp[1];
}

void RubiksCube::turnPurpleLeftDown(){
    byte temp[3] = {purple[0][0], purple[1][0], purple[2][0]};
    purple[0][0] = green[0][0];
    purple[1][0] = green[1][0];
    purple[2][0] = green[2][0];
    green[0][0] = yellow[2][2];
    green[1][0] = yellow[1][2];
    green[2][0] = yellow[0][2];
    yellow[2][2] = blue[0][0];
    yellow[1][2] = blue[1][0];
    yellow[0][2] = blue[2][0];
    blue[0][0] = temp[0];
    blue[1][0] = temp[1];
    blue[2][0] = temp[2];
    temp[0] = red[0][0];
    temp[1] = red[0][1];
    red[0][1] = red[1][0];
    red[0][0] = red[2][0];
    red[1][0] = red[2][1];
    red[2][0] = red[2][2];
    red[2][1] = red[1][2];
    red[2][2] = red[0][2];
    red[1][2] = temp[1];
    red[0][2] = temp[0];
}

void RubiksCube::turnPurpleRightUp(){
    byte temp[3] = {purple[0][2], purple[1][2], purple[2][2]};
    purple[0][2] = blue[0][2];
    purple[1][2] = blue[1][2];
    purple[2][2] = blue[2][2];
    blue[0][2] = yellow[2][0];
    blue[1][2] = yellow[1][0];
    blue[2][2] = yellow[0][0];
    yellow[2][0] = green[0][2];
    yellow[1][0] = green[1][2];
    yellow[0][0] = green[2][2];
    green[0][2] = temp[0];
    green[1][2] = temp[1];
    green[2][2] = temp[2];
    temp[0] = cyan[0][0];
    temp[1] = cyan[0][1];
    cyan[0][1] = cyan[1][0];
    cyan[0][0] = cyan[2][0];
    cyan[1][0] = cyan[2][1];
    cyan[2][0] = cyan[2][2];
    cyan[2][1] = cyan[1][2];
    cyan[2][2] = cyan[0][2];
    cyan[1][2] = temp[1];
    cyan[0][2] = temp[0];
}

void RubiksCube::turnPurpleRightDown(){
    byte temp[3] = {purple[0][2], purple[1][2], purple[2][2]};
    purple[0][2] = green[0][2];
    purple[1][2] = green[1][2];
    purple[2][2] = green[2][2];
    green[0][2] = yellow[2][0];
    green[1][2] = yellow[1][0];
    green[2][2] = yellow[0][0];
    yellow[2][0] = blue[0][2];
    yellow[1][0] = blue[1][2];
    yellow[0][0] = blue[2][2];
    blue[0][2] = temp[0];
    blue[1][2] = temp[1];
    blue[2][2] = temp[2];
    temp[0] = cyan[0][0];
    temp[1] = cyan[0][1];
    cyan[0][0] = cyan[0][2];
    cyan[0][1] = cyan[1][2];
    cyan[0][2] = cyan[2][2];
    cyan[1][2] = cyan[2][1];
    cyan[2][2] = cyan[2][0];
    cyan[2][1] = cyan[1][0];
    cyan[2][0] = temp[0];
    cyan[1][0] = temp[1];
}

void RubiksCube::turnPurpleAboveLeft(){
    byte temp[3] = {purple[0][0], purple[0][1], purple[0][2]};
    purple[0][0] = cyan[0][0];
    purple[0][1] = cyan[0][1];
    purple[0][2] = cyan[0][2];
    cyan[0][0] = yellow[0][0];
    cyan[0][1] = yellow[0][1];
    cyan[0][2] = yellow[0][2];
    yellow[0][0] = red[0][0];
    yellow[0][1] = red[0][1];
    yellow[0][2] = red[0][2];
    red[0][0] = temp[0];
    red[0][1] = temp[1];
    red[0][2] = temp[2];
    temp[0] = green[0][0];
    temp[1] = green[0][1];
    green[0][1] = green[1][0];
    green[0][0] = green[2][0];
    green[1][0] = green[2][1];
    green[2][0] = green[2][2];
    green[2][1] = green[1][2];
    green[2][2] = green[0][2];
    green[1][2] = temp[1];
    green[0][2] = temp[0];
}

void RubiksCube::turnPurpleAboveRight(){
    byte temp[3] = {purple[0][0], purple[0][1], purple[0][2]};
    purple[0][0] = red[0][0];
    purple[0][1] = red[0][1];
    purple[0][2] = red[0][2];
    red[0][0] = yellow[0][0];
    red[0][1] = yellow[0][1];
    red[0][2] = yellow[0][2];
    yellow[0][0] = cyan[0][0];
    yellow[0][1] = cyan[0][1];
    yellow[0][2] = cyan[0][2];
    cyan[0][0] = temp[0];
    cyan[0][1] = temp[1];
    cyan[0][2] = temp[2];
    temp[0] = green[0][0];
    temp[1] = green[0][1];
    green[0][0] = green[0][2];
    green[0][1] = green[1][2];
    green[0][2] = green[2][2];
    green[1][2] = green[2][1];
    green[2][2] = green[2][0];
    green[2][1] = green[1][0];
    green[2][0] = temp[0];
    green[1][0] = temp[1];
}

void RubiksCube::turnPurpleBelowLeft(){
    byte temp[3] = {purple[2][0], purple[2][1], purple[2][2]};
    purple[2][0] = cyan[2][0];
    purple[2][1] = cyan[2][1];
    purple[2][2] = cyan[2][2];
    cyan[2][0] = yellow[2][0];
    cyan[2][1] = yellow[2][1];
    cyan[2][2] = yellow[2][2];
    yellow[2][0] = red[2][0];
    yellow[2][1] = red[2][1];
    yellow[2][2] = red[2][2];
    red[2][0] = temp[0];
    red[2][1] = temp[1];
    red[2][2] = temp[2];
    temp[0] = blue[0][0];
    temp[1] = blue[0][1];
    blue[0][0] = blue[0][2];
    blue[0][1] = blue[1][2];
    blue[0][2] = blue[2][2];
    blue[1][2] = blue[2][1];
    blue[2][2] = blue[2][0];
    blue[2][1] = blue[1][0];
    blue[2][0] = temp[0];
    blue[1][0] = temp[1];
}

void RubiksCube::turnPurpleBelowRight(){
    byte temp[3] = {purple[2][0], purple[2][1], purple[2][2]};
    purple[2][0] = red[2][0];
    purple[2][1] = red[2][1];
    purple[2][2] = red[2][2];
    red[2][0] = yellow[2][0];
    red[2][1] = yellow[2][1];
    red[2][2] = yellow[2][2];
    yellow[2][0] = cyan[2][0];
    yellow[2][1] = cyan[2][1];
    yellow[2][2] = cyan[2][2];
    cyan[2][0] = temp[0];
    cyan[2][1] = temp[1];
    cyan[2][2] = temp[2];
    temp[0] = blue[0][0];
    temp[1] = blue[0][1];
    blue[0][1] = blue[1][0];
    blue[0][0] = blue[2][0];
    blue[1][0] = blue[2][1];
    blue[2][0] = blue[2][2];
    blue[2][1] = blue[1][2];
    blue[2][2] = blue[0][2];
    blue[1][2] = temp[1];
    blue[0][2] = temp[0];
}

void RubiksCube::turnPurpleClockwise(){
    byte temp[3] = {green[2][0], green[2][1], green[2][2]};
    green[2][0] = red[2][2];
    green[2][1] = red[1][2];
    green[2][2] = red[0][2];
    red[0][2] = blue[0][0];
    red[1][2] = blue[0][1];
    red[2][2] = blue[0][2];
    blue[0][0] = cyan[2][0];
    blue[0][1] = cyan[1][0];
    blue[0][2] = cyan[0][0];
    cyan[0][0] = temp[0];
    cyan[1][0] = temp[1];
    cyan[2][0] = temp[2];
    temp[0] = purple[0][0];
    temp[1] = purple[0][1];
    purple[0][1] = purple[1][0];
    purple[0][0] = purple[2][0];
    purple[1][0] = purple[2][1];
    purple[2][0] = purple[2][2];
    purple[2][1] = purple[1][2];
    purple[2][2] = purple[0][2];
    purple[1][2] = temp[1];
    purple[0][2] = temp[0];
}

void RubiksCube::turnPurpleCounterClockwise(){
    byte temp[3] = {green[2][0], green[2][1], green[2][2]};
    green[2][0] = cyan[0][0];
    green[2][1] = cyan[1][0];
    green[2][2] = cyan[2][0];
    cyan[0][0] = blue[0][2];
    cyan[1][0] = blue[0][1];
    cyan[2][0] = blue[0][0];
    blue[0][0] = red[0][2];
    blue[0][1] = red[1][2];
    blue[0][2] = red[2][2];
    red[2][2] = temp[0];
    red[1][2] = temp[1];
    red[0][2] = temp[2];
    temp[0] = purple[0][0];
    temp[1] = purple[0][1];
    purple[0][0] = purple[0][2];
    purple[0][1] = purple[1][2];
    purple[0][2] = purple[2][2];
    purple[1][2] = purple[2][1];
    purple[2][2] = purple[2][0];
    purple[2][1] = purple[1][0];
    purple[2][0] = temp[0];
    purple[1][0] = temp[1];
}

void RubiksCube::turnYellowClockWise(){
    byte temp[3] = {green[0][0], green[0][1], green[0][2]};
    green[0][0] = cyan[0][2];
    green[0][1] = cyan[1][2];
    green[0][2] = cyan[2][2];
    cyan[0][2] = blue[2][2];
    cyan[1][2] = blue[2][1];
    cyan[2][2] = blue[2][0];
    blue[2][0] = red[0][0];
    blue[2][1] = red[1][0];
    blue[2][2] = red[2][0];
    red[2][0] = temp[0];
    red[1][0] = temp[1];
    red[0][0] = temp[2];
    temp[0] = yellow[0][0];
    temp[1] = yellow[0][1];
    yellow[0][0] = yellow[0][2];
    yellow[0][1] = yellow[1][2];
    yellow[0][2] = yellow[2][2];
    yellow[1][2] = yellow[2][1];
    yellow[2][2] = yellow[2][0];
    yellow[2][1] = yellow[1][0];
    yellow[2][0] = temp[0];
    yellow[1][0] = temp[1];
}

void RubiksCube::turnYellowCounterClockwise(){
    byte temp[3] = {green[0][0], green[0][1], green[0][2]};
    green[0][0] = red[2][0];
    green[0][1] = red[1][0];
    green[0][2] = red[0][0]; 
    red[0][0] = blue[2][0];
    red[1][0] = blue[2][1];
    red[2][0] = blue[2][2];
    blue[2][0] = cyan[2][2];
    blue[2][1] = cyan[1][2];
    blue[2][2] = cyan[0][2];
    cyan[0][2] = temp[0];
    cyan[1][2] = temp[1];
    cyan[2][2] = temp[2];
    temp[0] = yellow[0][0];
    temp[1] = yellow[0][1];
    yellow[0][1] = yellow[1][0];
    yellow[0][0] = yellow[2][0];
    yellow[1][0] = yellow[2][1];
    yellow[2][0] = yellow[2][2];
    yellow[2][1] = yellow[1][2];
    yellow[2][2] = yellow[0][2];
    yellow[1][2] = temp[1];
    yellow[0][2] = temp[0];
}

void RubiksCube::showColumn(byte column, byte cel1, byte cel2, byte cel3) { 
    digitalWrite(row1_r, cel3 >> 2&1); 
    digitalWrite(row1_g, cel3 >> 1&1);
    digitalWrite(row1_b, cel3 & 1);
    digitalWrite(row2_r, cel2 >> 2&1); 
    digitalWrite(row2_g, cel2 >> 1&1);
    digitalWrite(row2_b, cel2 & 1);
    digitalWrite(row3_r, cel1 >> 2&1); 
    digitalWrite(row3_g, cel1 >> 1&1);
    digitalWrite(row3_b, cel1 & 1);
    digitalWrite(column, HIGH);
    delay(1);
    digitalWrite(column, LOW);
}

void RubiksCube::showLEDS(){
    RubiksCube::showColumn(this->col1_g, green[2][0], green[2][1], green[2][2]);
    RubiksCube::showColumn(this->col2_g, green[1][0], green[1][1], green[1][2]);
    RubiksCube::showColumn(this->col3_g, green[0][0], green[0][1], green[0][2]);
    RubiksCube::showColumn(this->col1_p, purple[0][0], purple[1][0], purple[2][0]);
    RubiksCube::showColumn(this->col2_p, purple[0][1], purple[1][1], purple[2][1]);
    RubiksCube::showColumn(this->col3_p, purple[0][2], purple[1][2], purple[2][2]);
    RubiksCube::showColumn(this->col1_r, red[0][0], red[1][0], red[2][0]);
    RubiksCube::showColumn(this->col2_r, red[0][1], red[1][1], red[2][1]);
    RubiksCube::showColumn(this->col3_r, red[0][2], red[1][2], red[2][2]);
    RubiksCube::showColumn(this->col1_y, yellow[0][0], yellow[1][0], yellow[2][0]);
    RubiksCube::showColumn(this->col2_y, yellow[0][1], yellow[1][1], yellow[2][1]);
    RubiksCube::showColumn(this->col3_y, yellow[0][2], yellow[1][2], yellow[2][2]);
    RubiksCube::showColumn(this->col1_b, blue[2][0], blue[2][1], blue[2][2]);
    RubiksCube::showColumn(this->col2_b, blue[1][0], blue[1][1], blue[1][2]);
    RubiksCube::showColumn(this->col3_b, blue[0][0], blue[0][1], blue[0][2]);
    RubiksCube::showColumn(this->col1_c, cyan[0][0], cyan[1][0], cyan[2][0]);
    RubiksCube::showColumn(this->col2_c, cyan[0][1], cyan[1][1], cyan[2][1]);
    RubiksCube::showColumn(this->col3_c, cyan[0][2], cyan[1][2], cyan[2][2]);
}

void RubiksCube::moveCube(int move){
    switch (move)
    {
        case 0:
            RubiksCube::turnPurpleLeftUp();
            RubiksCube::printCube();
            break;
        case 1:
            RubiksCube::turnPurpleLeftDown();
            RubiksCube::printCube();
            break;    
        case 2:
            RubiksCube::turnPurpleRightUp();
            RubiksCube::printCube();
            break;
        case 3:
            RubiksCube::turnPurpleRightDown();
            RubiksCube::printCube();
            break;
        case 4:
            RubiksCube::turnPurpleBelowRight();
            RubiksCube::printCube();
            break;
        case 5:
            RubiksCube::turnPurpleBelowLeft();
            RubiksCube::printCube();
            break;
        case 6:
            RubiksCube::turnPurpleAboveRight();
            RubiksCube::printCube();
            break;
        case 7:
            RubiksCube::turnPurpleAboveLeft();
            RubiksCube::printCube();
            break;
        case 8:
            RubiksCube::turnPurpleClockwise();
            RubiksCube::printCube();
            break;
        case 9:
            RubiksCube::turnPurpleCounterClockwise();
            RubiksCube::printCube();
            break;
        case 10:
            RubiksCube::turnYellowClockWise();
            RubiksCube::printCube();
            break;
        case 11:
            RubiksCube::turnYellowCounterClockwise(); 
            RubiksCube::printCube();
            break;
    } 
}

void RubiksCube::printCube() {
    for (int i = 0; i < 3; i++) {
        Serial.print("      ");
        for (int j = 0; j < 3; j++) {
            Serial.print(green[i][j], DEC);
            Serial.print(" ");
        }
        Serial.println();
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Serial.print(red[i][j], DEC); Serial.print(" ");
        }
        for (int j = 0; j < 3; j++) {
            Serial.print(purple[i][j], DEC); Serial.print(" ");
        }
        for (int j = 0; j < 3; j++) {
            Serial.print(cyan[i][j], DEC); Serial.print(" ");
        }
        for (int j = 0; j < 3; j++) {
            Serial.print(yellow[i][j], DEC); Serial.print(" ");
        }
        Serial.println();
    }
    for (int i = 0; i < 3; i++) {
        Serial.print("      ");
        for (int j = 0; j < 3; j++) {
            Serial.print(blue[i][j], DEC); Serial.print(" ");
        }
        Serial.println();
    }
    Serial.println();
}
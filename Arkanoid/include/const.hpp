#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#pragma once

const float PI = 3.14159265359f;
const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 50; // размер сетки (GRID_SIZExGRID_SIZE квадратов)

const float SPEEDPLATFORM = 0.05f;

const float SPEEDBONUS = 0.01f;
const float BONUSRADIUS = 0.01f;

const float BALLRADIUS = 0.017f;
const float MINSPEEDBALL = 0.01f;
const float MAXSPEEDBALL = 0.015f;
const int NUMSLEEPSPEED = 600;

// Цвета квадратов
const float COLORS[4][3]= {
    {0.0f, 0.0f, 0.0f}, // черный
    {1.0f, 0.0f, 0.0f}, // красный
    {0.0f, 1.0f, 0.0f}, // зеленый
    {0.0f, 0.0f, 1.0f}, // синий
    // {1.0f, 1.0f, 0.0f}, // желтый
    // {1.0f, 0.0f, 1.0f}, // фиолетовый
    // {0.0f, 1.0f, 1.0f},  // голубой
    // {0.5f, 0.5f, 0.5f}, // серый
    // {0.75f, 0.25f, 0.0f}, // оранжевый
    // {0.0f, 0.5f, 0.5f}, // бирюзовый
    // {0.5f, 0.0f, 0.5f}, // пурпурный
    // {0.25f, 0.75f, 0.0f}, // салатовый
    // {0.75f, 0.75f, 0.75f}, // светло-серый
    // {0.25f, 0.25f, 0.25f}, // темно-серый
    // {0.9f, 0.9f, 0.9f}, // почти белый
    // {0.6f, 0.2f, 0.8f}, // малиновый
    // {0.4f, 0.6f, 0.2f}, // оливковый
};
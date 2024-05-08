#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>
#pragma once
const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 50; // размер сетки (GRID_SIZExGRID_SIZE квадратов)
const float SQUARE_SIZE = WIDTH / GRID_SIZE; // размер каждого квадрата

// Цвета квадратов
const std::vector<std::vector<float>> COLORS = {
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

/** \file       main.cpp
 * \brief       His file contains a small shaped-drawing program
 * \author      Minh Nguyen Truong Quang
 * \date        08/03/2024
 * \copyright   UNIC
 * <BR>
 */
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawHorizontalLine(int length, char ch);
void drawVerticalLine(int height, char ch);
void drawSquare(int size, char ch);
void drawRectangle(int height, int length, char ch);
void drawShape(int numShapes);

const int MAX_SHAPES = 10;
/**
* <code>main</code> is the main function of this program.
* <BR>
* @return Returns 0 if success, any other value otherwise.
*/
int main() {
    int choice = 0;
    int length, row, numShape = 0;
    char ch;
    do {
        cout << "Enter your Option:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter your length of the line:" << endl;
                cin >> length;
                cout << "Enter your character:" << endl;
                cin >> ch;
                drawHorizontalLine(length, ch);
                break;
            case 2:
                cout << "Enter your length of the line:" << endl;
                cin >> length;
                cout << "Enter your character:" << endl;
                cin >> ch;
                drawVerticalLine(length, ch);
                break;
            case 3:
                cout << "Enter your length of the square:" << endl;
                cin >> length;
                cout << "Enter your character:" << endl;
                cin >> ch;
                drawSquare(length, ch);
                break;
            case 4:
                cout << "Enter your height of the rectangle:" << endl;
                cin >> row;
                cout << "Enter your length of the rectangle:" << endl;
                cin >> length;
                cout << "Enter your character:" << endl;
                cin >> ch;
                drawRectangle(row, length, ch);
                break;
            case 6:
                cout << "Enter the number of shapes you want (From 1 to 10 shapes):" << endl;
                cin >> numShape;
                drawShape(numShape);
                break;
            default:
                break;
        }
    } while (choice != 5);

    return 0;
}
/**
 * Draw a horizontal line
 * <BR>
 * @param length The length if the line to be drawn
 * @param ch The symbol to be used to draw line
 */
void drawHorizontalLine(const int length, const char ch) {
    assert(length > 0);
    assert(ch >= '!' && ch <= '~');
    int i;
    for (i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
    assert(i == length);
}
/**
 * Draw a vertical line
 * <BR>
 * @param height The length if the line to be drawn
 * @param ch The symbol to be used to draw line
 */
void drawVerticalLine(const int height, const char ch) {
    assert(height > 0);
    assert(ch >= '!' && ch <= '~');
    int i;
    for (i = 0; i < height; ++i) {
        cout << ch << endl;
    }
    assert(i == height);
}
/**
 * Draw a square
 * <BR>
 * @param size the length of the square to be drawn
 * @param ch The symbol to be used to draw lines
 */
void drawSquare(const int size, const char ch) {
    assert(size > 0);
    assert(ch >= '!' && ch <= '~');
    int i;
    int j;
    for (i = 0; i < size; ++i) {
        cout << ch << " ";
    }
    cout << endl;
    for (i = 0; i < (size - 2); ++i) {
        cout << ch;
        for (j = 0; j < (size - 2); ++j) {
            cout << "  ";
        }
        cout << " " << ch;
        cout << endl;
    }
    for (i = 0; i < size; ++i) {
        cout << ch << " ";
    }
    cout << endl;
    assert(i == size);
    assert(j == (size - 2));
}
/**
 * Draw a rectangle with symbols
 * <BR>
 * @param height the length if the rectangle to be drawn
 * @param length the length if the rectangle to be drawn
 * These are interchangeable
 * @param ch The symbol to be used to draw lines
 */
void drawRectangle(const int height, const int length, const char ch) {
    assert(height > 0);
    assert(length > 0);
    assert(ch >= '!' && ch <= '~');
    int i;
    int j;
    for (i = 0; i < length; ++i) {
        cout << ch << " ";
    }
    cout << endl;
    for (i = 0; i < (height - 2); ++i) {
        cout << ch;
        for (j = 0; j < (length - 2); ++j){
            cout << "  ";
        }
        cout << " " << ch;
        cout << endl;
    }
    for (i = 0; i < length; ++i) {
        cout << ch << " ";
    }
    cout << endl;
    assert(i == length);
    assert(j == (length - 2));
}
/**
 * Draw a number of shapes (From 1 to 10 shapes)
 * Where we randomize
 * the type of shapes (4 types)
 * The length of the shapes (there also will be height of the shape for rectangle)
 * The character used to draw the shapes (printable ASCII)
 * <BR>
 * @param numShapes the length if the line to be draw
 */
void drawShape(const int numShapes) {
    if (numShapes <= MAX_SHAPES) {
        srand (time(NULL));

        int shapeTypes = rand() % 4 + 1;
        int shapeHeight;
        int shapeLength = rand() % 16 + 5;

        int shapeCharInt = rand() % 94 + 33;
        char shapeChar = char(shapeCharInt);

        for (int i = 0; i < numShapes; i++) {
            switch (shapeTypes) {
                case 1:
                    drawHorizontalLine(shapeLength, shapeChar);
                    cout << endl;
                    break;
                case 2:
                    drawVerticalLine(shapeLength, shapeChar);
                    cout << endl;
                    break;
                case 3:
                    drawSquare(shapeLength, shapeChar);
                    cout << endl;
                    break;
                case 4:
                    shapeHeight = rand() % 15 + 5;
                    drawRectangle(shapeHeight, shapeLength, shapeChar);
                    break;
                default:
                    break;
            }
        }
    }
    else {
        cout << "The number of shapes allowed is less than 11" << endl;
    }
}

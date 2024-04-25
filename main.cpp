#include <iostream>
#include <math.h>
#include "stack.h"
#include "pawns.h"
#include "queries.h"
#include "input.h"
#include <fstream>
//#include <regex>
#include <chrono>
#include <iomanip>
using namespace std;


int main() {

    // create a stack to store the board hexes and their coords
    auto* hexes = new stack();

    // create a stack to store the board symbols
    // needed to detect when the board is being parsed in its middle
    auto* middle_board_symbols = new stack();

    // create and initiate a flag that will tell the program when to toggle
    // the direction of movement for found hexes in the board
    bool middle_found_flag = false;

    // create and initiate variables that will store a hex's position coords
    int position_x = 0;
    int position_y = 0;
    int last_position_y = 0; // this one is needed to get the left-most symbol on a new level

    // create and initiate a variable that will help the program know when to "reset" the coords
    // i.e. when the last hex in the row is parsed, the program needs to "jump" all the way to the left
    // and one level lower
    int hexes_in_line = 1;

    // create and initiate a level counter (or so-called board height)
    int level = 0;

    // create and initiate a variable that will count until the final element of the level is reached
    int hexes_in_line_counter = 0;

    // create and initiate a flag that will tell the program whether to add a '.' to the stack, or a pawn
    bool pawn_detected = false;

    // create and initialize a variable that will store the size of the board
    // warning: it stores the number of hexes, i.e. size squared - to get the normal size, use sqrt()
    int number_of_hexes = 0;

    // create and initialize a variable that will store the number of pawns of the red player
    int red_pawns_counter = 0;

    // create and initialize a variable that will store the number of pawns of the blue player
    int blue_pawns_counter = 0;

    // create and initiate a variable that will store the number of empty hexes
    int empty_hexes_counter = 0;

    // create and initiate a variable that will store the last successful comparison's function id
    // for the program to know where to keep looking for similarities between the input query and the reserved ones
    int query_id = 0;

    // create and initiate a variable that will store the last successful comparison's symbol id
    // for the program to know where to keep looking for similarities between the input query and the reserved ones
    int symbol_id = 0;

    // create and initiate a flag that will tell the program whether to reset all of the above variables for the next board or not yet
    bool finished_board_parsing = false;

    /* ---------------------------------------------------------------------------------------------------------- */

    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    launch_parser(hexes, middle_board_symbols, &number_of_hexes, &red_pawns_counter, &blue_pawns_counter, &empty_hexes_counter, &query_id, &symbol_id, &hexes_in_line_counter, &hexes_in_line, &level, &position_x, &position_y, &last_position_y, &finished_board_parsing, &pawn_detected, &middle_found_flag);

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;

//    std::ifstream inFile("goluch.txt");
//    std::ofstream outFile("temp.txt"); // Temporary file to store modified content
//
//    std::string line;
//    int counter = 0;
//
//    while (std::getline(inFile, line)) {
//        if (counter != 2) { // Keep the line if it's not the second line
//            outFile << line << std::endl;
//            //std::getline(inFile, line);
//            //outFile << line << std::endl;
//        }
//        if (counter == 2) { // Reset counter after every two lines
//            counter = 0;
//        }
//        ++counter;
//    }
//
//    inFile.close();
//    outFile.close();
//
//    // Remove the original file
//    std::remove("goluch.txt");
//
//    // Rename the temporary file to the original file name
//    std::rename("temp.txt", "goluch.txt");

//    int line_number = 1570; // Specify the line number here
//    std::fstream file("input.txt"); // Specify the input file name here
//
//    std::string line;
//    int current_line_number = 1;
//
//    while (std::getline(file, line)) {
//
//        std::regex pattern("[^A-Z0-9_]");
//
//        if (!std::regex_search(line, pattern)) {
//            current_line_number++;
//        }
//
//        if (current_line_number == line_number) {
//            file << "HERE\n";
//            break;
//        }
//
//    }
//
//    file.close();

    // free memory
    hexes->clear();
    delete hexes;
    middle_board_symbols->clear();
    delete middle_board_symbols;

    return 0;

}

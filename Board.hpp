#pragma once

#include <string>
#include "Direction.hpp"

namespace ariel {
    class Board {
        char **chars;
        //Save all used corners of the board
        u_int top;
        u_int left;
        u_int bot;
        u_int right;

    private:
        void first_board_size(u_int, u_int, Direction, u_int);
        void first_msg(Direction, std::string);
        bool update_board_size(u_int, u_int, Direction, u_int);
        void update_board(u_int old_top, u_int old_bot, u_int old_left, u_int old_right);
        void post_message(u_int, u_int, Direction, std::string);
    public:
        Board() 
        {
            this->chars = NULL;
            this->top = 0;
            this->left = 0;
            this->bot = 0;
            this->right = 0;
        }
        ~Board()
        {
            if(chars)
            {
                u_int cols = right - left + 1;
                u_int rows = bot - top + 1;
                for(u_int i = 0; i < rows; i++)
                {
                    delete[] chars[i];
                }
                delete[] chars;
            }
        }
        void post(u_int row, u_int column, Direction direction, std::string message);
        std::string read(u_int row, u_int column, Direction direction, u_int length);
        void show();
    };
}
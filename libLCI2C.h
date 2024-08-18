#pragma once

#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "builtins.h"

using byte = unsigned char;
using uint = unsigned int;

class LCD{

    public:
        LCD(const byte address, const byte cols, const byte rows);
        ~LCD() = default;

        void init(void);
        void clear(void);
        void reset(void);

        void create_char(byte location, byte* char_map);
        void set_position_cursor(byte col, byte row);
        void print(const char* str);

        void set_display(bool flag);
        void set_backlight(bool flag); 
        void set_blink(bool flag);

        bool get_display(void);
        bool get_backlight(void);
        bool get_blink(void);

        inline void send_command(byte);
        inline void write(byte);


    private:
        inline void __send(byte, byte);
        inline void __write_4bits(byte);
        inline void __write(byte);
        inline void __pulse(byte);

        const byte __address;
        const byte __rows;
        const byte __cols;

        byte __display_function;
        byte __display_control;
        byte __display_mode;
        byte __backlight_value;
};
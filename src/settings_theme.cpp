/* CommanderLineSSL

The MIT License

Copyright (c) 2025 Tar95DV.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <ncurses.h>
#include "./../include/settings_theme.h"

void set_settings_theme(int num_theme){
	 if(!can_change_color()){ /* If the terminal does not support the theme, the default colors will be set. */
		num_theme = 0;
		} 
	switch(num_theme) {
		 case 0:{
				break;
			} 
		case 1: {
				init_pair(1,COLOR_YELLOW,COLOR_BLACK);
				//attrset(COLOR_PAIR(1));
				bkgd(COLOR_PAIR(1));
				break;
			}
		case 2:{
			
				init_pair(1,COLOR_GREEN,COLOR_BLACK);
				//attrset(COLOR_PAIR(1));
				bkgd(COLOR_PAIR(1));				
				break;
			}
		}

	}


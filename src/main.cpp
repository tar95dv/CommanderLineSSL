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

#include <iostream>
#include <ncurses.h>
#include <string>
#include "./../include/global.h"  //Define global keys, variables

int main(){
	
initNcurses();

printw("CommanderLineSSL \n");


kryptographie processNumOne;

processNumOne.openssl_rand_hex16();
processNumOne.openssl_rand_hex32();
processNumOne.openssl_encrypt_aes256_cbc();
processNumOne.openssl_decrypt_aes256_cbc();


printw("Enter any key for exit");
getch();
endwin();
return 0;
}

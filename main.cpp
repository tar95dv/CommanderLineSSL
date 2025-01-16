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

#include "global.h"  //Define global keys, variables


#include <iostream>

#include <menu.h>
#include <panel.h>
#include <form.h>

#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

#include <fmt/core.h>



void openssl_rand_hex16();
void openssl_rand_hex32();

void openssl_encrypt_aes256_cbc();
void openssl_decrypt_aes256_cbc();


int main(){
initscr();
keypad(stdscr, true); // enable func keys as F1,F2,...F12



printw("CLI for encrypt/decrypt files \n");

openssl_rand_hex16();
openssl_rand_hex32();
openssl_encrypt_aes256_cbc();
openssl_decrypt_aes256_cbc();

printw("Enter any key for exit");
getch();
endwin();
return 0;
}


void openssl_rand_hex16(){
printw("\n");
printw("Rand hex16: ");
std::system("openssl rand -hex 16 > tempHEX16.textOUT");
FILE *fd = fopen("tempHEX16.textOUT","r");
if (fd == NULL){
	printw("Can't open file\n");
}
else	{


	char *tempHEX16;
	tempHEX16 = new char[17];
	fgets(tempHEX16,17,fd);
	printw(tempHEX16,"\n");
	delete[] tempHEX16;
	fclose(fd);
	}
}

void openssl_rand_hex32(){
	printw("\n");
	printw("Rand hex32: ");
	std::system("openssl rand -hex 32 > tempHEX32.textOUT");
	FILE *fd = fopen("tempHEX32.textOUT","r");
		if (fd == NULL){
		printw("Can't open file\n");
		}
		else	{


	char *tempHEX32;
	tempHEX32 =new char[33];
	fgets(tempHEX32,33,fd);
	printw(tempHEX32,"\n");
	delete[] tempHEX32;
	fclose(fd);
	}
}
void openssl_encrypt_aes256_cbc(){
	printw("\n");

	char *tempHEX16;
	tempHEX16 =new char[17];
	FILE *fd = fopen("tempHEX16.textOUT","r");
	fscanf(fd,"%16s",tempHEX16);
	printw("\n");	
	printw(tempHEX16);
	fclose(fd);
	
	char *tempHEX32;
	tempHEX32 =new char[33];
	FILE *fd2 = fopen("tempHEX32.textOUT","r");
	fscanf(fd2,"%32s",tempHEX32);
	printw("\n");	
	printw(tempHEX32,"\n");
	fclose(fd2);
		
	printw("\nEnter the file name of the file to encrypt: ");
	char NameFileForEncrypt[32];
	scanw("%s",NameFileForEncrypt);
	printw("\nEnter the file name of the file to encrypted: ");	
	char NameFileEncrypted[32];
	scanw("%s",NameFileEncrypted);
		
	auto cmd = fmt::format("openssl enc -aes-256-cbc -K {} -iv {} -in {} -out {}\n",tempHEX32,tempHEX16,NameFileForEncrypt,NameFileEncrypted);
	
	//FILE *popen
	 
	std::system(cmd.c_str());
	printw("\nOperation successfull\n");

	delete[] tempHEX16;
	delete[] tempHEX32;
	

	}
void openssl_decrypt_aes256_cbc(){
	printw("\n");

	char *tempHEX16;
	tempHEX16 =new char[17];
	FILE *fd = fopen("tempHEX16.textOUT","r");
	fscanf(fd,"%16s",tempHEX16);
	printw("\n");	
	printw(tempHEX16);
	fclose(fd);
	
	char *tempHEX32;
	tempHEX32 =new char[33];
	FILE *fd2 = fopen("tempHEX32.textOUT","r");
	fscanf(fd2,"%32s",tempHEX32);
	printw("\n");	
	printw(tempHEX32);
	fclose(fd2);
		
	printw("Enter the file name of the file to decrypt: ");
	char NameFileForDecrypt[32];
	scanw("%s",NameFileForDecrypt);
	printw("Enter the file name of the file to decrypted: ");
	char NameFileDecrypted[32];
	scanw("%s",NameFileDecrypted);
	auto cmd = fmt::format("openssl enc -aes-256-cbc -K {} -iv {} -d -in {} -out {}",tempHEX32,tempHEX16,NameFileForDecrypt,NameFileDecrypted); 
	std::system(cmd.c_str());

	delete tempHEX16;
	delete tempHEX32;
	

	}

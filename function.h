#include "datatype.h"
//nguyen mau ham
//LUA CHON 
void Choice_Login(int *choice_login);//lua chon dang nhap 
void Choice_Menu(int *choice_menu);//lua chon chuc nang
//LOGIN
int LoginAdmin();//dang nhap tai khoan admin
void LoginUser();//dang nhap tai khoan User
void LoginNewUser();//dang ky User moi

//Menu Book
void MenuLogin();//hien thi lua chon login
void MenuBook();//menu lua chon chuc nang

//Chuc nang Book
void Book_01(int *Count, int *number, Book Books[100]);//In sach
void Book_02(int *Count, int *temp,int *number, Book Books[100]);//Them Sach
int Book_03(int *temp,int *number, Book Books[100]);//sua danh sach Book
int Book_04(int *temp, int *number, Book Books[100]);




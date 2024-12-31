#include <stdio.h>
#include <stdlib.h>
#include "function.h"
int main(int argc, char *argv[]) {
	int Count = 0;
	int number = 5;// 5 Phan tu cua Books
	int temp;//Sua ID
	int choice_login;//Lua chon dang nhap
	int choice_menu;//lua chon chuc nang trong menu
	Book Books[100] = {
	{1,"Truyen Kieu","Nguyen Du",25},
	{2,"Doraemon","Fujiko",15},
	{3,"One Piece","Oda",20},
	{4,"Mat Biec","Nguyen Nhat Anh",40},
	{5,"Dat Rung Phuong Nam","Doan Gioi",45}
	};
	MenuLogin();//Hien thi Menu dang nhap tai khoan , mat khau
	Choice_Login(&choice_login);//Lua chon cach thuc dang nhap
	

switch(choice_login){//Lua chon cach dang nhap
	
	case 0://Thoat khoi chuong trinh
	printf("Ban da thoat khoi login\n");
		break;
	case 1://login admin
		LoginAdmin();
			if(1){
		do{
		MenuBook();
		choice_menu =0;
		Choice_Menu(&choice_menu);
		
			switch(choice_menu){//switch lua chon menu
				case 1:
					Book_01(&Count,&number,Books);//In Book
					break;
				case 2:
					Book_02(&Count, &temp, &number, Books);//Them Sach
					break;
				case 3:
					Book_03(&temp,&number, Books);//Sua sach
					break;
				
				case 4:
					Book_04(&temp,&number, Books);
					break;
			}//switch lua chon menu
		}while(choice_menu !=4);
	}
			break;
	
	case 2://login User
		break;
	
	case 3://login New User
	
		break;
		
	default:
		printf("Lua chon cua ban khong hop le. Vui long chon lai\n");	
}//switch/

	return 0;
}

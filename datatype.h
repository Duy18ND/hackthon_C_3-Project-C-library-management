#include<stdbool.h>
//cau truc 
struct login{//cau truc dang nhap tk,mk
//tai khoan nguoi dung nhap vao 
	char Email[150];
	char Password[100];	
};

typedef struct {//Menu book
	int ID;
	char Name[100];
	char Author[100]; 
	double Price;
}Book;

